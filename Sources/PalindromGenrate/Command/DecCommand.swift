fileprivate let decCommand = Command(
    code: 0x0048,
    name: "Dec",
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
            "reg_%reg_%dataSizeu -= 1;",
            "LazyFlagResultContainer%dataSize = reg_%reg_%dataSizeu;",
            "lazyFlagType = t_DEC%dataSize;"
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendDecCommand(generator: Generator) {
    generator.addCommand(decCommand)
}
