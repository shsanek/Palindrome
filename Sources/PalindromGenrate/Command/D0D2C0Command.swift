let SHL = Formatter(
    customizers: [
        "value = value & 0x1F;",
        "if (value == 0) { return; }",
        "",
        "LazyFlagVarB8 = value;",
        "LazyFlagVarA%dataSize = *(u%int*)target;",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) << value;",
        "",
        "LazyFlagResultContainer%dataSize = (*(uint%dataSize_t*)target);",
        "lazyFlagType=t_SHL%dataSize;"
    ]
)

let SHR = Formatter(
    customizers: [
        "value = value & 0x1F;",
        "if (value == 0) { return; }",
        "",
        "LazyFlagVarB8 = value;",
        "LazyFlagVarA%dataSize = *(u%int*)target;",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) >> (value);",
        "",
        "LazyFlagResultContainer%dataSize = (*(uint%dataSize_t*)target);",
        "lazyFlagType=t_SHR%dataSize;"
    ]
)

let SAL = SHL

let SAR = Formatter(
    customizers: [
        "value = value & 0x1F;",
        "if (value == 0) { return; }",
        "if (value > %dataSize) { value = %dataSize; }",
        "FillFlagsNoCFOF();",
        "",
        "LazyFlagVarB8 = value;",
        "LazyFlagVarA%dataSize = *(u%int*)target;",
        "if (LazyFlagVarA%dataSize & %firstBitMask) {",
        "LazyFlagResultContainer%dataSize = ((LazyFlagVarA%dataSize) >> value) | ((0xFFFFFFFF) << (%dataSize - value));",
        "} else {",
        "LazyFlagResultContainer%dataSize = (LazyFlagVarA%dataSize) >> value;",
        "}",
        "(*(u%int*)target) = LazyFlagResultContainer%dataSize;",
        "",
        "lazyFlagType=t_SAR%dataSize;"
    ]
)

//
let ROL = Formatter(
    customizers: [
        "value = value & 0x1F;",
        "if (value == 0) { return; }",
        "FillFlagsNoCFOF();",
        "value = value % %dataSize;",
        "",
        "u%int tmp = ((*(u%int*)target) << value) | ((*(u%int*)target) >> (%dataSize - value));",
        "",
        "(*(u%int*)target) = tmp;",
        "SET_FLAG(CF, (tmp & 1));",
        "SET_FLAG(OF, (tmp >> (%dataSize - 1)) ^ CF );",
        ""
    ]
)

let ROR = Formatter(
    customizers: [
        "value = value & 0x1F;",
        "if (value == 0) { return; }",
        "FillFlagsNoCFOF();",
        "value = value % %dataSize;",
        "",
        "u%int tmp = ((*(u%int*)target) >> value) | ((*(u%int*)target) << (%dataSize - value));",
        "",
        "(*(uint%dataSize_t*)target) = tmp;",
        "",
        "SET_FLAG(CF, (tmp & %firstBitMask));",
        "SET_FLAG(OF, (tmp ^ (tmp << 1)) & %firstBitMask);",
        ""
    ]
)

let RCL = Formatter(
    customizers: [
        "value = (value & 0x1F) % (%dataSize + 1);",
        "if (value == 0) { return; }",
        "FillFlags();",
        "",
        "SET_FLAG(CF, (((*(u%int*)target) >> (%dataSize - value)) & 0x1) );",
        "u%int tmp = ((*(u%int*)target) << value) | ((u%int)CF >> (%dataSize - value + 1)) | ((*(u%int*)target) >> (%dataSize - value));",
        "",
        "(*(u%int*)target) = tmp;",
        "SET_FLAG(OF, (tmp >> (%dataSize - 1)) ^ CF );",
        ""
    ]
)

// SET_BIT

let RCR = Formatter(
    customizers: [
        "value = (value & 0x1F) % (%dataSize + 1);",
        "if (value == 0) { return; }",
        "FillFlags();",
        "",
        "u%int tmp = *(u%int*)target;",
        "LazyFlagVarB8 = value;",
        "LazyFlagVarA%dataSize = tmp;",

        "tmp = (tmp >> value) | ((u%int)CF << (%dataSize - value)) | (tmp << (%dataSize - value + 1));",
        "",
        "(*(u%int*)target) = tmp;",
        "SET_FLAG(CF, (((LazyFlagVarA%dataSize) >> (value - 1)) & 1));",
        "SET_FLAG(OF, (tmp ^ (tmp << 1)) & %firstBitMask);",
        ""
    ]
)

let bitsShift: [(code: String, formatter: IFormatter)] = [
    (code: "0", formatter: ROL),
    (code: "1", formatter: ROR),
    (code: "2", formatter: RCL),
    (code: "3", formatter: RCR),
    (code: "4", formatter: SHL),
    (code: "5", formatter: SHR),
    (code: "7", formatter: SAR),
]

let D0 = Command(
    code: 0x00D0,
    name: "Move bits",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [.init(name: "w", indexBit: 0, count: 1)]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([.changeableData]),
            .nnn(bitsShift, prepare: TemplateFormat("uint8_t value = 1;"))
        ]
    ),
    installFormatter: InitialFormatter()
)

let D2 = Command(
    code: 0x00D2,
    name: "Move bits",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [.init(name: "w", indexBit: 0, count: 1)]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([.changeableData]),
            .nnn(bitsShift, prepare: TemplateFormat("uint8_t value = reg_CL_8u;"))
        ]
    ),
    installFormatter: InitialFormatter()
)

let C0 = Command(
    code: 0x00C0,
    name: "Move bits",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [.init(name: "w", indexBit: 0, count: 1)]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([.changeableData]),
            .nnn(bitsShift, prepare: TemplateFormat("uint8_t value = read8u();"))
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendBitShiftCommand(generator: Generator) {
    generator.addCommand(D0)
    generator.addCommand(D2)
    generator.addCommand(C0)
}
