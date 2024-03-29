func flagCommand(value: Bool, flag: String, code: UInt16, name: String) -> Command {
    Command(
        code: code,
        name: "Flag \(name) set \(value)",
        format: .init(hasPrefixAddress: false, hasPrefixData: false, inlines: []),
        functionFormatter: Formatter(customizers: [
            .functionName,
            .template("SET_FLAG(\(flag), \(value ? 1 : 0));")
        ]),
        installFormatter: InitialFormatter()
    )
}

let commandF5 = Command(
    code: 0x00F5,
    name: "~CF",
    format: .init(hasPrefixAddress: false, hasPrefixData: false, inlines: []),
    functionFormatter: Formatter(customizers: [
        .functionName,
        "SET_FLAG(CF, !GET_FLAG(CF));"
    ]),
    installFormatter: InitialFormatter()
)

func appendFlagsCommand(generator: Generator) {
    generator.addCommand(flagCommand(value: false, flag: "CF", code: 0x00F8, name: "CF"))
    generator.addCommand(flagCommand(value: true, flag: "CF", code: 0x00F9, name: "CF"))
    generator.addCommand(flagCommand(value: false, flag: "DF", code: 0x00FC, name: "DF"))
    generator.addCommand(flagCommand(value: true, flag: "DF", code: 0x00FD, name: "DF"))

    generator.addCommand(flagCommand(value: true, flag: "IF", code: 0x00FB, name: "IF"))
    generator.addCommand(flagCommand(value: false, flag: "IF", code: 0x00FA, name: "IF"))

    generator.addCommand(commandF5)
}
