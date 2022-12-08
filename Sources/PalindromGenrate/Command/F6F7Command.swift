extension Command {
    static func generateF6Command(templates: [(String, IFormatter)]) -> Command {
        return Command(
            code: 0x00F6,
            name: "Math",
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
                    .settings([.changeableData, .bigAddress]),
                    .nnn(templates.map { (code: $0.0, formatter: $0.1) } )
                ]
            ),
            installFormatter: InitialFormatter()
        )
    }
}

private let IMULTreg = BaseFormat{ info in
    if info.dataSize == 8 {
        return """
        reg_AX_16 = reg_AL_8 * (*((int8_t*)target));
        FillFlagsNoCFOF();
        SET_FLAG(ZF, reg_AL_8 == 0);
        SET_FLAG(SF, reg_AL_8 & 0x80);
        if ((reg_AX_16 & 0xff80)==0xff80 || (reg_AX_16 & 0xff80)==0x0000) {
        SET_FLAG(CF,0);SET_FLAG(OF,0);
        } else {
        SET_FLAG(CF,1);SET_FLAG(OF,1);
        }
        """
    } else if info.dataSize == 16 {
        return """
        int32_t temps=reg_AX_16 * (*((int16_t*)target));
        reg_AX_16=(uint16_t)(temps);
        reg_DX_16=(uint16_t)(temps >> 16);
        FillFlagsNoCFOF();
        SET_FLAG(ZF,reg_AX_16 == 0);
        SET_FLAG(SF,reg_AX_16 & 0x8000);
        if ((((uint32_t)temps & 0xffff8000)==0xffff8000 || ((uint32_t)temps & 0xffff8000)==0x0000)) {
        SET_FLAG(CF,0);SET_FLAG(OF,0);
        } else {
        SET_FLAG(CF,1);SET_FLAG(OF,1);
        }
        """
    } else {
        return """
        int64_t temps=((int64_t)(reg_AX_32))*((int64_t)(*(int32_t*)(target)));
        reg_AX_32=(uint32_t)(temps);
        reg_DX_32=(uint32_t)(temps >> 32);
        FillFlagsNoCFOF();
        SET_FLAG(ZF,reg_AX_32 == 0);
        SET_FLAG(SF,reg_AX_32 & 0x80000000);
        if ((reg_AX_32==0xffffffff) && (reg_AX_32 & 0x80000000) ) {
        SET_FLAG(CF,0);SET_FLAG(OF,0);
        } else if ( (reg_AX_32==0x00000000) && (reg_AX_32< 0x80000000) ) {
        SET_FLAG(CF,0);SET_FLAG(OF,0);
        } else {
        SET_FLAG(CF,1);SET_FLAG(OF,1);
        }
        """
    }
 }


private let IDIVreg = BaseFormat{ info in
    if info.dataSize == 8 {
        return """
        int16_t val= *(int8_t*)(target);
        int16_t quo= ((int16_t)reg_AX_16) / val;
        int8_t rem=(int8_t)((int16_t)reg_AX_16 % val);
        int8_t quo8s=(int8_t)(quo&0xff);
        reg_AH_8=(uint8_t)rem;
        reg_AL_8=(uint8_t)quo8s;
        FillFlags();
        SET_FLAG(ZF,(rem==0)&&((quo8s&1)!=0));
        SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
        SET_FLAG(PF,parity_lookup[rem&0xff]^parity_lookup[quo8s&0xff]^GET_FLAG(PF));
        """
    } else if info.dataSize == 16 {
        return """
        int32_t val=*(int16_t*)(target);
        int32_t num=(int32_t)(((uint32_t)reg_DX_16<<16u)|(unsigned int)reg_AX_16);
        int32_t quo=num/val;
        int16_t rem=(int16_t)(num % val);
        int16_t quo16s=(int16_t)(quo&0xffff);
        reg_DX_16u=(uint16_t)rem;
        reg_AX_16u=(uint16_t)quo16s;
        FillFlags();
        SET_FLAG(ZF,(rem==0)&&((quo16s&1)!=0));
        SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
        SET_FLAG(PF,PARITY16(rem&0xffff)^PARITY16(quo16s&0xffff)^GET_FLAG(PF));
        """
    } else {
        return """
        int64_t val=*(int32_t*)(target);
        int64_t num=(int64_t)((((uint64_t)reg_DX_32)<<(uint64_t)32)|(uint64_t)reg_AX_32);
        int64_t quo=num/val;
        int32_t rem=(int32_t)(num % val);
        int32_t quo32s=(int32_t)(quo&0xffffffff);
        reg_DX_32u=(uint32_t)rem;
        reg_AX_32u=(uint32_t)quo32s;
        FillFlags();
        SET_FLAG(ZF,(rem==0)&&((quo32s&1)!=0));
        SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
        SET_FLAG(PF,PARITY32((uint32_t)rem&0xffffffffu)^PARITY32((uint32_t)quo32s&0xffffffffu)^GET_FLAG(PF));
        """
    }
}

private let DIVreg = BaseFormat{ info in
    if info.dataSize == 8 {
        return """
        uint8_t val= *(uint8_t*)(target);
        uint16_t quo = reg_AX_16u / val;
        uint8_t rem = (uint8_t)(reg_AX_16 % val);
        uint8_t quo8 = (uint8_t)(quo&0xff);
        reg_AH_8u=rem;
        reg_AL_8u=quo8;
        FillFlags();
        SET_FLAG(ZF,(rem==0)&&((quo8&1)!=0));
        SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
        SET_FLAG(PF,parity_lookup[rem]^parity_lookup[quo8]);
        """
    } else if info.dataSize == 16 {
        return """
        uint16_t val= *(uint16_t*)(target);
        uint32_t num=((uint32_t)reg_DX_16u<<16) | reg_AX_16u;
        uint32_t quo=num/val;
        uint16_t rem=(uint16_t)(num % val);
        uint16_t quo16=(uint16_t)(quo&0xffff);
        reg_DX_16u=rem;
        reg_AX_16u=quo16;
        FillFlags();
        SET_FLAG(ZF,(rem==0)&&((quo16&1)!=0));
        SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
        SET_FLAG(PF,PARITY16(rem)^PARITY16(quo16));
        """
    } else {
        return """
        uint32_t val= *(uint32_t*)(target);
        uint64_t num=(((uint64_t)reg_DX_32u)<<32) | reg_AX_32u;
        uint64_t quo=num/val;
        uint32_t rem=(uint32_t)(num % val);
        uint32_t quo32=(uint32_t)(quo&0xffffffff);
        reg_DX_32u=rem;
        reg_AX_32u=quo32;
        FillFlags();
        SET_FLAG(ZF,(rem==0)&&((quo32&1)!=0));
        SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
        SET_FLAG(PF,PARITY32(rem)^PARITY32(quo32));
        """
    }
}

private let MULTreg = BaseFormat{ info in
    if info.dataSize == 8 {
        return """
        reg_AX_16u=((uint16_t)reg_AL_8u)*((uint16_t)(*(uint8_t*)target));
        FillFlagsNoCFOF();
        SET_FLAG(ZF,reg_AL_8 == 0);
        SET_FLAG(PF,PARITY16(reg_AX_16));
        if (reg_AX_16 & 0xff00) {
        SET_FLAG(CF,1);SET_FLAG(OF,1);
        } else {
        SET_FLAG(CF,0);SET_FLAG(OF,0);
        }
        """
    } else if info.dataSize == 16 {
        return """
        uint32_t tempu=((uint32_t)reg_AX_16u)*(uint32_t)(*(uint16_t*)(target));
        reg_AX_16=(uint16_t)(tempu);
        reg_DX_16=(uint16_t)(tempu >> 16);
        FillFlagsNoCFOF();
        SET_FLAG(ZF,reg_AX_16 == 0);
        SET_FLAG(PF,PARITY16(reg_AX_16)^PARITY16(reg_DX_16));
        if (reg_DX_16) {
        SET_FLAG(CF,1);SET_FLAG(OF,1);
        } else {
        SET_FLAG(CF,0);SET_FLAG(OF,0);
        }
        """
    } else {
        return """
        uint64_t tempu=((uint64_t)reg_AX_32u)*((uint64_t)(*(uint32_t*)(target)));
        reg_AX_32=(uint32_t)(tempu);
        reg_DX_32=(uint32_t)(tempu >> 32);
        FillFlagsNoCFOF();
        SET_FLAG(ZF,reg_AX_32 == 0);
        SET_FLAG(PF,PARITY32(reg_AX_32)^PARITY32(reg_DX_32));
        if (reg_DX_32) {
        SET_FLAG(CF,1);SET_FLAG(OF,1);
        } else {
        SET_FLAG(CF,0);SET_FLAG(OF,0);
        }
        """
    }
 }

func appendF6F7Command(generator: Generator) {
    let command = Command.generateF6Command(templates: [
        ("0x00", TemplateFormat("""
        // TEST
        LazyFlagVarA%dataSize = *(int%dataSize_t*)target;
        LazyFlagVarB%dataSize = read%operandSize();
        LazyFlagResultContainer%dataSize = LazyFlagVarA%dataSize & ((%signint%operandSize_t)LazyFlagVarB%dataSize);
        lazyFlagType = t_TEST%dataSize;
        """)),
        ("0x02", TemplateFormat("""
        // NOT
        *(int%dataSize_t*)target = ~(*(int%dataSize_t*)target);
        """)),
        ("0x03", TemplateFormat("""
        // NEG
        LazyFlagVarA%dataSize = *(int%dataSize_t*)target;
        LazyFlagResultContainer%dataSize = 0 - LazyFlagVarA%dataSize;
        *(int%dataSize_t*)target = LazyFlagResultContainer%dataSize;
        lazyFlagType = t_NEG%dataSize;
        """)),
        ("0x04", MULTreg),
        ("0x05", IMULTreg),
        ("0x06", DIVreg),
        ("0x07", IDIVreg)
    ])

    generator.addCommand(command)
}
