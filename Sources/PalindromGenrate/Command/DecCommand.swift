fileprivate let decCommand = Command(
    code: 0x0048,
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
        baseFormatter: TemplateFormat(template: "*register%dataSizeu(context, reg) -= 1;")
    ),
    installFormatter: InitialFormatter()
)

func appendDecCommand(generator: Generator) {
    generator.addCommand(decCommand)
}
