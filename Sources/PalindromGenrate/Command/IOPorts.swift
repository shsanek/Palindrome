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
            "context.ports[port].input(port, (uint8_t*)register%dataSizeu(0x00), %dataSize / 4);"
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let outputCommand = Command(
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
            "context.ports[port].output(port, (uint8_t*)register%dataSizeu(0x00), %dataSize / 4);"
        ]
    ),
    installFormatter: InitialFormatter()
)


func appendIOCommand(generator: Generator) {
    generator.addCommand(outputCommand)
    generator.addCommand(inputCommand)
}
