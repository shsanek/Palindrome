import PalindromeC
import Foundation

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

    private var functionsContainer = FunctionContainer()

    private static let installQueue = DispatchQueue(label: "com.install.palindromfunction")
    private static var isFirst: Bool = true

    public init(memorySize: Int = 32 * 1024, notUseExternalFunction: Bool = false) {
        Self.load()
        self.context = resetContext(UInt32(memorySize))
        if !notUseExternalFunction {
            setting()
        }
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
        freeContext()
    }

    public func runCommand() {
        PalindromeC.runCommand()
    }

    public func setMemory(_ memory: [UInt8], offset: Int = 0) {
        for container in memory.enumerated() {
            context?[0].memory[container.offset + offset] = container.element
        }
        context?[0].memory[memory.count] = 0xCD
        context?[0].memory[memory.count + 1] = 0x20
        pushInStack32(Int32(memory.count))
        context?[0].index = context![0].memory + offset
    }

    public func setMemory(_ data: Data, offset: Int = 0) {
        let array = data.withUnsafeBytes {
            [UInt8](UnsafeBufferPointer(start: $0, count: data.count))
        }
        setMemory(array, offset: offset)
    }

    public func setMemory(_ text: String, offset: Int = 0) {
        let regex = try! NSRegularExpression(pattern: "[0-9a-f]{1,2}", options: .caseInsensitive)
        var memory: [UInt8] = []
        let text = text.lowercased().replacingOccurrences(of: " ", with: "").replacingOccurrences(of: "\n", with: "").replacingOccurrences(of: "\t", with: "")
        regex.enumerateMatches(in: text, range: NSRange(text.startIndex..., in: text)) { match, _, _ in
            let byteString = (text as NSString).substring(with: match!.range)
            let num = UInt8(byteString, radix: 16)!
            memory.append(num)
        }
        setMemory(memory, offset: offset)
    }

    public func setFunction(_ index: UInt8, block: @escaping (inout Context) -> Void) {
        self.functionsContainer.functions[index] = block
    }

    private func setting() {
//        let pointer = UnsafeMutableRawPointer(&functionsContainer)
//        self.context?[0].additionalContext = pointer
//        for i in 0..<256 {
//            self.context?[0].functions(i) = { (index) in
//                let opaquePtr = OpaquePointer()
//                let context = UnsafeMutablePointer<Context>(opaquePtr)
//                guard let context = context else {
//                    return
//                }
//                let functionsContainerPtr = OpaquePointer([0].additionalContext)
//                let functionsContainer = UnsafeMutablePointer<FunctionContainer>(functionsContainerPtr)
//
//                functionsContainer?[0].functions[UInt8(index)]?(&context[0])
//            }
//        }
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

final class FunctionContainer {
    var functions: [UInt8: (inout Context) -> Void] = [:]
}
