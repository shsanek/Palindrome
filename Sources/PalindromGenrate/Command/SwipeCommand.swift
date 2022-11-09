fileprivate let XCHGCommand = Command(
    code: 0x0090,
    name: "XCHG",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [
            .init(name: "reg", indexBit: 0, count: 3)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .vars,
            .settings([.bigData, .bigAddress]),
            .formatter(
                BaseFormat { info in
                    if info.variation == 0x0090 {
                        return "// NOP"
                    } else {
                        return """
                        uint%addressSize_t tmp = reg_AX_%addressSizeu;
                        reg_AX_%addressSizeu = reg_%reg_%addressSizeu;
                        reg_%reg_%addressSizeu = tmp;
                        """
                    }
                }
            )
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let XCHGMrmCommand = Command(
    code: 0x0086,
    name: "XCHG",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [
            .init(name: "w", indexBit: 0, count: 1)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .mrm,
            .settings([.changeableData, .bigAddress]),
            """
            uint%addressSize_t tmp = *(uint%addressSize_t*)target;
            *(uint%addressSize_t*)target = *(uint%addressSize_t*)source;
            *(uint%addressSize_t*)source = tmp;
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let BSWAPCommand = Command(
    code: 0x01C8,
    name: "Swap",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: [
            .init(name: "reg", indexBit: 0, count: 3)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .vars,
            .settings([.fixData(32), .bigAddress]),
            """
            uint32_t value = reg_%reg_32u;
            uint8_t b1 = value & 0x000000FF;
            uint8_t b2 = value >> 8 & 0x000000FF;
            uint8_t b3 = value >> 16 & 0x000000FF;
            uint8_t b4 = value >> 24 & 0x000000FF;
            value = 0;
            value |= (((uint32_t)b1) << 24) & 0xFF000000;
            value |= (((uint32_t)b3) << 16) & 0x00FF0000;
            value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
            value |= ((uint32_t)b4)      & 0x000000FF;
            """
        ]
    ),
    installFormatter: InitialFormatter()
)


func appendSwipeCommand(generator: Generator) {
    generator.addCommand(XCHGCommand)
    generator.addCommand(XCHGMrmCommand)
    generator.addCommand(BSWAPCommand)
}
