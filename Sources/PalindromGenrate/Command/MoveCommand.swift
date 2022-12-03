fileprivate let moveMRMCommand = Command(
    code: 0x0088,
    name: "Move",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [
            .init(name: "w", indexBit: 0, count: 1),
            .init(name: "d", indexBit: 1, count: 1)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([.changeableData, .bigAddress]),
            .mrm,
            "*(%dataType*)target = *(%dataType*)source;"
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let moveDataCommand = Command(
    code: 0x00B0,
    name: "Move",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [
            .init(name: "w", indexBit: 3, count: 1),
            .init(name: "reg", indexBit: 0, count: 3)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([.changeableData]),
            "reg_%reg_%dataSizeu = read%dataSizeu();"
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let moveDataToMemoryCommand = Command(
    code: 0x00C6,
    name: "Move",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [
            .init(name: "w", indexBit: 0, count: 1)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .mrm,
            .settings([.changeableData]),
            "*(uint%dataSize_t*)target = read%dataSizeu();"
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let moveBEMoveCommand = Command(
    code: 0x01BE,
    name: "MOVSX",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([.bigData]),
            "uint8_t mrmByte = read8u();",
            "int%dataSize_t* target = (int%dataSize_t*)readRegisterMRM%dataSize(mrmByte);",
            "int8_t* source = (int8_t*)readAddressMRM32For8(mrmByte);",
            "*target = (int%dataSize_t)*source;"
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let moveBFMoveCommand = Command(
    code: 0x01BF,
    name: "MOVSX",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .settings([]),
            "uint8_t mrmByte = read8u();",
            "int32_t* target = (int32_t*)readRegisterMRM32(mrmByte);",
            "int16_t* source = (int16_t*)readAddressMRM32For16(mrmByte);",
            "*target = (int32_t)*source;"
        ]
    ),
    installFormatter: InitialFormatter()
)


fileprivate let moveB6MoveCommand = Command(
    code: 0x01B6,
    name: "MOVZX",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([.bigData]),
            "uint8_t mrmByte = read8u();",
            "uint%dataSize_t* target = (uint%dataSize_t*)readRegisterMRM%dataSize(mrmByte);",
            "uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);",
            "*target = (uint%dataSize_t)*source;"
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let moveB7MoveCommand = Command(
    code: 0x01B7,
    name: "MOVZX",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([]),
            "uint8_t mrmByte = read8u();",
            "uint32_t* target = (uint32_t*)readRegisterMRM32(mrmByte);",
            "uint16_t* source = (uint16_t*)readAddressMRM32For16(mrmByte);",
            "*target = (uint32_t)*source;"
        ]
    ),
    installFormatter: InitialFormatter()
)


fileprivate let move98MoveCommand = Command(
    code: 0x98,
    name: "CBW",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([]),
            .formatter(BaseFormat({ info in
                if info.mode == .mod32 {
                    if info.prefixs.contains(.dataSizePrefix) {
                        return "reg_AX_16 = reg_AL_8;"
                    } else {
                        return "reg_AX_32 = reg_AX_16;"
                    }
                } else {
                    if !info.prefixs.contains(.dataSizePrefix) {
                        return "reg_AX_16 = reg_AL_8;"
                    } else {
                        return "reg_AX_32 = reg_AX_16;"
                    }
                }
            }))
        ]
    ),
    installFormatter: InitialFormatter()
)

// if (reg_ax & 0x8000) reg_dx=0xffff;else reg_dx=0;
// if (reg_eax & 0x80000000) reg_edx=0xffffffff; else reg_edx=0;
fileprivate let move99MoveCommand = Command(
    code: 0x99,
    name: "CBW",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .functionName,
            .settings([]),
            .formatter(BaseFormat({ info in
                if info.mode == .mod32 {
                    if info.prefixs.contains(.dataSizePrefix) {
                        return "if (reg_AX_16 & 0x8000) reg_DX_16=0xffff;else reg_DX_16=0;"
                    } else {
                        return "if (reg_AX_32 & 0x80000000) reg_DX_32=0xffffffff; else reg_DX_32=0;"
                    }
                } else {
                    if !info.prefixs.contains(.dataSizePrefix) {
                        return "if (reg_AX_16 & 0x8000) reg_DX_16=0xffff;else reg_DX_16=0;"
                    } else {
                        return "if (reg_AX_32 & 0x80000000) reg_DX_32=0xffffffff; else reg_DX_32=0;"
                    }
                }
            }))
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let moveSegmentRegisterCommand = Command(
    code: 0x008C,
    name: "Move",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: [
            .init(name: "SEGMENT", indexBit: 0, count: 1, value: "true"),
            .init(name: "d", indexBit: 1, count: 1)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .mrm,
            .settings([.fixData(16)]),
            "*(uint%dataSize_t*)target = *(uint%dataSize_t*)source;",
            ""
        ]
    ),
    installFormatter: InitialFormatter()
)

fileprivate let moveACommand = Command(
    code: 0x00A0,
    name: "Move",
    format: .init(
        hasPrefixAddress: true,
        hasPrefixData: true,
        inlines: [
            .init(name: "w", indexBit: 0, count: 1),
            .init(name: "d", indexBit: 1, count: 1)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [
            .prefixData,
            .prefixAddress,
            .functionName,
            .settings([.changeableData, .bigAddress]),
            .formatter(DestFormatter {
                BaseFormat { info in
                    """
                    uint%dataSize_t* target = (uint%dataSize_t*)register%dataSizeu(BR_AX);
                    uint%dataSize_t* source = (uint%dataSize_t*)(GET_SEGMENT_POINTER_WITH_REPLACE(SR_DS) + read%addressSize());
                    """
                }
            }),
            "*(uint%dataSize_t*)target = *(uint%dataSize_t*)source;"
        ]
    ),
    installFormatter: InitialFormatter()
)

private func makeLoadMemorySegmentRegister(code: UInt16, reg: String) -> Command {
    Command(
        code: code,
        name: "Load \(reg)",
        format: .init(
            hasPrefixAddress: false,
            hasPrefixData: false,
            inlines: []
        ),
        functionFormatter: Formatter(
            customizers: [
                .functionName,
                .mrm,
                .template("SET_VALUE_IN_SEGMENT(\(reg), *(uint16_t*)(target + 2));"),
                "*(uint%MOD_t*)source = *(uint%MOD_t*)(target);"
            ]
        ),
        installFormatter: InitialFormatter()
    )
}


func appendMoveCommand(generator: Generator) {
    generator.addCommand(moveMRMCommand)
    generator.addCommand(moveDataCommand)
    generator.addCommand(moveDataToMemoryCommand)

    generator.addCommand(moveB7MoveCommand)
    generator.addCommand(moveB6MoveCommand)
    generator.addCommand(moveBFMoveCommand)
    generator.addCommand(moveBEMoveCommand)

    generator.addCommand(move98MoveCommand)
    generator.addCommand(move99MoveCommand)

    generator.addCommand(moveACommand)

    generator.addCommand(moveSegmentRegisterCommand)

    generator.addCommand(makeLoadMemorySegmentRegister(code: 0x00C4, reg: "SR_ES"))
    generator.addCommand(makeLoadMemorySegmentRegister(code: 0x00C5, reg: "SR_DS"))
    generator.addCommand(makeLoadMemorySegmentRegister(code: 0x01B2, reg: "SR_SS"))
    generator.addCommand(makeLoadMemorySegmentRegister(code: 0x01B4, reg: "SR_FS"))
    generator.addCommand(makeLoadMemorySegmentRegister(code: 0x01B5, reg: "SR_GS"))
}
