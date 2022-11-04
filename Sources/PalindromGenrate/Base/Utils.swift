import Foundation

//struct MachineCommand {
//    let name: String
//    let command: CommandIdentifier
//    let format: CommandFormat
//    let functionFormat: String
//    var functionPrepareFormat: String? = nil
//}
//
//struct CommandIdentifier: Equatable {
//    let base: UInt16
//}
//
//enum FunctionType {
//    case mrm
//    case custom
//    case mnm(code: UInt8)
//
//    var nnn: Int16 {
//        switch self {
//        case .mrm:
//            return -1
//        case .custom:
//            return -1
//        case .mnm(let code):
//            return Int16(code)
//        }
//    }
//}
//
//struct InlineElementFormat {
//    let name: String
//    // with last
//    let indexBit: Int
//    let count: Int
//
//    let recoverable: Bool
//
//    func getByte(_ byte: UInt8) -> UInt8 {
//        var mask: UInt8 = 1
//        for _ in 0..<count {
//            mask *= 2
//        }
//        return (byte >> indexBit) & (mask - 1)
//    }
//}
//
//struct ArgumentFormat {
//    let name: String
//    let type: ArgumentType
//    let size: ArgumentSize
//
//    enum ArgumentType {
//        case address
//        case data
//    }
//
//    enum ArgumentSize {
//        case minMax(min: Int, big: Int)
//        case fixed(fixed16: Int, fixed32: Int)
//        case changeable
//    }
//}
//
//struct CommandFormat {
//    let functioinType: FunctionType
//    let inlineElements: [InlineElementFormat]
//    let arguments: [ArgumentFormat]
//    var fixedSize: Generator.Size? = nil
//}
//
//extension MachineCommand {
//    var allVariation: [UInt16] {
//        let bitCount = format.inlineElements.reduce(0, { $0 + $1.count })
//        let variationCount = powf(Float(2), Float(bitCount))
//        let baseBits = command.base.bits
//
//        var result: [UInt16] = []
//
//        for i in 0..<UInt8(variationCount) {
//            var current = baseBits
//            var index = 0
//            for inline in format.inlineElements {
//                for j in 0..<inline.count {
//                    current[15 - inline.indexBit - j] = i.bits[7 - index]
//                    index += 1
//                }
//            }
//            result.append(.init(bits: current))
//        }
//        return result.sorted()
//    }
//}
//
//
//final class Generator {
//    private var commands: [MachineCommand] = []
//
//    enum Size {
//        case big
//        case small
//        case not
//    }
//
//    enum Direction  {
//        case normal
//        case invert
//        case not
//    }
//
//    func machineCommand(_ command: MachineCommand) {
//        commands.append(command)
//    }
//
//    func generateAllCommand() -> String {
//        var result = "#include \"GenerateFunctions.h\"\n"
//        result.append("// 32 bits\n")
//        for command in commands {
//            let variations = command.allVariation
//            for variation in variations {
//                result.append(generateCFunction(for: command, with: UInt8(bits: variation.bits), isMod32: true))
//                result.append("\n")
//            }
//        }
//        result.append("// 16 bits\n")
//        for command in commands {
//            let variations = command.allVariation
//            for variation in variations {
//                result.append(generateCFunction(for: command, with: UInt8(bits: variation.bits), isMod32: false))
//                result.append("\n")
//            }
//        }
//        result.append("\n\n//install\n\n\(installGenerate())")
//        return result
//    }
//
//    private func functionName(for command: MachineCommand, with rootByte: UInt8, isMod32: Bool) -> String {
//        return "handlerCommand\(isMod32 ? "32" : "16")\(command.format.functioinType.nnn == -1 ? command.name : "NNN")\(rootByte)"
//    }
//
//    func generateCFunction(for command: MachineCommand, with rootByte: UInt8, isMod32: Bool) -> String {
//        let generator = FunctionGenerator()
//        let size = wordInline(for: command, with: rootByte)
//        let direction = directionInline(for: command, with: rootByte)
//        let sign = signInline(for: command, with: rootByte)
//
//        generator.add("void \(functionName(for: command, with: rootByte, isMod32: isMod32))(Context *context) {")
//
//        switch command.format.functioinType {
//        case .mnm:
//            let commands = commands
//                .filter { $0.command == command.command }
//                .sorted(by: { $0.format.functioinType.nnn <  $1.format.functioinType.nnn })
//            guard !commands.isEmpty, command.format.functioinType.nnn == commands.first?.format.functioinType.nnn else {
//                return ""
//            }
//            generateNNNFunction(
//                for: commands,
//                with: rootByte,
//                isMod32: isMod32,
//                generator: generator,
//                size: size,
//                sign: sign,
//                direction: direction
//            )
//        case .mrm:
//            generateMRMFunction(
//                for: command,
//                with: rootByte,
//                isMod32: isMod32,
//                generator: generator,
//                size: size,
//                sign: sign,
//                direction: direction
//            )
//        case .custom:
//            generateCustomFunction(
//                for: command,
//                with: rootByte,
//                isMod32: isMod32,
//                generator: generator,
//                size: size,
//                sign: sign,
//                direction: direction
//            )
//        }
//
//
//        generator.add("}")
//        return generator.text
//    }
//
//    private func generateCustomFunction(
//        for command: MachineCommand,
//        with rootByte: UInt8,
//        isMod32: Bool,
//        generator: FunctionGenerator,
//        size: Size,
//        sign: Bool,
//        direction: Direction
//    ) {
//        var isInject = false
//        isInject = isInject || injectData(
//            generator: generator,
//            command: command,
//            byte: rootByte,
//            isMod32: isMod32
//        ) { dataSize, dataType in
//            if !injectAddress(
//                generator: generator,
//                command: command,
//                byte: rootByte,
//                isMod32: isMod32,
//                block: { addSize in
//                    generateFunction(
//                        generator: generator,
//                        command: command,
//                        byte: rootByte,
//                        dataType: dataType,
//                        addressSize: addSize,
//                        dataSize: dataSize
//                    )
//                })
//            {
//                generateFunction(
//                    generator: generator,
//                    command: command,
//                    byte: rootByte,
//                    dataType: dataType,
//                    dataSize: dataSize
//                )
//            }
//        }
//        if !isInject {
//            isInject = isInject || injectAddress(
//                generator: generator,
//                command: command,
//                byte: rootByte,
//                isMod32: isMod32
//            ) { addSize in
//                generateFunction(generator: generator, command: command, byte: rootByte,  addressSize: addSize)
//            }
//        }
//        guard !isInject else {
//            return
//        }
//        generateFunction(generator: generator, command: command, byte: rootByte)
//    }
//
//    private func generateMRMFunction(
//        for command: MachineCommand,
//        with rootByte: UInt8,
//        isMod32: Bool,
//        generator: FunctionGenerator,
//        size: Size,
//        sign: Bool,
//        direction: Direction
//    ) {
//        generator.add("uint8_t mrmByte = read8u(context);")
//        if isMod32 && size == .big {
//            generator.add("if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {")
//            generateMRMFunction(
//                generator: generator,
//                command: command,
//                byte: rootByte,
//                size: "16",
//                sign: sign,
//                direction: direction,
//                isMod32: isMod32,
//                functionFormat: command.functionFormat
//            )
//            generator.add("} else {")
//            generateMRMFunction(
//                generator: generator,
//                command: command,
//                byte: rootByte,
//                size: "32",
//                sign: sign,
//                direction: direction,
//                isMod32: isMod32,
//                functionFormat: command.functionFormat
//            )
//            generator.add("}")
//        } else {
//            generateMRMFunction(
//                generator: generator,
//                command: command,
//                byte: rootByte,
//                size: size == .big ? "16" : "8",
//                sign: sign,
//                direction: direction,
//                isMod32: isMod32,
//                functionFormat: command.functionFormat
//            )
//        }
//    }
//
//    private func generateNNNFunction(
//        for commands: [MachineCommand],
//        with rootByte: UInt8,
//        isMod32: Bool,
//        generator: FunctionGenerator,
//        size: Size,
//        sign: Bool,
//        direction: Direction
//    ) {
//        generator.add("uint8_t mrmByte = read8u(context);")
//        generator.add("uint8_t nnn = readMiddle3Bit(mrmByte);")
//        if isMod32 && size == .big {
//            generator.add("if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {")
//            generateNNNFunction(
//                generator: generator,
//                commands: commands,
//                byte: rootByte,
//                size: "16",
//                sign: sign,
//                direction: direction,
//                isMod32: isMod32
//            )
//            generator.add("} else {")
//            generateNNNFunction(
//                generator: generator,
//                commands: commands,
//                byte: rootByte,
//                size: "32",
//                sign: sign,
//                direction: direction,
//                isMod32: isMod32
//            )
//            generator.add("}")
//        } else {
//            generateNNNFunction(
//                generator: generator,
//                commands: commands,
//                byte: rootByte,
//                size: size == .big ? "16" : "8",
//                sign: sign,
//                direction: direction,
//                isMod32: isMod32
//            )
//        }
//    }
//
//    private func generateMRMFunction(
//        generator: FunctionGenerator,
//        command: MachineCommand,
//        byte: UInt8,
//        size: String,
//        sign: Bool,
//        direction: Direction,
//        isMod32: Bool,
//        functionFormat: String
//    ) {
//        let type = "\(sign ? "" : "u")int\(size)_t"
//        let registerFunction = "(\(type)*)readRegisterMRM\(size)(context, mrmByte);"
//        let addressFunction = "(\(type)*)readAddressMRM\(isMod32 ? "32" : "16")(context, mrmByte);"
//        let prepare = """
//        \(type)* target = \(addressFunction);
//        \(type)* source = \(registerFunction);
//        """
//
//        generateFunction(
//            generator: generator,
//            command: command,
//            byte: byte,
//            prepare: prepare,
//            sType: sign ? "" : "u",
//            dataType: type,
//            dataSize: size
//        )
//    }
//
//    private func generateNNNFunction(
//        generator: FunctionGenerator,
//        commands: [MachineCommand],
//        byte: UInt8,
//        size: String,
//        sign: Bool,
//        direction: Direction,
//        isMod32: Bool
//    ) {
//        let type = "\(sign ? "" : "u")int\(size)_t"
//        let nnnFunction = "readMiddle3Bit(mrmByte)"
//        let addressFunction = "(\(type)*)readAddressMRM\(isMod32 ? "32" : "16")(context, mrmByte)"
//        let prepare = """
//        \(type)* target = \(addressFunction);
//        """
//
//        generateFunction(
//            generator: generator,
//            command: commands[0],
//            byte: byte,
//            prepare: prepare,
//            sType: sign ? "" : "u",
//            dataType: type,
//            dataSize: size,
//            part: .prepare
//        )
//
//        var isNotFirst = false
//        for command in commands {
//            if case .mnm(let code) = command.format.functioinType {
//                let prefix = isNotFirst ? "} else " : ""
//                generator.add(prefix + "if (nnn == \(code)) {")
//                generateFunction(
//                    generator: generator,
//                    command: command,
//                    byte: byte,
//                    prepare: prepare,
//                    sType: sign ? "" : "u",
//                    dataType: type,
//                    dataSize: size,
//                    part: .function
//                )
//                isNotFirst = true
//            } else {
//                fatalError("что то пошло не так")
//            }
//        }
//        if isNotFirst {
//            generator.add("}")
//        }
//    }
//
//    private func injectData(
//        generator: FunctionGenerator,
//        command: MachineCommand,
//        byte: UInt8,
//        isMod32: Bool,
//        block: (_ dataSize: String, _ dataType: String) -> Void
//    ) -> Bool {
//        let datas = command.format.arguments.filter({ $0.type == .data })
//        guard datas.count > 0 else {
//            return false
//        }
//        let size = wordInline(for: command, with: byte)
//        let sign = signInline(for: command, with: byte)
//
//        if case .changeable = datas[0].size {
//            if isMod32 && (size == .big || size == .not) {
//                generator.add("if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {")
//                block("16", getType("16", sign: sign))
//                generator.add("} else {")
//                block("32", getType("32", sign: sign))
//                generator.add("}")
//            } else {
//                let size = size == .big ? "16" : "8"
//                block(size, getType(size, sign: sign))
//            }
//        } else if case .fixed(let fixed16, let fixed32) = datas[0].size {
//            let fixed = isMod32 ? fixed32 : fixed16
//            block("\(fixed)", getType("\(fixed)", sign: sign))
//        } else if case .minMax(let min, let max) = datas[0].size {
//            if isMod32 {
//                generator.add("if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {")
//                block("\(min)", getType("\(min)", sign: sign))
//                generator.add("} else {")
//                block("\(max)", getType("\(max)", sign: sign))
//                generator.add("}")
//            } else {
//                block("\(min)", getType("\(min)", sign: sign))
//            }
//        }
//        return true
//    }
//
//    private func injectAddress(
//        generator: FunctionGenerator,
//        command: MachineCommand,
//        byte: UInt8,
//        isMod32: Bool,
//        block: (_ addSize: String) -> Void
//    ) -> Bool {
//        let datas = command.format.arguments.filter({ $0.type == .address })
//        guard datas.count > 0 else {
//            return false
//        }
//        if case .changeable = datas[0].size {
//            if isMod32 {
//                generator.add("if (context->lastCommandInfo.prefixInfo.addressSizePrefix) {")
//                block("16")
//                generator.add("} else {")
//                block("32")
//                generator.add("}")
//            } else {
//                block("8")
//            }
//        } else if case .fixed(let fixed16, let fixed32) = datas[0].size {
//            let fixed = isMod32 ? fixed32 : fixed16
//            block("\(fixed)")
//        } else if case .minMax(let min, let max) = datas[0].size {
//            if isMod32 {
//                generator.add("if (context->lastCommandInfo.prefixInfo.addressSizePrefix) {")
//                block("\(min)")
//                generator.add("} else {")
//                block("\(max)")
//                generator.add("}")
//            } else {
//                block("\(min)")
//            }
//        }
//        return true
//    }
//
//    private func installGenerate() -> String {
//        let base = """
//        void mCommandFunctionEmpty(Context* context) {
//        printf("function not implementation\\n");
//        }
//
//        void installCommandFunction() {
//        for(int i = 0; i < 512; i++) {
//        commandFunctions16[i] = mCommandFunctionEmpty;
//        commandFunctions32[i] = mCommandFunctionEmpty;
//        }
//        """
//        let generator = FunctionGenerator()
//        generator.add(base)
//        for command in commands {
//            let variations = command.allVariation
//            for variation in variations {
//                generator.add(
//                    "commandFunctions16[\(variation)] = \(functionName(for: command, with: UInt8(bits: variation.bits), isMod32: false));"
//                )
//                generator.add(
//                    "commandFunctions32[\(variation)] = \(functionName(for: command, with: UInt8(bits: variation.bits), isMod32: true));"
//                )
//            }
//        }
//        generator.add("}")
//
//        return generator.text
//    }
//
//    enum GeneratePart {
//        case prepare
//        case function
//        case all
//    }
//
//    private func generateFunction(
//        generator: FunctionGenerator,
//        command: MachineCommand,
//        byte: UInt8,
//        prepare: String? = nil,
//        sType: String = "",
//        dataType: String = "none",
//        addressSize: String = "none",
//        dataSize: String = "none",
//        part: GeneratePart = .all
//    ) {
//        let functionGenerator = FunctionGenerator()
//        for inline in command.format.inlineElements {
//            if inline.recoverable {
//                functionGenerator.add("uint8_t \(inline.name) = \(inline.getByte(byte).hex.uppercased());")
//            }
//        }
//        let function = command.functionFormat
//            .replacingOccurrences(of: "%dataType", with: dataType)
//            .replacingOccurrences(of: "%addressSize", with: addressSize)
//            .replacingOccurrences(of: "%dataSize", with: dataSize)
//            .replacingOccurrences(of: "%sType", with: sType)
//        let direction = directionInline(for: command, with: byte)
//        if let prepare = prepare {
//            functionGenerator.add(prepare)
//        }
//        if let prepare = command.functionPrepareFormat {
//            let prepare = prepare
//                .replacingOccurrences(of: "%dataType", with: dataType)
//                .replacingOccurrences(of: "%addressSize", with: addressSize)
//                .replacingOccurrences(of: "%dataSize", with: dataSize)
//                .replacingOccurrences(of: "%sType", with: sType)
//            functionGenerator.add(prepare)
//        }
//        if direction == .invert {
//            functionGenerator.swich(a: "target", b: "source")
//        }
//        if part == .all || part == .prepare {
//            generator.add(functionGenerator.text)
//        }
//        if part == .all || part == .function {
//            generator.add(function)
//        }
//    }
//
//    private func getType(_ size: String, sign: Bool) -> String {
//        let type = "\(sign ? "" : "u")int\(size)_t"
//        return type
//    }
//
//    private func signInline(for command: MachineCommand, with rootByte: UInt8) -> Bool {
//        guard let wordInfo = command.format.inlineElements.first(where: { $0.name == "s" }) else {
//            return false
//        }
//        return wordInfo.getByte(rootByte) != 0
//    }
//
//    private func wordInline(for command: MachineCommand, with rootByte: UInt8) -> Size {
//        guard let wordInfo = command.format.inlineElements.first(where: { $0.name == "w" }) else {
//            return command.format.fixedSize ?? .not
//        }
//        return wordInfo.getByte(rootByte) == 0 ? .small : .big
//    }
//
//    private func directionInline(for command: MachineCommand, with rootByte: UInt8) -> Direction {
//        guard let directionInfo = command.format.inlineElements.first(where: { $0.name == "d" }) else {
//            return .not
//        }
//        return directionInfo.getByte(rootByte) == 1 ? .invert : .normal
//    }
//}

extension UInt8 {
    var hex: String {
        String(format: "0x%02X", self)
    }

    public init(bits: [UInt8]) {
        var result: UInt8 = 0
        var m: UInt32 = 1
        let min = bits.count < 8 ? bits.count : 8
        for i in 0..<min {
            result += UInt8(bits[bits.count - 1 - i]) * UInt8(m)
            m *= 2
        }
        self = result
    }

    var bits: [UInt8] {
        var base = Array(repeating: UInt8(0), count: 8)
        var byte = self
        for i in 0..<8 {
            base[7 - i] = UInt8(byte % 2)
            byte = byte / 2
        }
        return base
    }
}

extension UInt16 {
    public init(bits: [UInt8]) {
        var result: UInt16 = 0
        var m: UInt32 = 1
        let min = bits.count < 16 ? bits.count : 16
        for i in 0..<min {
            result += UInt16(bits[bits.count - 1 - i]) * UInt16(m)
            m *= 2
        }
        self = result
    }

    var bits: [UInt8] {
        var base = Array(repeating: UInt8(0), count: 16)
        var byte = self
        for i in 0..<16 {
            base[15 - i] = UInt8(byte % 2)
            byte = byte / 2
        }
        return base
    }
}

final class FunctionGenerator {
    private(set) var text = ""
    private var tab: Int = 0

    func add(_ lines: String?) {
        guard let lines = lines else {
            return
        }
        for line in lines.split(separator: "\n") {
            let line = line.replacingOccurrences(of: "\t", with: "")
            if let separate = line.firstIndex(where: { $0 == "{" || $0 == "(" || $0 == "[" }) {
                tab -= line[line.startIndex..<separate].filter( { $0 == "}" || $0 == ")" || $0 == "]" }).count
            } else {
                tab -= line.filter( { $0 == "}" || $0 == ")" || $0 == "]" }).count
            }
            text += (0..<tab).map { _ in "\t" }.joined() + line + "\n"
            if let separate = line.lastIndex(where: { $0 == "}" || $0 == ")" || $0 == "]" }) {
                tab += line[separate..<line.endIndex].filter( { $0 == "{" || $0 == "(" || $0 == "[" }).count
            } else {
                tab += line.filter( { $0 == "{" || $0 == "(" || $0 == "[" }).count
            }

        }
    }

    func swich(a: String, b: String, tmp: String = "SYSTEM_REPLACE_STRING") {
        text = text.replacingOccurrences(of: a, with: tmp)
        text = text.replacingOccurrences(of: b, with: a)
        text = text.replacingOccurrences(of: tmp, with: b)
    }
}
