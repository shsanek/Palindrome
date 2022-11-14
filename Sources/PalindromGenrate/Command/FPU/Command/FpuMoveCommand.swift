fileprivate let fpuMoveCommand = Command(
    code: 0x00D9 << 3,
    name: "FPU Move",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: [
            .init(name: "MF", indexBit: 4, count: 2),
            .init(name: "pop", indexBit: 0, count: 1),
            .init(name: "d", indexBit: 1, count: 1),
            .init(name: "push", indexBit: 0, count: 1, value: "true")
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .formatter(
                fpuMFDefault(
                    BaseFormat { _ in
                        "*target = *source;"
                    },
                    isStack: false
                )
            ),
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let fpuStackMoveCommand = Command(
    code: 0x00D9 << 3,
    name: "FPU Move",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: [
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .formatter(
                fpuMFDefault(
                    BaseFormat { _ in
                        "*target = *source;"
                    },
                    isStack: true
                )
            ),
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendFPUMoveCommand(generator: FPUGenerator) {
    generator.addCommand(fpuMoveCommand, isStack: false)
    generator.addCommand(fpuStackMoveCommand, isStack: true)
}
