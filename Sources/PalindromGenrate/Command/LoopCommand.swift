fileprivate let loopCommand = Command(
    code: 0x00E2,
    name: "Loop",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            """
            int8_t addr = read8();
            uint16_t* reg = register16u(BR_CX);
            *reg -= 1;
            if (*reg != 0) {
            context.index += addr;
            }
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let jmpCommand = Command(
    code: 0x00EB,
    name: "Jmp",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .vars,
            .settings([.fixData(8)]),
            """
            context.index += read8();
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let callCommand = Command(
    code: 0x00E8,
    name: "Call",
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
            .settings([.bigData]),
            """
            context.currentCallStack[0] = context.index + %dataSize / 8;
            context.currentCallStack = context.currentCallStack + 1;
            uint%addressSize_t* sp = register%addressSizeu(BR_SP);
            *sp -= %dataSize / 8;
            context.index += read%dataSize();
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let returnCommand = Command(
    code: 0x00C3,
    name: "Ret",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .vars,
            .settings([.bigData]),
            """
            uint%addressSize_t* sp = register%addressSizeu(BR_SP);
            *sp += %dataSize / 8;
            context.currentCallStack = context.currentCallStack - 1;
            context.index = context.currentCallStack[0];
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let jmpCondCommand = Command(
    code: 0x0070,
    name: "J(cond)",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: [.init(name: "cond", indexBit: 0, count: 4)]
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .settings([]),
            """
            FillFlags();
            int8_t address = read8();
            if COND%cond {
            context.index += address;
            }
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendLoopCommand(generator: Generator) {
    generator.addCommand(loopCommand)
    generator.addCommand(jmpCommand)
    generator.addCommand(callCommand)
    generator.addCommand(returnCommand)
    generator.addCommand(jmpCondCommand)
}

