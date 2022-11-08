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
            .vars,
            .settings([.bigData]),
            "*register%dataSizeu(reg) += 1;"
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendIncCommand(generator: Generator) {
    generator.addCommand(incCommand)
}
