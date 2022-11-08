fileprivate let leaCommand = Command(
    code: 0x008D,
    name: "Lea",
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
            .mrm,
            """
            *((uint%dataSize_t*)source) = (uint%dataSize_t)(((uint64_t)(target - context.memory)) & %dataMask);
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendSpecialCommand(generator: Generator) {
    generator.addCommand(leaCommand)
}
