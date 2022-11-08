extension Command {
    static func generateF6Command(templates: [(String, String)]) -> Command {
        return Command(
            code: 0x00F6,
            name: "Math",
            format: .init(
                hasPrefixAddress: false,
                hasPrefixData: true,
                inlines: [
                    .init(name: "w", indexBit: 0, count: 1)
                ]
            ),
            functionFormatter: Formatter(
                customizers: [
                    .prefixData,
                    .functionName,
                    .settings([.changeableData, .bigAddress]),
                    .nnn(templates.map { (code: $0.0, formatter: TemplateFormat($0.1)) } )
                ]
            ),
            installFormatter: InitialFormatter()
        )
    }
}

func appendF6F7Command(generator: Generator) {
    let command = Command.generateF6Command(templates: [
        ("0x00", """
        // TEST
        LazyFlagVarA%dataSize = *(int%dataSize_t*)target;
        LazyFlagVarB%dataSize = read%operandSize();
        LazyFlagResultContainer%dataSize = LazyFlagVarA%dataSize & ((%signint%operandSize_t)LazyFlagVarB%dataSize);
        lazyFlagType = t_TEST%dataSize;
        """),
        ("0x03", """
        // NEG
        LazyFlagVarA%dataSize = *(int%dataSize_t*)target;
        LazyFlagResultContainer%dataSize = 0 - LazyFlagVarA%dataSize;
        *(int%dataSize_t*)target = LazyFlagResultContainer%dataSize;
        lazyFlagType = t_NEG%dataSize;
        """),
        ("0x02", """
        // NOT
        *(int%dataSize_t*)target = ~(*(int%dataSize_t*)target);
        """)
    ])
    generator.addCommand(command)
}
