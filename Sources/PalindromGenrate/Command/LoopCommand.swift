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

fileprivate let jmpBigCommand = Command(
    code: 0x00E9,
    name: "Jmp",
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
            context.index += read%dataSize();
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
            uint%addressSize_t* sp = register%addressSizeu(BR_SP);
            *sp -= %MOD / 8;
            *(uint%MOD_t*)(mem(SR_SS) + *sp) = (uint%MOD_t)(context.index + %dataSize / 8 - mem(1));
            context.index += read%dataSize();
            """
        ]
    ),
    installFormatter: InitialFormatter()
)


fileprivate let callFarCommand = Command(
    code: 0x009A,
    name: "Call",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .vars,
            .settings([.bigAddress]),
            "int%addressSize_t newIP = read%addressSize();",
            "uint16_t newCS = read16u();",
            .template(pushValue("context.segmentRegisters[SR_CS]", size: "16")),
            .template(pushValue("((uint%addressSize_t)(context.index - mem(SR_CS)))", size: "%addressSize")),
            "setMem(SR_CS, newCS);",
            "context.index = mem(SR_CS) + newIP;"
        ]
    ),
    installFormatter: InitialFormatter()
)


fileprivate let returnC3Command = Command(
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
            context.index = mem(1) + *(uint%MOD_t*)(mem(SR_SS) + *sp);
            *sp += %MOD / 8;
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let returnCBCommand = Command(
    code: 0x00CB,
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
            setMem(1, *(int16_t*)(mem(SR_SS) + *sp + %MOD / 8));
            context.index = mem(1) + *(uint%MOD_t*)(mem(SR_SS) + *sp);
            *sp += %MOD / 8 + 2;
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

fileprivate let bigJmpCondCommand = Command(
    code: 0x0180,
    name: "J(cond)",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: [.init(name: "cond", indexBit: 0, count: 4)]
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .settings([.bigAddress]),
            """
            FillFlags();
            int%addressSize_t address = read%addressSize();
            if COND%cond {
            context.index += address;
            }
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let loopE1Command = Command(
    code: 0x00E1,
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
            reg_0x01_%MOD -= 1;
            FillFlags();
            if (reg_0x01_%MOD != 0 && GET_FLAG(ZF) == 1) {
            context.index += addr;
            }
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let loopE0Command = Command(
    code: 0x00E0,
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
            reg_0x01_%MOD -= 1;
            FillFlags();
            if (reg_0x01_%MOD != 0 && GET_FLAG(ZF) == 0) {
            context.index += addr;
            }
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let loopE2Command = Command(
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
            reg_0x01_%MOD -= 1;
            if (reg_0x01_%MOD != 0) {
            context.index += addr;
            }
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let loopE3Command = Command(
    code: 0x00E3,
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
            if (reg_0x01_%MOD == 0) {
            context.index += addr;
            }
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendLoopCommand(generator: Generator) {
    generator.addCommand(loopE3Command)
    generator.addCommand(loopE2Command)
    generator.addCommand(loopE1Command)
    generator.addCommand(loopE0Command)

    generator.addCommand(jmpCommand)
    generator.addCommand(jmpBigCommand)
    generator.addCommand(bigJmpCondCommand)
    generator.addCommand(callCommand)
    generator.addCommand(callFarCommand)
    generator.addCommand(jmpCondCommand)

    generator.addCommand(returnC3Command)
    generator.addCommand(returnCBCommand)
}

