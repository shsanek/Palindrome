fileprivate func storageFPUControlRegCommand(command: UInt16) -> Command {
    Command(
        code: (command << 3) | 7,
        name: "Store FPU control",
        format: .init(
            hasPrefixAddress: false,
            hasPrefixData: false,
            inlines: []
        ),
        functionFormatter: Formatter(
            customizers: [
                .formatter(BaseFormat({ info in
                    "*(uint16_t*)readAddressMRM\(info.mode == .mod32 ? "32" : "16")For16(mrmByte) = fpuRegControll;"
                })),
            ]
        ),
        installFormatter: InitialFormatter()
    )
}

fileprivate func loadFPUControlRegCommand(command: UInt16) -> Command {
    Command(
        code: (command << 3) | 5,
        name: "Load FPU control",
        format: .init(
            hasPrefixAddress: false,
            hasPrefixData: false,
            inlines: []
        ),
        functionFormatter: Formatter(
            customizers: [
                .formatter(BaseFormat({ info in
                    "fpuRegControll = *(uint16_t*)readAddressMRM\(info.mode == .mod32 ? "32" : "16")For16(mrmByte);"
                })),
            ]
        ),
        installFormatter: InitialFormatter()
    )
}

fileprivate func fpuInitCommand(command: UInt16) -> Command {
    Command(
        code: (command << 3) | 4,
        name: "FPU Init",
        format: .init(
            hasPrefixAddress: false,
            hasPrefixData: false,
            inlines: []
        ),
        functionFormatter: Formatter(
            customizers: [
                "fpuStackIndex = 7;",
                "fpuRegControll = 0x37F;",
                "fpuRegStatus = 0;",
                "fpuRegTag = 0xFFFF;",
                "fpuRegPointer = 0;",
                "fpuRegInstructionPointer = 0;",
                "fpuRegInstructionOpcode = 0;"
            ]
        ),
        installFormatter: InitialFormatter()
    )
}

fileprivate func fpuControlReg2Command(command: UInt16) -> Command {
    Command(
        code: (command << 3) | 7,
        name: "Load FPU empty",
        format: .init(
            hasPrefixAddress: false,
            hasPrefixData: false,
            inlines: []
        ),
        functionFormatter: Formatter(
            customizers: [
                .formatter(BaseFormat({ info in
                    "*(uint16_t*)readAddressMRM16For16(mrmByte) = 0;"
                })),
            ]
        ),
        installFormatter: InitialFormatter()
    )
}

fileprivate func fpuLoadStateCommand(command: UInt16) -> Command {
    Command(
        code: (command << 3) | 7,
        name: "Load FPU empty",
        format: .init(
            hasPrefixAddress: false,
            hasPrefixData: false,
            inlines: []
        ),
        functionFormatter: Formatter(
            customizers: [
                .formatter(BaseFormat({ info in
                    "*(uint16_t*)readAddressMRM16For16(mrmByte) = fpuRegStatus;"
                })),
            ]
        ),
        installFormatter: InitialFormatter()
    )
}

func appendFPUControlCommand(generator: FPUGenerator) {
    generator.addCommand(storageFPUControlRegCommand(command: 0x00DB), isStack: true)
    generator.addCommand(storageFPUControlRegCommand(command: 0x00DB), isStack: false)
    generator.addCommand(storageFPUControlRegCommand(command: 0x00D9), isStack: true)
    generator.addCommand(storageFPUControlRegCommand(command: 0x00D9), isStack: false)

    generator.addCommand(loadFPUControlRegCommand(command: 0x00D9), isStack: true)
    generator.addCommand(loadFPUControlRegCommand(command: 0x00D9), isStack: false)

    generator.addCommand(fpuInitCommand(command: 0x00DB), isStack: true)
    generator.addCommand(fpuInitCommand(command: 0x00DB), isStack: false)

    generator.addCommand(fpuLoadStateCommand(command: 0x00DD), isStack: true)
    generator.addCommand(fpuLoadStateCommand(command: 0x00DD), isStack: false)
}
