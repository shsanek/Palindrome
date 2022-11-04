#include "GenerateFunctions.h"
void handlerCommand16Code0(Context *context) {
	uint8_t mrmByte = read8u(context);
	uint8_t* target = (uint8_t*)readAddressMRM16(context, mrmByte);;
	uint8_t* source = (uint8_t*)readRegisterMRM8(context, mrmByte);;
	*(uint8_t*)target += *(uint8_t*)source;
}
void handlerCommand16Code1(Context *context) {
	uint8_t mrmByte = read8u(context);
	uint16_t* target = (uint16_t*)readAddressMRM16(context, mrmByte);;
	uint16_t* source = (uint16_t*)readRegisterMRM16(context, mrmByte);;
	*(uint16_t*)target += *(uint16_t*)source;
}
void handlerCommand16Code2(Context *context) {
	uint8_t mrmByte = read8u(context);
	uint8_t* source = (uint8_t*)readAddressMRM16(context, mrmByte);;
	uint8_t* target = (uint8_t*)readRegisterMRM8(context, mrmByte);;
	*(uint8_t*)target += *(uint8_t*)source;
}
void handlerCommand16Code3(Context *context) {
	uint8_t mrmByte = read8u(context);
	uint16_t* source = (uint16_t*)readAddressMRM16(context, mrmByte);;
	uint16_t* target = (uint16_t*)readRegisterMRM16(context, mrmByte);;
	*(uint16_t*)target += *(uint16_t*)source;
}
void handlerCommand16Code136(Context *context) {
	uint8_t mrmByte = read8u(context);
	uint8_t* target = (uint8_t*)readAddressMRM16(context, mrmByte);;
	uint8_t* source = (uint8_t*)readRegisterMRM8(context, mrmByte);;
	*(uint8_t*)target = *(uint8_t*)source;
}
void handlerCommand16Code137(Context *context) {
	uint8_t mrmByte = read8u(context);
	uint16_t* target = (uint16_t*)readAddressMRM16(context, mrmByte);;
	uint16_t* source = (uint16_t*)readRegisterMRM16(context, mrmByte);;
	*(uint16_t*)target = *(uint16_t*)source;
}
void handlerCommand16Code138(Context *context) {
	uint8_t mrmByte = read8u(context);
	uint8_t* source = (uint8_t*)readAddressMRM16(context, mrmByte);;
	uint8_t* target = (uint8_t*)readRegisterMRM8(context, mrmByte);;
	*(uint8_t*)target = *(uint8_t*)source;
}
void handlerCommand16Code139(Context *context) {
	uint8_t mrmByte = read8u(context);
	uint16_t* source = (uint16_t*)readAddressMRM16(context, mrmByte);;
	uint16_t* target = (uint16_t*)readRegisterMRM16(context, mrmByte);;
	*(uint16_t*)target = *(uint16_t*)source;
}
void handlerCommand16Code176(Context *context) {
	uint8_t reg = 0x00;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand16Code177(Context *context) {
	uint8_t reg = 0x01;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand16Code178(Context *context) {
	uint8_t reg = 0x02;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand16Code179(Context *context) {
	uint8_t reg = 0x03;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand16Code180(Context *context) {
	uint8_t reg = 0x04;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand16Code181(Context *context) {
	uint8_t reg = 0x05;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand16Code182(Context *context) {
	uint8_t reg = 0x06;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand16Code183(Context *context) {
	uint8_t reg = 0x07;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand16Code184(Context *context) {
	uint8_t reg = 0x00;
	*register16u(context, reg) = read16u(context);
}
void handlerCommand16Code185(Context *context) {
	uint8_t reg = 0x01;
	*register16u(context, reg) = read16u(context);
}
void handlerCommand16Code186(Context *context) {
	uint8_t reg = 0x02;
	*register16u(context, reg) = read16u(context);
}
void handlerCommand16Code187(Context *context) {
	uint8_t reg = 0x03;
	*register16u(context, reg) = read16u(context);
}
void handlerCommand16Code188(Context *context) {
	uint8_t reg = 0x04;
	*register16u(context, reg) = read16u(context);
}
void handlerCommand16Code189(Context *context) {
	uint8_t reg = 0x05;
	*register16u(context, reg) = read16u(context);
}
void handlerCommand16Code190(Context *context) {
	uint8_t reg = 0x06;
	*register16u(context, reg) = read16u(context);
}
void handlerCommand16Code191(Context *context) {
	uint8_t reg = 0x07;
	*register16u(context, reg) = read16u(context);
}
void handlerCommand16Code64(Context *context) {
	uint8_t reg = 0x00;
	*register16u(context, reg) += 1;
}
void handlerCommand16Code65(Context *context) {
	uint8_t reg = 0x01;
	*register16u(context, reg) += 1;
}
void handlerCommand16Code66(Context *context) {
	uint8_t reg = 0x02;
	*register16u(context, reg) += 1;
}
void handlerCommand16Code67(Context *context) {
	uint8_t reg = 0x03;
	*register16u(context, reg) += 1;
}
void handlerCommand16Code68(Context *context) {
	uint8_t reg = 0x04;
	*register16u(context, reg) += 1;
}
void handlerCommand16Code69(Context *context) {
	uint8_t reg = 0x05;
	*register16u(context, reg) += 1;
}
void handlerCommand16Code70(Context *context) {
	uint8_t reg = 0x06;
	*register16u(context, reg) += 1;
}
void handlerCommand16Code71(Context *context) {
	uint8_t reg = 0x07;
	*register16u(context, reg) += 1;
}
void handlerCommand16Code72(Context *context) {
	uint8_t reg = 0x00;
	*register16u(context, reg) -= 1;
}
void handlerCommand16Code73(Context *context) {
	uint8_t reg = 0x01;
	*register16u(context, reg) -= 1;
}
void handlerCommand16Code74(Context *context) {
	uint8_t reg = 0x02;
	*register16u(context, reg) -= 1;
}
void handlerCommand16Code75(Context *context) {
	uint8_t reg = 0x03;
	*register16u(context, reg) -= 1;
}
void handlerCommand16Code76(Context *context) {
	uint8_t reg = 0x04;
	*register16u(context, reg) -= 1;
}
void handlerCommand16Code77(Context *context) {
	uint8_t reg = 0x05;
	*register16u(context, reg) -= 1;
}
void handlerCommand16Code78(Context *context) {
	uint8_t reg = 0x06;
	*register16u(context, reg) -= 1;
}
void handlerCommand16Code79(Context *context) {
	uint8_t reg = 0x07;
	*register16u(context, reg) -= 1;
}
void handlerCommand16Code226(Context *context) {
	int8_t addr = read8(context);
	uint16_t* reg = register16u(context, BR_CX);
	*reg -= 1;
	if (*reg != 0) {
		context->index += addr;
	}
}
void handlerCommand16Code205(Context *context) {
	uint8_t addr = read8u(context);
	context->functions[addr](context, addr);
}
void handlerCommand16Code80(Context *context) {
	uint8_t reg = 0x00;
	uint16_t* sp = register16u(context, BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
}
void handlerCommand16Code81(Context *context) {
	uint8_t reg = 0x01;
	uint16_t* sp = register16u(context, BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
}
void handlerCommand16Code82(Context *context) {
	uint8_t reg = 0x02;
	uint16_t* sp = register16u(context, BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
}
void handlerCommand16Code83(Context *context) {
	uint8_t reg = 0x03;
	uint16_t* sp = register16u(context, BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
}
void handlerCommand16Code84(Context *context) {
	uint8_t reg = 0x04;
	uint16_t* sp = register16u(context, BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
}
void handlerCommand16Code85(Context *context) {
	uint8_t reg = 0x05;
	uint16_t* sp = register16u(context, BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
}
void handlerCommand16Code86(Context *context) {
	uint8_t reg = 0x06;
	uint16_t* sp = register16u(context, BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
}
void handlerCommand16Code87(Context *context) {
	uint8_t reg = 0x07;
	uint16_t* sp = register16u(context, BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
}
void handlerCommand16Code88(Context *context) {
	uint8_t reg = 0x00;
	uint16_t* sp = register16u(context, BR_SP);
	*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
	*sp += 16 / 8;
}
void handlerCommand16Code89(Context *context) {
	uint8_t reg = 0x01;
	uint16_t* sp = register16u(context, BR_SP);
	*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
	*sp += 16 / 8;
}
void handlerCommand16Code90(Context *context) {
	uint8_t reg = 0x02;
	uint16_t* sp = register16u(context, BR_SP);
	*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
	*sp += 16 / 8;
}
void handlerCommand16Code91(Context *context) {
	uint8_t reg = 0x03;
	uint16_t* sp = register16u(context, BR_SP);
	*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
	*sp += 16 / 8;
}
void handlerCommand16Code92(Context *context) {
	uint8_t reg = 0x04;
	uint16_t* sp = register16u(context, BR_SP);
	*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
	*sp += 16 / 8;
}
void handlerCommand16Code93(Context *context) {
	uint8_t reg = 0x05;
	uint16_t* sp = register16u(context, BR_SP);
	*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
	*sp += 16 / 8;
}
void handlerCommand16Code94(Context *context) {
	uint8_t reg = 0x06;
	uint16_t* sp = register16u(context, BR_SP);
	*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
	*sp += 16 / 8;
}
void handlerCommand16Code95(Context *context) {
	uint8_t reg = 0x07;
	uint16_t* sp = register16u(context, BR_SP);
	*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
	*sp += 16 / 8;
}
void handlerCommand32Code0(Context *context) {
	uint8_t mrmByte = read8u(context);
	uint8_t* target = (uint8_t*)readAddressMRM32(context, mrmByte);;
	uint8_t* source = (uint8_t*)readRegisterMRM8(context, mrmByte);;
	*(uint8_t*)target += *(uint8_t*)source;
}
void handlerCommand32Code1(Context *context) {
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint8_t mrmByte = read8u(context);
		uint16_t* target = (uint16_t*)readAddressMRM32(context, mrmByte);;
		uint16_t* source = (uint16_t*)readRegisterMRM16(context, mrmByte);;
		*(uint16_t*)target += *(uint16_t*)source;
	} else {
		uint8_t mrmByte = read8u(context);
		uint32_t* target = (uint32_t*)readAddressMRM32(context, mrmByte);;
		uint32_t* source = (uint32_t*)readRegisterMRM32(context, mrmByte);;
		*(uint32_t*)target += *(uint32_t*)source;
	}
}
void handlerCommand32Code2(Context *context) {
	uint8_t mrmByte = read8u(context);
	uint8_t* source = (uint8_t*)readAddressMRM32(context, mrmByte);;
	uint8_t* target = (uint8_t*)readRegisterMRM8(context, mrmByte);;
	*(uint8_t*)target += *(uint8_t*)source;
}
void handlerCommand32Code3(Context *context) {
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint8_t mrmByte = read8u(context);
		uint16_t* source = (uint16_t*)readAddressMRM32(context, mrmByte);;
		uint16_t* target = (uint16_t*)readRegisterMRM16(context, mrmByte);;
		*(uint16_t*)target += *(uint16_t*)source;
	} else {
		uint8_t mrmByte = read8u(context);
		uint32_t* source = (uint32_t*)readAddressMRM32(context, mrmByte);;
		uint32_t* target = (uint32_t*)readRegisterMRM32(context, mrmByte);;
		*(uint32_t*)target += *(uint32_t*)source;
	}
}
void handlerCommand32Code136(Context *context) {
	uint8_t mrmByte = read8u(context);
	uint8_t* target = (uint8_t*)readAddressMRM32(context, mrmByte);;
	uint8_t* source = (uint8_t*)readRegisterMRM8(context, mrmByte);;
	*(uint8_t*)target = *(uint8_t*)source;
}
void handlerCommand32Code137(Context *context) {
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint8_t mrmByte = read8u(context);
		uint16_t* target = (uint16_t*)readAddressMRM32(context, mrmByte);;
		uint16_t* source = (uint16_t*)readRegisterMRM16(context, mrmByte);;
		*(uint16_t*)target = *(uint16_t*)source;
	} else {
		uint8_t mrmByte = read8u(context);
		uint32_t* target = (uint32_t*)readAddressMRM32(context, mrmByte);;
		uint32_t* source = (uint32_t*)readRegisterMRM32(context, mrmByte);;
		*(uint32_t*)target = *(uint32_t*)source;
	}
}
void handlerCommand32Code138(Context *context) {
	uint8_t mrmByte = read8u(context);
	uint8_t* source = (uint8_t*)readAddressMRM32(context, mrmByte);;
	uint8_t* target = (uint8_t*)readRegisterMRM8(context, mrmByte);;
	*(uint8_t*)target = *(uint8_t*)source;
}
void handlerCommand32Code139(Context *context) {
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint8_t mrmByte = read8u(context);
		uint16_t* source = (uint16_t*)readAddressMRM32(context, mrmByte);;
		uint16_t* target = (uint16_t*)readRegisterMRM16(context, mrmByte);;
		*(uint16_t*)target = *(uint16_t*)source;
	} else {
		uint8_t mrmByte = read8u(context);
		uint32_t* source = (uint32_t*)readAddressMRM32(context, mrmByte);;
		uint32_t* target = (uint32_t*)readRegisterMRM32(context, mrmByte);;
		*(uint32_t*)target = *(uint32_t*)source;
	}
}
void handlerCommand32Code176(Context *context) {
	uint8_t reg = 0x00;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand32Code177(Context *context) {
	uint8_t reg = 0x01;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand32Code178(Context *context) {
	uint8_t reg = 0x02;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand32Code179(Context *context) {
	uint8_t reg = 0x03;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand32Code180(Context *context) {
	uint8_t reg = 0x04;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand32Code181(Context *context) {
	uint8_t reg = 0x05;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand32Code182(Context *context) {
	uint8_t reg = 0x06;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand32Code183(Context *context) {
	uint8_t reg = 0x07;
	*register8u(context, reg) = read8u(context);
}
void handlerCommand32Code184(Context *context) {
	uint8_t reg = 0x00;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) = read16u(context);
	} else {
		*register32u(context, reg) = read32u(context);
	}
}
void handlerCommand32Code185(Context *context) {
	uint8_t reg = 0x01;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) = read16u(context);
	} else {
		*register32u(context, reg) = read32u(context);
	}
}
void handlerCommand32Code186(Context *context) {
	uint8_t reg = 0x02;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) = read16u(context);
	} else {
		*register32u(context, reg) = read32u(context);
	}
}
void handlerCommand32Code187(Context *context) {
	uint8_t reg = 0x03;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) = read16u(context);
	} else {
		*register32u(context, reg) = read32u(context);
	}
}
void handlerCommand32Code188(Context *context) {
	uint8_t reg = 0x04;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) = read16u(context);
	} else {
		*register32u(context, reg) = read32u(context);
	}
}
void handlerCommand32Code189(Context *context) {
	uint8_t reg = 0x05;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) = read16u(context);
	} else {
		*register32u(context, reg) = read32u(context);
	}
}
void handlerCommand32Code190(Context *context) {
	uint8_t reg = 0x06;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) = read16u(context);
	} else {
		*register32u(context, reg) = read32u(context);
	}
}
void handlerCommand32Code191(Context *context) {
	uint8_t reg = 0x07;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) = read16u(context);
	} else {
		*register32u(context, reg) = read32u(context);
	}
}
void handlerCommand32Code64(Context *context) {
	uint8_t reg = 0x00;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) += 1;
	} else {
		*register32u(context, reg) += 1;
	}
}
void handlerCommand32Code65(Context *context) {
	uint8_t reg = 0x01;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) += 1;
	} else {
		*register32u(context, reg) += 1;
	}
}
void handlerCommand32Code66(Context *context) {
	uint8_t reg = 0x02;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) += 1;
	} else {
		*register32u(context, reg) += 1;
	}
}
void handlerCommand32Code67(Context *context) {
	uint8_t reg = 0x03;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) += 1;
	} else {
		*register32u(context, reg) += 1;
	}
}
void handlerCommand32Code68(Context *context) {
	uint8_t reg = 0x04;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) += 1;
	} else {
		*register32u(context, reg) += 1;
	}
}
void handlerCommand32Code69(Context *context) {
	uint8_t reg = 0x05;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) += 1;
	} else {
		*register32u(context, reg) += 1;
	}
}
void handlerCommand32Code70(Context *context) {
	uint8_t reg = 0x06;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) += 1;
	} else {
		*register32u(context, reg) += 1;
	}
}
void handlerCommand32Code71(Context *context) {
	uint8_t reg = 0x07;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) += 1;
	} else {
		*register32u(context, reg) += 1;
	}
}
void handlerCommand32Code72(Context *context) {
	uint8_t reg = 0x00;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) -= 1;
	} else {
		*register32u(context, reg) -= 1;
	}
}
void handlerCommand32Code73(Context *context) {
	uint8_t reg = 0x01;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) -= 1;
	} else {
		*register32u(context, reg) -= 1;
	}
}
void handlerCommand32Code74(Context *context) {
	uint8_t reg = 0x02;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) -= 1;
	} else {
		*register32u(context, reg) -= 1;
	}
}
void handlerCommand32Code75(Context *context) {
	uint8_t reg = 0x03;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) -= 1;
	} else {
		*register32u(context, reg) -= 1;
	}
}
void handlerCommand32Code76(Context *context) {
	uint8_t reg = 0x04;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) -= 1;
	} else {
		*register32u(context, reg) -= 1;
	}
}
void handlerCommand32Code77(Context *context) {
	uint8_t reg = 0x05;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) -= 1;
	} else {
		*register32u(context, reg) -= 1;
	}
}
void handlerCommand32Code78(Context *context) {
	uint8_t reg = 0x06;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) -= 1;
	} else {
		*register32u(context, reg) -= 1;
	}
}
void handlerCommand32Code79(Context *context) {
	uint8_t reg = 0x07;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		*register16u(context, reg) -= 1;
	} else {
		*register32u(context, reg) -= 1;
	}
}
void handlerCommand32Code226(Context *context) {
	int8_t addr = read8(context);
	uint16_t* reg = register16u(context, BR_CX);
	*reg -= 1;
	if (*reg != 0) {
		context->index += addr;
	}
}
void handlerCommand32Code205(Context *context) {
	uint8_t addr = read8u(context);
	context->functions[addr](context, addr);
}
void handlerCommand32Code80(Context *context) {
	uint8_t reg = 0x00;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*sp -= 16 / 8;
		*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*sp -= 32 / 8;
		*(uint32_t*)(mem(context, SR_SS) + *sp) = *register32u(context, reg);
	}
}
void handlerCommand32Code81(Context *context) {
	uint8_t reg = 0x01;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*sp -= 16 / 8;
		*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*sp -= 32 / 8;
		*(uint32_t*)(mem(context, SR_SS) + *sp) = *register32u(context, reg);
	}
}
void handlerCommand32Code82(Context *context) {
	uint8_t reg = 0x02;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*sp -= 16 / 8;
		*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*sp -= 32 / 8;
		*(uint32_t*)(mem(context, SR_SS) + *sp) = *register32u(context, reg);
	}
}
void handlerCommand32Code83(Context *context) {
	uint8_t reg = 0x03;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*sp -= 16 / 8;
		*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*sp -= 32 / 8;
		*(uint32_t*)(mem(context, SR_SS) + *sp) = *register32u(context, reg);
	}
}
void handlerCommand32Code84(Context *context) {
	uint8_t reg = 0x04;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*sp -= 16 / 8;
		*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*sp -= 32 / 8;
		*(uint32_t*)(mem(context, SR_SS) + *sp) = *register32u(context, reg);
	}
}
void handlerCommand32Code85(Context *context) {
	uint8_t reg = 0x05;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*sp -= 16 / 8;
		*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*sp -= 32 / 8;
		*(uint32_t*)(mem(context, SR_SS) + *sp) = *register32u(context, reg);
	}
}
void handlerCommand32Code86(Context *context) {
	uint8_t reg = 0x06;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*sp -= 16 / 8;
		*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*sp -= 32 / 8;
		*(uint32_t*)(mem(context, SR_SS) + *sp) = *register32u(context, reg);
	}
}
void handlerCommand32Code87(Context *context) {
	uint8_t reg = 0x07;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*sp -= 16 / 8;
		*(uint16_t*)(mem(context, SR_SS) + *sp) = *register16u(context, reg);
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*sp -= 32 / 8;
		*(uint32_t*)(mem(context, SR_SS) + *sp) = *register32u(context, reg);
	}
}
void handlerCommand32Code88(Context *context) {
	uint8_t reg = 0x00;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
		*sp += 16 / 8;
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*register32u(context, reg) = *(uint32_t*)(mem(context, SR_SS) + *sp);
		*sp += 32 / 8;
	}
}
void handlerCommand32Code89(Context *context) {
	uint8_t reg = 0x01;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
		*sp += 16 / 8;
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*register32u(context, reg) = *(uint32_t*)(mem(context, SR_SS) + *sp);
		*sp += 32 / 8;
	}
}
void handlerCommand32Code90(Context *context) {
	uint8_t reg = 0x02;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
		*sp += 16 / 8;
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*register32u(context, reg) = *(uint32_t*)(mem(context, SR_SS) + *sp);
		*sp += 32 / 8;
	}
}
void handlerCommand32Code91(Context *context) {
	uint8_t reg = 0x03;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
		*sp += 16 / 8;
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*register32u(context, reg) = *(uint32_t*)(mem(context, SR_SS) + *sp);
		*sp += 32 / 8;
	}
}
void handlerCommand32Code92(Context *context) {
	uint8_t reg = 0x04;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
		*sp += 16 / 8;
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*register32u(context, reg) = *(uint32_t*)(mem(context, SR_SS) + *sp);
		*sp += 32 / 8;
	}
}
void handlerCommand32Code93(Context *context) {
	uint8_t reg = 0x05;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
		*sp += 16 / 8;
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*register32u(context, reg) = *(uint32_t*)(mem(context, SR_SS) + *sp);
		*sp += 32 / 8;
	}
}
void handlerCommand32Code94(Context *context) {
	uint8_t reg = 0x06;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
		*sp += 16 / 8;
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*register32u(context, reg) = *(uint32_t*)(mem(context, SR_SS) + *sp);
		*sp += 32 / 8;
	}
}
void handlerCommand32Code95(Context *context) {
	uint8_t reg = 0x07;
	if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {
		uint16_t* sp = register16u(context, BR_SP);
		*register16u(context, reg) = *(uint16_t*)(mem(context, SR_SS) + *sp);
		*sp += 16 / 8;
	} else {
		uint32_t* sp = register32u(context, BR_SP);
		*register32u(context, reg) = *(uint32_t*)(mem(context, SR_SS) + *sp);
		*sp += 32 / 8;
	}
}
 

void mCommandFunctionEmpty(Context* context) {
	printf("function not implementation\n");
}
void installCommandFunction() {
	for(int i = 0; i < 512; i++) {
		commandFunctions16[i] = mCommandFunctionEmpty;
		commandFunctions32[i] = mCommandFunctionEmpty;
	}
	commandFunctions16[0] = handlerCommand16Code0;
	commandFunctions16[1] = handlerCommand16Code1;
	commandFunctions16[2] = handlerCommand16Code2;
	commandFunctions16[3] = handlerCommand16Code3;
	commandFunctions16[136] = handlerCommand16Code136;
	commandFunctions16[137] = handlerCommand16Code137;
	commandFunctions16[138] = handlerCommand16Code138;
	commandFunctions16[139] = handlerCommand16Code139;
	commandFunctions16[176] = handlerCommand16Code176;
	commandFunctions16[177] = handlerCommand16Code177;
	commandFunctions16[178] = handlerCommand16Code178;
	commandFunctions16[179] = handlerCommand16Code179;
	commandFunctions16[180] = handlerCommand16Code180;
	commandFunctions16[181] = handlerCommand16Code181;
	commandFunctions16[182] = handlerCommand16Code182;
	commandFunctions16[183] = handlerCommand16Code183;
	commandFunctions16[184] = handlerCommand16Code184;
	commandFunctions16[185] = handlerCommand16Code185;
	commandFunctions16[186] = handlerCommand16Code186;
	commandFunctions16[187] = handlerCommand16Code187;
	commandFunctions16[188] = handlerCommand16Code188;
	commandFunctions16[189] = handlerCommand16Code189;
	commandFunctions16[190] = handlerCommand16Code190;
	commandFunctions16[191] = handlerCommand16Code191;
	commandFunctions16[64] = handlerCommand16Code64;
	commandFunctions16[65] = handlerCommand16Code65;
	commandFunctions16[66] = handlerCommand16Code66;
	commandFunctions16[67] = handlerCommand16Code67;
	commandFunctions16[68] = handlerCommand16Code68;
	commandFunctions16[69] = handlerCommand16Code69;
	commandFunctions16[70] = handlerCommand16Code70;
	commandFunctions16[71] = handlerCommand16Code71;
	commandFunctions16[72] = handlerCommand16Code72;
	commandFunctions16[73] = handlerCommand16Code73;
	commandFunctions16[74] = handlerCommand16Code74;
	commandFunctions16[75] = handlerCommand16Code75;
	commandFunctions16[76] = handlerCommand16Code76;
	commandFunctions16[77] = handlerCommand16Code77;
	commandFunctions16[78] = handlerCommand16Code78;
	commandFunctions16[79] = handlerCommand16Code79;
	commandFunctions16[226] = handlerCommand16Code226;
	commandFunctions16[205] = handlerCommand16Code205;
	commandFunctions16[80] = handlerCommand16Code80;
	commandFunctions16[81] = handlerCommand16Code81;
	commandFunctions16[82] = handlerCommand16Code82;
	commandFunctions16[83] = handlerCommand16Code83;
	commandFunctions16[84] = handlerCommand16Code84;
	commandFunctions16[85] = handlerCommand16Code85;
	commandFunctions16[86] = handlerCommand16Code86;
	commandFunctions16[87] = handlerCommand16Code87;
	commandFunctions16[88] = handlerCommand16Code88;
	commandFunctions16[89] = handlerCommand16Code89;
	commandFunctions16[90] = handlerCommand16Code90;
	commandFunctions16[91] = handlerCommand16Code91;
	commandFunctions16[92] = handlerCommand16Code92;
	commandFunctions16[93] = handlerCommand16Code93;
	commandFunctions16[94] = handlerCommand16Code94;
	commandFunctions16[95] = handlerCommand16Code95;
	commandFunctions32[0] = handlerCommand32Code0;
	commandFunctions32[1] = handlerCommand32Code1;
	commandFunctions32[2] = handlerCommand32Code2;
	commandFunctions32[3] = handlerCommand32Code3;
	commandFunctions32[136] = handlerCommand32Code136;
	commandFunctions32[137] = handlerCommand32Code137;
	commandFunctions32[138] = handlerCommand32Code138;
	commandFunctions32[139] = handlerCommand32Code139;
	commandFunctions32[176] = handlerCommand32Code176;
	commandFunctions32[177] = handlerCommand32Code177;
	commandFunctions32[178] = handlerCommand32Code178;
	commandFunctions32[179] = handlerCommand32Code179;
	commandFunctions32[180] = handlerCommand32Code180;
	commandFunctions32[181] = handlerCommand32Code181;
	commandFunctions32[182] = handlerCommand32Code182;
	commandFunctions32[183] = handlerCommand32Code183;
	commandFunctions32[184] = handlerCommand32Code184;
	commandFunctions32[185] = handlerCommand32Code185;
	commandFunctions32[186] = handlerCommand32Code186;
	commandFunctions32[187] = handlerCommand32Code187;
	commandFunctions32[188] = handlerCommand32Code188;
	commandFunctions32[189] = handlerCommand32Code189;
	commandFunctions32[190] = handlerCommand32Code190;
	commandFunctions32[191] = handlerCommand32Code191;
	commandFunctions32[64] = handlerCommand32Code64;
	commandFunctions32[65] = handlerCommand32Code65;
	commandFunctions32[66] = handlerCommand32Code66;
	commandFunctions32[67] = handlerCommand32Code67;
	commandFunctions32[68] = handlerCommand32Code68;
	commandFunctions32[69] = handlerCommand32Code69;
	commandFunctions32[70] = handlerCommand32Code70;
	commandFunctions32[71] = handlerCommand32Code71;
	commandFunctions32[72] = handlerCommand32Code72;
	commandFunctions32[73] = handlerCommand32Code73;
	commandFunctions32[74] = handlerCommand32Code74;
	commandFunctions32[75] = handlerCommand32Code75;
	commandFunctions32[76] = handlerCommand32Code76;
	commandFunctions32[77] = handlerCommand32Code77;
	commandFunctions32[78] = handlerCommand32Code78;
	commandFunctions32[79] = handlerCommand32Code79;
	commandFunctions32[226] = handlerCommand32Code226;
	commandFunctions32[205] = handlerCommand32Code205;
	commandFunctions32[80] = handlerCommand32Code80;
	commandFunctions32[81] = handlerCommand32Code81;
	commandFunctions32[82] = handlerCommand32Code82;
	commandFunctions32[83] = handlerCommand32Code83;
	commandFunctions32[84] = handlerCommand32Code84;
	commandFunctions32[85] = handlerCommand32Code85;
	commandFunctions32[86] = handlerCommand32Code86;
	commandFunctions32[87] = handlerCommand32Code87;
	commandFunctions32[88] = handlerCommand32Code88;
	commandFunctions32[89] = handlerCommand32Code89;
	commandFunctions32[90] = handlerCommand32Code90;
	commandFunctions32[91] = handlerCommand32Code91;
	commandFunctions32[92] = handlerCommand32Code92;
	commandFunctions32[93] = handlerCommand32Code93;
	commandFunctions32[94] = handlerCommand32Code94;
	commandFunctions32[95] = handlerCommand32Code95;
}
