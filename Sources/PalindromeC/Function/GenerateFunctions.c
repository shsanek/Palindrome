#include "GenerateFunctions.h"
//ADD
void handlerCommand16Code0000() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 + LazyFlagVarB8;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand16Code0001() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 + LazyFlagVarB16;
	lazyFlagType = t_ADD16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//ADD
void handlerCommand16Code0002() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 + LazyFlagVarB8;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand16Code0003() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 + LazyFlagVarB16;
	lazyFlagType = t_ADD16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//OR
void handlerCommand16Code0008() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 | LazyFlagVarB8;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand16Code0009() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 | LazyFlagVarB16;
	lazyFlagType = t_OR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//OR
void handlerCommand16Code000A() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 | LazyFlagVarB8;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand16Code000B() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 | LazyFlagVarB16;
	lazyFlagType = t_OR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//AND
void handlerCommand16Code0020() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 & LazyFlagVarB8;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand16Code0021() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 & LazyFlagVarB16;
	lazyFlagType = t_AND16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//AND
void handlerCommand16Code0022() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 & LazyFlagVarB8;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand16Code0023() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 & LazyFlagVarB16;
	lazyFlagType = t_AND16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//SUB
void handlerCommand16Code0028() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand16Code0029() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
	lazyFlagType = t_SUB16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//SUB
void handlerCommand16Code002A() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand16Code002B() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
	lazyFlagType = t_SUB16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//XOR
void handlerCommand16Code0030() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 ^ LazyFlagVarB8;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand16Code0031() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 ^ LazyFlagVarB16;
	lazyFlagType = t_XOR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//XOR
void handlerCommand16Code0032() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 ^ LazyFlagVarB8;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand16Code0033() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 ^ LazyFlagVarB16;
	lazyFlagType = t_XOR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//CMP
void handlerCommand16Code0038() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand16Code0039() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
	lazyFlagType = t_CMP16;
}
//CMP
void handlerCommand16Code003A() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand16Code003B() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
	lazyFlagType = t_CMP16;
}
//Math
void handlerCommand16Code0080() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 + LazyFlagVarB8;
			lazyFlagType = t_ADD8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x1: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 | LazyFlagVarB8;
			lazyFlagType = t_OR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x4: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 & LazyFlagVarB8;
			lazyFlagType = t_AND8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x5: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_SUB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x6: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 ^ LazyFlagVarB8;
			lazyFlagType = t_XOR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x7: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_CMP8;
		}
		break;
	}
}
//Math
void handlerCommand16Code0081() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 + LazyFlagVarB16;
			lazyFlagType = t_ADD16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x1: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 | LazyFlagVarB16;
			lazyFlagType = t_OR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x4: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 & LazyFlagVarB16;
			lazyFlagType = t_AND16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x5: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
			lazyFlagType = t_SUB16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x6: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 ^ LazyFlagVarB16;
			lazyFlagType = t_XOR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x7: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
			lazyFlagType = t_CMP16;
		}
		break;
	}
}
//Math
void handlerCommand16Code0082() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 + LazyFlagVarB8;
			lazyFlagType = t_ADD8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x1: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 | LazyFlagVarB8;
			lazyFlagType = t_OR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x4: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 & LazyFlagVarB8;
			lazyFlagType = t_AND8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x5: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_SUB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x6: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 ^ LazyFlagVarB8;
			lazyFlagType = t_XOR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x7: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_CMP8;
		}
		break;
	}
}
//Math
void handlerCommand16Code0083() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read8();
			LazyFlagResultContainer16 = LazyFlagVarA16 + LazyFlagVarB16;
			lazyFlagType = t_ADD16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x1: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read8();
			LazyFlagResultContainer16 = LazyFlagVarA16 | LazyFlagVarB16;
			lazyFlagType = t_OR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x4: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read8();
			LazyFlagResultContainer16 = LazyFlagVarA16 & LazyFlagVarB16;
			lazyFlagType = t_AND16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x5: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read8();
			LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
			lazyFlagType = t_SUB16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x6: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read8();
			LazyFlagResultContainer16 = LazyFlagVarA16 ^ LazyFlagVarB16;
			lazyFlagType = t_XOR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x7: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read8();
			LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
			lazyFlagType = t_CMP16;
		}
		break;
	}
}
//Mul
void handlerCommand16Code01AF() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 * LazyFlagVarB16;
	lazyFlagType = t_MUL;
	*(int16_t*)source = LazyFlagResultContainer16;
}
//Move
void handlerCommand16Code0088() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code0089() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand16Code008A() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code008B() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand16Code00B0() {
	uint8_t reg = 0x00;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand16Code00B1() {
	uint8_t reg = 0x01;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand16Code00B2() {
	uint8_t reg = 0x02;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand16Code00B3() {
	uint8_t reg = 0x03;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand16Code00B4() {
	uint8_t reg = 0x04;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand16Code00B5() {
	uint8_t reg = 0x05;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand16Code00B6() {
	uint8_t reg = 0x06;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand16Code00B7() {
	uint8_t reg = 0x07;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand16Code00B8() {
	uint8_t reg = 0x00;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand16Code00B9() {
	uint8_t reg = 0x01;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand16Code00BA() {
	uint8_t reg = 0x02;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand16Code00BB() {
	uint8_t reg = 0x03;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand16Code00BC() {
	uint8_t reg = 0x04;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand16Code00BD() {
	uint8_t reg = 0x05;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand16Code00BE() {
	uint8_t reg = 0x06;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand16Code00BF() {
	uint8_t reg = 0x07;
	*register16u(reg) = read16u();
}
//Inc
void handlerCommand16Code0040() {
	uint8_t reg = 0x00;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand16Code0041() {
	uint8_t reg = 0x01;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand16Code0042() {
	uint8_t reg = 0x02;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand16Code0043() {
	uint8_t reg = 0x03;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand16Code0044() {
	uint8_t reg = 0x04;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand16Code0045() {
	uint8_t reg = 0x05;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand16Code0046() {
	uint8_t reg = 0x06;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand16Code0047() {
	uint8_t reg = 0x07;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand16Code0048() {
	uint8_t reg = 0x00;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand16Code0049() {
	uint8_t reg = 0x01;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand16Code004A() {
	uint8_t reg = 0x02;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand16Code004B() {
	uint8_t reg = 0x03;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand16Code004C() {
	uint8_t reg = 0x04;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand16Code004D() {
	uint8_t reg = 0x05;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand16Code004E() {
	uint8_t reg = 0x06;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand16Code004F() {
	uint8_t reg = 0x07;
	*register16u(reg) -= 1;
}
//Loop
void handlerCommand16Code00E2() {
	int8_t addr = read8();
	uint16_t* reg = register16u(BR_CX);
	*reg -= 1;
	if (*reg != 0) {
		context.index += addr;
	}
}
//Jmp
void handlerCommand16Code00EB() {
	context.index += read8();
}
//Call
void handlerCommand16Code00E8() {
	context.currentCallStack[0] = context.index + 16 / 8;
	context.currentCallStack = context.currentCallStack + 1;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	context.index += read16();
}
//Ret
void handlerCommand16Code00C3() {
	uint16_t* sp = register16u(BR_SP);
	*sp += 16 / 8;
	context.currentCallStack = context.currentCallStack - 1;
	context.index = context.currentCallStack[0];
}
//J(cond)
void handlerCommand16Code0070() {
	FillFlags();
	int8_t address = read8();
	if COND0x00 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0071() {
	FillFlags();
	int8_t address = read8();
	if COND0x01 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0072() {
	FillFlags();
	int8_t address = read8();
	if COND0x02 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0073() {
	FillFlags();
	int8_t address = read8();
	if COND0x03 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0074() {
	FillFlags();
	int8_t address = read8();
	if COND0x04 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0075() {
	FillFlags();
	int8_t address = read8();
	if COND0x05 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0076() {
	FillFlags();
	int8_t address = read8();
	if COND0x06 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0077() {
	FillFlags();
	int8_t address = read8();
	if COND0x07 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0078() {
	FillFlags();
	int8_t address = read8();
	if COND0x08 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0079() {
	FillFlags();
	int8_t address = read8();
	if COND0x09 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code007A() {
	FillFlags();
	int8_t address = read8();
	if COND0x0A {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code007B() {
	FillFlags();
	int8_t address = read8();
	if COND0x0B {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code007C() {
	FillFlags();
	int8_t address = read8();
	if COND0x0C {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code007D() {
	FillFlags();
	int8_t address = read8();
	if COND0x0D {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code007E() {
	FillFlags();
	int8_t address = read8();
	if COND0x0E {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code007F() {
	FillFlags();
	int8_t address = read8();
	if COND0x0F {
		context.index += address;
	}
}
//Int
void handlerCommand16Code00CD() {
	uint8_t addr = read8u();
	context.functions[addr](addr);
}
//Push
void handlerCommand16Code0050() {
	uint8_t reg = 0x00;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand16Code0051() {
	uint8_t reg = 0x01;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand16Code0052() {
	uint8_t reg = 0x02;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand16Code0053() {
	uint8_t reg = 0x03;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand16Code0054() {
	uint8_t reg = 0x04;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand16Code0055() {
	uint8_t reg = 0x05;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand16Code0056() {
	uint8_t reg = 0x06;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand16Code0057() {
	uint8_t reg = 0x07;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Pop
void handlerCommand16Code0058() {
	uint8_t reg = 0x00;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand16Code0059() {
	uint8_t reg = 0x01;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand16Code005A() {
	uint8_t reg = 0x02;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand16Code005B() {
	uint8_t reg = 0x03;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand16Code005C() {
	uint8_t reg = 0x04;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand16Code005D() {
	uint8_t reg = 0x05;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand16Code005E() {
	uint8_t reg = 0x06;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand16Code005F() {
	uint8_t reg = 0x07;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Leave
void handlerCommand16Code00C9() {
	*register16u(BR_SP) = *register16u(BR_BP);
	*register16u(BR_BP) = *(uint16_t*)(mem(SR_SS) + *register16u(BR_SP));
	*register16u(BR_SP) += 16 / 8;
}
//Ofther
void handlerCommand16Code00FF() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	switch (nnn) {
		case 0x00: {
			// MOVEL
			*target = read8u();
		}
		break;
		case 0x6: {
			// PUSH
			uint16_t* sp = register16u(BR_SP);
			*sp -= 16 / 8;
			*(uint16_t*)(mem(SR_SS) + *sp) = *(uint16_t*)target;
		}
		break;
	}
}
//Push
void handlerCommand16Code006A() {
	uint16_t* sp = register16u(BR_SP);
	*sp -= 8 / 8;
	*(uint8_t*)(mem(SR_SS) + *sp) = read8u();
}
//Push
void handlerCommand16Code0068() {
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = read16u();
}
//Lea
void handlerCommand16Code008D() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	*((uint16_t*)source) = (uint16_t)(((uint64_t)(target - context.memory)) & 0xFFFF);
}
//ADD
void handlerCommand32Code0000P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 + LazyFlagVarB8;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand32Code0000() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 + LazyFlagVarB8;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand32Code0001P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 + LazyFlagVarB16;
	lazyFlagType = t_ADD16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//ADD
void handlerCommand32Code0001() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = LazyFlagVarA32 + LazyFlagVarB32;
	lazyFlagType = t_ADD32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//ADD
void handlerCommand32Code0002P66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 + LazyFlagVarB8;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand32Code0002() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 + LazyFlagVarB8;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand32Code0003P66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 + LazyFlagVarB16;
	lazyFlagType = t_ADD16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//ADD
void handlerCommand32Code0003() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = LazyFlagVarA32 + LazyFlagVarB32;
	lazyFlagType = t_ADD32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//OR
void handlerCommand32Code0008P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 | LazyFlagVarB8;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand32Code0008() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 | LazyFlagVarB8;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand32Code0009P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 | LazyFlagVarB16;
	lazyFlagType = t_OR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//OR
void handlerCommand32Code0009() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = LazyFlagVarA32 | LazyFlagVarB32;
	lazyFlagType = t_OR32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//OR
void handlerCommand32Code000AP66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 | LazyFlagVarB8;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand32Code000A() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 | LazyFlagVarB8;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand32Code000BP66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 | LazyFlagVarB16;
	lazyFlagType = t_OR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//OR
void handlerCommand32Code000B() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = LazyFlagVarA32 | LazyFlagVarB32;
	lazyFlagType = t_OR32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//AND
void handlerCommand32Code0020P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 & LazyFlagVarB8;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand32Code0020() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 & LazyFlagVarB8;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand32Code0021P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 & LazyFlagVarB16;
	lazyFlagType = t_AND16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//AND
void handlerCommand32Code0021() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = LazyFlagVarA32 & LazyFlagVarB32;
	lazyFlagType = t_AND32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//AND
void handlerCommand32Code0022P66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 & LazyFlagVarB8;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand32Code0022() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 & LazyFlagVarB8;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand32Code0023P66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 & LazyFlagVarB16;
	lazyFlagType = t_AND16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//AND
void handlerCommand32Code0023() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = LazyFlagVarA32 & LazyFlagVarB32;
	lazyFlagType = t_AND32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//SUB
void handlerCommand32Code0028P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand32Code0028() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand32Code0029P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
	lazyFlagType = t_SUB16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//SUB
void handlerCommand32Code0029() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = LazyFlagVarA32 - LazyFlagVarB32;
	lazyFlagType = t_SUB32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//SUB
void handlerCommand32Code002AP66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand32Code002A() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand32Code002BP66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
	lazyFlagType = t_SUB16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//SUB
void handlerCommand32Code002B() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = LazyFlagVarA32 - LazyFlagVarB32;
	lazyFlagType = t_SUB32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//XOR
void handlerCommand32Code0030P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 ^ LazyFlagVarB8;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand32Code0030() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 ^ LazyFlagVarB8;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand32Code0031P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 ^ LazyFlagVarB16;
	lazyFlagType = t_XOR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//XOR
void handlerCommand32Code0031() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = LazyFlagVarA32 ^ LazyFlagVarB32;
	lazyFlagType = t_XOR32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//XOR
void handlerCommand32Code0032P66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 ^ LazyFlagVarB8;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand32Code0032() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 ^ LazyFlagVarB8;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand32Code0033P66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 ^ LazyFlagVarB16;
	lazyFlagType = t_XOR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//XOR
void handlerCommand32Code0033() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = LazyFlagVarA32 ^ LazyFlagVarB32;
	lazyFlagType = t_XOR32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//CMP
void handlerCommand32Code0038P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand32Code0038() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand32Code0039P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
	lazyFlagType = t_CMP16;
}
//CMP
void handlerCommand32Code0039() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = LazyFlagVarA32 - LazyFlagVarB32;
	lazyFlagType = t_CMP32;
}
//CMP
void handlerCommand32Code003AP66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand32Code003A() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand32Code003BP66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
	lazyFlagType = t_CMP16;
}
//CMP
void handlerCommand32Code003B() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = LazyFlagVarA32 - LazyFlagVarB32;
	lazyFlagType = t_CMP32;
}
//Math
void handlerCommand32Code0080P66P67() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 + LazyFlagVarB8;
			lazyFlagType = t_ADD8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x1: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 | LazyFlagVarB8;
			lazyFlagType = t_OR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x4: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 & LazyFlagVarB8;
			lazyFlagType = t_AND8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x5: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_SUB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x6: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 ^ LazyFlagVarB8;
			lazyFlagType = t_XOR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x7: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_CMP8;
		}
		break;
	}
}
//Math
void handlerCommand32Code0080P67() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 + LazyFlagVarB8;
			lazyFlagType = t_ADD8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x1: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 | LazyFlagVarB8;
			lazyFlagType = t_OR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x4: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 & LazyFlagVarB8;
			lazyFlagType = t_AND8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x5: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_SUB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x6: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 ^ LazyFlagVarB8;
			lazyFlagType = t_XOR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x7: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_CMP8;
		}
		break;
	}
}
//Math
void handlerCommand32Code0080P66() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 + LazyFlagVarB8;
			lazyFlagType = t_ADD8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x1: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 | LazyFlagVarB8;
			lazyFlagType = t_OR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x4: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 & LazyFlagVarB8;
			lazyFlagType = t_AND8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x5: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_SUB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x6: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 ^ LazyFlagVarB8;
			lazyFlagType = t_XOR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x7: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_CMP8;
		}
		break;
	}
}
//Math
void handlerCommand32Code0080() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 + LazyFlagVarB8;
			lazyFlagType = t_ADD8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x1: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 | LazyFlagVarB8;
			lazyFlagType = t_OR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x4: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 & LazyFlagVarB8;
			lazyFlagType = t_AND8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x5: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_SUB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x6: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 ^ LazyFlagVarB8;
			lazyFlagType = t_XOR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x7: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_CMP8;
		}
		break;
	}
}
//Math
void handlerCommand32Code0081P66P67() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 + LazyFlagVarB16;
			lazyFlagType = t_ADD16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x1: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 | LazyFlagVarB16;
			lazyFlagType = t_OR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x4: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 & LazyFlagVarB16;
			lazyFlagType = t_AND16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x5: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
			lazyFlagType = t_SUB16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x6: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 ^ LazyFlagVarB16;
			lazyFlagType = t_XOR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x7: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
			lazyFlagType = t_CMP16;
		}
		break;
	}
}
//Math
void handlerCommand32Code0081P67() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 + LazyFlagVarB32;
			lazyFlagType = t_ADD32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x1: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 | LazyFlagVarB32;
			lazyFlagType = t_OR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x4: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 & LazyFlagVarB32;
			lazyFlagType = t_AND32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x5: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 - LazyFlagVarB32;
			lazyFlagType = t_SUB32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x6: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 ^ LazyFlagVarB32;
			lazyFlagType = t_XOR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x7: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 - LazyFlagVarB32;
			lazyFlagType = t_CMP32;
		}
		break;
	}
}
//Math
void handlerCommand32Code0081P66() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 + LazyFlagVarB16;
			lazyFlagType = t_ADD16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x1: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 | LazyFlagVarB16;
			lazyFlagType = t_OR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x4: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 & LazyFlagVarB16;
			lazyFlagType = t_AND16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x5: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
			lazyFlagType = t_SUB16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x6: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 ^ LazyFlagVarB16;
			lazyFlagType = t_XOR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x7: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
			lazyFlagType = t_CMP16;
		}
		break;
	}
}
//Math
void handlerCommand32Code0081() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 + LazyFlagVarB32;
			lazyFlagType = t_ADD32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x1: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 | LazyFlagVarB32;
			lazyFlagType = t_OR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x4: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 & LazyFlagVarB32;
			lazyFlagType = t_AND32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x5: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 - LazyFlagVarB32;
			lazyFlagType = t_SUB32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x6: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 ^ LazyFlagVarB32;
			lazyFlagType = t_XOR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x7: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 - LazyFlagVarB32;
			lazyFlagType = t_CMP32;
		}
		break;
	}
}
//Math
void handlerCommand32Code0082() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 + LazyFlagVarB8;
			lazyFlagType = t_ADD8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x1: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 | LazyFlagVarB8;
			lazyFlagType = t_OR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x4: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 & LazyFlagVarB8;
			lazyFlagType = t_AND8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x5: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_SUB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x6: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 ^ LazyFlagVarB8;
			lazyFlagType = t_XOR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x7: {
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 - LazyFlagVarB8;
			lazyFlagType = t_CMP8;
		}
		break;
	}
}
//Math
void handlerCommand32Code0083P66() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read8();
			LazyFlagResultContainer16 = LazyFlagVarA16 + LazyFlagVarB16;
			lazyFlagType = t_ADD16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x1: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read8();
			LazyFlagResultContainer16 = LazyFlagVarA16 | LazyFlagVarB16;
			lazyFlagType = t_OR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x4: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read8();
			LazyFlagResultContainer16 = LazyFlagVarA16 & LazyFlagVarB16;
			lazyFlagType = t_AND16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x5: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read8();
			LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
			lazyFlagType = t_SUB16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x6: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read8();
			LazyFlagResultContainer16 = LazyFlagVarA16 ^ LazyFlagVarB16;
			lazyFlagType = t_XOR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x7: {
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read8();
			LazyFlagResultContainer16 = LazyFlagVarA16 - LazyFlagVarB16;
			lazyFlagType = t_CMP16;
		}
		break;
	}
}
//Math
void handlerCommand32Code0083() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	switch (nnn) {
		case 0x0: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read8();
			LazyFlagResultContainer32 = LazyFlagVarA32 + LazyFlagVarB32;
			lazyFlagType = t_ADD32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x1: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read8();
			LazyFlagResultContainer32 = LazyFlagVarA32 | LazyFlagVarB32;
			lazyFlagType = t_OR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x4: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read8();
			LazyFlagResultContainer32 = LazyFlagVarA32 & LazyFlagVarB32;
			lazyFlagType = t_AND32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x5: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read8();
			LazyFlagResultContainer32 = LazyFlagVarA32 - LazyFlagVarB32;
			lazyFlagType = t_SUB32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x6: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read8();
			LazyFlagResultContainer32 = LazyFlagVarA32 ^ LazyFlagVarB32;
			lazyFlagType = t_XOR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x7: {
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read8();
			LazyFlagResultContainer32 = LazyFlagVarA32 - LazyFlagVarB32;
			lazyFlagType = t_CMP32;
		}
		break;
	}
}
//Mul
void handlerCommand32Code01AF() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = LazyFlagVarA32 * LazyFlagVarB32;
	lazyFlagType = t_MUL;
	*(int32_t*)source = LazyFlagResultContainer32;
}
//Move
void handlerCommand32Code0088P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code0088() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code0089P66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand32Code0089() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	*(uint32_t*)target = *(uint32_t*)source;
}
//Move
void handlerCommand32Code008AP66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code008A() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code008BP66() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand32Code008B() {
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	*(uint32_t*)target = *(uint32_t*)source;
}
//Move
void handlerCommand32Code00B0P66() {
	uint8_t reg = 0x00;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B0() {
	uint8_t reg = 0x00;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B1P66() {
	uint8_t reg = 0x01;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B1() {
	uint8_t reg = 0x01;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B2P66() {
	uint8_t reg = 0x02;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B2() {
	uint8_t reg = 0x02;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B3P66() {
	uint8_t reg = 0x03;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B3() {
	uint8_t reg = 0x03;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B4P66() {
	uint8_t reg = 0x04;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B4() {
	uint8_t reg = 0x04;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B5P66() {
	uint8_t reg = 0x05;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B5() {
	uint8_t reg = 0x05;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B6P66() {
	uint8_t reg = 0x06;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B6() {
	uint8_t reg = 0x06;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B7P66() {
	uint8_t reg = 0x07;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B7() {
	uint8_t reg = 0x07;
	*register8u(reg) = read8u();
}
//Move
void handlerCommand32Code00B8P66() {
	uint8_t reg = 0x00;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand32Code00B8() {
	uint8_t reg = 0x00;
	*register32u(reg) = read32u();
}
//Move
void handlerCommand32Code00B9P66() {
	uint8_t reg = 0x01;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand32Code00B9() {
	uint8_t reg = 0x01;
	*register32u(reg) = read32u();
}
//Move
void handlerCommand32Code00BAP66() {
	uint8_t reg = 0x02;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand32Code00BA() {
	uint8_t reg = 0x02;
	*register32u(reg) = read32u();
}
//Move
void handlerCommand32Code00BBP66() {
	uint8_t reg = 0x03;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand32Code00BB() {
	uint8_t reg = 0x03;
	*register32u(reg) = read32u();
}
//Move
void handlerCommand32Code00BCP66() {
	uint8_t reg = 0x04;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand32Code00BC() {
	uint8_t reg = 0x04;
	*register32u(reg) = read32u();
}
//Move
void handlerCommand32Code00BDP66() {
	uint8_t reg = 0x05;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand32Code00BD() {
	uint8_t reg = 0x05;
	*register32u(reg) = read32u();
}
//Move
void handlerCommand32Code00BEP66() {
	uint8_t reg = 0x06;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand32Code00BE() {
	uint8_t reg = 0x06;
	*register32u(reg) = read32u();
}
//Move
void handlerCommand32Code00BFP66() {
	uint8_t reg = 0x07;
	*register16u(reg) = read16u();
}
//Move
void handlerCommand32Code00BF() {
	uint8_t reg = 0x07;
	*register32u(reg) = read32u();
}
//Inc
void handlerCommand32Code0040P66() {
	uint8_t reg = 0x00;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand32Code0040() {
	uint8_t reg = 0x00;
	*register32u(reg) += 1;
}
//Inc
void handlerCommand32Code0041P66() {
	uint8_t reg = 0x01;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand32Code0041() {
	uint8_t reg = 0x01;
	*register32u(reg) += 1;
}
//Inc
void handlerCommand32Code0042P66() {
	uint8_t reg = 0x02;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand32Code0042() {
	uint8_t reg = 0x02;
	*register32u(reg) += 1;
}
//Inc
void handlerCommand32Code0043P66() {
	uint8_t reg = 0x03;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand32Code0043() {
	uint8_t reg = 0x03;
	*register32u(reg) += 1;
}
//Inc
void handlerCommand32Code0044P66() {
	uint8_t reg = 0x04;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand32Code0044() {
	uint8_t reg = 0x04;
	*register32u(reg) += 1;
}
//Inc
void handlerCommand32Code0045P66() {
	uint8_t reg = 0x05;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand32Code0045() {
	uint8_t reg = 0x05;
	*register32u(reg) += 1;
}
//Inc
void handlerCommand32Code0046P66() {
	uint8_t reg = 0x06;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand32Code0046() {
	uint8_t reg = 0x06;
	*register32u(reg) += 1;
}
//Inc
void handlerCommand32Code0047P66() {
	uint8_t reg = 0x07;
	*register16u(reg) += 1;
}
//Inc
void handlerCommand32Code0047() {
	uint8_t reg = 0x07;
	*register32u(reg) += 1;
}
//Inc
void handlerCommand32Code0048P66() {
	uint8_t reg = 0x00;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand32Code0048() {
	uint8_t reg = 0x00;
	*register32u(reg) -= 1;
}
//Inc
void handlerCommand32Code0049P66() {
	uint8_t reg = 0x01;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand32Code0049() {
	uint8_t reg = 0x01;
	*register32u(reg) -= 1;
}
//Inc
void handlerCommand32Code004AP66() {
	uint8_t reg = 0x02;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand32Code004A() {
	uint8_t reg = 0x02;
	*register32u(reg) -= 1;
}
//Inc
void handlerCommand32Code004BP66() {
	uint8_t reg = 0x03;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand32Code004B() {
	uint8_t reg = 0x03;
	*register32u(reg) -= 1;
}
//Inc
void handlerCommand32Code004CP66() {
	uint8_t reg = 0x04;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand32Code004C() {
	uint8_t reg = 0x04;
	*register32u(reg) -= 1;
}
//Inc
void handlerCommand32Code004DP66() {
	uint8_t reg = 0x05;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand32Code004D() {
	uint8_t reg = 0x05;
	*register32u(reg) -= 1;
}
//Inc
void handlerCommand32Code004EP66() {
	uint8_t reg = 0x06;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand32Code004E() {
	uint8_t reg = 0x06;
	*register32u(reg) -= 1;
}
//Inc
void handlerCommand32Code004FP66() {
	uint8_t reg = 0x07;
	*register16u(reg) -= 1;
}
//Inc
void handlerCommand32Code004F() {
	uint8_t reg = 0x07;
	*register32u(reg) -= 1;
}
//Loop
void handlerCommand32Code00E2() {
	int8_t addr = read8();
	uint16_t* reg = register16u(BR_CX);
	*reg -= 1;
	if (*reg != 0) {
		context.index += addr;
	}
}
//Jmp
void handlerCommand32Code00EB() {
	context.index += read8();
}
//Call
void handlerCommand32Code00E8P66() {
	context.currentCallStack[0] = context.index + 16 / 8;
	context.currentCallStack = context.currentCallStack + 1;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 16 / 8;
	context.index += read16();
}
//Call
void handlerCommand32Code00E8() {
	context.currentCallStack[0] = context.index + 32 / 8;
	context.currentCallStack = context.currentCallStack + 1;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 32 / 8;
	context.index += read32();
}
//Ret
void handlerCommand32Code00C3() {
	uint32_t* sp = register32u(BR_SP);
	*sp += 32 / 8;
	context.currentCallStack = context.currentCallStack - 1;
	context.index = context.currentCallStack[0];
}
//J(cond)
void handlerCommand32Code0070() {
	FillFlags();
	int8_t address = read8();
	if COND0x00 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0071() {
	FillFlags();
	int8_t address = read8();
	if COND0x01 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0072() {
	FillFlags();
	int8_t address = read8();
	if COND0x02 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0073() {
	FillFlags();
	int8_t address = read8();
	if COND0x03 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0074() {
	FillFlags();
	int8_t address = read8();
	if COND0x04 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0075() {
	FillFlags();
	int8_t address = read8();
	if COND0x05 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0076() {
	FillFlags();
	int8_t address = read8();
	if COND0x06 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0077() {
	FillFlags();
	int8_t address = read8();
	if COND0x07 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0078() {
	FillFlags();
	int8_t address = read8();
	if COND0x08 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0079() {
	FillFlags();
	int8_t address = read8();
	if COND0x09 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code007A() {
	FillFlags();
	int8_t address = read8();
	if COND0x0A {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code007B() {
	FillFlags();
	int8_t address = read8();
	if COND0x0B {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code007C() {
	FillFlags();
	int8_t address = read8();
	if COND0x0C {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code007D() {
	FillFlags();
	int8_t address = read8();
	if COND0x0D {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code007E() {
	FillFlags();
	int8_t address = read8();
	if COND0x0E {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code007F() {
	FillFlags();
	int8_t address = read8();
	if COND0x0F {
		context.index += address;
	}
}
//Int
void handlerCommand32Code00CD() {
	uint8_t addr = read8u();
	context.functions[addr](addr);
}
//Push
void handlerCommand32Code0050P66P67() {
	uint8_t reg = 0x00;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0050P67() {
	uint8_t reg = 0x00;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0050P66() {
	uint8_t reg = 0x00;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0050() {
	uint8_t reg = 0x00;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0051P66P67() {
	uint8_t reg = 0x01;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0051P67() {
	uint8_t reg = 0x01;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0051P66() {
	uint8_t reg = 0x01;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0051() {
	uint8_t reg = 0x01;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0052P66P67() {
	uint8_t reg = 0x02;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0052P67() {
	uint8_t reg = 0x02;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0052P66() {
	uint8_t reg = 0x02;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0052() {
	uint8_t reg = 0x02;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0053P66P67() {
	uint8_t reg = 0x03;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0053P67() {
	uint8_t reg = 0x03;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0053P66() {
	uint8_t reg = 0x03;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0053() {
	uint8_t reg = 0x03;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0054P66P67() {
	uint8_t reg = 0x04;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0054P67() {
	uint8_t reg = 0x04;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0054P66() {
	uint8_t reg = 0x04;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0054() {
	uint8_t reg = 0x04;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0055P66P67() {
	uint8_t reg = 0x05;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0055P67() {
	uint8_t reg = 0x05;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0055P66() {
	uint8_t reg = 0x05;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0055() {
	uint8_t reg = 0x05;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0056P66P67() {
	uint8_t reg = 0x06;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0056P67() {
	uint8_t reg = 0x06;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0056P66() {
	uint8_t reg = 0x06;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0056() {
	uint8_t reg = 0x06;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0057P66P67() {
	uint8_t reg = 0x07;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0057P67() {
	uint8_t reg = 0x07;
	uint16_t* sp = register16u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Push
void handlerCommand32Code0057P66() {
	uint8_t reg = 0x07;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = *register16u(reg);
}
//Push
void handlerCommand32Code0057() {
	uint8_t reg = 0x07;
	uint32_t* sp = register32u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = *register32u(reg);
}
//Pop
void handlerCommand32Code0058P66P67() {
	uint8_t reg = 0x00;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code0058P67() {
	uint8_t reg = 0x00;
	uint16_t* sp = register16u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code0058P66() {
	uint8_t reg = 0x00;
	uint32_t* sp = register32u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code0058() {
	uint8_t reg = 0x00;
	uint32_t* sp = register32u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code0059P66P67() {
	uint8_t reg = 0x01;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code0059P67() {
	uint8_t reg = 0x01;
	uint16_t* sp = register16u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code0059P66() {
	uint8_t reg = 0x01;
	uint32_t* sp = register32u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code0059() {
	uint8_t reg = 0x01;
	uint32_t* sp = register32u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code005AP66P67() {
	uint8_t reg = 0x02;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code005AP67() {
	uint8_t reg = 0x02;
	uint16_t* sp = register16u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code005AP66() {
	uint8_t reg = 0x02;
	uint32_t* sp = register32u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code005A() {
	uint8_t reg = 0x02;
	uint32_t* sp = register32u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code005BP66P67() {
	uint8_t reg = 0x03;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code005BP67() {
	uint8_t reg = 0x03;
	uint16_t* sp = register16u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code005BP66() {
	uint8_t reg = 0x03;
	uint32_t* sp = register32u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code005B() {
	uint8_t reg = 0x03;
	uint32_t* sp = register32u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code005CP66P67() {
	uint8_t reg = 0x04;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code005CP67() {
	uint8_t reg = 0x04;
	uint16_t* sp = register16u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code005CP66() {
	uint8_t reg = 0x04;
	uint32_t* sp = register32u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code005C() {
	uint8_t reg = 0x04;
	uint32_t* sp = register32u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code005DP66P67() {
	uint8_t reg = 0x05;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code005DP67() {
	uint8_t reg = 0x05;
	uint16_t* sp = register16u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code005DP66() {
	uint8_t reg = 0x05;
	uint32_t* sp = register32u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code005D() {
	uint8_t reg = 0x05;
	uint32_t* sp = register32u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code005EP66P67() {
	uint8_t reg = 0x06;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code005EP67() {
	uint8_t reg = 0x06;
	uint16_t* sp = register16u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code005EP66() {
	uint8_t reg = 0x06;
	uint32_t* sp = register32u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code005E() {
	uint8_t reg = 0x06;
	uint32_t* sp = register32u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code005FP66P67() {
	uint8_t reg = 0x07;
	uint16_t* sp = register16u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code005FP67() {
	uint8_t reg = 0x07;
	uint16_t* sp = register16u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Pop
void handlerCommand32Code005FP66() {
	uint8_t reg = 0x07;
	uint32_t* sp = register32u(BR_SP);
	*register16u(reg) = *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Pop
void handlerCommand32Code005F() {
	uint8_t reg = 0x07;
	uint32_t* sp = register32u(BR_SP);
	*register32u(reg) = *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Leave
void handlerCommand32Code00C9P66P67() {
	*register16u(BR_SP) = *register16u(BR_BP);
	*register16u(BR_BP) = *(uint16_t*)(mem(SR_SS) + *register16u(BR_SP));
	*register16u(BR_SP) += 16 / 8;
}
//Leave
void handlerCommand32Code00C9P67() {
	*register16u(BR_SP) = *register16u(BR_BP);
	*register32u(BR_BP) = *(uint32_t*)(mem(SR_SS) + *register16u(BR_SP));
	*register32u(BR_SP) += 32 / 8;
}
//Leave
void handlerCommand32Code00C9P66() {
	*register32u(BR_SP) = *register32u(BR_BP);
	*register16u(BR_BP) = *(uint16_t*)(mem(SR_SS) + *register32u(BR_SP));
	*register16u(BR_SP) += 16 / 8;
}
//Leave
void handlerCommand32Code00C9() {
	*register32u(BR_SP) = *register32u(BR_BP);
	*register32u(BR_BP) = *(uint32_t*)(mem(SR_SS) + *register32u(BR_SP));
	*register32u(BR_SP) += 32 / 8;
}
//Ofther
void handlerCommand32Code00FFP66P67() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	switch (nnn) {
		case 0x00: {
			// MOVEL
			*target = read8u();
		}
		break;
		case 0x6: {
			// PUSH
			uint16_t* sp = register16u(BR_SP);
			*sp -= 16 / 8;
			*(uint16_t*)(mem(SR_SS) + *sp) = *(uint16_t*)target;
		}
		break;
	}
}
//Ofther
void handlerCommand32Code00FFP67() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	switch (nnn) {
		case 0x00: {
			// MOVEL
			*target = read8u();
		}
		break;
		case 0x6: {
			// PUSH
			uint16_t* sp = register16u(BR_SP);
			*sp -= 32 / 8;
			*(uint32_t*)(mem(SR_SS) + *sp) = *(uint32_t*)target;
		}
		break;
	}
}
//Ofther
void handlerCommand32Code00FFP66() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	switch (nnn) {
		case 0x00: {
			// MOVEL
			*target = read8u();
		}
		break;
		case 0x6: {
			// PUSH
			uint32_t* sp = register32u(BR_SP);
			*sp -= 16 / 8;
			*(uint16_t*)(mem(SR_SS) + *sp) = *(uint16_t*)target;
		}
		break;
	}
}
//Ofther
void handlerCommand32Code00FF() {
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	switch (nnn) {
		case 0x00: {
			// MOVEL
			*target = read8u();
		}
		break;
		case 0x6: {
			// PUSH
			uint32_t* sp = register32u(BR_SP);
			*sp -= 32 / 8;
			*(uint32_t*)(mem(SR_SS) + *sp) = *(uint32_t*)target;
		}
		break;
	}
}
//Push
void handlerCommand32Code006AP67() {
	uint16_t* sp = register16u(BR_SP);
	*sp -= 8 / 8;
	*(uint8_t*)(mem(SR_SS) + *sp) = read8u();
}
//Push
void handlerCommand32Code006A() {
	uint32_t* sp = register32u(BR_SP);
	*sp -= 8 / 8;
	*(uint8_t*)(mem(SR_SS) + *sp) = read8u();
}
//Push
void handlerCommand32Code0068P66P67() {
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = read16u();
}
//Push
void handlerCommand32Code0068P67() {
	uint16_t* sp = register16u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = read32u();
}
//Push
void handlerCommand32Code0068P66() {
	uint32_t* sp = register32u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = read16u();
}
//Push
void handlerCommand32Code0068() {
	uint32_t* sp = register32u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = read32u();
}
//Lea
void handlerCommand32Code008DP66P67() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	*((uint16_t*)source) = (uint16_t)(((uint64_t)(target - context.memory)) & 0xFFFF);
}
//Lea
void handlerCommand32Code008DP67() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	*((uint32_t*)source) = (uint32_t)(((uint64_t)(target - context.memory)) & 0xFFFFFFFF);
}
//Lea
void handlerCommand32Code008DP66() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	*((uint16_t*)source) = (uint16_t)(((uint64_t)(target - context.memory)) & 0xFFFF);
}
//Lea
void handlerCommand32Code008D() {
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	*((uint32_t*)source) = (uint32_t)(((uint64_t)(target - context.memory)) & 0xFFFFFFFF);
}
 

void mCommandFunctionEmpty() {
	context.end = 2;
	printf("function not implementation\n");
}
void installCommandFunction() {
	for(int i = 0; i < 256 * 8; i++) {
		commandFunctions16[i] = mCommandFunctionEmpty;
		commandFunctions32[i] = mCommandFunctionEmpty;
	}
	commandFunctions16[0] = handlerCommand16Code0000;
	commandFunctions16[1] = handlerCommand16Code0001;
	commandFunctions16[2] = handlerCommand16Code0002;
	commandFunctions16[3] = handlerCommand16Code0003;
	commandFunctions16[8] = handlerCommand16Code0008;
	commandFunctions16[9] = handlerCommand16Code0009;
	commandFunctions16[10] = handlerCommand16Code000A;
	commandFunctions16[11] = handlerCommand16Code000B;
	commandFunctions16[32] = handlerCommand16Code0020;
	commandFunctions16[33] = handlerCommand16Code0021;
	commandFunctions16[34] = handlerCommand16Code0022;
	commandFunctions16[35] = handlerCommand16Code0023;
	commandFunctions16[40] = handlerCommand16Code0028;
	commandFunctions16[41] = handlerCommand16Code0029;
	commandFunctions16[42] = handlerCommand16Code002A;
	commandFunctions16[43] = handlerCommand16Code002B;
	commandFunctions16[48] = handlerCommand16Code0030;
	commandFunctions16[49] = handlerCommand16Code0031;
	commandFunctions16[50] = handlerCommand16Code0032;
	commandFunctions16[51] = handlerCommand16Code0033;
	commandFunctions16[56] = handlerCommand16Code0038;
	commandFunctions16[57] = handlerCommand16Code0039;
	commandFunctions16[58] = handlerCommand16Code003A;
	commandFunctions16[59] = handlerCommand16Code003B;
	commandFunctions16[128] = handlerCommand16Code0080;
	commandFunctions16[129] = handlerCommand16Code0081;
	commandFunctions16[130] = handlerCommand16Code0082;
	commandFunctions16[131] = handlerCommand16Code0083;
	commandFunctions16[431] = handlerCommand16Code01AF;
	commandFunctions16[136] = handlerCommand16Code0088;
	commandFunctions16[137] = handlerCommand16Code0089;
	commandFunctions16[138] = handlerCommand16Code008A;
	commandFunctions16[139] = handlerCommand16Code008B;
	commandFunctions16[176] = handlerCommand16Code00B0;
	commandFunctions16[177] = handlerCommand16Code00B1;
	commandFunctions16[178] = handlerCommand16Code00B2;
	commandFunctions16[179] = handlerCommand16Code00B3;
	commandFunctions16[180] = handlerCommand16Code00B4;
	commandFunctions16[181] = handlerCommand16Code00B5;
	commandFunctions16[182] = handlerCommand16Code00B6;
	commandFunctions16[183] = handlerCommand16Code00B7;
	commandFunctions16[184] = handlerCommand16Code00B8;
	commandFunctions16[185] = handlerCommand16Code00B9;
	commandFunctions16[186] = handlerCommand16Code00BA;
	commandFunctions16[187] = handlerCommand16Code00BB;
	commandFunctions16[188] = handlerCommand16Code00BC;
	commandFunctions16[189] = handlerCommand16Code00BD;
	commandFunctions16[190] = handlerCommand16Code00BE;
	commandFunctions16[191] = handlerCommand16Code00BF;
	commandFunctions16[64] = handlerCommand16Code0040;
	commandFunctions16[65] = handlerCommand16Code0041;
	commandFunctions16[66] = handlerCommand16Code0042;
	commandFunctions16[67] = handlerCommand16Code0043;
	commandFunctions16[68] = handlerCommand16Code0044;
	commandFunctions16[69] = handlerCommand16Code0045;
	commandFunctions16[70] = handlerCommand16Code0046;
	commandFunctions16[71] = handlerCommand16Code0047;
	commandFunctions16[72] = handlerCommand16Code0048;
	commandFunctions16[73] = handlerCommand16Code0049;
	commandFunctions16[74] = handlerCommand16Code004A;
	commandFunctions16[75] = handlerCommand16Code004B;
	commandFunctions16[76] = handlerCommand16Code004C;
	commandFunctions16[77] = handlerCommand16Code004D;
	commandFunctions16[78] = handlerCommand16Code004E;
	commandFunctions16[79] = handlerCommand16Code004F;
	commandFunctions16[226] = handlerCommand16Code00E2;
	commandFunctions16[235] = handlerCommand16Code00EB;
	commandFunctions16[232] = handlerCommand16Code00E8;
	commandFunctions16[195] = handlerCommand16Code00C3;
	commandFunctions16[112] = handlerCommand16Code0070;
	commandFunctions16[113] = handlerCommand16Code0071;
	commandFunctions16[114] = handlerCommand16Code0072;
	commandFunctions16[115] = handlerCommand16Code0073;
	commandFunctions16[116] = handlerCommand16Code0074;
	commandFunctions16[117] = handlerCommand16Code0075;
	commandFunctions16[118] = handlerCommand16Code0076;
	commandFunctions16[119] = handlerCommand16Code0077;
	commandFunctions16[120] = handlerCommand16Code0078;
	commandFunctions16[121] = handlerCommand16Code0079;
	commandFunctions16[122] = handlerCommand16Code007A;
	commandFunctions16[123] = handlerCommand16Code007B;
	commandFunctions16[124] = handlerCommand16Code007C;
	commandFunctions16[125] = handlerCommand16Code007D;
	commandFunctions16[126] = handlerCommand16Code007E;
	commandFunctions16[127] = handlerCommand16Code007F;
	commandFunctions16[205] = handlerCommand16Code00CD;
	commandFunctions16[80] = handlerCommand16Code0050;
	commandFunctions16[81] = handlerCommand16Code0051;
	commandFunctions16[82] = handlerCommand16Code0052;
	commandFunctions16[83] = handlerCommand16Code0053;
	commandFunctions16[84] = handlerCommand16Code0054;
	commandFunctions16[85] = handlerCommand16Code0055;
	commandFunctions16[86] = handlerCommand16Code0056;
	commandFunctions16[87] = handlerCommand16Code0057;
	commandFunctions16[88] = handlerCommand16Code0058;
	commandFunctions16[89] = handlerCommand16Code0059;
	commandFunctions16[90] = handlerCommand16Code005A;
	commandFunctions16[91] = handlerCommand16Code005B;
	commandFunctions16[92] = handlerCommand16Code005C;
	commandFunctions16[93] = handlerCommand16Code005D;
	commandFunctions16[94] = handlerCommand16Code005E;
	commandFunctions16[95] = handlerCommand16Code005F;
	commandFunctions16[201] = handlerCommand16Code00C9;
	commandFunctions16[255] = handlerCommand16Code00FF;
	commandFunctions16[106] = handlerCommand16Code006A;
	commandFunctions16[104] = handlerCommand16Code0068;
	commandFunctions16[141] = handlerCommand16Code008D;
	commandFunctions32[0] = handlerCommand32Code0000;
	commandFunctions32[0 | 0x0400] = handlerCommand32Code0000P66;
	commandFunctions32[1] = handlerCommand32Code0001;
	commandFunctions32[1 | 0x0400] = handlerCommand32Code0001P66;
	commandFunctions32[2] = handlerCommand32Code0002;
	commandFunctions32[2 | 0x0400] = handlerCommand32Code0002P66;
	commandFunctions32[3] = handlerCommand32Code0003;
	commandFunctions32[3 | 0x0400] = handlerCommand32Code0003P66;
	commandFunctions32[8] = handlerCommand32Code0008;
	commandFunctions32[8 | 0x0400] = handlerCommand32Code0008P66;
	commandFunctions32[9] = handlerCommand32Code0009;
	commandFunctions32[9 | 0x0400] = handlerCommand32Code0009P66;
	commandFunctions32[10] = handlerCommand32Code000A;
	commandFunctions32[10 | 0x0400] = handlerCommand32Code000AP66;
	commandFunctions32[11] = handlerCommand32Code000B;
	commandFunctions32[11 | 0x0400] = handlerCommand32Code000BP66;
	commandFunctions32[32] = handlerCommand32Code0020;
	commandFunctions32[32 | 0x0400] = handlerCommand32Code0020P66;
	commandFunctions32[33] = handlerCommand32Code0021;
	commandFunctions32[33 | 0x0400] = handlerCommand32Code0021P66;
	commandFunctions32[34] = handlerCommand32Code0022;
	commandFunctions32[34 | 0x0400] = handlerCommand32Code0022P66;
	commandFunctions32[35] = handlerCommand32Code0023;
	commandFunctions32[35 | 0x0400] = handlerCommand32Code0023P66;
	commandFunctions32[40] = handlerCommand32Code0028;
	commandFunctions32[40 | 0x0400] = handlerCommand32Code0028P66;
	commandFunctions32[41] = handlerCommand32Code0029;
	commandFunctions32[41 | 0x0400] = handlerCommand32Code0029P66;
	commandFunctions32[42] = handlerCommand32Code002A;
	commandFunctions32[42 | 0x0400] = handlerCommand32Code002AP66;
	commandFunctions32[43] = handlerCommand32Code002B;
	commandFunctions32[43 | 0x0400] = handlerCommand32Code002BP66;
	commandFunctions32[48] = handlerCommand32Code0030;
	commandFunctions32[48 | 0x0400] = handlerCommand32Code0030P66;
	commandFunctions32[49] = handlerCommand32Code0031;
	commandFunctions32[49 | 0x0400] = handlerCommand32Code0031P66;
	commandFunctions32[50] = handlerCommand32Code0032;
	commandFunctions32[50 | 0x0400] = handlerCommand32Code0032P66;
	commandFunctions32[51] = handlerCommand32Code0033;
	commandFunctions32[51 | 0x0400] = handlerCommand32Code0033P66;
	commandFunctions32[56] = handlerCommand32Code0038;
	commandFunctions32[56 | 0x0400] = handlerCommand32Code0038P66;
	commandFunctions32[57] = handlerCommand32Code0039;
	commandFunctions32[57 | 0x0400] = handlerCommand32Code0039P66;
	commandFunctions32[58] = handlerCommand32Code003A;
	commandFunctions32[58 | 0x0400] = handlerCommand32Code003AP66;
	commandFunctions32[59] = handlerCommand32Code003B;
	commandFunctions32[59 | 0x0400] = handlerCommand32Code003BP66;
	commandFunctions32[128] = handlerCommand32Code0080;
	commandFunctions32[128 | 0x0200 ] = handlerCommand32Code0080P67;
	commandFunctions32[128 | 0x0400] = handlerCommand32Code0080P66;
	commandFunctions32[128 | 0x0200 | 0x0400] = handlerCommand32Code0080P66P67;
	commandFunctions32[129] = handlerCommand32Code0081;
	commandFunctions32[129 | 0x0200 ] = handlerCommand32Code0081P67;
	commandFunctions32[129 | 0x0400] = handlerCommand32Code0081P66;
	commandFunctions32[129 | 0x0200 | 0x0400] = handlerCommand32Code0081P66P67;
	commandFunctions32[130] = handlerCommand32Code0082;
	commandFunctions32[131] = handlerCommand32Code0083;
	commandFunctions32[431] = handlerCommand32Code01AF;
	commandFunctions32[136] = handlerCommand32Code0088;
	commandFunctions32[136 | 0x0400] = handlerCommand32Code0088P66;
	commandFunctions32[137] = handlerCommand32Code0089;
	commandFunctions32[137 | 0x0400] = handlerCommand32Code0089P66;
	commandFunctions32[138] = handlerCommand32Code008A;
	commandFunctions32[138 | 0x0400] = handlerCommand32Code008AP66;
	commandFunctions32[139] = handlerCommand32Code008B;
	commandFunctions32[139 | 0x0400] = handlerCommand32Code008BP66;
	commandFunctions32[176] = handlerCommand32Code00B0;
	commandFunctions32[176 | 0x0400] = handlerCommand32Code00B0P66;
	commandFunctions32[177] = handlerCommand32Code00B1;
	commandFunctions32[177 | 0x0400] = handlerCommand32Code00B1P66;
	commandFunctions32[178] = handlerCommand32Code00B2;
	commandFunctions32[178 | 0x0400] = handlerCommand32Code00B2P66;
	commandFunctions32[179] = handlerCommand32Code00B3;
	commandFunctions32[179 | 0x0400] = handlerCommand32Code00B3P66;
	commandFunctions32[180] = handlerCommand32Code00B4;
	commandFunctions32[180 | 0x0400] = handlerCommand32Code00B4P66;
	commandFunctions32[181] = handlerCommand32Code00B5;
	commandFunctions32[181 | 0x0400] = handlerCommand32Code00B5P66;
	commandFunctions32[182] = handlerCommand32Code00B6;
	commandFunctions32[182 | 0x0400] = handlerCommand32Code00B6P66;
	commandFunctions32[183] = handlerCommand32Code00B7;
	commandFunctions32[183 | 0x0400] = handlerCommand32Code00B7P66;
	commandFunctions32[184] = handlerCommand32Code00B8;
	commandFunctions32[184 | 0x0400] = handlerCommand32Code00B8P66;
	commandFunctions32[185] = handlerCommand32Code00B9;
	commandFunctions32[185 | 0x0400] = handlerCommand32Code00B9P66;
	commandFunctions32[186] = handlerCommand32Code00BA;
	commandFunctions32[186 | 0x0400] = handlerCommand32Code00BAP66;
	commandFunctions32[187] = handlerCommand32Code00BB;
	commandFunctions32[187 | 0x0400] = handlerCommand32Code00BBP66;
	commandFunctions32[188] = handlerCommand32Code00BC;
	commandFunctions32[188 | 0x0400] = handlerCommand32Code00BCP66;
	commandFunctions32[189] = handlerCommand32Code00BD;
	commandFunctions32[189 | 0x0400] = handlerCommand32Code00BDP66;
	commandFunctions32[190] = handlerCommand32Code00BE;
	commandFunctions32[190 | 0x0400] = handlerCommand32Code00BEP66;
	commandFunctions32[191] = handlerCommand32Code00BF;
	commandFunctions32[191 | 0x0400] = handlerCommand32Code00BFP66;
	commandFunctions32[64] = handlerCommand32Code0040;
	commandFunctions32[64 | 0x0400] = handlerCommand32Code0040P66;
	commandFunctions32[65] = handlerCommand32Code0041;
	commandFunctions32[65 | 0x0400] = handlerCommand32Code0041P66;
	commandFunctions32[66] = handlerCommand32Code0042;
	commandFunctions32[66 | 0x0400] = handlerCommand32Code0042P66;
	commandFunctions32[67] = handlerCommand32Code0043;
	commandFunctions32[67 | 0x0400] = handlerCommand32Code0043P66;
	commandFunctions32[68] = handlerCommand32Code0044;
	commandFunctions32[68 | 0x0400] = handlerCommand32Code0044P66;
	commandFunctions32[69] = handlerCommand32Code0045;
	commandFunctions32[69 | 0x0400] = handlerCommand32Code0045P66;
	commandFunctions32[70] = handlerCommand32Code0046;
	commandFunctions32[70 | 0x0400] = handlerCommand32Code0046P66;
	commandFunctions32[71] = handlerCommand32Code0047;
	commandFunctions32[71 | 0x0400] = handlerCommand32Code0047P66;
	commandFunctions32[72] = handlerCommand32Code0048;
	commandFunctions32[72 | 0x0400] = handlerCommand32Code0048P66;
	commandFunctions32[73] = handlerCommand32Code0049;
	commandFunctions32[73 | 0x0400] = handlerCommand32Code0049P66;
	commandFunctions32[74] = handlerCommand32Code004A;
	commandFunctions32[74 | 0x0400] = handlerCommand32Code004AP66;
	commandFunctions32[75] = handlerCommand32Code004B;
	commandFunctions32[75 | 0x0400] = handlerCommand32Code004BP66;
	commandFunctions32[76] = handlerCommand32Code004C;
	commandFunctions32[76 | 0x0400] = handlerCommand32Code004CP66;
	commandFunctions32[77] = handlerCommand32Code004D;
	commandFunctions32[77 | 0x0400] = handlerCommand32Code004DP66;
	commandFunctions32[78] = handlerCommand32Code004E;
	commandFunctions32[78 | 0x0400] = handlerCommand32Code004EP66;
	commandFunctions32[79] = handlerCommand32Code004F;
	commandFunctions32[79 | 0x0400] = handlerCommand32Code004FP66;
	commandFunctions32[226] = handlerCommand32Code00E2;
	commandFunctions32[235] = handlerCommand32Code00EB;
	commandFunctions32[232] = handlerCommand32Code00E8;
	commandFunctions32[232 | 0x0400] = handlerCommand32Code00E8P66;
	commandFunctions32[195] = handlerCommand32Code00C3;
	commandFunctions32[112] = handlerCommand32Code0070;
	commandFunctions32[113] = handlerCommand32Code0071;
	commandFunctions32[114] = handlerCommand32Code0072;
	commandFunctions32[115] = handlerCommand32Code0073;
	commandFunctions32[116] = handlerCommand32Code0074;
	commandFunctions32[117] = handlerCommand32Code0075;
	commandFunctions32[118] = handlerCommand32Code0076;
	commandFunctions32[119] = handlerCommand32Code0077;
	commandFunctions32[120] = handlerCommand32Code0078;
	commandFunctions32[121] = handlerCommand32Code0079;
	commandFunctions32[122] = handlerCommand32Code007A;
	commandFunctions32[123] = handlerCommand32Code007B;
	commandFunctions32[124] = handlerCommand32Code007C;
	commandFunctions32[125] = handlerCommand32Code007D;
	commandFunctions32[126] = handlerCommand32Code007E;
	commandFunctions32[127] = handlerCommand32Code007F;
	commandFunctions32[205] = handlerCommand32Code00CD;
	commandFunctions32[80] = handlerCommand32Code0050;
	commandFunctions32[80 | 0x0200 ] = handlerCommand32Code0050P67;
	commandFunctions32[80 | 0x0400] = handlerCommand32Code0050P66;
	commandFunctions32[80 | 0x0200 | 0x0400] = handlerCommand32Code0050P66P67;
	commandFunctions32[81] = handlerCommand32Code0051;
	commandFunctions32[81 | 0x0200 ] = handlerCommand32Code0051P67;
	commandFunctions32[81 | 0x0400] = handlerCommand32Code0051P66;
	commandFunctions32[81 | 0x0200 | 0x0400] = handlerCommand32Code0051P66P67;
	commandFunctions32[82] = handlerCommand32Code0052;
	commandFunctions32[82 | 0x0200 ] = handlerCommand32Code0052P67;
	commandFunctions32[82 | 0x0400] = handlerCommand32Code0052P66;
	commandFunctions32[82 | 0x0200 | 0x0400] = handlerCommand32Code0052P66P67;
	commandFunctions32[83] = handlerCommand32Code0053;
	commandFunctions32[83 | 0x0200 ] = handlerCommand32Code0053P67;
	commandFunctions32[83 | 0x0400] = handlerCommand32Code0053P66;
	commandFunctions32[83 | 0x0200 | 0x0400] = handlerCommand32Code0053P66P67;
	commandFunctions32[84] = handlerCommand32Code0054;
	commandFunctions32[84 | 0x0200 ] = handlerCommand32Code0054P67;
	commandFunctions32[84 | 0x0400] = handlerCommand32Code0054P66;
	commandFunctions32[84 | 0x0200 | 0x0400] = handlerCommand32Code0054P66P67;
	commandFunctions32[85] = handlerCommand32Code0055;
	commandFunctions32[85 | 0x0200 ] = handlerCommand32Code0055P67;
	commandFunctions32[85 | 0x0400] = handlerCommand32Code0055P66;
	commandFunctions32[85 | 0x0200 | 0x0400] = handlerCommand32Code0055P66P67;
	commandFunctions32[86] = handlerCommand32Code0056;
	commandFunctions32[86 | 0x0200 ] = handlerCommand32Code0056P67;
	commandFunctions32[86 | 0x0400] = handlerCommand32Code0056P66;
	commandFunctions32[86 | 0x0200 | 0x0400] = handlerCommand32Code0056P66P67;
	commandFunctions32[87] = handlerCommand32Code0057;
	commandFunctions32[87 | 0x0200 ] = handlerCommand32Code0057P67;
	commandFunctions32[87 | 0x0400] = handlerCommand32Code0057P66;
	commandFunctions32[87 | 0x0200 | 0x0400] = handlerCommand32Code0057P66P67;
	commandFunctions32[88] = handlerCommand32Code0058;
	commandFunctions32[88 | 0x0200 ] = handlerCommand32Code0058P67;
	commandFunctions32[88 | 0x0400] = handlerCommand32Code0058P66;
	commandFunctions32[88 | 0x0200 | 0x0400] = handlerCommand32Code0058P66P67;
	commandFunctions32[89] = handlerCommand32Code0059;
	commandFunctions32[89 | 0x0200 ] = handlerCommand32Code0059P67;
	commandFunctions32[89 | 0x0400] = handlerCommand32Code0059P66;
	commandFunctions32[89 | 0x0200 | 0x0400] = handlerCommand32Code0059P66P67;
	commandFunctions32[90] = handlerCommand32Code005A;
	commandFunctions32[90 | 0x0200 ] = handlerCommand32Code005AP67;
	commandFunctions32[90 | 0x0400] = handlerCommand32Code005AP66;
	commandFunctions32[90 | 0x0200 | 0x0400] = handlerCommand32Code005AP66P67;
	commandFunctions32[91] = handlerCommand32Code005B;
	commandFunctions32[91 | 0x0200 ] = handlerCommand32Code005BP67;
	commandFunctions32[91 | 0x0400] = handlerCommand32Code005BP66;
	commandFunctions32[91 | 0x0200 | 0x0400] = handlerCommand32Code005BP66P67;
	commandFunctions32[92] = handlerCommand32Code005C;
	commandFunctions32[92 | 0x0200 ] = handlerCommand32Code005CP67;
	commandFunctions32[92 | 0x0400] = handlerCommand32Code005CP66;
	commandFunctions32[92 | 0x0200 | 0x0400] = handlerCommand32Code005CP66P67;
	commandFunctions32[93] = handlerCommand32Code005D;
	commandFunctions32[93 | 0x0200 ] = handlerCommand32Code005DP67;
	commandFunctions32[93 | 0x0400] = handlerCommand32Code005DP66;
	commandFunctions32[93 | 0x0200 | 0x0400] = handlerCommand32Code005DP66P67;
	commandFunctions32[94] = handlerCommand32Code005E;
	commandFunctions32[94 | 0x0200 ] = handlerCommand32Code005EP67;
	commandFunctions32[94 | 0x0400] = handlerCommand32Code005EP66;
	commandFunctions32[94 | 0x0200 | 0x0400] = handlerCommand32Code005EP66P67;
	commandFunctions32[95] = handlerCommand32Code005F;
	commandFunctions32[95 | 0x0200 ] = handlerCommand32Code005FP67;
	commandFunctions32[95 | 0x0400] = handlerCommand32Code005FP66;
	commandFunctions32[95 | 0x0200 | 0x0400] = handlerCommand32Code005FP66P67;
	commandFunctions32[201] = handlerCommand32Code00C9;
	commandFunctions32[201 | 0x0200 ] = handlerCommand32Code00C9P67;
	commandFunctions32[201 | 0x0400] = handlerCommand32Code00C9P66;
	commandFunctions32[201 | 0x0200 | 0x0400] = handlerCommand32Code00C9P66P67;
	commandFunctions32[255] = handlerCommand32Code00FF;
	commandFunctions32[255 | 0x0200 ] = handlerCommand32Code00FFP67;
	commandFunctions32[255 | 0x0400] = handlerCommand32Code00FFP66;
	commandFunctions32[255 | 0x0200 | 0x0400] = handlerCommand32Code00FFP66P67;
	commandFunctions32[106] = handlerCommand32Code006A;
	commandFunctions32[106 | 0x0200 ] = handlerCommand32Code006AP67;
	commandFunctions32[104] = handlerCommand32Code0068;
	commandFunctions32[104 | 0x0200 ] = handlerCommand32Code0068P67;
	commandFunctions32[104 | 0x0400] = handlerCommand32Code0068P66;
	commandFunctions32[104 | 0x0200 | 0x0400] = handlerCommand32Code0068P66P67;
	commandFunctions32[141] = handlerCommand32Code008D;
	commandFunctions32[141 | 0x0200 ] = handlerCommand32Code008DP67;
	commandFunctions32[141 | 0x0400] = handlerCommand32Code008DP66;
	commandFunctions32[141 | 0x0200 | 0x0400] = handlerCommand32Code008DP66P67;
}
