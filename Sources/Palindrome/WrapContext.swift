import PalindromeC
import Foundation

public final class WrapContext {
    public enum State {
        case done
        case normal
        case invalidate
    }

    public var state: State {
        guard let context = context else {
            return .invalidate
        }
        if context[0].end == 0 {
            return .normal
        } else {
            return .done
        }
    }
    public private(set) var context: UnsafeMutablePointer<Context>?

    private var functionsContainer = FunctionContainer()

    private static let installQueue = DispatchQueue(label: "com.install.palindromfunction")
    private static var isFirst: Bool = true

    public init(memorySize: Int = 32 * 1024, notUseExternalFunction: Bool = false) {
        Self.load()
        self.context = makeContext(UInt16(memorySize))
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
        freeContext(context)
    }

    public func runCommand() {
        PalindromeC.runCommand(context)
    }

    public func setMemory(_ memory: [UInt8]) {
        for container in memory.enumerated() {
            context?[0].memory[container.offset] = container.element
        }
    }

    public func setFunction(_ index: UInt8, block: @escaping (inout Context) -> Void) {
        self.functionsContainer.functions[index] = block
    }

    private func setting() {
        let pointer = UnsafeMutableRawPointer(&functionsContainer)
        self.context?[0].additionalContext = pointer
        for i in 0..<256 {
            self.context?[0].functions[i] = { (context, index) in
                let opaquePtr = OpaquePointer(context)
                let context = UnsafeMutablePointer<Context>(opaquePtr)
                guard let context = context else {
                    return
                }
                let functionsContainerPtr = OpaquePointer(context[0].additionalContext)
                let functionsContainer = UnsafeMutablePointer<FunctionContainer>(functionsContainerPtr)

                functionsContainer?[0].functions[UInt8(index)]?(&context[0])
            }
        }
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
