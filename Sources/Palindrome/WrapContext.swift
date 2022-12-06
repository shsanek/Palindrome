import PalindromeC
import Foundation

public enum Mod {
    case mod32
    case mod16
}

public enum LoadProgramType {
    /// программа будет загружена с 0 байта, ограничения `(программа) < 0xFFFF - 2`
    /// все регистры 0 кроме стековых
    /// годиться только для тестов
    /// процессор работает в реальном режиме
    /// (0xFFFF - 2) заноситься прерывание `CD10` на выход программы, адрес занесен в стек чтобы по `C3` завершать программу
    case simple(mod: Mod)

    /// Загрузка Windows/Dos программ по заголовку процессор будет переведен в рельный или в защищеный режим
    /// Если загрузка в реальном режиме то будет выделено` 0xFFFF * 16` байт памяти
    /// будут частично заполнены вектора прерывания в 0 адресах
    /// также будет заполнена часть верхних адресов
    /// программа разместиться с секции `0x178E` (для нормальной работы тестов записаных с эмулятора кьюми)
    case program
}

public final class WrapContext {
    public enum State {
        case done
        case normal
        case invalidate
        case notCommand
    }

    public var state: State {
        guard let context = context else {
            return .invalidate
        }
        if context[0].end == 0 {
            return .normal
        } else if context[0].end == 1 {
            return .done
        } else if context[0].end == 2 {
            return .notCommand
        }
        return .invalidate
    }
    public private(set) var context: UnsafeMutablePointer<Context>?
    public let timer = TickTimer()

    private var functionsContainer = FunctionContainer()

    private static let installQueue = DispatchQueue(label: "com.install.palindromfunction")
    private static var isFirst: Bool = true

    public init() {
        Self.load()
        self.context = resetContext()
    }

    private static func load() {
        installQueue.sync {
            guard isFirst else {
                return
            }
            installCommandFunction()
            isFirst = false
        }
    }

    deinit {
        timer.stop()
        freeContext()
    }

    public func loadProgram(with type: LoadProgramType, pointer: UnsafeMutablePointer<UInt8>, size: Int) {
        switch type {
        case .program:
            loadDosProgram(pointer, UInt32(size))
        case .simple(let mod):
            loadProgramInZeroMemory(pointer, UInt32(size), mod == .mod16 ? 0: 1)
        }
    }

    public func loadProgram(with type: LoadProgramType, _ data: Data) {
        var mData = data
        mData.toPointer({ pointer in
            loadProgram(with: type, pointer: pointer, size: data.count)
        })
    }

    public func loadProgram(with type: LoadProgramType, _ text: String) {
        let regex = try! NSRegularExpression(pattern: "[0-9a-f]{1,2}", options: .caseInsensitive)
        var memory = Data()
        let text = text.lowercased().replacingOccurrences(of: " ", with: "").replacingOccurrences(of: "\n", with: "").replacingOccurrences(of: "\t", with: "")
        regex.enumerateMatches(in: text, range: NSRange(text.startIndex..., in: text)) { match, _, _ in
            let byteString = (text as NSString).substring(with: match!.range)
            let num = UInt8(byteString, radix: 16)!
            memory.append(num)
        }
        loadProgram(with: type, memory)
    }

    public func setFunction(_ index: UInt8, block: @escaping (inout Context) -> Void) {
        self.functionsContainer.functions[index] = block
    }

    private func generateProgramm(
        programm: [UInt8],
        block: (_ pointer: UnsafeMutablePointer<UInt8>, _ size: Int) -> Void
    ) {
        let buffer = UnsafeMutablePointer<UInt8>.allocate(capacity: programm.count)
        for container in programm.enumerated() {
            buffer[container.offset] = container.element
        }
        block(buffer, programm.count)
        buffer.deallocate()
    }

}

public final class TickTimer {
    private var firstTime: TimeInterval = Date().timeIntervalSince1970
    private var tick = 0
    private var timer: Timer?
    private let stepTime: TimeInterval

    private var isRun: Bool = false
    private let queue = DispatchQueue(label: "TickTimer")

    init(stepTime: TimeInterval = 55.0 / 1000.0) {
        self.stepTime = stepTime
    }

    @discardableResult
    public func stop() -> Self {
        queue.sync {
            self.isRun = false
        }
        return self
    }

    @discardableResult
    public func run() -> Self {
        queue.async {
            self.isRun = true
            self.runTickTimer()
        }
        return self
    }

    private func runTickTimer() {
        let base = TimeInterval(self.tick + 1) * self.stepTime
        let count = (base - self.firstTime) / self.stepTime

        queue.asyncAfter(deadline: .now() + self.stepTime / count) {
            guard self.isRun else {
                return
            }
            InterruptCall(0x08)
            self.tick += 1
            self.runTickTimer()
        }
    }
}

final class FunctionContainer {
    var functions: [UInt8: (inout Context) -> Void] = [:]
}


public extension String {
    func toCString(_ block: (UnsafeMutablePointer<Int8>) -> Void) {
        self.withCString { pointer in
            var len = 0
            while pointer[len] != 0 { len += 1 }
            len += 1
            let result = UnsafeMutablePointer<Int8>.allocate(capacity: len)

            for i in 0..<len {
                result[i] = pointer[i]
            }
            block(result)
            result.deallocate()
        }
    }

    func toCUString(_ block: (UnsafeMutablePointer<UInt8>) -> Void) {
        self.withCString { pointer in
            var len = 0
            while pointer[len] != 0 { len += 1 }
            len += 1
            let result = UnsafeMutablePointer<UInt8>.allocate(capacity: len)

            for i in 0..<len {
                result[i] = UInt8(bitPattern: pointer[i])
            }
            block(result)
            result.deallocate()
        }
    }
}

extension Data {
    mutating func toPointer(_ block: (UnsafeMutablePointer<UInt8>) -> Void) {
        withUnsafeMutableBytes { (rawMutableBufferPointer) in
            let bufferPointer = rawMutableBufferPointer.bindMemory(to: UInt8.self)
            if let address = bufferPointer.baseAddress{
                block(address)
            }
        }
    }
}

public extension WrapContext {
    func addVirtualFolder(_ virtualPath: String, path: String) {
        path.toCString { path in
            virtualPath.toCString { vPath in
                PalindromeC.addVirtualFolder(vPath, path, 1)
            }
        }
    }
}
