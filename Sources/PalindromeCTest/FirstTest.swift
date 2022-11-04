import XCTest
import PalindromeC
import Palindrome

final class FirstTest: XCTestCase {
    func test00() throws {
        let wrapContext = WrapContext()
        wrapContext.setMemory(
            [0xBB, 0x11, 0x00, 0xB9, 0x0D, 0x00, 0xB4, 0x0E, 0x8A, 0x07, 0x43,
             0xCD, 0x10, 0xE2, 0xF9, 0xCD, 0x20, 0x48, 0x65, 0x6C, 0x6C, 0x6F,
             0x2C, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21]
        )
        var result = "";
        wrapContext.setFunction(0x10) { context in
            if let string = String(bytes: [context.uAL], encoding: .utf8) {
                result.append(string)
            }
        }

        wrapContext.setFunction(0x20) { context in
            context.end = 1
        }

        while wrapContext.state == .normal {
            wrapContext.runCommand()
        }

        XCTAssert("Hello, World!" == result)
    }

    func test00Performance() {
        let wrapContext = WrapContext()
        wrapContext.setMemory(
            [0xBB, 0x11, 0x00, 0xB9, 0x0D, 0x00, 0xB4, 0x0E, 0x8A, 0x07, 0x43,
             0xCD, 0x10, 0xE2, 0xF9, 0xCD, 0x20, 0x48, 0x65, 0x6C, 0x6C, 0x6F,
             0x2C, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21]
        )
        var result = ""
        wrapContext.setFunction(0x10) { context in
            if let string = String(bytes: [context.uAL], encoding: .utf8) {
                result.append(string)
            }
        }

        wrapContext.setFunction(0x20) { context in
            context.end = 1
        }

        measure {
            for _ in 0..<10000 {
                result = ""
                wrapContext.context?[0].index = wrapContext.context?[0].program
                wrapContext.context?[0].end = 0
                while wrapContext.state == .normal {
                    wrapContext.runCommand()
                }
                XCTAssert("Hello, World!" == result)
            }
        }
    }

    func test01Performance() {
        let context = HelloWoldPerformFunction()
        var result = ""
        context.callBacks[0x10] = {
            result.append("\($0)")
        }
        context.callBacks[0x20] = { _ in
            context.end = 1
        }
        measure {
            for _ in 0..<10000 {
                result = ""
                context.index = 0
                context.end = 0
                while context.end == 0 {
                    context.run()
                }
                XCTAssert("Hello, World!" == result)
            }
        }
    }

    final class HelloWoldPerformFunction {
        var callBacks = [UInt8: (Character) -> Void]()
        var end = 0
        var index = 0
        let text = "Hello, World!"

        func run() {
            let a = text[text.index(text.startIndex, offsetBy: index)]
            callBacks[0x10]?(a)
            index += 1
            if index == text.count {
                callBacks[0x20]?("0")
            }
        }
    }
}
