import XCTest
import PalindromeC
import Palindrome

final class FirstTest: XCTestCase {

    override class func tearDown() {
        super.tearDown()
        printAllCommands()
    }

    func test00() throws {
        let wrapContext = WrapContext()
        wrapContext.loadProgram(
            with: .simple(mod: .mod16),
            "BB1100B90D00B40E8A0743CD10E2F9CD2048656C6C6F2C20576F726C6421"
        )

        DebugOnlyPrint = 1;

        runFullModeToEndWithStop(10000)

        let cString = wrapContext.context?[0].text
        let result = String(cString: cString!)

        TAssert("Hello, World!" == result)
    }

    func test01() throws {
        let wrapContext = WrapContext()
        wrapContext.loadProgram(
            with: .simple(mod: .mod32),
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

        runFullModeToEndWithStop(0)

        let value = fregister32(UInt8(BR_EAX_F))?[0]

        TAssert(3628800 == value)
    }

    func test02() throws {
        let wrapContext = WrapContext()
        wrapContext.loadProgram(
            with: .simple(mod: .mod32),
            """
            8b442404
            ba01000000
            85c0
            740b
            8d7600
            0fafd0
            83e801
            75f8
            89d0
            c3
            """
        )
        pushInStack32(10)
        returnToTopStack();

        runFullModeToEndWithStop(10000)

        let value = fregister32(UInt8(BR_EAX_F))?[0]

        TAssert(3628800 == value)
    }

    let basePath = "/Users/alexandershipin/Documents/projects/Palindrome/Sources/TestSource/"

    func test03() throws {
        let wrapContext = WrapContext()

        let programm = try! Data(
            contentsOf: URL.init(
                fileURLWithPath: basePath + "FactorialTest/factorial.bin"
            )
        )
        wrapContext.loadProgram(
            with: .simple(mod: .mod32),
            programm
        )

        runFullModeToEndWithStop(10000)

        let cString = wrapContext.context?[0].text
        let result = String(cString: cString!)

        let realResult = (0..<10).map({ "\(factorial(number: Int32($0)))" }).joined()
        TAssert(result == realResult)
    }

    func test03_O1() throws {
        let wrapContext = WrapContext()

        let programm = try! Data(
            contentsOf: URL.init(
                fileURLWithPath: basePath + "FactorialTest/factorialO1.bin"
            )
        )
        wrapContext.loadProgram(
            with: .simple(mod: .mod32),
            programm
        )

        runFullModeToEndWithStop(10000)

        let cString = wrapContext.context?[0].text
        let result = String(cString: cString!)

        let realResult = (0..<10).map({ "\(factorial(number: Int32($0)))" }).joined()
        TAssert(result == realResult)
    }

    func test04() throws {
        let wrapContext = WrapContext()

        let programm = try! Data(
            contentsOf: URL.init(
                fileURLWithPath: basePath + "SortTest/sort.bin"
            )
        )
        wrapContext.loadProgram(
            with: .simple(mod: .mod32),
            programm
        )

        runFullModeToEndWithStop(10000)

        let cString = wrapContext.context?[0].text
        let result = String(cString: cString!)

        print(result)

        TAssert(result == "-2 0 1 2 3 ")
    }

    func test04_O1() throws {
        let wrapContext = WrapContext()

        let programm = try! Data(
            contentsOf: URL.init(
                fileURLWithPath: basePath + "SortTest/sortO1.bin"
            )
        )
        wrapContext.loadProgram(
            with: .simple(mod: .mod32),
            programm
        )

        runFullModeToEndWithStop(10000)

        let cString = wrapContext.context?[0].text
        let result = String(cString: cString!)

        print(result)

        TAssert(result == "-2 0 1 2 3 ")
    }

    func test05() throws {
        let wrapContext = WrapContext()

        let programm = try! Data(
            contentsOf: URL.init(
                fileURLWithPath: basePath + "NegTest/neg.bin"
            )
        )
        wrapContext.loadProgram(
            with: .simple(mod: .mod32),
            programm
        )

        runFullModeToEndWithStop(10000)

        let cString = wrapContext.context?[0].text
        let result = String(cString: cString!)

        TAssert(result == "-10")
    }

    func test05_O1() throws {
        let wrapContext = WrapContext()

        let programm = try! Data(
            contentsOf: URL.init(
                fileURLWithPath: basePath + "NegTest/negO1.bin"
            )
        )
        wrapContext.loadProgram(
            with: .simple(mod: .mod32),
            programm
        )

        runFullModeToEndWithStop(10000)

        let cString = wrapContext.context?[0].text
        let result = String(cString: cString!)

        TAssert(result == "-10")
    }

    func test06() throws {
        let wrapContext = WrapContext()

        let programm = try! Data(
            contentsOf: URL.init(
                fileURLWithPath: basePath + "FpuTest/fpu.bin"
            )
        )
        wrapContext.loadProgram(
            with: .simple(mod: .mod32),
            programm
        )

        runFullModeToEndWithStop(10000)

        let cString = wrapContext.context?[0].text
        let result = String(cString: cString!)

        TAssert(result == "100")
    }

    func test07() throws {
        let wrapContext = WrapContext()

        let testPath = "/Users/alexandershipin/Documents/projects/Palindrome/Sources/TestSource/Tetris/out.txt"
        let programm = try! Data(
            contentsOf: URL.init(
                fileURLWithPath: "/Users/alexandershipin/Documents/projects/Palindrome/Sources/TestSource/Tetris/TETRIS.COM"
            )
        )

        wrapContext.loadProgram(with: .program, programm)

        let value = runFullModeToEndWithStopForTest(104)

        let result = String(cString: value!)

//        let out = String(data: try! Data(contentsOf: URL(fileURLWithPath: "/Users/alexandershipin/Documents/projects/Palindrome/Sources/TestSource/Tetris/full3.log")), encoding: .utf8)!.convertFullOutToTest()

        // try! result.write(toFile: testPath, atomically: true, encoding: .utf8)

        value?.deallocate()

        let source = String(data: try! Data(contentsOf: URL(fileURLWithPath: testPath)), encoding: .utf8)!
        let error = result.getErrorCommand(source: source)
        TAssert(error == nil)

        runFullModeToEndWithStop(0);
    }

    func test08() throws {
        let wrapContext = WrapContext()

        let testPath = "/Users/alexandershipin/Documents/projects/Palindrome/Sources/TestSource/Doom/out.txt"

        let programm = try! Data(
            contentsOf: URL.init(
                fileURLWithPath: "/Users/alexandershipin/Downloads/doom/doom.exe"
            )
        )

        wrapContext.addVirtualFolder("D:\\", path: "/Users/alexandershipin/Downloads/doom/")

        wrapContext.loadProgram(with: .program, programm)

        let number = 6748
        let value = runFullModeToEndWithStopForTest(Int32(number))
        let result = String(cString: value!)
        value?.deallocate()

//        let out = String(data: try! Data(contentsOf: URL(fileURLWithPath: "/Users/alexandershipin/Documents/projects/Palindrome/Sources/TestSource/Doom/full4.log")), encoding: .utf8)!.convertFullOutToTest()
//
//        try! out.write(toFile: testPath, atomically: true, encoding: .utf8)

        // try! result.convertFullOutToTest().write(toFile: testPath, atomically: true, encoding: .utf8)

        let source = String(data: try! Data(contentsOf: URL(fileURLWithPath: testPath)), encoding: .utf8)!
        let error = result.getErrorCommand(source: source)

        TAssert(error == nil || error == number)

        // runFullModeToEndWithStop(100);
    }

    func test09() throws {
        let wrapContext = WrapContext()
        wrapContext.context?[0].mod = 1

        let testPath = "/Users/alexandershipin/Documents/projects/Palindrome/Sources/TestSource/Wolf/out.txt"

        let programm = try! Data(
            contentsOf: URL.init(
                fileURLWithPath: "/Users/alexandershipin/Downloads/wolf3d-box/WOLF3D/WOLF3D.EXE"
            )
        )

        wrapContext.addVirtualFolder("D:\\", path: "/Users/alexandershipin/Downloads/wolf3d-box/WOLF3D/")
        wrapContext.loadProgram(with: .program, programm)


        let number = 1000
        let value = runFullModeToEndWithStopForTest(Int32(number))
        let result = String(cString: value!)
        value?.deallocate()

        // try! result.write(toFile: testPath, atomically: true, encoding: .utf8)

        let source = String(data: try! Data(contentsOf: URL(fileURLWithPath: testPath)), encoding: .utf8)!
        let error = result.getErrorCommand(source: source)

        TAssert(error == nil || error == number)

        runFullModeToEndWithStop(0);
    }

    func test10() throws {
        let wrapContext = WrapContext()
        wrapContext.context?[0].mod = 1

        let testPath = "/Users/alexandershipin/Documents/projects/Palindrome/Sources/TestSource/prince/reg.txt"
//        let out = String(data: try! Data(contentsOf: URL(fileURLWithPath: "/Users/alexandershipin/Documents/projects/Palindrome/Sources/TestSource/prince/full.log")), encoding: .utf8)!.convertFullOutToTest()
//
//        try! out.write(toFile: testPath, atomically: true, encoding: .utf8)

        let programm = try! Data(
            contentsOf: URL.init(
                fileURLWithPath: "/Users/alexandershipin/Downloads/pop1dem/POP1DEMO/PRINCE.EXE"
            )
        )

        wrapContext.addVirtualFolder("D:\\", path: "/Users/alexandershipin/Downloads/pop1dem/POP1DEMO")
        wrapContext.addVirtualFolder("D:\\DOOM.EXE", path: "/Users/alexandershipin/Downloads/pop1dem/POP1DEMO/PRINCE.EXE")

        wrapContext.loadProgram(with: .program, programm)

        let number = 315
        let value = runFullModeToEndWithStopForTest(Int32(number))
        let result = String(cString: value!)
        value?.deallocate()

        // try! result.write(toFile: testPath, atomically: true, encoding: .utf8)

        let source = String(data: try! Data(contentsOf: URL(fileURLWithPath: testPath)), encoding: .utf8)!
        let error = result.getErrorCommand(source: source)

        TAssert(error == nil || error == number)

        runFullModeToEndWithStop(40000);

        TAssert(true);
    }
}

func factorial(number: Int32) -> Int32 {
    if (number == 0) {
        return 1
    }
    return number * factorial(number: number - 1)
}
