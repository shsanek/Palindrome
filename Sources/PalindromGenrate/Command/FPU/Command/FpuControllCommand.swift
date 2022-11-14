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

func appendFPUControlCommand(generator: FPUGenerator) {
    generator.addCommand(storageFPUControlRegCommand(command: 0x00DB), isStack: true)
    generator.addCommand(storageFPUControlRegCommand(command: 0x00DB), isStack: false)
    generator.addCommand(storageFPUControlRegCommand(command: 0x00D9), isStack: true)
    generator.addCommand(storageFPUControlRegCommand(command: 0x00D9), isStack: false)

    generator.addCommand(loadFPUControlRegCommand(command: 0x00D9), isStack: true)
    generator.addCommand(loadFPUControlRegCommand(command: 0x00D9), isStack: false)
}
