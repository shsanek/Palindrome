fileprivate let pushRegCommand = Command(
    code: 0x0050,
    name: "Push",
    format: .init(
        hasPrefixAddress: true,
        hasPrefixData: true,
        inlines: [
            .init(name: "reg", indexBit: 0, count: 3)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixAddress,
            .prefixData,
            .functionName,
            .vars,
            .settings([.bigData, .bigAddress]),
            """
            reg_SP_%addressSizeu -= %dataSize / 8;
            *(uint%dataSize_t*)(mem(SR_SS) + reg_SP_%addressSizeu) = reg_%reg_%dataSizeu;
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let pushData1Command = Command(
    code: 0x006A,
    name: "Push",
    format: .init(
        hasPrefixAddress: true,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixAddress,
            .functionName,
            .vars,
            .settings([.fixData(8), .bigAddress]),
            """
            reg_SP_%addressSizeu -= %dataSize / 8;
            *(uint%dataSize_t*)(mem(SR_SS) + reg_SP_%addressSizeu) = read%dataSize%sign();
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let pushData2Command = Command(
    code: 0x0068,
    name: "Push",
    format: .init(
        hasPrefixAddress: true,
        hasPrefixData: true,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixAddress,
            .prefixData,
            .functionName,
            .vars,
            .settings([.bigData, .bigAddress]),
            """
            uint%addressSize_t* sp = register%addressSizeu(BR_SP);
            *sp -= %dataSize / 8;
            *(uint%dataSize_t*)(mem(SR_SS) + *sp) = read%dataSize%sign();
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let oftherCommand = Command(
    code: 0x00FF,
    name: "Ofther",
    format: .init(
        hasPrefixAddress: true,
        hasPrefixData: true,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixAddress,
            .prefixData,
            .functionName,
            .settings([.fpu]),
            .vars,
            .nnn([
                (code: "0x00",
                 formatter: Formatter(
                    customizers: [
                        .settings([.bigAddress ,.changeableData]),
                        "// MOVEL",
                        .formatter(targetMRMFormat),
                        "*target = read%dataSizeu();"
                    ]
                )
                ),
                (code: "0x6",
                 formatter: Formatter(
                    customizers: [
                        .settings([.bigAddress]),
                        "// PUSH",
                        .formatter(targetMRMFormat),
                        "uint%addressSize_t* sp = register%addressSizeu(BR_SP);",
                        "*sp -= %dataSize / 8;",
                        "*(uint%dataSize_t*)(mem(SR_SS) + *sp) = *(uint%dataSize_t*)target;"
                    ]
                )
                )
            ])
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let popRegCommand = Command(
    code: 0x0058,
    name: "Pop",
    format: .init(
        hasPrefixAddress: true,
        hasPrefixData: true,
        inlines: [
            .init(name: "reg", indexBit: 0, count: 3)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixAddress,
            .prefixData,
            .functionName,
            .vars,
            .settings([.bigData, .bigAddress]),
            """
            reg_%reg_%dataSizeu = *(uint%dataSize_t*)(mem(SR_SS) + reg_SP_%addressSizeu);
            reg_SP_%addressSizeu += %dataSize / 8;
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let leaveCommand = Command(
    code: 0x00C9,
    name: "Leave",
    format: .init(
        hasPrefixAddress: true,
        hasPrefixData: true,
        inlines: [
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixAddress,
            .prefixData,
            .functionName,
            .settings([.bigData, .bigAddress]),
            """
            reg_SP_%addressSizeu = reg_BP_%addressSizeu;
            reg_BP_%addressSizeu = *(uint%dataSize_t*)(mem(SR_SS) + reg_SP_%addressSizeu);
            reg_SP_%addressSizeu += %dataSize / 8;
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let pushSegRegCommand = Command(
    code: 0x0006,
    name: "Push",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: [
            .init(name: "rg", indexBit: 3, count: 2)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .vars,
            .settings([.bigAddress]),
            """
            reg_SP_%addressSizeu -= 16 / 8;
            *(uint16_t*)(mem(SR_SS) + reg_SP_%addressSizeu) = context.segmentRegisters[rg];
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let popSegRegCommand = Command(
    code: 0x0007,
    name: "Pop",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: [
            .init(name: "rg", indexBit: 3, count: 2)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .vars,
            .settings([.bigAddress]),
            """
            context.segmentRegisters[rg] = *(uint16_t*)(mem(SR_SS) + reg_SP_%addressSizeu);
            reg_SP_%addressSizeu += 16 / 8;
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendStackCommand(generator: Generator) {
    generator.addCommand(pushRegCommand)
    generator.addCommand(popRegCommand)
    generator.addCommand(leaveCommand)
    generator.addCommand(oftherCommand)
    generator.addCommand(pushData1Command)
    generator.addCommand(pushData2Command)

    generator.addCommand(popSegRegCommand)
    generator.addCommand(pushSegRegCommand)
}
