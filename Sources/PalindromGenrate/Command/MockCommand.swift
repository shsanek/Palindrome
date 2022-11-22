extension Command {
    static func mock(code: UInt16, operandSize: UInt8, name: String) -> Command {
        Command(
            code: code,
            name: "name",
            format: .init(
                hasPrefixAddress: false,
                hasPrefixData: false,
                inlines: []
            ),
            functionFormatter: Formatter(
                customizers: [
                    .functionName,
                    .settings([.changeableData, .bigAddress]),
                    """
                    // MOCK
                    """
                ] + (operandSize > 0 ? (["uint8_t value = 0;"] + (0..<operandSize).map { _ in .formatter(TemplateFormat("value = read8u();")) }) : [])

            ),
            installFormatter: InitialFormatter()
        )
    }
}

func appendMockCommand(generator: Generator) {
}
