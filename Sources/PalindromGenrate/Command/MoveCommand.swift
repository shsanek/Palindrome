fileprivate let moveMRMCommand = Command(
    code: 0x0088,
    name: "Move",
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
            "*(%dataType*)target = *(%dataType*)source;"
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let moveDataCommand = Command(
    code: 0x00B0,
    name: "Move",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [
            .init(name: "w", indexBit: 3, count: 1),
            .init(name: "reg", indexBit: 0, count: 3)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([.changeableData]),
            "reg_%reg_%dataSizeu = read%dataSizeu();"
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendMoveCommand(generator: Generator) {
    generator.addCommand(moveMRMCommand)
    generator.addCommand(moveDataCommand)
}
