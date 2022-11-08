extension Command {
    fileprivate static func mathCommands(code: UInt16, name: String, template: String, short: Bool = false) -> [Command] {
        [
            Command(
                code: code,
                name: name,
                format: .init(
                    hasPrefixAddress: false,
                    hasPrefixData: true,
                    inlines: [
                        .init(name: "w", indexBit: 0, count: 1)
                    ] + (short ? [] : [.init(name: "d", indexBit: 1, count: 1)])
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
        ]
    }

    fileprivate static func mathCommands(
        code: UInt16,
        name: String,
        symbol: String,
        set: Bool = true,
        useCF: Bool = false,
        short: Bool = false
    ) -> [Command] {
        self.mathCommands(
            code: code,
            name: name,
            template: """
            LazyFlagVarA%dataSize = *(int%dataSize_t*)target;
            LazyFlagVarB%dataSize = *(int%dataSize_t*)source;
            \(useCF ? "FillFlags();" : "")
            \(useCF ? "oldcf = GET_FLAG(CF);" : "")
            LazyFlagResultContainer%dataSize = LazyFlagVarA%dataSize \(symbol) LazyFlagVarB%dataSize \(useCF ? "\(symbol) oldcf" : "");
            lazyFlagType = t_\(name)%dataSize;
            \(set ? "*(int%dataSize_t*)target = LazyFlagResultContainer%dataSize;" : "")
            """,
            short: short
        ) + [
            Command(
                code: short ? 0x00A8 : code + 4,
                name: name,
                format: .init(
                    hasPrefixAddress: false,
                    hasPrefixData: true,
                    inlines: [
                        .init(name: "w", indexBit: 0, count: 1),
                    ]
                ),
                functionFormatter: Formatter(
                    customizers: [
                        .prefixData,
                        .functionName,
                        .settings([.changeableData]),
                        .template(
                        """
                        uint8_t* target = (uint8_t*)register%dataSizeu(BR_AX);
                        LazyFlagVarA%dataSize = *(int%dataSize_t*)target;
                        LazyFlagVarB%dataSize = read%dataSizeu();
                        \(useCF ? "FillFlags();" : "")
                        \(useCF ? "oldcf = GET_FLAG(CF);" : "")
                        LazyFlagResultContainer%dataSize = LazyFlagVarA%dataSize \(symbol) LazyFlagVarB%dataSize \(useCF ? "\(symbol) oldcf" : "");
                        lazyFlagType = t_\(name)%dataSize;
                        \(set ? "*(int%dataSize_t*)target = LazyFlagResultContainer%dataSize;" : "")
                        """
                        )
                    ]
                ),
                installFormatter: InitialFormatter()
            )
        ]
    }

    fileprivate static func mathNNNCommands(code: UInt16, templates: [(String, String)]) -> [Command] {
        return [
            Command(
                code: code,
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

    fileprivate static func mathNNNCommands(code: UInt16, symbol: [(String, String, String, Bool, Bool, Bool)]) -> [Command] {
        mathNNNCommands(
            code: code,
            templates: symbol.map {
                ($0.0, """
                LazyFlagVarA%dataSize = *(int%dataSize_t*)target;
                LazyFlagVarB%dataSize = read%operandSize();
                \($0.4 ? "FillFlags();" : "")
                \($0.4 ? "oldcf = GET_FLAG(CF);" : "")
                LazyFlagResultContainer%dataSize = LazyFlagVarA%dataSize \($0.1) (\($0.5 ? "": "(%signint%operandSize_t)")LazyFlagVarB%dataSize) \($0.4 ? "\($0.1) oldcf" : "");
                lazyFlagType = t_\($0.2)%dataSize;
                \($0.3 ? "*(int%dataSize_t*)target = LazyFlagResultContainer%dataSize;" : "")
                """
                )
            }
        )
    }
}

func appendAddCommand(generator: Generator) {
    generator.addCommands(Command.mathCommands(code: 0x0000, name: "ADD", symbol: "+"))
    generator.addCommands(Command.mathCommands(code: 0x0008, name: "OR", symbol: "|"))
    generator.addCommands(Command.mathCommands(code: 0x0010, name: "ADC", symbol: "+", useCF: true))
    generator.addCommands(Command.mathCommands(code: 0x0018, name: "SBB", symbol: "-", useCF: true))
    generator.addCommands(Command.mathCommands(code: 0x0020, name: "AND", symbol: "&"))
    generator.addCommands(Command.mathCommands(code: 0x0028, name: "SUB", symbol: "-"))
    generator.addCommands(Command.mathCommands(code: 0x0030, name: "XOR", symbol: "^"))
    generator.addCommands(Command.mathCommands(code: 0x0038, name: "CMP", symbol: "-", set: false))
    generator.addCommands(Command.mathCommands(code: 0x0084, name: "TEST", symbol: "&", set: false, short: true))
    generator.addCommands(
        Command.mathNNNCommands(
            code: 0x0080,
            symbol: [
                ("0x0", "+", "ADD", true, false, false),
                ("0x1", "|", "OR", true, false, true),
                ("0x2", "+", "AND", true, true, false),
                ("0x3", "-", "SUB", true, true, false),
                ("0x4", "&", "AND", true, false, true),
                ("0x5", "-", "SUB", true, false, false),
                ("0x6", "^", "XOR", true, false, true),
                ("0x7", "-", "CMP", false, false, false)
            ]
        )
    )
}
