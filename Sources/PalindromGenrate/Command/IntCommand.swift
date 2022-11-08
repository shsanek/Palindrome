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
            """
            uint8_t addr = read8u();
            context.functions[addr](addr);
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendIntCommand(generator: Generator) {
    generator.addCommand(intCommand)
}
