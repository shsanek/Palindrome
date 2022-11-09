extension Command {
    static func generate0190Command(templates: [(String, IFormatter)]) -> Command {
        return Command(
            code: 0x0190,
            name: "Math",
            format: .init(
                hasPrefixAddress: false,
                hasPrefixData: true,
                inlines: [
                    .init(name: "cond", indexBit: 0, count: 4)
                ]
            ),
            functionFormatter: Formatter(
                customizers: [
                    .prefixData,
                    .functionName,
                    .vars,
                    .settings([.fixAddress(8), .fixData(8)]),
                    .nnn(templates.map { (code: $0.0, formatter: $0.1) } )
                ]
            ),
            installFormatter: InitialFormatter()
        )
    }
}

let setCond = BaseFormat { info in
    """
    // SET(cond)
    *target = COND%cond ? 1 : 0;
    """
}


func append0F90Command(generator: Generator) {
    let command = Command.generate0190Command(templates: [
        ("0x00", setCond)
    ])
    generator.addCommand(command)
}
