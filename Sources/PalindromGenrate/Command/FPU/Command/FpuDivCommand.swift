fileprivate let divFormatter = BaseFormat { info in
    if !info.flags.contains("r") {
        return "*target = (double)(((double)*valueA) / ((double)*valueB));"
    } else {
        return "*target = (double)(((double)*valueB) / ((double)*valueA));"
    }
}

fileprivate let divStackFPUCommand = Command(
    code: (0x00D8 << 3) | 6,
    name: "FPU Div",
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
                    divFormatter,
                    isStack: true
                )
            ),
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let divMemFPUCommand = Command(
    code: (0x00D8 << 3) | 6,
    name: "FPU Div",
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
                    divFormatter,
                    isStack: false
                )
            ),
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendFPUDivCommand(generator: FPUGenerator) {
    generator.addCommand(divStackFPUCommand, isStack: true)
    generator.addCommand(divMemFPUCommand, isStack: false)
}
