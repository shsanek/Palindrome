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
    for command in 0..<512 {
        let string = "\(UInt16(command).rawHex): " + (commands[UInt16(command)] ?? []).map { $0 ? "+" : "-" }.joined()
        text += string + "\n"
    }
    try! text.write(
        toFile: "/Users/alexandershipin/Documents/projects/Palindrome/Sources/TestSource/TestResult.text",
        atomically: true,
        encoding: .utf8
    )
}
