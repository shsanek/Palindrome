fileprivate let pop8FRegCommand = Command(
    code: 0x008F,
    name: "Pop",
    format: .init(
        hasPrefixAddress: true,
        hasPrefixData: true,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixAddress,
            .prefixData,
            .functionName,
            .settings([.bigData, .bigAddress]),
            .nnn([(code: "0x00", formatter: BaseFormat { _ in
            """
            // *target = *(uint%dataSize_t*)(mem(SR_SS) + reg_SP_%addressSizeu);
            // reg_SP_%addressSizeu += %dataSize / 8;
            """
            })])

        ]
    ),
    installFormatter: InitialFormatter()
)

func appendPop8fCommand(generator: Generator) {
    generator.addCommand(pop8FRegCommand)
}
