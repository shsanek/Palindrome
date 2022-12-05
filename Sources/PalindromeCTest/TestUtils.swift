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

extension String {
    func removeAllTwoSpaceSpace() -> String {
        var result = self
        var current = self.replacingOccurrences(of: "  ", with: " ")
        while (result.count != current.count) {
            result = current;
            current = current.replacingOccurrences(of: "  ", with: " ")
        }
        return result
    }
    func convertFullOutToTest() -> String {
        removeAllTwoSpaceSpace()
            .split(separator: "\n")
            .filter({ $0.hasPrefix("AX=") || $0.hasPrefix("DS=") })
            .joined(separator: "\n")
    }

    func convertIgnore(flags: [String]) -> String {
        var result = self
        for flag in flags {
            result = result.replacingOccurrences(of: " \(flag)", with: "")
        }
        return result
    }

    func getErrorCommand(source: String) -> Int? {
        var raws1 = self.removeAllTwoSpaceSpace().convertIgnore(flags: ["PO", "PE", "NA", "AC", "NC", "CY"]).split(separator: "\n")
        var raws2 = source.removeAllTwoSpaceSpace().convertIgnore(flags: ["PO", "PE", "NA", "AC", "NC", "CY"]).split(separator: "\n")

        raws1 = raws1.map { $0.hasSuffix(" ") ? $0.dropLast() : $0 }
        raws2 = raws2.map { $0.hasSuffix(" ") ? $0.dropLast() : $0 }

        var index = 0

        while (index < raws1.count && index < raws2.count && raws2[index] == raws1[index]) {
            index += 1
        }

        if (index == raws1.count && index == raws2.count) {
            return nil
        }
        let generator = FunctionGenerator()
        let instruct = index / 2
        generator.add("ERROR in instruction \(instruct)")
        if instruct * 2 + 1 < raws1.count {
            generator.add("Result:")
            generator.add("\(raws1[instruct * 2])")
            generator.add("\(raws1[instruct * 2 + 1])")
        }
        if (index / 2) * 2 + 1 < raws2.count {
            generator.add("Real result:")
            generator.add("\(raws2[instruct * 2])")
            generator.add("\(raws2[instruct * 2 + 1])")
        }
        print("\n\(generator.text)")
        return instruct
    }
}
