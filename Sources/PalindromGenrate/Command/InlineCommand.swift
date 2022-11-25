fileprivate let regDIInc = "reg_DI_%addressSize += %dataSize / 8;"
fileprivate let regDIDec = "reg_DI_%addressSize -= %dataSize / 8;"
fileprivate let regCIInc = "reg_SI_%addressSize += %dataSize / 8;"
fileprivate let regCIDec = "reg_SI_%addressSize -= %dataSize / 8;"

fileprivate let regCXDec = "reg_CX_%addressSize -= 1;"

fileprivate let memoryToMemoryHeader = """
uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
uint8_t* targetSegment = mem(SR_ES);
"""

fileprivate func inlineOperationIfWhile(_ function: () -> String) -> String {
    return """
    if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
    \(inlineOperationWhile({ function() }))
    } else {
    \(function())
    }
    """
}

fileprivate func inlineOperationWhile(_ function: () -> String) -> String {
    """
    while (reg_CX_%addressSize != 0) {
    \(function())
    \(regCXDec)
    }
    """
}

fileprivate func compareInlineOperationIfWhile(_ function: () -> String) -> String {
    return """
    if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
    \(compareInlineWhile({ function() }, operatorString: "=="))
    SET_FLAG(ZF, 0);
    } else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
    \(compareInlineWhile({ function() }, operatorString: "!="))
    SET_FLAG(ZF, 1);
    } else {
    SET_FLAG(ZF, %aValue == %bValue);
    \(function())
    }
    """
}

fileprivate func compareInlineWhile(_ function: () -> String, operatorString: String) -> String {
    """
    while (reg_CX_%addressSize != 0) {
    uint8_t result = %aValue \(operatorString) %bValue;
    \(function())
    \(regCXDec)
    if (result) { SET_FLAG(ZF, (1 \(operatorString) 1));  return; }
    }
    """
}

func inlineCommand(name: String, code: UInt16, prefix: String = "", dec: @escaping () -> String, inc: @escaping () -> String) -> Command {
    Command(
        code: code,
        name: name,
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
            .formatter(
                BaseFormat { info in
                    """
                    \(prefix)
                    \(memoryToMemoryHeader)
                    if (GET_FLAG(DF)) {
                    \(dec())
                    } else {
                    \(inc())
                    }
                    """
                }
                .replace("%source", to: "*(uint%dataSize_t*)(sourceSegment + reg_SI_%addressSize)")
                .replace("%target", to: "*(uint%dataSize_t*)(targetSegment + reg_DI_%addressSize)")
                .replace("%reg", to: "reg_0x00_%dataSizeu" )
            )
        ]),
        installFormatter: InitialFormatter()
    )
}

fileprivate let moveOperation = "%target = %source;"

fileprivate let moveLoop = inlineCommand(
    name: "MOVS",
    code: 0x00A4,
    dec: { inlineOperationIfWhile({ "\(moveOperation)\n\(regDIDec)\(regCIDec)\n" }) },
    inc: { inlineOperationIfWhile({ "\(moveOperation)\n\(regDIInc)\(regCIInc)\n" }) }
)

fileprivate let loadsOperation = "%reg = %source;"

fileprivate let loadsLoop = inlineCommand(
    name: "LOADS",
    code: 0x00AC,
    dec: { inlineOperationIfWhile({ "\(loadsOperation)\n\(regCIDec)\n" }) },
    inc: { inlineOperationIfWhile({ "\(loadsOperation)\n\(regCIInc)\n" }) }
)

fileprivate let stosOperation = "%target = %reg;"

fileprivate let stosLoop = inlineCommand(
    name: "STOS",
    code: 0x00AA,
    dec: { inlineOperationIfWhile({ "\(stosOperation)\n\(regDIDec)\n" }) },
    inc: { inlineOperationIfWhile({ "\(stosOperation)\n\(regDIInc)\n" }) }
)

fileprivate let scasLoop = inlineCommand(
    name: "SCAS",
    code: 0x00AE,
    prefix: "lazyFlagType = t_UNKNOWN;",
    dec: {
        compareInlineOperationIfWhile({ "\(regDIDec)\n" })
            .replacingOccurrences(of: "%aValue", with: "%target")
            .replacingOccurrences(of: "%bValue", with: "%reg")
    },
    inc: {
        compareInlineOperationIfWhile({ "\(regDIInc)\n" })
            .replacingOccurrences(of: "%aValue", with: "%target")
            .replacingOccurrences(of: "%bValue", with: "%reg")
    }
)

fileprivate let cmpsLoop = inlineCommand(
    name: "CMPS",
    code: 0x00A6,
    prefix: "lazyFlagType = t_UNKNOWN;",
    dec: {
        compareInlineOperationIfWhile({ "\(loadsOperation)\n\(regDIDec)\(regCIDec)\n" })
            .replacingOccurrences(of: "%aValue", with: "%target")
            .replacingOccurrences(of: "%bValue", with: "%source")
    },
    inc: {
        compareInlineOperationIfWhile({ "\(loadsOperation)\n\(regDIInc)\(regCIInc)\n" })
            .replacingOccurrences(of: "%aValue", with: "%target")
            .replacingOccurrences(of: "%bValue", with: "%source")
    }
)

func appendInlineCommand(generator: Generator) {
    generator.addCommand(moveLoop)
    generator.addCommand(loadsLoop)
    generator.addCommand(stosLoop)
    generator.addCommand(scasLoop)
    generator.addCommand(cmpsLoop)
}
