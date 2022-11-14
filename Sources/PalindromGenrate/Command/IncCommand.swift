fileprivate let incCommand = Command(
    code: 0x0040,
    name: "Inc",
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
            .settings([.bigData]),
            "reg_%reg_%dataSizeu += 1;",
            "LazyFlagResultContainer%dataSize = reg_%reg_%dataSizeu;",
            "lazyFlagType = t_INC%dataSize;"
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendIncCommand(generator: Generator) {
    generator.addCommand(incCommand)
}
