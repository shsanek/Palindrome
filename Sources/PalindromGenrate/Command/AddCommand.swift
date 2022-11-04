fileprivate let addBaseCommand = Command(
    code: 0x0000,
    name: "ADD",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [
            .init(name: "w", indexBit: 0, count: 1),
            .init(name: "d", indexBit: 1, count: 1)
        ]
    ),
    functionFormatter: Formatter.defaultMRM(TemplateFormat(template: "*(%dataType*)target += *(%dataType*)source;")),
    installFormatter: InitialFormatter()
)


func appendAddCommand(generator: Generator) {
    generator.addCommand(addBaseCommand)
}

