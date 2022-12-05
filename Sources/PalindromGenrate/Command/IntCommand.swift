fileprivate let intCommand = Command(
    code: 0x00CD,
    name: "Int",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .settings([.bigData, .bigAddress]),
            "uint8_t *target = GET_REAL_MOD_MEMORY_POINTER(0) + (read8u() * (2 + 2));",
            .template(pushValue("SR_VALUE(SR_CS)", size: "16")),
            .template(pushValue("((uint%addressSize_t)(context.index - GET_SEGMENT_POINTER(SR_CS)))", size: "%addressSize")),
            "SET_VALUE_IN_SEGMENT(SR_CS, (*((uint16_t*)(target + 2))));",
            "context.index = GET_SEGMENT_POINTER(SR_CS) + (*((uint16_t*)(target)));"
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let externalCallCommand = Command(
    code: 0x00F1,
    name: "External call",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            """
            uint8_t addr = read8u();
            FillFlags();
            context.functions[addr](addr);
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendIntCommand(generator: Generator) {
    generator.addCommand(externalCallCommand)
    generator.addCommand(intCommand)
}
