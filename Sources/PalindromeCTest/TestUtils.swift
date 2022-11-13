import XCTest
import PalindromGenrate
import PalindromeC

fileprivate let testModInfo: Bool = false
fileprivate var commands = [UInt16: [Bool]]()

func TAssert(_ condition: Bool, file: StaticString = #file, line: UInt = #line, function: String = #function) {
    for command in 0..<512 {
        let index = UInt16(command)
        if debugCommands[command] != 0 {
            commands[index] = commands[index] ?? []
            commands[index]?.append(condition)
        }
    }
    XCTAssert(condition, file: file, line: line)
}

func printAllCommands() {
    var text = ""
    var all: Int = 0
    var s: Int = 0
    var f: Int = 0
    for command in 0..<512 {
        guard let results = commands[UInt16(command)], !results.isEmpty else {
            continue
        }
        all += 1
        s += !results.contains { !$0 } ? 1 : 0
        f += !results.contains { $0 } ? 1 : 0
        let string = "\(UInt16(command).rawHex): " + results.map { $0 ? "+" : "-" }.joined()
        text += string + "\n"
    }
    text += "\nall: \(all) <+: \(s)><-: \(f)><+-: \(all - s - f)>\n"
    try! text.write(
        toFile: "/Users/alexandershipin/Documents/projects/Palindrome/Sources/TestSource/TestResult.text",
        atomically: true,
        encoding: .utf8
    )
}
