let moveLoop = Command(
    code: 0x00A4,
    name: "MOVS",
    format: .init(
        hasPrefixAddress: true,
        hasPrefixData: true,
        inlines: [.init(name: "w", indexBit: 0, count: 1)]
    ),
    functionFormatter: Formatter(customizers: [
        .prefixData,
        .prefixAddress,
        .functionName,
        .settings([.changeableData, .bigAddress]),
        "uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;",
        "sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);",
        "uint8_t* targetSegment = mem(SR_ES);",
        .formatter(BaseFormat { info in
            """
            if (GET_FLAG(DF)) {
            \(moveOperationIfWhile({ "\(moveOperation)\n\(moveOperationDec)\n\(moveOperationCXDec)\n" }))
            } else {
            \(moveOperationIfWhile({ "\(moveOperation)\n\(moveOperationInc)\n\(moveOperationCXDec)\n" }))
            }
            """
        })

    ]),
    installFormatter: InitialFormatter()
)

fileprivate let moveOperation = "*(uint%dataSize_t*)(targetSegment + reg_DI_%addressSize) = *(uint%dataSize_t*)(sourceSegment + reg_SI_%addressSize);"
fileprivate let moveOperationInc = "reg_DI_%addressSize += %dataSize / 8; reg_SI_%addressSize += %dataSize / 8;"
fileprivate let moveOperationDec = "reg_DI_%addressSize -= %dataSize / 8; reg_SI_%addressSize -= %dataSize / 8;"
fileprivate let moveOperationCXDec = "reg_CX_%addressSize -= 1;"

fileprivate func moveOperationIfWhile(_ function: () -> String) -> String {
    return """
    if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
    \(operationWhile({ function() }))
    } else {
    \(function())
    }
    """
}

fileprivate func operationWhile(_ function: () -> String) -> String {
    """
    while (reg_CX_%addressSize != 0) {
    \(function())
    }
    """
}

private let loadsOperation = "reg_0x00_%dataSizeu= *(uint%dataSize_t*)(sourceSegment + reg_SI_%addressSize);"
private let loadsInc = "reg_SI_%addressSize += %dataSize / 8;"
private let loadsDec = "reg_SI_%addressSize -= %dataSize / 8;"

let loadsLoop = Command(
    code: 0x00AC,
    name: "MOVS",
    format: .init(
        hasPrefixAddress: true,
        hasPrefixData: true,
        inlines: [.init(name: "w", indexBit: 0, count: 1)]
    ),
    functionFormatter: Formatter(customizers: [
        .prefixData,
        .prefixAddress,
        .functionName,
        .settings([.changeableData, .bigAddress]),
        "uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;",
        "sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);",
        "uint8_t* targetSegment = mem(SR_ES);",
        .formatter(BaseFormat { info in
            """
            if (GET_FLAG(DF)) {
            \(moveOperationIfWhile({ "\(loadsOperation)\n\(loadsDec)\n\(moveOperationCXDec)\n" }))
            } else {
            \(moveOperationIfWhile({ "\(loadsOperation)\n\(loadsInc)\n\(moveOperationCXDec)\n" }))
            }
            """
        })

    ]),
    installFormatter: InitialFormatter()
)

fileprivate let stosOperation = "*(uint%dataSize_t*)(targetSegment + reg_DI_%addressSize) = reg_0x00_%dataSizeu;"
fileprivate let stosOperationInc = "reg_DI_%addressSize += %dataSize / 8;"
fileprivate let stosOperationDec = "reg_DI_%addressSize -= %dataSize / 8;"

let stosLoop = Command(
    code: 0x00AA,
    name: "MOVS",
    format: .init(
        hasPrefixAddress: true,
        hasPrefixData: true,
        inlines: [.init(name: "w", indexBit: 0, count: 1)]
    ),
    functionFormatter: Formatter(customizers: [
        .prefixData,
        .prefixAddress,
        .functionName,
        .settings([.changeableData, .bigAddress]),
        "uint8_t* targetSegment = mem(SR_ES);",
        .formatter(BaseFormat { info in
            """
            if (GET_FLAG(DF)) {
            \(moveOperationIfWhile({ "\(stosOperation)\n\(stosOperationDec)\n\(moveOperationCXDec)\n" }))
            } else {
            \(moveOperationIfWhile({ "\(stosOperation)\n\(stosOperationInc)\n\(moveOperationCXDec)\n" }))
            }
            """
        })

    ]),
    installFormatter: InitialFormatter()
)

func appendInlineCommand(generator: Generator) {
    generator.addCommand(moveLoop)
    generator.addCommand(loadsLoop)
    generator.addCommand(stosLoop)
}
