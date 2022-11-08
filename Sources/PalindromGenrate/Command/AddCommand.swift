extension Command {
    fileprivate static func mathCommand(code: UInt16, name: String, template: String) -> Command {
        Command(
            code: code,
            name: name,
            format: .init(
                hasPrefixAddress: false,
                hasPrefixData: true,
                inlines: [
                    .init(name: "w", indexBit: 0, count: 1),
                    .init(name: "d", indexBit: 1, count: 1)
                ]
            ),
            functionFormatter: Formatter(
                customizers: [
                    .prefixData,
                    .functionName,
                    .settings([.changeableData, .bigAddress]),
                    .mrm,
                    .template(template)
                ]
            ),
            installFormatter: InitialFormatter()
        )
    }

    fileprivate static func mathCommand(code: UInt16, name: String, symbol: String, set: Bool = true) -> Command {
        self.mathCommand(
            code: code,
            name: name,
            template: """
            LazyFlagVarA%dataSize = *(int%dataSize_t*)target;
            LazyFlagVarB%dataSize = *(int%dataSize_t*)source;
            LazyFlagResultContainer%dataSize = LazyFlagVarA%dataSize \(symbol) LazyFlagVarB%dataSize;
            lazyFlagType = t_\(name)%dataSize;
            \(set ? "*(int%dataSize_t*)target = LazyFlagResultContainer%dataSize;" : "")
            """
        )
    }

    fileprivate static func mathNNNCommands(code: UInt16, templates: [(String, String)]) -> [Command] {
        return [
            Command(
                code: code,
                name: "Math",
                format: .init(
                    hasPrefixAddress: true,
                    hasPrefixData: true,
                    inlines: [
                        .init(name: "w", indexBit: 0, count: 1)
                    ]
                ),
                functionFormatter: Formatter(
                    customizers: [
                        .prefixAddress,
                        .prefixData,
                        .functionName,
                        .settings([.changeableData, .bigAddress]),
                        .nnn(templates.map { (code: $0.0, formatter: TemplateFormat($0.1)) } )
                    ]
                ),
                installFormatter: InitialFormatter()
            ),
            Command(
                code: code + 2,
                name: "Math",
                format: .init(
                    hasPrefixAddress: false,
                    hasPrefixData: false,
                    inlines: []
                ),
                functionFormatter: Formatter(
                    customizers: [
                        .functionName,
                        .settings([.fixData(8), .fixAddress(8), .sign]),
                        .nnn(templates.map { (code: $0.0, formatter: TemplateFormat($0.1)) } )
                    ]
                ),
                installFormatter: InitialFormatter()
            ),
            Command(
                code: code + 3,
                name: "Math",
                format: .init(
                    hasPrefixAddress: false,
                    hasPrefixData: false,
                    inlines: []
                ),
                functionFormatter: Formatter(
                    customizers: [
                        .prefixData,
                        .functionName,
                        .settings([.bigData, .fixOperand(8), .bigAddress, .sign]),
                        .nnn(templates.map { (code: $0.0, formatter: TemplateFormat($0.1)) } )
                    ]
                ),
                installFormatter: InitialFormatter()
            )
        ]
    }

    fileprivate static func mathNNNCommands(code: UInt16, symbol: [(String, String, String, Bool)]) -> [Command] {
        mathNNNCommands(
            code: code,
            templates: symbol.map {
                ($0.0, """
                LazyFlagVarA%dataSize = *(int%dataSize_t*)target;
                LazyFlagVarB%dataSize = read%operandSize();
                LazyFlagResultContainer%dataSize = LazyFlagVarA%dataSize \($0.1) LazyFlagVarB%dataSize;
                lazyFlagType = t_\($0.2)%dataSize;
                \($0.3 ? "*(int%dataSize_t*)target = LazyFlagResultContainer%dataSize;" : "")
                """
                )
            }
        )
    }
}


func appendAddCommand(generator: Generator) {
    generator.addCommand(.mathCommand(code: 0x0000, name: "ADD", symbol: "+"))
    generator.addCommand(.mathCommand(code: 0x0008, name: "OR", symbol: "|"))
    generator.addCommand(.mathCommand(code: 0x0020, name: "AND", symbol: "&"))
    generator.addCommand(.mathCommand(code: 0x0028, name: "SUB", symbol: "-"))
    generator.addCommand(.mathCommand(code: 0x0030, name: "XOR", symbol: "^"))
    generator.addCommand(.mathCommand(code: 0x0038, name: "CMP", symbol: "-", set: false))
    generator.addCommands(
        Command.mathNNNCommands(
            code: 0x0080,
            symbol: [
                ("0x0", "+", "ADD", true),
                ("0x1", "|", "OR", true),
                ("0x4", "&", "AND", true),
                ("0x5", "-", "SUB", true),
                ("0x6", "^", "XOR", true),
                ("0x7", "-", "CMP", false)
            ]
        )
    )

    generator.addCommand(multlCommand)
}

let multlCommand = Command(
    code: 0x01AF,
    name: "Mul",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .settings([.bigData, .bigAddress]),
            .mrm,
            """
            LazyFlagVarA%dataSize = *(int%dataSize_t*)target;
            LazyFlagVarB%dataSize = *(int%dataSize_t*)source;
            LazyFlagResultContainer%dataSize = LazyFlagVarA%dataSize * LazyFlagVarB%dataSize;
            lazyFlagType = t_MUL;
            *(int%dataSize_t*)source = LazyFlagResultContainer%dataSize;
            """
        ]
    ),
    installFormatter: InitialFormatter()
)
