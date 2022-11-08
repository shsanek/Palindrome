import XCTest
import PalindromeC
import Palindrome

final class FirstTest: XCTestCase {
    func test00() throws {
        let wrapContext = WrapContext()
        wrapContext.setMemory(
            "BB1100B90D00B40E8A0743CD10E2F9CD2048656C6C6F2C20576F726C6421"
        )

        wrapContext.context?[0].mod = 0

        while wrapContext.state == .normal {
            wrapContext.runCommand()
        }

        let cString = wrapContext.context?[0].text
        let result = String(cString: cString!)

        XCTAssert("Hello, World!" == result)
    }

    func test01() throws {
        let wrapContext = WrapContext()
        wrapContext.context?[0].mod = 1
        wrapContext.setMemory(
            """
            8d4c2404
            83e4f0
            ff71fc
            55
            89e5
            51
            83ec04
            83ec0c
            6a0a
            e80b000000
            83c410
            8d4dfc
            c9
            8d61fc
            c3
            55
            89e583ec08
            837d0800
            7507
            b801000000
            eb16
            8b4508
            83e801
            83ec0c
            50
            e8deffffff
            83c410
            0faf4508
            c9
            c3
            """
        )

        while wrapContext.state == .normal {
            wrapContext.runCommand()
        }
        let value = register32(UInt8(BR_EAX_F))?[0]

        XCTAssert(3628800 == value)
    }

    func test00Performance() {
        let wrapContext = WrapContext()
        wrapContext.setMemory(
            "BB1100B90D00B40E8A0743CD10E2F9CD2048656C6C6F2C20576F726C6421"
        )
        wrapContext.context?[0].mod = 0
        measure {
            for _ in 0..<10000 {
                wrapContext.context?[0].index = wrapContext.context?[0].program
                wrapContext.context?[0].end = 0
                wrapContext.context?[0].cursor = 0
                while wrapContext.state == .normal {
                    wrapContext.runCommand()
                }
                let cString = wrapContext.context?[0].text
                let result = String(cString: cString!)
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
