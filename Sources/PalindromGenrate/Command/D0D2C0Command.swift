// D0D2C0

///000   ROL
//      /001   ROR
//      /010   RCL
//      /011   RCR
//      /100   SHL/SAL
//      /101   SHR
//      /110   (----)
//      /111   SAR


let SHL = Formatter(
    customizers: [
        "LazyFlagVarB8 = value;",
        "LazyFlagVarA%dataSize = (*(uint%dataSize_t*)target);",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) << value;",
        "LazyFlagResultContainer%dataSize = (*(uint%dataSize_t*)target);",
        "lazyFlagType = t_SHL%dataSize;"
    ]
)

let SHR = Formatter(
    customizers: [
        "LazyFlagVarB8 = value;",
        "LazyFlagVarA%dataSize = (*(uint%dataSize_t*)target);",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) >> value;",
        "LazyFlagResultContainer%dataSize = (*(uint%dataSize_t*)target);",
        "lazyFlagType = t_SHR%dataSize;"
    ]
)

let SAL = Formatter(
    customizers: [
        "LazyFlagVarB8 = value;",
        "LazyFlagVarA%dataSize = (*(uint%dataSize_t*)target);",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) << value;",
        "LazyFlagResultContainer%dataSize = (*(uint%dataSize_t*)target);",
        "lazyFlagType = t_SHL%dataSize;"
    ]
)

let SAR = Formatter(
    customizers: [
        "LazyFlagVarB8 = value;",
        "LazyFlagVarA%dataSize = (*(uint%dataSize_t*)target);",
        "uint64_t tmp = ((*(int%dataSize_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + 4) = (*(uint%dataSize_t*)target);",
        "tmp = tmp >> value;",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)(((uint8_t*)&tmp) + 4));",
        "LazyFlagResultContainer%dataSize = (*(uint%dataSize_t*)target);",
        "lazyFlagType = t_SAR%dataSize;"
    ]
)

let ROL = Formatter(
    customizers: [
        "LazyFlagVarB8 = value;",
        "LazyFlagVarA%dataSize = (*(uint%dataSize_t*)target);",
        "uint%2dataSize_t tmp = 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp)) = (*(uint%dataSize_t*)target);",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) = (*(uint%dataSize_t*)target);",
        "tmp = tmp << (value % %dataSize);",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)(((uint8_t*)&tmp)));",
        "LazyFlagResultContainer%dataSize = (*(uint%dataSize_t*)target);",
        "lazyFlagType = t_ROL%dataSize;"
    ]
)

let ROR = Formatter(
    customizers: [
        "LazyFlagVarB8 = value;",
        "LazyFlagVarA%dataSize = (*(uint%dataSize_t*)target);",
        "uint%2dataSize_t tmp = 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp)) = (*(uint%dataSize_t*)target);",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) = (*(uint%dataSize_t*)target);",
        "tmp = tmp >> (value % %dataSize);",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)(((uint8_t*)&tmp + 4)));",
        "LazyFlagResultContainer%dataSize = (*(uint%dataSize_t*)target);",
        "lazyFlagType = t_ROR%dataSize;"
    ]
)

let RCL = Formatter(
    customizers: [
        "FillFlags();",
        "LazyFlagVarB8 = value;",
        "LazyFlagVarA%dataSize = (*(uint%dataSize_t*)target);",
        "uint%2dataSize_t tmp = 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) = (*(uint%dataSize_t*)target);",
        "tmp = tmp >> 1;",
        "SET_BIT((*(((uint8_t*)&tmp) + (%dataSize / 8))), 0, GET_FLAG(CF));",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp)) = (*(uint%dataSize_t*)target);",
        "tmp = tmp << (value % %dataSize);",
        "(*(uint%dataSize_t*)target) = *(uint%dataSize_t*)((uint8_t*)&tmp);",
        "LazyFlagResultContainer%dataSize = (*(uint%dataSize_t*)target);",
        "lazyFlagType = t_RCL%dataSize;"
    ]
)

// SET_BIT

let RCR = Formatter(
    customizers: [
        "FillFlags();",
        "LazyFlagVarB8 = value;",
        "LazyFlagVarA%dataSize = (*(uint%dataSize_t*)target);",
        "uint%dataSize_t tmp = 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp)) = (*(uint%dataSize_t*)target);",
        "tmp = tmp << 1;",
        "SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) = (*(uint%dataSize_t*)target);",
        "tmp = tmp >> (value % %dataSize);",
        "(*(uint%dataSize_t*)target) = *(uint%dataSize_t*)((uint8_t*)&tmp + (%dataSize / 8));",
        "LazyFlagResultContainer%dataSize = (*(uint%dataSize_t*)target);",
        "lazyFlagType = t_RCR%dataSize;"
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
