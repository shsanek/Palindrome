let SHL = Formatter(
    customizers: [
        "if (value == 0) { return; }",
        "",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) << (value - 1);",
        "SET_FLAG(CF, (*(uint%dataSize_t*)target) & %firstBitMask);",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) << 1;",
        "",
        "LazyFlagResultContainer%dataSize = (*(uint%dataSize_t*)target);",
        "if (value == 1) { SET_FLAG(OF, (((*(uint%dataSize_t*)target) & %firstBitMask) ? 1 : 0) ^ CF); }",
        "lazyFlagType = t_VALUE%dataSize;"
    ]
)

let SHR = Formatter(
    customizers: [
        "if (value == 0) { return; }",
        "",
        "if (value == 1) { SET_FLAG(OF, (*(uint%dataSize_t*)target) & %firstBitMask) };",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) >> (value % %dataSize - 1);",
        "SET_FLAG(CF, (*(uint%dataSize_t*)target) & 1);",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) >> 1;",
        "",
        "LazyFlagResultContainer%dataSize = (*(uint%dataSize_t*)target);",
        "lazyFlagType = t_VALUE%dataSize;"
    ]
)

let SAL = SHL

let SAR = Formatter(
    customizers: [
        "if (value == 0) { return; }",
        "",
        "uint64_t tmp = ((*(int%dataSize_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + 4) = (*(uint%dataSize_t*)target);",
        "",
        "tmp = tmp >> (value % %dataSize - 1);",
        "SET_FLAG(CF, tmp & 1);",
        "tmp = tmp >> 1;",
        "",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)(((uint8_t*)&tmp) + 4));",
        "",
        "SET_FLAG(OF, 0);",
        "LazyFlagResultContainer%dataSize = (*(uint%dataSize_t*)target);",
        "lazyFlagType = t_VALUE%dataSize;"
    ]
)

//
let ROL = Formatter(
    customizers: [
        "if (value == 0) { return; }",
        "FillFlags();",
        "",
        "uint%2dataSize_t tmp = 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp)) = (*(uint%dataSize_t*)target);",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) = (*(uint%dataSize_t*)target);",
        "",
        "SET_FLAG(CF, (tmp << (value % %dataSize + %dataSize - 1)) & %firstBitMask);",
        "tmp = tmp << (value % %dataSize);",
        "",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)(((uint8_t*)&tmp)));",
        "if (value == 1) { SET_FLAG(OF, (((*(uint%dataSize_t*)target) & %firstBitMask) ? 1 : 0) ^ CF); }",
        ""
    ]
)

let ROR = Formatter(
    customizers: [
        "if (value == 0) { return; }",
        "FillFlags();",
        "if (value == 1) { SET_FLAG(OF, (((*(uint%dataSize_t*)target) & %firstBitMask) ? 1 : 0) ^ CF); }",
        "",
        "uint%2dataSize_t tmp = 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp)) = (*(uint%dataSize_t*)target);",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) = (*(uint%dataSize_t*)target);",
        "",
        "tmp = tmp >> (value % %dataSize - 1);",
        "SET_FLAG(CF, tmp & 1);",
        "tmp = tmp >> 1;",
        "",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)(((uint8_t*)&tmp + 4)));",
        ""
    ]
)

let RCL = Formatter(
    customizers: [
        "if (value == 0) { return; }",
        "FillFlags();",
        "",
        "uint%2dataSize_t tmp = 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) = (*(uint%dataSize_t*)target);",
        "tmp = tmp >> 1;",
        "uint%dataSize_t mask = GET_FLAG(CF);",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) |= mask;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp)) = (*(uint%dataSize_t*)target);",
        "",
        "SET_FLAG(CF, (tmp << (value % (%dataSize + 1) + %dataSize)) & %firstBitMask);",
        "tmp = tmp << ((value % (%dataSize + 1)));",
        "",
        "(*(uint%dataSize_t*)target) = *(uint%dataSize_t*)((uint8_t*)&tmp);",
        "if (value == 1) { SET_FLAG(OF, (((*(uint%dataSize_t*)target) & %firstBitMask) ? 1 : 0) ^ CF); }",
        ""
    ]
)

// SET_BIT

let RCR = Formatter(
    customizers: [
        "if (value == 0) { return; }",
        "FillFlags();",
        "",
        "if (value == 1) { SET_FLAG(OF, (((*(uint%dataSize_t*)target) & %firstBitMask) ? 1 : 0) ^ CF); }",
        "",
        "uint%dataSize_t tmp = 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp)) = (*(uint%dataSize_t*)target);",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) = GET_FLAG(CF);",
        "tmp = tmp << 1;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) = (*(uint%dataSize_t*)target);",
        "",
        "tmp = tmp >> ((value % (%dataSize + 1)) - 1);",
        "SET_FLAG(CF, tmp & 1);",
        "tmp = tmp >> 1;",
        "",
        "(*(uint%dataSize_t*)target) = *(uint%dataSize_t*)((uint8_t*)&tmp + (%dataSize / 8));",
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
            .nnn(bitsShift, prepare: TemplateFormat("uint8_t value = reg_CL_8u & 0x1F;"))
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
            .nnn(bitsShift, prepare: TemplateFormat("uint8_t value = read8u() & 0x1F;"))
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendBitShiftCommand(generator: Generator) {
    generator.addCommand(D0)
    generator.addCommand(D2)
    generator.addCommand(C0)
}
