import Foundation


fileprivate let twoOperandAdressMemoryMrmFormatters: [Int: String] = [
    0: "*register16(%fR) + *register16(%lR)",
    1: "*register16(%fR) + *register16(%lR) + ((int16_t)read8())",
    2: "*register16(%fR) + *register16(%lR) + read16()"
]

fileprivate let operand16AdressMemoryMrm1Formatters: [Int: String] = [
    0: "*register16(%fR)",
    1: "*register16(%fR) + ((int16_t)read8())",
    2: "*register16(%fR) + read16()"
]

fileprivate let operand16AdressMemoryMrm2Formatters: [Int: String] = [
    0: "read16()",
    1: "*register16(%fR) + ((int16_t)read8())",
    2: "*register16(%fR) + read16()"
]


fileprivate let operand32AdressMemoryMrm1Formatters: [Int: String] = [
    0: "*register32(%fR)",
    1: "*register32(%fR) + ((int16_t)read8())",
    2: "*register32(%fR) + read32()"
]

fileprivate let operand32AdressMemoryMrm2Formatters: [Int: String] = [
    0: "read32()",
    1: "*register32(%fR) + ((int16_t)read8())",
    2: "*register32(%fR) + read32()"
]

fileprivate let operand32AdressMemorySIB1Formatters: [Int: String] = [
    0: "*register32(%fR) + shift",
    1: "*register32(%fR) + shift + ((int16_t)read8())",
    2: "*register32(%fR) + shift + read32()"
]

fileprivate let operand32AdressMemorySIB2Formatters: [Int: String] = [
    0: "read32() + shift",
    1: "*register32(%fR) + shift + ((int16_t)read8())",
    2: "*register32(%fR) + shift + read32()"
]

fileprivate func generateSwitchFunction(
    name: String,
    prefix: String,
    suffix: String,
    defaultText: String,
    values: [Int],
    info: FormatterInfo,
    functions: (_ value: Int) -> String
) -> String {
    let generator = FunctionGenerator()
    generator.add("switch (\(name)) {")
    for value in values {
        generator.add("case \(value): {")
        generator.add("\(prefix)\(functions(value));\(suffix)")
        generator.add("}\nbreak;")
    }
    generator.add("default:")
    generator.add("\(defaultText)")
    generator.add("}")
    return generator.text
}

fileprivate func mrmSwitchFunction(
    base: String,
    base0: String? = nil,
    address: [Int: String],
    info: FormatterInfo,
    useBase: Bool,
    fR: String,
    lR: String = ""
) -> String {
    let functions = { (value: Int) -> String in
        let log = useBase ? "DATA_LOG%size((uint64_t)memory, memory);" : ""
        switch value {
        case 0:
            return """
            int32_t address = \(address[0]!);
            uint8_t* memory = \(useBase ? (base0 ?? base) : "") \(useBase ? "+" : "") address;
            \(log)
            return memory;
            """
        case 1:
            return """
            int32_t address = \(address[1]!);
            uint8_t* memory = \(useBase ? (base) : "") \(useBase ? "+" : "") address;
            \(log)
            return memory;
            """
        case 2:
            return """
            int32_t address = \(address[2]!);
            uint8_t* memory = \(useBase ? (base) : "") \(useBase ? "+" : "") address;
            \(log)
            return memory;
            """
        default:
            return ""
        }
    }
    return generateSwitchFunction(
        name: "mod",
        prefix: "",
        suffix: "",
        defaultText: "return 0;",
        values: [0, 1, 2],
        info: info,
        functions: functions
    )
    .replacingOccurrences(of: "%fR", with: fR)
    .replacingOccurrences(of: "%lR", with: lR)
}

fileprivate func sibSwitchFunction(
    info: FormatterInfo,
    useBase: Bool
) -> String {
    let head = """
    uint8_t sibByte = read8u();
    uint8_t scaleByte = readFirst2Bit(sibByte);
    uint8_t indexByte = readMiddle3Bit(sibByte);
    uint8_t baseByte = readLast3Bit(sibByte);
    int32_t shift = 0;
    LOG("SIB(b: %d, i: %d, s: %d)", baseByte, indexByte, scaleByte);
    """
    let scale = generateSwitchFunction(
        name: "scaleByte",
        prefix: "shift = *register32(indexByte) * ",
        suffix: "",
        defaultText: "shift = 0;",
        values: [0, 1, 2, 3],
        info: info,
        functions: {
            "\(Int(pow(Double(2), Double($0))))"
        }
    )
    let scaleWithIndex = generateSwitchFunction(
        name: "indexByte",
        prefix: "",
        suffix: "",
        defaultText: "{\n\(scale)\n} break;",
        values: [4],
        info: info
    ) { value in
        return "shift = 0;"
    }

    let generate = FunctionGenerator()

    generate.add(head)
    generate.add(scaleWithIndex)

    let function1 = { (reg1: String, reg2: String) -> String in
        let `switch` = mrmSwitchFunction(
            base: "GET_SEGMENT_POINTER_WITH_REPLACE(\(reg1))",
            address: operand32AdressMemorySIB1Formatters,
            info: info,
            useBase: useBase,
            fR: "\(reg2)"
        )
        return """
        \(`switch`)
        """
    }

    let function2 = { () -> String in
        let `switch` = mrmSwitchFunction(
            base: "GET_SEGMENT_POINTER_WITH_REPLACE(SR_SS)",
            base0: "GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS)",
            address: operand32AdressMemorySIB2Formatters,
            info: info,
            useBase: useBase,
            fR: "BR_EBP_F"
        )
        return """
        \(`switch`)
        """
    }

    let mainSwitch = generateSwitchFunction(
        name: "baseByte",
        prefix: "",
        suffix: "",
        defaultText: "return 0;",
        values: [0, 1, 2, 3, 4, 5, 6, 7],
        info: info) { value in
            switch value {
            case 0:
                return function1("SR_DS", "BR_EAX_F")
            case 1:
                return function1("SR_DS", "BR_ECX_F")
            case 2:
                return function1("SR_DS", "BR_EDX_F")
            case 3:
                return function1("SR_DS", "BR_EBX_F")
            case 4:
                return function1("SR_SS", "BR_ESP_F")
            case 5:
                return function2()
            case 6:
                return function1("SR_DS", "BR_ESI_F")
            case 7:
                return function1("SR_DS", "BR_EDI_F")
            default:
                return """
                return NULL;
                """
            }
        }
    generate.add(mainSwitch)
    return generate.text
}

fileprivate func mrmHeadForFunction(
    for size: Int,
    useBase: Bool
) -> String {
    return """
    uint8_t mod = readFirst2Bit(mrmByte);
    uint8_t base = readLast3Bit(mrmByte);\n
    """ + (useBase ? """
    if (mod == 3) {
    return (uint8_t*)register\(size)(base);
    }
    LOG("MRM(m: %d, b: %d)", mod, base);
    """ : """
    if (mod == 3) {
    return 0;
    }
    LOG("MRM(m: %d, b: %d)", mod, base);
    """)
}

fileprivate func mrm32SwitchFunction(
    info: FormatterInfo,
    for size: Int,
    useBase: Bool
) -> String {

    let generate = FunctionGenerator()

    generate.add(mrmHeadForFunction(for: size, useBase: useBase))

    let function1 = { (reg1: String, reg2: String?, reg3: String) -> String in
        let `switch` = mrmSwitchFunction(
            base: "GET_SEGMENT_POINTER_WITH_REPLACE(\(reg1))",
            base0: "GET_SEGMENT_POINTER_WITH_REPLACE(\(reg2 ?? reg1))",
            address: operand32AdressMemoryMrm1Formatters,
            info: info,
            useBase: useBase,
            fR: "\(reg3)"
        )
        return """
        \(`switch`)
        """
    }

    let function2 = { (reg1: String, reg2: String?, reg3: String) -> String in
        let `switch` = mrmSwitchFunction(
            base: "GET_SEGMENT_POINTER_WITH_REPLACE(\(reg1))",
            base0: "GET_SEGMENT_POINTER_WITH_REPLACE(\(reg2 ?? reg1))",
            address: operand32AdressMemoryMrm2Formatters,
            info: info,
            useBase: useBase,
            fR: "\(reg3)"
        )
        return """
        \(`switch`)
        """
    }

    let mainSwitch = generateSwitchFunction(
        name: "base",
        prefix: "",
        suffix: "",
        defaultText: "return 0;",
        values: [0, 1, 2, 3, 4, 5, 6, 7],
        info: info) { value in
            switch value {
            case 0:
                return function1("SR_DS", "SR_DS", "BR_EAX_F")
            case 1:
                return function1("SR_DS", "SR_DS", "BR_ECX_F")
            case 2:
                return function1("SR_DS", "SR_DS", "BR_EDX_F")
            case 3:
                return function1("SR_DS", "SR_DS", "BR_EBX_F")
            case 4:
                return sibSwitchFunction(info: info, useBase: useBase)
            case 5:
                return function2("SR_SS", "SR_DS", "BR_EBP_F")
            case 6:
                return function1("SR_DS", "SR_DS", "BR_ESI_F")
            case 7:
                return function1("SR_DS", "SR_DS", "BR_EDI_F")
            default:
                return """
                return NULL;
                """
            }
        }
    generate.add(mainSwitch)
    return generate.text
}

fileprivate func mrm16SwitchFunction(
    info: FormatterInfo,
    for size: Int,
    useBase: Bool
) -> String {
    let generate = FunctionGenerator()

    generate.add(mrmHeadForFunction(for: size, useBase: useBase))

    let function1 = { (reg1: String, reg2: String, reg3: String) -> String in
        let `switch` = mrmSwitchFunction(
            base: "GET_SEGMENT_POINTER_WITH_REPLACE(\(reg1))",
            address: twoOperandAdressMemoryMrmFormatters,
            info: info,
            useBase: useBase,
            fR: "\(reg2)",
            lR: "\(reg3)"
        )
        return """
        \(`switch`)
        """
    }

    let function2 = { (reg1: String, reg2: String?, reg3: String) -> String in
        let `switch` = mrmSwitchFunction(
            base: "GET_SEGMENT_POINTER_WITH_REPLACE(\(reg1))",
            base0: "GET_SEGMENT_POINTER_WITH_REPLACE(\(reg2 ?? reg1))",
            address: operand16AdressMemoryMrm1Formatters,
            info: info,
            useBase: useBase,
            fR: "\(reg3)"
        )
        return """
        \(`switch`)
        """
    }

    let function3 = { (reg1: String, reg2: String?, reg3: String) -> String in
        let `switch` = mrmSwitchFunction(
            base: "GET_SEGMENT_POINTER_WITH_REPLACE(\(reg1))",
            base0: "GET_SEGMENT_POINTER_WITH_REPLACE(\(reg2 ?? reg1))",
            address: operand16AdressMemoryMrm2Formatters,
            info: info,
            useBase: useBase,
            fR: "\(reg3)"
        )
        return """
        \(`switch`)
        """
    }

    let mainSwitch = generateSwitchFunction(
        name: "base",
        prefix: "",
        suffix: "",
        defaultText: "return 0;",
        values: [0, 1, 2, 3, 4, 5, 6, 7],
        info: info) { value in
            switch value {
            case 0:
                return function1("SR_DS", "BR_BX", "BR_SI")
            case 1:
                return function1("SR_DS", "BR_BX", "BR_DI")
            case 2:
                return function1("SR_SS", "BR_BP", "BR_SI")
            case 3:
                return function1("SR_SS", "BR_BP", "BR_SI")
            case 4:
                return function2("SR_DS", "SR_DS", "BR_SI")
            case 5:
                return function2("SR_DS", "SR_DS", "BR_DI")
            case 6:
                return function3("SR_SS", "SR_DS", "BR_BP")
            case 7:
                return function2("SR_DS", "SR_DS", "BR_BX")
            default:
                return """
                return NULL;
                """
            }
        }
    generate.add(mainSwitch)
    return generate.text
}

fileprivate func generateFunction(mod: Int, size: Int, info: FormatterInfo, useBase: Bool) -> String  {
    let generate = FunctionGenerator()
    if useBase {
        generate.add("uint8_t* readAddressMRM\(mod)For\(size)(uint8_t mrmByte) {")
    } else {
        generate.add("int\(mod)_t effectiveAddressMRM\(mod)For\(size)(uint8_t mrmByte) {")
    }
    if mod == 32 {
        generate.add(mrm32SwitchFunction(info: info, for: size, useBase: useBase))
    } else {
        generate.add(mrm16SwitchFunction(info: info, for: size, useBase: useBase))
    }
    generate.add("}")
    return generate.text.replacingOccurrences(of: "%size", with: "\(size)")
}

func generateMRMFunction(info: FormatterInfo?) -> String {
    let info = info ?? .init(command: .init(code: 0, name: "", format: .init(hasPrefixAddress: false, hasPrefixData: false, inlines: []), functionFormatter: TemplateFormat(""), installFormatter: TemplateFormat("")), flags: Set<String>(), mode: .mod16, variation: 0, vars: [], prefixs: [])
    let generate = FunctionGenerator()

    generate.add("#include \"MRM.h\"")
    generate.add(generateFunction(mod: 32, size: 32, info: info, useBase: true))
    generate.add("\n")
    generate.add(generateFunction(mod: 32, size: 16, info: info, useBase: true))
    generate.add("\n")
    generate.add(generateFunction(mod: 32, size: 8, info: info, useBase: true))
    generate.add("\n")

    generate.add(generateFunction(mod: 32, size: 32, info: info, useBase: false))
    generate.add("\n")
    generate.add(generateFunction(mod: 16, size: 16, info: info, useBase: false))
    generate.add("\n")

    generate.add(generateFunction(mod: 16, size: 32, info: info, useBase: true))
    generate.add("\n")
    generate.add(generateFunction(mod: 16, size: 16, info: info, useBase: true))
    generate.add("\n")
    generate.add(generateFunction(mod: 16, size: 8, info: info, useBase: true))

    return generate.text
}
