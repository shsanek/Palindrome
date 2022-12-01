fileprivate let leaCommand = Command(
    code: 0x008D,
    name: "Lea",
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
            uint8_t mrmByte = read8u();
            uint8_t* source = (uint8_t*)readRegisterMRM%dataSize(mrmByte);
            uint%MOD_t target = effectiveAddressMRM%MODFor%MOD(mrmByte);
            *((uint%dataSize_t*)source) = (uint%dataSize_t)(target & %dataMask);
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

let command0F01 = Command(
    code: 0x0101,
    name: "???",
    format: .init(hasPrefixAddress: false, hasPrefixData: false, inlines: []),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .settings([.fpu]),
            .nnn([
                (
                    code: "0x4",
                    formatter: Formatter(customizers: [
                        .settings([.fixData(16)]),
                        .formatter(targetMRMFormat),
                        "*(uint%dataSize_t*)target = 0x0019;"
                    ])
                )
            ])
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendSpecialCommand(generator: Generator) {
    generator.addCommand(leaCommand)
    generator.addCommand(command0F01)
}
