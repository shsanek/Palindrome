func incFormatter(_ target: String) -> IFormatter {
    TemplateFormat(
        """
        \(target) += 1;
        LazyFlagResultContainer%dataSize = \(target);
        lazyFlagType = t_INC%dataSize;
        """
    )
}

func decFormatter(_ target: String) -> IFormatter {
    TemplateFormat(
        """
        \(target) -= 1;
        LazyFlagResultContainer%dataSize = \(target);
        lazyFlagType = t_DEC%dataSize;
        """
    )
}

fileprivate let incCommand = Command(
    code: 0x0040,
    name: "Inc",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [
            .init(name: "reg", indexBit: 0, count: 3)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([.bigData]),
            .formatter(incFormatter("reg_%reg_%dataSizeu"))
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let decCommand = Command(
    code: 0x0048,
    name: "Dec",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [
            .init(name: "reg", indexBit: 0, count: 3)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([.bigData]),
            .formatter(decFormatter("reg_%reg_%dataSizeu"))
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let commandFE = Command(
    code: 0x00FE,
    name: "Inc/Dec",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: [
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .settings([.fixData(8)]),
            .nnn([
                (code: "0x00", formatter: incFormatter("(*(uint%dataSize_t*)target)")),
                (code: "0x01", formatter: decFormatter("(*(uint%dataSize_t*)target)"))
            ])
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendIncCommand(generator: Generator) {
    generator.addCommand(commandFE)
    generator.addCommand(incCommand)
    generator.addCommand(decCommand)

}
