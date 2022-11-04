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
        customizers: [.functionName, .vars, .prefixBigData, .bigData],
        baseFormatter: TemplateFormat(template: "*register%dataSizeu(context, reg) += 1;")
    ),
    installFormatter: InitialFormatter()
)

func appendIncCommand(generator: Generator) {
    generator.addCommand(incCommand)
}
