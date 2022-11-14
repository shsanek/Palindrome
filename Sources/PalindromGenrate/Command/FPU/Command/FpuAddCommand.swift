let addStackFPUCommand = Command(
    code: 0x00D8 << 3,
    name: "FPU Add",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: [
            .init(name: "pop", indexBit: 4, count: 1),
            .init(name: "d", indexBit: 5, count: 1),
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .formatter(
                fpuMFDefault(
                    BaseFormat { _ in
                        "*target = (double)(((double)*valueA) + ((double)*valueB));"
                    },
                    isStack: true
                )
            ),
        ]
    ),
    installFormatter: InitialFormatter()
)

let addMemFPUCommand = Command(
    code: 0x00D8 << 3,
    name: "FPU Add",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: [
            .init(name: "MF", indexBit: 4, count: 2)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .formatter(
                fpuMFDefault(
                    BaseFormat { _ in
                        "*target = (double)(((double)*valueA) + ((double)*valueB));"
                    },
                    isStack: false
                )
            ),
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendFPUAddCommand(generator: FPUGenerator) {
    generator.addCommand(addStackFPUCommand, isStack: true)
    generator.addCommand(addMemFPUCommand, isStack: false)
}
