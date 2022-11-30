fileprivate func bitScanCommand(code: UInt16, name: String, direction: Bool) -> Command {
    let directionMask = direction ? "1 << (%dataSize - 1)" : "1"
    let directionOperand = direction ? "<<" : ">>"
    return Command(
        code: code,
        name: name,
        format: .init(hasPrefixAddress: false, hasPrefixData: true, inlines: []),
        functionFormatter: Formatter(
            customizers: [
                .prefixData,
                .functionName,
                .settings([.bigData]),
                .mrm,
                "FillFlags();",
                "uint%dataSize_t value = *(uint%dataSize_t*)source;",
                "if (value == 0) { SET_FLAG(ZF, 0); return; }",
                .template("uint%dataSize_t mask = \(directionMask);"),
                "uint%dataSize_t len = 0;",
                "while ((mask & value) && (len < %dataSize)) {",
                .template("value = value \(directionOperand) 1;"),
                "len++;",
                "}",
                "SET_FLAG(ZF, 1);",
                "*(uint%dataSize_t*)target = len;"
            ]
        ),
        installFormatter: InitialFormatter()
    )
}

fileprivate enum BitCommandAdditionOperation: String {
    case invert = "BTC"
    case nop = "BT"
    case one = "BTS"
    case zero = "BTR"
}

fileprivate func getBitCommand(operation: BitCommandAdditionOperation) -> IFormatter {
    let additionOperation: String
    switch operation {
    case .invert:
        additionOperation = """
        if (value) {
        (*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) & (~mask);
        } else {
        (*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) | mask;
        }
        """
    case .nop:
        additionOperation = ""
    case .one:
        additionOperation = "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) | mask;"
    case .zero:
        additionOperation = "(*(uint%dataSize_t*)target) = (*(uint%dataSize_t*)target) & (~mask);"
    }
    return Formatter(customizers: [
        .template("// \(operation.rawValue)"),
        "FillFlags();",
        "uint%dataSize_t mask = 1 << shift;",
        "uint8_t value = ((*(uint%dataSize_t*)target) & mask) ? 1 : 0;",
        "SET_FLAG(CF, value);",
        .template(additionOperation)
    ])
}

fileprivate func nnnFormatBitCommand(
    code: String,
    operation: BitCommandAdditionOperation
) -> (code: String, formatter: IFormatter) {
    (
        code: code,
        formatter: Formatter(
            customizers: [
                "uint8_t shift = read8u();",
                .formatter(
                    getBitCommand(
                        operation: operation
                    )
                )
            ]
        )
    )
}

fileprivate let command0FBA = Command(
    code: 0x01BA,
    name: "Bit scan",
    format: CommandFormat(hasPrefixAddress: false, hasPrefixData: true, inlines: []),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .nnn([
                nnnFormatBitCommand(code: "0x4", operation: .nop),
                nnnFormatBitCommand(code: "0x5", operation: .one),
                nnnFormatBitCommand(code: "0x6", operation: .zero),
                nnnFormatBitCommand(code: "0x7", operation: .invert)
            ])
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate func mrmFormatBitCommand(
    code: UInt16,
    operation: BitCommandAdditionOperation
) -> Command {
    Command(
        code: code,
        name: operation.rawValue,
        format: CommandFormat(hasPrefixAddress: false, hasPrefixData: true, inlines: []),
        functionFormatter: Formatter(customizers: [
            .prefixData,
            .functionName,
            .mrm,
            "uint%dataSize_t shift = *(uint%dataSize_t*)source;",
            .formatter(getBitCommand(operation: operation))
        ]),
        installFormatter: InitialFormatter()
    )
}

func appendBitScanCommand(generator: Generator) {
    generator.addCommand(bitScanCommand(code: 0x01BC, name: "BFC", direction: false))
    generator.addCommand(bitScanCommand(code: 0x01BD, name: "BSR", direction: true))

    generator.addCommand(command0FBA)

    generator.addCommand(mrmFormatBitCommand(code: 0x01A3, operation: .nop))
    generator.addCommand(mrmFormatBitCommand(code: 0x01AB, operation: .one))
    generator.addCommand(mrmFormatBitCommand(code: 0x01B3, operation: .zero))
    generator.addCommand(mrmFormatBitCommand(code: 0x01BB, operation: .invert))
}
