fileprivate let loopCommand = Command(
    code: 0x00E2,
    name: "Loop",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [.functionName],
        baseFormatter: TemplateFormat(
            template: """
            int8_t addr = read8(context);
            uint16_t* reg = register16u(context, BR_CX);
            *reg -= 1;
            if (*reg != 0) {
            context->index += addr;
            }
            """
        )
    ),
    installFormatter: InitialFormatter()
)

func appendLoopCommand(generator: Generator) {
    generator.addCommand(loopCommand)
}

