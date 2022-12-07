import Foundation

func makeMove(target: String, value: String) -> String {
    let move: String = "mov %target, %value"
    return move
        .replacingOccurrences(of: "%target", with: target)
        .replacingOccurrences(of: "%value", with: value)
}

func makeCommand(name: String, arg1: String, arg2: String?) -> String {
    var template: String = "%command %x, %y"
    if arg2 == nil {
        template = "%command %x"
    }
    return template
        .replacingOccurrences(of: "%x", with: arg1)
        .replacingOccurrences(of: "%y", with: arg2 ?? "")
        .replacingOccurrences(of: "%command", with: name)

}

let mathCommands = ["ADD", "OR", "ADC", "SBB", "AND", "SUB", "XOR"]
let oneOperandCommands = ["NOT", "NEG"]
let specialValue: [UInt16] = [0x0000, 0x0001, 0xFFFF, 0x8000, 0x7FFF, 0x7F, 0x80, 0x8001, 0x7FFE, 0x7E, 0x81]

extension UInt8 {
    public var rawHex: String {
        String(format: "%02X", self).uppercased()
    }
}

extension UInt16 {
    public var rawHex: String {
        UInt8((self >> 8) & 0x00FF).rawHex + UInt8(self & 0x00FF).rawHex
    }
}

func generateCommand(for command: String, value1: String, value2: String? = nil, useData: Bool = false, w: Bool = true) -> String {
    var result = ""
    result.append("PUSH BP\nPUSH BP\nPOPF\n")
    result.append("\(makeMove(target: "SP", value: "SI"))\n")

    if let value2 = value2 {
        if !useData {
            if (w) {
                result.append("\(makeMove(target: "AX", value: value1))\n")
                result.append("\(makeMove(target: "DX", value: value2))\n")

                result.append("\(makeCommand(name: command, arg1: "AX", arg2: "DX"))\n")
            } else {
                result.append("\(makeMove(target: "AL", value: String(value1.suffix(2))))\n")
                result.append("\(makeMove(target: "DL", value: String(value2.suffix(2))))\n")

                result.append("\(makeCommand(name: command, arg1: "AL", arg2: "DL"))\n")
            }
        } else {
            if (w) {
                result.append("\(makeMove(target: "AX", value: value1))\n")

                result.append("\(makeCommand(name: command, arg1: "AX", arg2: value2))\n")
            } else {
                result.append("\(makeMove(target: "AL", value: String(value1.suffix(2))))\n")

                result.append("\(makeCommand(name: command, arg1: "AL", arg2: String(value2.suffix(2))))\n")
            }
        }
    } else {
        if (w) {
            result.append("\(makeMove(target: "AX", value: value1))\n")

            result.append("\(makeCommand(name: command, arg1: "AX", arg2: nil))\n")
        } else {
            result.append("\(makeMove(target: "AL", value: String(value1.suffix(2))))\n")

            result.append("\(makeCommand(name: command, arg1: "AL", arg2: nil))\n")
        }
    }

    return result
}

func generateAll(for command: String, a1: UInt16, a2: UInt16) -> String{
    var result = ""

    result.append(generateCommand(for: command, value1: a1.rawHex, value2: a2.rawHex, w: true))
    result.append(generateCommand(for: command, value1: a1.rawHex, value2: a2.rawHex, w: false))
    result.append(generateCommand(for: command, value1: a1.rawHex, value2: a2.rawHex, useData: true, w: true))
    result.append(generateCommand(for: command, value1: a1.rawHex, value2: a2.rawHex, useData: true, w: false))
    result.append(generateCommand(for: command, value1: a1.rawHex, value2: String(a2.rawHex.suffix(2)), useData: true, w: true))

    return result
}

func generate(for command: String, randomCount: Int) -> String {
    var result = ""
    for _ in 0..<randomCount {
        let a1 = UInt16.random(in: 0..<0xFFFF)
        let a2 = UInt16.random(in: 0..<0xFFFF)
        result.append(generateAll(for: command, a1: a1, a2: a2))
    }
    for i in 0..<specialValue.count * 2 {
        let a1 = specialValue[i / 2]
        let a2 = specialValue[i % 2]

        result.append(generateAll(for: command, a1: a1, a2: a2))
    }
    return result
}

func generateOneOperand(for command: String, randomCount: Int) -> String {
    var result = ""
    for _ in 0..<randomCount {
        let a1 = UInt16.random(in: 0..<0xFFFF)

        result.append(generateCommand(for: command, value1: a1.rawHex, w: true))
        result.append(generateCommand(for: command, value1: a1.rawHex, w: false))
    }
    for i in 0..<specialValue.count * 2 {
        let a1 = specialValue[i / 2]

        result.append(generateCommand(for: command, value1: a1.rawHex, w: true))
        result.append(generateCommand(for: command, value1: a1.rawHex, w: false))

    }
    return result
}


var result = ""

for command in mathCommands {
    result.append("\"\(command)_flag_of\": \"\"\"\n")
    result.append("\(makeMove(target: "SI", value: "SP"))\n")
    result.append("\(makeMove(target: "BP", value: "0000"))\n")
    result.append(generate(for: command, randomCount: 10))
    result.append("int 20\n")
    result.append("\"\"\",\n")
}
for command in oneOperandCommands {
    result.append("\"\(command)_flag_off\": \"\"\"\n")
    result.append("\(makeMove(target: "SI", value: "SP"))\n")
    result.append("\(makeMove(target: "BP", value: "0000"))\n")
    result.append(generate(for: command, randomCount: 10))
    result.append("int 20\n")
    result.append("\"\"\",\n")
}
for command in mathCommands {
    result.append("\"\(command)_flag_on\": \"\"\"\n")
    result.append("\(makeMove(target: "SI", value: "SP"))\n")
    result.append("\(makeMove(target: "BP", value: "FFFF"))\n")
    result.append(generate(for: command, randomCount: 10))
    result.append("int 20\n")
    result.append("\"\"\",\n")
}
for command in oneOperandCommands {
    result.append("\"\(command)_flag_on\": \"\"\"\n")
    result.append("\(makeMove(target: "SI", value: "SP"))\n")
    result.append("\(makeMove(target: "BP", value: "FFFF"))\n")
    result.append(generate(for: command, randomCount: 10))
    result.append("int 20\n")
    result.append("\"\"\",\n")
}
result = result.lowercased()

print(result)

print("\n")
