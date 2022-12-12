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
        var log = removeAllTwoSpaceSpace()
            .split(separator: "\n")
            .filter({ $0.hasPrefix("AX=") || $0.hasPrefix("DS=") })
        log.removeFirst()
        log.removeFirst()
        return log.joined(separator: "\n")
    }

    func convertFullOutToCode() -> String {
        let code = removeAllTwoSpaceSpace()
            .split(separator: "\n")
            .filter({ !$0.hasPrefix("AX=") && !$0.hasPrefix("DS=") && !$0.hasPrefix(" ") })
            .map( {  String($0.components(separatedBy: " ")[1]) })
        return code.joined(separator: "\n")
    }

    func convertIgnore(flags: [String]) -> String {
        var result = self
        for flag in flags {
            result = result.replacingOccurrences(of: " \(flag)", with: "")
        }
        return result
    }

    func generateCommands(ignoreFlags: Bool = true, maps: [CommandMap] = []) -> [String] {
        let flags = ignoreFlags ? ["PO", "PE", "NA", "AC", "NC", "CY", "NG", "PL", "OV", "NV"] : []

        let raws = self
            .removeAllTwoSpaceSpace()
            .convertIgnore(flags: flags)
            .split(separator: "\n")
            .map(String.init)
            .map {
                $0.hasSuffix(" ") ? String($0.dropLast()) : $0
            }
        var result: [String] = []
        for i in 0..<(raws.count/2) {
            var text = "\(raws[i * 2])\n\(raws[i * 2 + 1])"
            for map in maps {
                if (map.condition(text)) {
                    text = map.map(text)
                }
            }
            result.append(text)
        }
        return result
    }

    func getErrorCommand(source: String, ignoreFlags: Bool = true, maps: [CommandMap] = []) -> Int? {
        let raws1 = self.generateCommands(ignoreFlags: ignoreFlags, maps: maps)
        let raws2 = source.generateCommands(ignoreFlags: ignoreFlags,maps: maps)

        var index = 0

        while (index < raws1.count && index < raws2.count && raws2[index] == raws1[index]) {
            index += 1
        }

        if (index == raws1.count && index == raws2.count) {
            return nil
        }
        let generator = FunctionGenerator()
        let instruct = index
        generator.add("ERROR in instruction \(instruct)")
        if instruct < raws1.count {
            generator.add("Result:")
            generator.add("\(raws1[instruct])")
        }
        if instruct < raws2.count {
            generator.add("Real result:")
            generator.add("\(raws2[instruct])")
        }
        print("\n\(generator.text)")
        return instruct
    }

    struct CommandMap {
        let condition: (String) -> Bool
        let map: (String) -> String

        init(condition: @escaping (String) -> Bool, map: @escaping (String) -> String) {
            self.condition = condition
            self.map = map
        }

        init(_ contains: String, remove: [String]) {
            self.condition = { $0.contains(contains) }
            self.map = { text in
                var result = text
                for item in remove {
                    result = result.replacingOccurrences(of: item, with: "")
                }
                return result
            }
        }

        init(not contains: String, remove: [String]) {
            self.condition = { !$0.contains(contains) }
            self.map = { text in
                var result = text
                for item in remove {
                    result = result.replacingOccurrences(of: item, with: "")
                }
                return result
            }
        }
    }
}
