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
            uint%addressSize_t* sp = register%addressSizeu(BR_SP);
            *sp -= %dataSize / 8;
            *(uint%dataSize_t*)(mem(SR_SS) + *sp) = *register%dataSizeu(reg);
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
            uint%addressSize_t* sp = register%addressSizeu(BR_SP);
            *sp -= %dataSize / 8;
            *(uint%dataSize_t*)(mem(SR_SS) + *sp) = read%dataSize%sign();
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
            .vars,
            .nnn([
                (code: "0x00",
                 formatter: Formatter(
                    customizers: [
                        .settings([.bigAddress ,.changeableData]),
                        "// MOVEL",
                        "*target = read%dataSizeu();"
                    ]
                )
                ),
                (code: "0x6",
                 formatter: Formatter(
                    customizers: [
                        .settings([.bigAddress]),
                        "// PUSH",
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
            uint%addressSize_t* sp = register%addressSizeu(BR_SP);
            *register%dataSizeu(reg) = *(uint%dataSize_t*)(mem(SR_SS) + *sp);
            *sp += %dataSize / 8;
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
            *register%addressSizeu(BR_SP) = *register%addressSizeu(BR_BP);
            *register%dataSizeu(BR_BP) = *(uint%dataSize_t*)(mem(SR_SS) + *register%addressSizeu(BR_SP));
            *register%dataSizeu(BR_SP) += %dataSize / 8;
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
}
