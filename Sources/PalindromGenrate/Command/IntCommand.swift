fileprivate let intCommand = Command(
    code: 0x00CD,
    name: "Int",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [.functionName],
        baseFormatter: TemplateFormat(
            template: """
            uint8_t addr = read8u(context);
            context->functions[addr](context, addr);
            """
        )
    ),
    installFormatter: InitialFormatter()
)

func appendIntCommand(generator: Generator) {
    generator.addCommand(intCommand)
}
