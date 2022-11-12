private let MULT = BaseFormat { info in
    if info.dataSize == 8 {
        return """
        int16_t tmp = (int16_t)source1 * (int16_t)source2;
        uint8_t value = source1 * source2;
        *((int8_t*)target) = value;
        SET_FLAG(ZF, value == 0);
        SET_FLAG(CF, value != tmp);
        SET_FLAG(OF, value != tmp);
        lazyFlagType = t_MUL;
        """
    } else if info.dataSize == 16 {
        return """
        int32_t tmp = (int32_t)source1 * (int32_t)source2;
        int16_t value = source1 * source2;
        *((int16_t*)target) = value;
        SET_FLAG(ZF, value == 0);
        SET_FLAG(CF, value != tmp);
        SET_FLAG(OF, value != tmp);
        lazyFlagType = t_MUL;
        """
    } else if info.dataSize == 32 {
        return """
        int64_t tmp = (int64_t)source1 * (int64_t)source2;
        int32_t value = source1 * source2;
        *((int32_t*)target) = value;
        SET_FLAG(ZF, value == 0);
        SET_FLAG(CF, value != tmp);
        SET_FLAG(OF, value != tmp);
        lazyFlagType = t_MUL;
        """
    }
    return ""
}


let multlCommand = Command(
    code: 0x01AF,
    name: "Mul",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([.bigData, .bigAddress]),
            .mrm,
            """
            int%dataSize_t source1 = *(int%dataSize_t*)source;
            int%dataSize_t source2 = *(int%dataSize_t*)target;
            target = source;
            """,
            .formatter(MULT)
        ]
    ),
    installFormatter: InitialFormatter()
)

let multlCommandBigData = Command(
    code: 0x0069,
    name: "Mul",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([.bigData, .bigAddress]),
            .mrm,
            """
            int%dataSize_t source1 = read%dataSize();
            int%dataSize_t source2 = *(int%dataSize_t*)target;
            target = source;
            """,
            .formatter(MULT)
        ]
    ),
    installFormatter: InitialFormatter()
)

let multlCommand8Data = Command(
    code: 0x006B,
    name: "Mul",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .settings([.bigData, .fixOperand(8), .bigAddress]),
            .mrm,
            """
            int%dataSize_t source1 = (int%dataSize_t)read%operandSize();
            int%dataSize_t source2 = *(int%dataSize_t*)target;
            target = source;
            """,
            .formatter(MULT)
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendMultCommand(generator: Generator) {
    generator.addCommand(multlCommand)
    generator.addCommand(multlCommandBigData)
    generator.addCommand(multlCommand8Data)
}
