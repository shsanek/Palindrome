fileprivate let inputCommand = Command(
    code: 0x00E4,
    name: "In",
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
            .settings([.changeableData]),
            "uint8_t port = read8u();",
            "context.ports[port].input(port, (uint8_t*)register%dataSizeu(0x00), %dataSize / 8);"
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let outputRegCommand = Command(
    code: 0x00E6,
    name: "Out",
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
            .settings([.changeableData]),
            "uint8_t port = read8u();",
            "context.ports[port].output(port, (uint8_t*)register%dataSizeu(0x00), %dataSize / 8);"
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let inputRegCommand = Command(
    code: 0x00EC,
    name: "In",
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
            .settings([.changeableData]),
            "uint16_t port = *regDXu;",
            "context.ports[port].input(port, (uint8_t*)register%dataSizeu(0x00), %dataSize / 8);"
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let outputCommand = Command(
    code: 0x00EE,
    name: "Out",
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
            .settings([.changeableData]),
            "uint16_t port = *regDXu;",
            "context.ports[port].output(port, (uint8_t*)register%dataSizeu(0x00), %dataSize / 8);"
        ]
    ),
    installFormatter: InitialFormatter()
)


func appendIOCommand(generator: Generator) {
    generator.addCommand(outputCommand)
    generator.addCommand(inputCommand)
    generator.addCommand(outputRegCommand)
    generator.addCommand(inputRegCommand)
}
