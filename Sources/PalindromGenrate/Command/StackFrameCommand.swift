fileprivate let leaveCommand = Command(
    code: 0x00C9,
    name: "Leave",
    format: .init(
        hasPrefixAddress: true,
        hasPrefixData: true,
        inlines: [
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixAddress,
            .prefixData,
            .functionName,
            .settings([.bigData, .bigAddress]),
            """
            reg_SP_%addressSizeu = reg_BP_%addressSizeu;
            reg_BP_%addressSizeu = *(uint%dataSize_t*)(GET_SEGMENT_POINTER(SR_SS) + reg_SP_%addressSizeu);
            reg_SP_%addressSizeu += %dataSize / 8;
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let enterCommand = Command(
    code: 0x00C8,
    name: "Enter",
    format: .init(
        hasPrefixAddress: true,
        hasPrefixData: true,
        inlines: [
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixAddress,
            .prefixData,
            .functionName,
            .settings([.bigData, .bigAddress]),
            """
            uint16_t size = read16u();
            uint8_t levels = read8u() % 32;
            """,
            .template(pushValue("reg_BP_%addressSizeu", size: "%addressSize")),
            "uint%addressSize_t tmp = reg_SP_%addressSizeu;",
            "if (levels > 0) {",
            "for (int i = 1; i < levels; ++i) {",
            "reg_BP_%addressSizeu = reg_BP_%addressSizeu - %dataSize / 8;",
            .template(pushValue("reg_BP_%addressSizeu", size: "%addressSize")),
            "}",
            "",
            .template(pushValue("reg_SP_%addressSizeu", size: "%addressSize")),
            "}",
            "reg_BP_%addressSizeu = tmp;",
            "reg_SP_%addressSizeu = reg_BP_%addressSizeu - size;"
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendFrameStackCommand(generator: Generator) {
    generator.addCommand(enterCommand)
    generator.addCommand(leaveCommand)
}
