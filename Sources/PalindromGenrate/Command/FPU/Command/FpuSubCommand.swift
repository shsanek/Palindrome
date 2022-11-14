fileprivate let subFormatter = BaseFormat { info in
    if !info.flags.contains("r") {
        return "*target = (double)(((double)*valueA) - ((double)*valueB));"
    } else {
        return "*target = (double)(((double)*valueB) + ((double)*valueA));"
    }
}

fileprivate let subStackFPUCommand = Command(
    code: (0x00D8 << 3) | 4,
    name: "FPU Sub",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: [
            .init(name: "r", indexBit: 0, count: 1),
            .init(name: "pop", indexBit: 4, count: 1),
            .init(name: "d", indexBit: 5, count: 1),
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .formatter(
                fpuMFDefault(
                    subFormatter,
                    isStack: true
                )
            ),
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let subMemFPUCommand = Command(
    code: (0x00D8 << 3) | 4,
    name: "FPU Sub",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: [
            .init(name: "r", indexBit: 0, count: 1),
            .init(name: "MF", indexBit: 4, count: 2)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .formatter(
                fpuMFDefault(
                    subFormatter,
                    isStack: false
                )
            ),
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendFPUSubCommand(generator: FPUGenerator) {
    generator.addCommand(subStackFPUCommand, isStack: true)
    generator.addCommand(subMemFPUCommand, isStack: false)
}
