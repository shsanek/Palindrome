func pushValue(_ value: String, size: String = "%dataSize") -> String {
    """
    reg_SP_%addressSizeu -= \(size) / 8;
    *(uint\(size)_t*)(GET_SEGMENT_POINTER(SR_SS) + reg_SP_%addressSizeu) = \(value);
    """
}

func popValue(_ value: String) -> String {
    """
    \(value) = *(uint%dataSize_t*)(GET_SEGMENT_POINTER(SR_SS) + reg_SP_%addressSizeu);
    reg_SP_%addressSizeu += %dataSize / 8;
    """
}


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
            "uint%dataSize_t value = reg_%reg_%dataSizeu;",
            .template(pushValue("value"))
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let pushData1Command = Command(
    code: 0x006A,
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
            reg_SP_%addressSizeu -= %dataSize / 8;
            *(int%dataSize_t*)(GET_SEGMENT_POINTER(SR_SS) + reg_SP_%addressSizeu) = (int%dataSize_t)read8();
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
            .template(pushValue("read%dataSizeu()"))
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
                (
                    code: "0x00",
                    formatter: Formatter(
                        customizers: [
                            .settings([.bigAddress ,.bigData]),
                            "// INC",
                            .formatter(targetMRMFormat),
                            "(*(uint%dataSize_t*)target)++;",
                            "LazyFlagResultContainer%dataSize = *(uint%dataSize_t*)target;",
                            "lazyFlagType = t_INC%dataSize;"
                        ]
                    )
                ),
                (
                    code: "0x01",
                    formatter: Formatter(
                        customizers: [
                            .settings([.bigAddress ,.bigData]),
                            "// DEC",
                            .formatter(targetMRMFormat),
                            "(*(uint%dataSize_t*)target)--;",
                            "LazyFlagResultContainer%dataSize = *(uint%dataSize_t*)target;",
                            "lazyFlagType = t_DEC%dataSize;"
                        ]
                    )
                ),
                (
                    code: "0x4",
                    formatter: Formatter(
                        customizers: [
                            .settings([.bigData]),
                            "// JMP",
                            .formatter(targetMRMFormat),
                            "context.index = GET_SEGMENT_POINTER(SR_CS) + (*((uint%dataSize_t*)target));"
                        ]
                    )
                ),
                (
                    code: "0x5",
                    formatter: Formatter(
                        customizers: [
                            .settings([.bigData]),
                            "// JMP",
                            .formatter(targetMRMFormat),
                            "SET_VALUE_IN_SEGMENT(SR_CS, (*((uint16_t*)(target + 2))));",
                            "context.index = GET_SEGMENT_POINTER(SR_CS) + (*((uint%dataSize_t*)(target)));"
                        ]
                    )
                ),
                (code: "0x6",
                 formatter: Formatter(
                    customizers: [
                        .settings([.bigAddress]),
                        "// PUSH",
                        .formatter(targetMRMFormat),
                        .template(pushValue("*(uint%dataSize_t*)target"))
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
            .template(popValue("reg_%reg_%dataSizeu"))
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
            *(uint16_t*)(GET_SEGMENT_POINTER(SR_SS) + reg_SP_%addressSizeu) = SR_VALUE(rg);
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
            .formatter(BaseFormat({ info in
                if (info.variation == 0x000F) {
                    return "// 0f???"
                }
                return """
                    SET_VALUE_IN_SEGMENT(rg, *(uint16_t*)(GET_SEGMENT_POINTER(SR_SS) + reg_SP_%addressSizeu));
                    reg_SP_%addressSizeu += 16 / 8;
                """
            }))
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let pushFlagRegCommand = Command(
    code: 0x009C,
    name: "PUSHF",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .vars,
            .settings([.bigAddress, .bigData]),
            """
            FillFlags();
            reg_SP_%addressSizeu -= %dataSize / 8;
            EncodeFlagsRegister();
            uint32_t value = reg_flags & 0xFCFFFF;
            *(uint%dataSize_t*)(GET_SEGMENT_POINTER(SR_SS) + reg_SP_%addressSizeu) = *((uint%dataSize_t*)&value);
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let popFlagRegCommand = Command(
    code: 0x009D,
    name: "POPF",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .vars,
            .settings([.bigAddress, .bigData]),
            """
            lazyFlagType = t_UNKNOWN;
            *(uint%dataSize_t*)(&reg_flags) = (*(uint%dataSize_t*)(GET_SEGMENT_POINTER(SR_SS) + reg_SP_%addressSizeu));
            reg_SP_%addressSizeu += %dataSize / 8;
            DecodeFlagsRegister%dataSize();
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let pushAllRegCommand = Command(
    code: 0x0060,
    name: "PUSHA",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .vars,
            .settings([.bigAddress, .bigData]),
            "uint%dataSize_t tmp = reg_SP_%dataSizeu;",
            .template(pushValue("reg_AX_%dataSizeu")),
            .template(pushValue("reg_CX_%dataSizeu")),
            .template(pushValue("reg_DX_%dataSizeu")),
            .template(pushValue("reg_BX_%dataSizeu")),
            .template(pushValue("tmp")),
            .template(pushValue("reg_BP_%dataSizeu")),
            .template(pushValue("reg_SI_%dataSizeu")),
            .template(pushValue("reg_DI_%dataSizeu"))
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let popAllRegCommand = Command(
    code: 0x0061,
    name: "POPA",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .vars,
            .settings([.bigAddress, .bigData]),
            .template(popValue("reg_DI_%dataSizeu")),
            .template(popValue("reg_SI_%dataSizeu")),
            .template(popValue("reg_BP_%dataSizeu")),
            "reg_SP_%addressSizeu += %dataSize / 8;",
            .template(popValue("reg_BX_%dataSizeu")),
            .template(popValue("reg_DX_%dataSizeu")),
            .template(popValue("reg_CX_%dataSizeu")),
            .template(popValue("reg_AX_%dataSizeu")),
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendStackCommand(generator: Generator) {
    generator.addCommand(pushRegCommand)
    generator.addCommand(popRegCommand)
    generator.addCommand(oftherCommand)
    generator.addCommand(pushData1Command)
    generator.addCommand(pushData2Command)

    generator.addCommand(popSegRegCommand)
    generator.addCommand(pushSegRegCommand)

    generator.addCommand(pushFlagRegCommand)
    generator.addCommand(popFlagRegCommand)

    generator.addCommand(pushAllRegCommand)
    generator.addCommand(popAllRegCommand)
}
