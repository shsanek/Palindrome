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
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) << value;"
    ]
)

let SHR = Formatter(
    customizers: [
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) >> value;"
    ]
)

let SAL = Formatter(
    customizers: [
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) << value;"
    ]
)

let SAR = Formatter(
    customizers: [
        "uint64_t tmp = ((*(int%dataSize_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + 4) = (*(uint%dataSize_t*)target);",
        "tmp = tmp >> value;",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)(((uint8_t*)&tmp) + 4));"
    ]
)

let ROL = Formatter(
    customizers: [
        "uint%2dataSize_t tmp = 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp)) = (*(uint%dataSize_t*)target);",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) = (*(uint%dataSize_t*)target);",
        "tmp = tmp << (value % %dataSize);",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)(((uint8_t*)&tmp)));"
    ]
)

let ROR = Formatter(
    customizers: [
        "uint%2dataSize_t tmp = 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp)) = (*(uint%dataSize_t*)target);",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) = (*(uint%dataSize_t*)target);",
        "tmp = tmp >> (value % %dataSize);",
        "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)(((uint8_t*)&tmp + 4)));"
    ]
)

let RCL = Formatter(
    customizers: [
        "FillFlags();",
        "uint%2dataSize_t tmp = 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) = (*(uint%dataSize_t*)target);",
        "tmp = tmp >> 1;",
        "SET_BIT((*(((uint8_t*)&tmp) + (%dataSize / 8))), 0, GET_FLAG(CF));",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp)) = (*(uint%dataSize_t*)target);",
        "SET_FLAG(CF, (*(uint%dataSize_t*)target) % 2);",
        "tmp = tmp << (value % %dataSize);",
        "(*(uint%dataSize_t*)target) = *(uint%dataSize_t*)((uint8_t*)&tmp);"
    ]
)

// SET_BIT

let RCR = Formatter(
    customizers: [
        "FillFlags();",
        "uint%2dataSize_t tmp = 0;",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp)) = (*(uint%dataSize_t*)target);",
        "tmp = tmp << 1;",
        "SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));",
        "*(uint%dataSize_t*)(((uint8_t*)&tmp) + (%dataSize / 8)) = (*(uint%dataSize_t*)target);",
        "SET_FLAG(CF, (*(int%dataSize_t*)target) < 0);",
        "tmp = tmp >> (value % %dataSize);",
        "(*(uint%dataSize_t*)target) = *(uint%dataSize_t*)((uint8_t*)&tmp + (%dataSize / 8));"
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
