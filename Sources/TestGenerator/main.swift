import Foundation

func makeMove(target: String, value: String) -> String {
    let move: String = "mov %target, %value"
    return move
        .replacingOccurrences(of: "%target", with: target)
        .replacingOccurrences(of: "%value", with: value)
}

func makeCommand(name: String, arg1: String, arg2: String?, arg3: String?) -> String {
    var template: String = "%command %x, %y"
    if arg2 == nil {
        template = "%command %x"
    }
    if arg3 != nil {
        template = "%command %x, %y, %z"
    }
    return template
        .replacingOccurrences(of: "%x", with: arg1)
        .replacingOccurrences(of: "%y", with: arg2 ?? "")
        .replacingOccurrences(of: "%z", with: arg3 ?? "")
        .replacingOccurrences(of: "%command", with: name)

}

let mathCommands = ["ADD", "OR", "ADC", "SBB", "AND", "SUB", "XOR"]
let mathMulDivCommands = ["MUL", "DIV", "IMUL", "IDIV"]

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

func generateMove(value1: String, value2: String?, w: Bool) -> String {
    var result = ""
    if (w) {
        result.append("\(makeMove(target: "AX", value: value1))\n")
        if let value2 {
            result.append("\(makeMove(target: "DX", value: value2))\n")
            result.append("\(makeMove(target: "BX", value: value2))\n")
        }
    } else {
        result.append("\(makeMove(target: "AL", value: String(value1.suffix(2))))\n")
        if let value2 {
            result.append("\(makeMove(target: "DL", value: String(value2.suffix(2))))\n")
            result.append("\(makeMove(target: "BL", value: String(value2.suffix(2)))))\n")
        }
    }
    return result
}

func generateCommand(for command: String, value1: String, value2: String? = nil, useData: Bool = false, w: Bool = true) -> String {
    var result = ""
    result.append("PUSH BP\nPUSH BP\nPOPF\n")
    result.append("\(makeMove(target: "SP", value: "SI"))\n")

    if let value2 = value2 {
        if !useData {
            result.append(generateMove(value1: value1, value2: value2, w: w))
            if (w) {
                result.append("\(makeCommand(name: command, arg1: "AX", arg2: "DX", arg3: nil))\n")
            } else {
                result.append("\(makeCommand(name: command, arg1: "AL", arg2: "DL", arg3: nil))\n")
            }
        } else {
            if (w) {
                result.append(generateMove(value1: value1, value2: nil, w: w))
                result.append("\(makeCommand(name: command, arg1: "AX", arg2: value2, arg3: nil))\n")
            } else {
                result.append(generateMove(value1: value1, value2: nil, w: w))
                result.append("\(makeCommand(name: command, arg1: "AL", arg2: String(value2.suffix(2)), arg3: nil))\n")
            }
        }
    } else {
        result.append(generateMove(value1: value1, value2: nil, w: w))
        if (w) {
            result.append("\(makeCommand(name: command, arg1: "AX", arg2: nil, arg3: nil))\n")
        } else {
            result.append("\(makeCommand(name: command, arg1: "AL", arg2: nil, arg3: nil))\n")
        }
    }

    return result
}

func generateMulCommand(for command: String, value1: String, value2: String, useData: Bool, w: Bool = true) -> String {
    var value2 = value2
    if !((w && value2 != "0000") || (!w && String(value1.suffix(2)) != "00")) {
        value2 = "1"
    }
    var result = ""
    result.append("PUSH BP\nPUSH BP\nPOPF\n")
    result.append("\(makeMove(target: "SP", value: "SI"))\n")

    result.append(generateMove(value1: value1, value2: value2, w: w))
    if (!useData) {
        if (w) {
            result.append("\(makeCommand(name: command, arg1: "BX", arg2: nil, arg3: nil))\n")
        } else {
            result.append("\(makeCommand(name: command, arg1: "BL", arg2: nil, arg3: nil))\n")
        }
    } else {
        if (w) {
            result.append("\(makeCommand(name: command, arg1: "AX", arg2: "BX", arg3: value1))\n")
        } else {
            result.append("\(makeCommand(name: command, arg1: "AL", arg2: "BL", arg3: String(value1.suffix(2))))\n")
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

func generateMulDivAll(for command: String, a1: UInt16, a2: UInt16) -> String{
    var result = ""

    result.append(generateMulCommand(for: command, value1: a1.rawHex, value2: a2.rawHex, useData: false, w: false))
    result.append(generateMulCommand(for: command, value1: a1.rawHex, value2: a2.rawHex, useData: false, w: true))

    if (command == "IMUL") {
        result.append(generateMulCommand(for: command, value1: a1.rawHex, value2: a2.rawHex, useData: true, w: false))
        result.append(generateMulCommand(for: command, value1: a1.rawHex, value2: a2.rawHex, useData: true, w: true))
        result.append(generateMulCommand(for: command, value1: a1.rawHex, value2: String(a2.rawHex.suffix(2)), useData: true, w: true))
    }

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

func generateMul(for command: String, randomCount: Int) -> String {
    var result = ""
    for _ in 0..<randomCount {
        let a1 = UInt16.random(in: 0..<0xFFFF)
        let a2 = UInt16.random(in: 0..<0xFFFF)
        result.append(generateMulDivAll(for: command, a1: a1, a2: a2))
    }
    for i in 0..<specialValue.count * 2 {
        let a1 = specialValue[i / 2]
        let a2 = specialValue[i % 2]

        result.append(generateMulDivAll(for: command, a1: a1, a2: a2))
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

//for command in mathCommands {
//    result.append("\"\(command)_flag_of\": \"\"\"\n")
//    result.append("\(makeMove(target: "SI", value: "SP"))\n")
//    result.append("\(makeMove(target: "BP", value: "0000"))\n")
//    result.append(generate(for: command, randomCount: 10))
//    result.append("int 20\n")
//    result.append("\"\"\",\n")
//}
//for command in oneOperandCommands {
//    result.append("\"\(command)_flag_off\": \"\"\"\n")
//    result.append("\(makeMove(target: "SI", value: "SP"))\n")
//    result.append("\(makeMove(target: "BP", value: "0000"))\n")
//    result.append(generate(for: command, randomCount: 10))
//    result.append("int 20\n")
//    result.append("\"\"\",\n")
//}
//for command in mathCommands {
//    result.append("\"\(command)_flag_on\": \"\"\"\n")
//    result.append("\(makeMove(target: "SI", value: "SP"))\n")
//    result.append("\(makeMove(target: "BP", value: "FFFF"))\n")
//    result.append(generate(for: command, randomCount: 10))
//    result.append("int 20\n")
//    result.append("\"\"\",\n")
//}
//for command in oneOperandCommands {
//    result.append("\"\(command)_flag_on\": \"\"\"\n")
//    result.append("\(makeMove(target: "SI", value: "SP"))\n")
//    result.append("\(makeMove(target: "BP", value: "FFFF"))\n")
//    result.append(generate(for: command, randomCount: 10))
//    result.append("int 20\n")
//    result.append("\"\"\",\n")
//}


for command in mathMulDivCommands {
    result.append("\"\(command)_flag\": \"\"\"\n")
    result.append("\(makeMove(target: "SI", value: "SP"))\n")
    result.append("\(makeMove(target: "BP", value: "0000"))\n")
    result.append(generateMul(for: command, randomCount: 10))
    result.append("int 20\n")
    result.append("\"\"\",\n")
}
result = result.lowercased()

print(result)

print("\n")
