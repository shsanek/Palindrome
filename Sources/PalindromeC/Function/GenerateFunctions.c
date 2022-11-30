#include "GenerateFunctions.h"
void mCommandFunctionEmpty() {
	context.end = 2;
	printf("function not implementation %X\n", context.lastCommandInfo.command);
	//*((uint8_t*)NULL) = 0;
}
//ADD
void handlerCommand16Code0000P66() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand16Code0000() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand16Code0001P66() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_ADD32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//ADD
void handlerCommand16Code0001() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_ADD16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//ADD
void handlerCommand16Code0002P66() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand16Code0002() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand16Code0003P66() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_ADD32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//ADD
void handlerCommand16Code0003() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_ADD16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//ADD
void handlerCommand16Code0004P66() {
	LOG("%s","ADD");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_ADD8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand16Code0004() {
	LOG("%s","ADD");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_ADD8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand16Code0005P66() {
	LOG("%s","ADD");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_ADD32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//ADD
void handlerCommand16Code0005() {
	LOG("%s","ADD");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_ADD16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//Push
void handlerCommand16Code0006() {
	LOG("%s","Push");
	uint8_t rg = 0x00;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = context.segmentRegisters[rg];
}
//Push
void handlerCommand16Code000E() {
	LOG("%s","Push");
	uint8_t rg = 0x01;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = context.segmentRegisters[rg];
}
//Push
void handlerCommand16Code0016() {
	LOG("%s","Push");
	uint8_t rg = 0x02;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = context.segmentRegisters[rg];
}
//Push
void handlerCommand16Code001E() {
	LOG("%s","Push");
	uint8_t rg = 0x03;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = context.segmentRegisters[rg];
}
//Pop
void handlerCommand16Code0007() {
	LOG("%s","Pop");
	uint8_t rg = 0x00;
	    context.segmentRegisters[rg] = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	    reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand16Code000F() {
	LOG("%s","Pop");
	uint8_t rg = 0x01;
	// 0f???
}
//Pop
void handlerCommand16Code0017() {
	LOG("%s","Pop");
	uint8_t rg = 0x02;
	    context.segmentRegisters[rg] = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	    reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand16Code001F() {
	LOG("%s","Pop");
	uint8_t rg = 0x03;
	    context.segmentRegisters[rg] = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	    reg_SP_16u += 16 / 8;
}
//OR
void handlerCommand16Code0008P66() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand16Code0008() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand16Code0009P66() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) | ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_OR32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//OR
void handlerCommand16Code0009() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) | ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_OR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//OR
void handlerCommand16Code000AP66() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand16Code000A() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand16Code000BP66() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) | ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_OR32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//OR
void handlerCommand16Code000B() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) | ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_OR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//OR
void handlerCommand16Code000CP66() {
	LOG("%s","OR");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_OR8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand16Code000C() {
	LOG("%s","OR");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_OR8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand16Code000DP66() {
	LOG("%s","OR");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) | ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_OR32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//OR
void handlerCommand16Code000D() {
	LOG("%s","OR");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) | ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_OR16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//ADC
void handlerCommand16Code0010P66() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) + oldcf;
	lazyFlagType = t_ADC8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADC
void handlerCommand16Code0010() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) + oldcf;
	lazyFlagType = t_ADC8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADC
void handlerCommand16Code0011P66() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32) + oldcf;
	lazyFlagType = t_ADC32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//ADC
void handlerCommand16Code0011() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16) + oldcf;
	lazyFlagType = t_ADC16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//ADC
void handlerCommand16Code0012P66() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) + oldcf;
	lazyFlagType = t_ADC8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADC
void handlerCommand16Code0012() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) + oldcf;
	lazyFlagType = t_ADC8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADC
void handlerCommand16Code0013P66() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32) + oldcf;
	lazyFlagType = t_ADC32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//ADC
void handlerCommand16Code0013() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16) + oldcf;
	lazyFlagType = t_ADC16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//ADC
void handlerCommand16Code0014P66() {
	LOG("%s","ADC");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8)) + oldcf;
	lazyFlagType = t_ADC8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//ADC
void handlerCommand16Code0014() {
	LOG("%s","ADC");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8)) + oldcf;
	lazyFlagType = t_ADC8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//ADC
void handlerCommand16Code0015P66() {
	LOG("%s","ADC");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32)) + oldcf;
	lazyFlagType = t_ADC32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//ADC
void handlerCommand16Code0015() {
	LOG("%s","ADC");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16)) + oldcf;
	lazyFlagType = t_ADC16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//SBB
void handlerCommand16Code0018P66() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) - oldcf;
	lazyFlagType = t_SBB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SBB
void handlerCommand16Code0018() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) - oldcf;
	lazyFlagType = t_SBB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SBB
void handlerCommand16Code0019P66() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) - oldcf;
	lazyFlagType = t_SBB32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//SBB
void handlerCommand16Code0019() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) - oldcf;
	lazyFlagType = t_SBB16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//SBB
void handlerCommand16Code001AP66() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) - oldcf;
	lazyFlagType = t_SBB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SBB
void handlerCommand16Code001A() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) - oldcf;
	lazyFlagType = t_SBB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SBB
void handlerCommand16Code001BP66() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) - oldcf;
	lazyFlagType = t_SBB32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//SBB
void handlerCommand16Code001B() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) - oldcf;
	lazyFlagType = t_SBB16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//SBB
void handlerCommand16Code001CP66() {
	LOG("%s","SBB");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8)) - oldcf;
	lazyFlagType = t_SBB8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//SBB
void handlerCommand16Code001C() {
	LOG("%s","SBB");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8)) - oldcf;
	lazyFlagType = t_SBB8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//SBB
void handlerCommand16Code001DP66() {
	LOG("%s","SBB");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32)) - oldcf;
	lazyFlagType = t_SBB32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//SBB
void handlerCommand16Code001D() {
	LOG("%s","SBB");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16)) - oldcf;
	lazyFlagType = t_SBB16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//AND
void handlerCommand16Code0020P66() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand16Code0020() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand16Code0021P66() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) & ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_AND32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//AND
void handlerCommand16Code0021() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) & ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_AND16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//AND
void handlerCommand16Code0022P66() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand16Code0022() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand16Code0023P66() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) & ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_AND32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//AND
void handlerCommand16Code0023() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) & ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_AND16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//AND
void handlerCommand16Code0024P66() {
	LOG("%s","AND");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_AND8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand16Code0024() {
	LOG("%s","AND");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_AND8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand16Code0025P66() {
	LOG("%s","AND");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) & ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_AND32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//AND
void handlerCommand16Code0025() {
	LOG("%s","AND");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) & ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_AND16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//SUB
void handlerCommand16Code0028P66() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand16Code0028() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand16Code0029P66() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_SUB32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//SUB
void handlerCommand16Code0029() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_SUB16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//SUB
void handlerCommand16Code002AP66() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand16Code002A() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand16Code002BP66() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_SUB32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//SUB
void handlerCommand16Code002B() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_SUB16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//SUB
void handlerCommand16Code002CP66() {
	LOG("%s","SUB");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_SUB8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand16Code002C() {
	LOG("%s","SUB");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_SUB8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand16Code002DP66() {
	LOG("%s","SUB");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_SUB32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//SUB
void handlerCommand16Code002D() {
	LOG("%s","SUB");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_SUB16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//XOR
void handlerCommand16Code0030P66() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand16Code0030() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand16Code0031P66() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) ^ ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_XOR32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//XOR
void handlerCommand16Code0031() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) ^ ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_XOR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//XOR
void handlerCommand16Code0032P66() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand16Code0032() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand16Code0033P66() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) ^ ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_XOR32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//XOR
void handlerCommand16Code0033() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) ^ ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_XOR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//XOR
void handlerCommand16Code0034P66() {
	LOG("%s","XOR");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_XOR8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand16Code0034() {
	LOG("%s","XOR");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_XOR8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand16Code0035P66() {
	LOG("%s","XOR");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) ^ ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_XOR32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//XOR
void handlerCommand16Code0035() {
	LOG("%s","XOR");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) ^ ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_XOR16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//CMP
void handlerCommand16Code0038P66() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand16Code0038() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand16Code0039P66() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_CMP32;
}
//CMP
void handlerCommand16Code0039() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_CMP16;
}
//CMP
void handlerCommand16Code003AP66() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand16Code003A() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand16Code003BP66() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_CMP32;
}
//CMP
void handlerCommand16Code003B() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_CMP16;
}
//CMP
void handlerCommand16Code003CP66() {
	LOG("%s","CMP");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand16Code003C() {
	LOG("%s","CMP");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand16Code003DP66() {
	LOG("%s","CMP");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_CMP32;
}
//CMP
void handlerCommand16Code003D() {
	LOG("%s","CMP");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_CMP16;
}
//Inc
void handlerCommand16Code0040P66() {
	LOG("%s","Inc");
	reg_0x00_32u += 1;
	LazyFlagResultContainer32 = reg_0x00_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand16Code0040() {
	LOG("%s","Inc");
	reg_0x00_16u += 1;
	LazyFlagResultContainer16 = reg_0x00_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand16Code0041P66() {
	LOG("%s","Inc");
	reg_0x01_32u += 1;
	LazyFlagResultContainer32 = reg_0x01_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand16Code0041() {
	LOG("%s","Inc");
	reg_0x01_16u += 1;
	LazyFlagResultContainer16 = reg_0x01_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand16Code0042P66() {
	LOG("%s","Inc");
	reg_0x02_32u += 1;
	LazyFlagResultContainer32 = reg_0x02_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand16Code0042() {
	LOG("%s","Inc");
	reg_0x02_16u += 1;
	LazyFlagResultContainer16 = reg_0x02_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand16Code0043P66() {
	LOG("%s","Inc");
	reg_0x03_32u += 1;
	LazyFlagResultContainer32 = reg_0x03_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand16Code0043() {
	LOG("%s","Inc");
	reg_0x03_16u += 1;
	LazyFlagResultContainer16 = reg_0x03_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand16Code0044P66() {
	LOG("%s","Inc");
	reg_0x04_32u += 1;
	LazyFlagResultContainer32 = reg_0x04_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand16Code0044() {
	LOG("%s","Inc");
	reg_0x04_16u += 1;
	LazyFlagResultContainer16 = reg_0x04_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand16Code0045P66() {
	LOG("%s","Inc");
	reg_0x05_32u += 1;
	LazyFlagResultContainer32 = reg_0x05_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand16Code0045() {
	LOG("%s","Inc");
	reg_0x05_16u += 1;
	LazyFlagResultContainer16 = reg_0x05_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand16Code0046P66() {
	LOG("%s","Inc");
	reg_0x06_32u += 1;
	LazyFlagResultContainer32 = reg_0x06_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand16Code0046() {
	LOG("%s","Inc");
	reg_0x06_16u += 1;
	LazyFlagResultContainer16 = reg_0x06_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand16Code0047P66() {
	LOG("%s","Inc");
	reg_0x07_32u += 1;
	LazyFlagResultContainer32 = reg_0x07_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand16Code0047() {
	LOG("%s","Inc");
	reg_0x07_16u += 1;
	LazyFlagResultContainer16 = reg_0x07_16u;
	lazyFlagType = t_INC16;
}
//Dec
void handlerCommand16Code0048P66() {
	LOG("%s","Dec");
	reg_0x00_32u -= 1;
	LazyFlagResultContainer32 = reg_0x00_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand16Code0048() {
	LOG("%s","Dec");
	reg_0x00_16u -= 1;
	LazyFlagResultContainer16 = reg_0x00_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand16Code0049P66() {
	LOG("%s","Dec");
	reg_0x01_32u -= 1;
	LazyFlagResultContainer32 = reg_0x01_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand16Code0049() {
	LOG("%s","Dec");
	reg_0x01_16u -= 1;
	LazyFlagResultContainer16 = reg_0x01_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand16Code004AP66() {
	LOG("%s","Dec");
	reg_0x02_32u -= 1;
	LazyFlagResultContainer32 = reg_0x02_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand16Code004A() {
	LOG("%s","Dec");
	reg_0x02_16u -= 1;
	LazyFlagResultContainer16 = reg_0x02_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand16Code004BP66() {
	LOG("%s","Dec");
	reg_0x03_32u -= 1;
	LazyFlagResultContainer32 = reg_0x03_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand16Code004B() {
	LOG("%s","Dec");
	reg_0x03_16u -= 1;
	LazyFlagResultContainer16 = reg_0x03_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand16Code004CP66() {
	LOG("%s","Dec");
	reg_0x04_32u -= 1;
	LazyFlagResultContainer32 = reg_0x04_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand16Code004C() {
	LOG("%s","Dec");
	reg_0x04_16u -= 1;
	LazyFlagResultContainer16 = reg_0x04_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand16Code004DP66() {
	LOG("%s","Dec");
	reg_0x05_32u -= 1;
	LazyFlagResultContainer32 = reg_0x05_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand16Code004D() {
	LOG("%s","Dec");
	reg_0x05_16u -= 1;
	LazyFlagResultContainer16 = reg_0x05_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand16Code004EP66() {
	LOG("%s","Dec");
	reg_0x06_32u -= 1;
	LazyFlagResultContainer32 = reg_0x06_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand16Code004E() {
	LOG("%s","Dec");
	reg_0x06_16u -= 1;
	LazyFlagResultContainer16 = reg_0x06_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand16Code004FP66() {
	LOG("%s","Dec");
	reg_0x07_32u -= 1;
	LazyFlagResultContainer32 = reg_0x07_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand16Code004F() {
	LOG("%s","Dec");
	reg_0x07_16u -= 1;
	LazyFlagResultContainer16 = reg_0x07_16u;
	lazyFlagType = t_DEC16;
}
//Push
void handlerCommand16Code0050P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x00;
	uint32_t value = reg_0x00_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0050P67() {
	LOG("%s","Push");
	uint8_t reg = 0x00;
	uint16_t value = reg_0x00_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0050P66() {
	LOG("%s","Push");
	uint8_t reg = 0x00;
	uint32_t value = reg_0x00_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0050() {
	LOG("%s","Push");
	uint8_t reg = 0x00;
	uint16_t value = reg_0x00_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0051P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x01;
	uint32_t value = reg_0x01_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0051P67() {
	LOG("%s","Push");
	uint8_t reg = 0x01;
	uint16_t value = reg_0x01_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0051P66() {
	LOG("%s","Push");
	uint8_t reg = 0x01;
	uint32_t value = reg_0x01_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0051() {
	LOG("%s","Push");
	uint8_t reg = 0x01;
	uint16_t value = reg_0x01_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0052P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x02;
	uint32_t value = reg_0x02_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0052P67() {
	LOG("%s","Push");
	uint8_t reg = 0x02;
	uint16_t value = reg_0x02_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0052P66() {
	LOG("%s","Push");
	uint8_t reg = 0x02;
	uint32_t value = reg_0x02_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0052() {
	LOG("%s","Push");
	uint8_t reg = 0x02;
	uint16_t value = reg_0x02_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0053P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x03;
	uint32_t value = reg_0x03_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0053P67() {
	LOG("%s","Push");
	uint8_t reg = 0x03;
	uint16_t value = reg_0x03_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0053P66() {
	LOG("%s","Push");
	uint8_t reg = 0x03;
	uint32_t value = reg_0x03_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0053() {
	LOG("%s","Push");
	uint8_t reg = 0x03;
	uint16_t value = reg_0x03_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0054P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x04;
	uint32_t value = reg_0x04_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0054P67() {
	LOG("%s","Push");
	uint8_t reg = 0x04;
	uint16_t value = reg_0x04_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0054P66() {
	LOG("%s","Push");
	uint8_t reg = 0x04;
	uint32_t value = reg_0x04_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0054() {
	LOG("%s","Push");
	uint8_t reg = 0x04;
	uint16_t value = reg_0x04_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0055P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x05;
	uint32_t value = reg_0x05_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0055P67() {
	LOG("%s","Push");
	uint8_t reg = 0x05;
	uint16_t value = reg_0x05_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0055P66() {
	LOG("%s","Push");
	uint8_t reg = 0x05;
	uint32_t value = reg_0x05_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0055() {
	LOG("%s","Push");
	uint8_t reg = 0x05;
	uint16_t value = reg_0x05_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0056P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x06;
	uint32_t value = reg_0x06_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0056P67() {
	LOG("%s","Push");
	uint8_t reg = 0x06;
	uint16_t value = reg_0x06_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0056P66() {
	LOG("%s","Push");
	uint8_t reg = 0x06;
	uint32_t value = reg_0x06_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0056() {
	LOG("%s","Push");
	uint8_t reg = 0x06;
	uint16_t value = reg_0x06_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0057P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x07;
	uint32_t value = reg_0x07_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0057P67() {
	LOG("%s","Push");
	uint8_t reg = 0x07;
	uint16_t value = reg_0x07_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand16Code0057P66() {
	LOG("%s","Push");
	uint8_t reg = 0x07;
	uint32_t value = reg_0x07_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand16Code0057() {
	LOG("%s","Push");
	uint8_t reg = 0x07;
	uint16_t value = reg_0x07_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Pop
void handlerCommand16Code0058P66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x00;
	reg_0x00_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand16Code0058P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x00;
	reg_0x00_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand16Code0058P66() {
	LOG("%s","Pop");
	uint8_t reg = 0x00;
	reg_0x00_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand16Code0058() {
	LOG("%s","Pop");
	uint8_t reg = 0x00;
	reg_0x00_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand16Code0059P66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x01;
	reg_0x01_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand16Code0059P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x01;
	reg_0x01_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand16Code0059P66() {
	LOG("%s","Pop");
	uint8_t reg = 0x01;
	reg_0x01_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand16Code0059() {
	LOG("%s","Pop");
	uint8_t reg = 0x01;
	reg_0x01_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand16Code005AP66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x02;
	reg_0x02_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand16Code005AP67() {
	LOG("%s","Pop");
	uint8_t reg = 0x02;
	reg_0x02_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand16Code005AP66() {
	LOG("%s","Pop");
	uint8_t reg = 0x02;
	reg_0x02_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand16Code005A() {
	LOG("%s","Pop");
	uint8_t reg = 0x02;
	reg_0x02_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand16Code005BP66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x03;
	reg_0x03_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand16Code005BP67() {
	LOG("%s","Pop");
	uint8_t reg = 0x03;
	reg_0x03_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand16Code005BP66() {
	LOG("%s","Pop");
	uint8_t reg = 0x03;
	reg_0x03_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand16Code005B() {
	LOG("%s","Pop");
	uint8_t reg = 0x03;
	reg_0x03_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand16Code005CP66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x04;
	reg_0x04_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand16Code005CP67() {
	LOG("%s","Pop");
	uint8_t reg = 0x04;
	reg_0x04_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand16Code005CP66() {
	LOG("%s","Pop");
	uint8_t reg = 0x04;
	reg_0x04_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand16Code005C() {
	LOG("%s","Pop");
	uint8_t reg = 0x04;
	reg_0x04_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand16Code005DP66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x05;
	reg_0x05_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand16Code005DP67() {
	LOG("%s","Pop");
	uint8_t reg = 0x05;
	reg_0x05_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand16Code005DP66() {
	LOG("%s","Pop");
	uint8_t reg = 0x05;
	reg_0x05_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand16Code005D() {
	LOG("%s","Pop");
	uint8_t reg = 0x05;
	reg_0x05_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand16Code005EP66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x06;
	reg_0x06_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand16Code005EP67() {
	LOG("%s","Pop");
	uint8_t reg = 0x06;
	reg_0x06_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand16Code005EP66() {
	LOG("%s","Pop");
	uint8_t reg = 0x06;
	reg_0x06_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand16Code005E() {
	LOG("%s","Pop");
	uint8_t reg = 0x06;
	reg_0x06_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand16Code005FP66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x07;
	reg_0x07_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand16Code005FP67() {
	LOG("%s","Pop");
	uint8_t reg = 0x07;
	reg_0x07_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand16Code005FP66() {
	LOG("%s","Pop");
	uint8_t reg = 0x07;
	reg_0x07_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand16Code005F() {
	LOG("%s","Pop");
	uint8_t reg = 0x07;
	reg_0x07_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//PUSHA
void handlerCommand16Code0060P66() {
	LOG("%s","PUSHA");
	uint32_t tmp = reg_SP_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = reg_AX_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = reg_CX_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = reg_DX_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = reg_BX_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = tmp;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = reg_BP_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = reg_SI_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = reg_DI_32u;
}
//PUSHA
void handlerCommand16Code0060() {
	LOG("%s","PUSHA");
	uint16_t tmp = reg_SP_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_AX_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_CX_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_DX_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_BX_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = tmp;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_BP_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_SI_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_DI_16u;
}
//POPA
void handlerCommand16Code0061P66() {
	LOG("%s","POPA");
	reg_DI_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
	reg_SI_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
	reg_BP_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
	reg_SP_16u += 32 / 8;
	reg_BX_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
	reg_DX_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
	reg_CX_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
	reg_AX_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//POPA
void handlerCommand16Code0061() {
	LOG("%s","POPA");
	reg_DI_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
	reg_SI_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
	reg_BP_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
	reg_SP_16u += 16 / 8;
	reg_BX_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
	reg_DX_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
	reg_CX_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
	reg_AX_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Push
void handlerCommand16Code0068P66P67() {
	LOG("%s","Push");
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = read32u();
}
//Push
void handlerCommand16Code0068P67() {
	LOG("%s","Push");
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = read16u();
}
//Push
void handlerCommand16Code0068P66() {
	LOG("%s","Push");
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = read32u();
}
//Push
void handlerCommand16Code0068() {
	LOG("%s","Push");
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = read16u();
}
//Mul
void handlerCommand16Code0069P66() {
	LOG("%s","Mul");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	int32_t source1 = read32();
	int32_t source2 = *(int32_t*)target;
	target = source;
	int64_t tmp = (int64_t)source1 * (int64_t)source2;
	int32_t value = source1 * source2;
	*((int32_t*)target) = value;
	SET_FLAG(ZF, value == 0);
	SET_FLAG(CF, value != tmp);
	SET_FLAG(OF, value != tmp);
	lazyFlagType = t_MUL;
}
//Mul
void handlerCommand16Code0069() {
	LOG("%s","Mul");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	int16_t source1 = read16();
	int16_t source2 = *(int16_t*)target;
	target = source;
	int32_t tmp = (int32_t)source1 * (int32_t)source2;
	int16_t value = source1 * source2;
	*((int16_t*)target) = value;
	SET_FLAG(ZF, value == 0);
	SET_FLAG(CF, value != tmp);
	SET_FLAG(OF, value != tmp);
	lazyFlagType = t_MUL;
}
//Push
void handlerCommand16Code006AP66P67() {
	LOG("%s","Push");
	reg_SP_32u -= 32 / 8;
	*(int32_t*)(mem(SR_SS) + reg_SP_32u) = (int32_t)read8();
}
//Push
void handlerCommand16Code006AP67() {
	LOG("%s","Push");
	reg_SP_32u -= 16 / 8;
	*(int16_t*)(mem(SR_SS) + reg_SP_32u) = (int16_t)read8();
}
//Push
void handlerCommand16Code006AP66() {
	LOG("%s","Push");
	reg_SP_16u -= 32 / 8;
	*(int32_t*)(mem(SR_SS) + reg_SP_16u) = (int32_t)read8();
}
//Push
void handlerCommand16Code006A() {
	LOG("%s","Push");
	reg_SP_16u -= 16 / 8;
	*(int16_t*)(mem(SR_SS) + reg_SP_16u) = (int16_t)read8();
}
//Mul
void handlerCommand16Code006B() {
	LOG("%s","Mul");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	int16_t source1 = (int16_t)read8();
	int16_t source2 = *(int16_t*)target;
	target = source;
	int32_t tmp = (int32_t)source1 * (int32_t)source2;
	int16_t value = source1 * source2;
	*((int16_t*)target) = value;
	SET_FLAG(ZF, value == 0);
	SET_FLAG(CF, value != tmp);
	SET_FLAG(OF, value != tmp);
	lazyFlagType = t_MUL;
}
//J(cond)
void handlerCommand16Code0070() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x00 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0071() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x01 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0072() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x02 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0073() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x03 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0074() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x04 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0075() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x05 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0076() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x06 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0077() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x07 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0078() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x08 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0079() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x09 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code007A() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x0A {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code007B() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x0B {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code007C() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x0C {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code007D() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x0D {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code007E() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x0E {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code007F() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x0F {
		context.index += address;
	}
}
//Math
void handlerCommand16Code0080P66() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_ADD8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_OR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) + oldcf;
			lazyFlagType = t_ADC8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) - oldcf;
			lazyFlagType = t_SBB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_AND8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_SUB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_XOR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_CMP8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0080() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_ADD8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_OR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) + oldcf;
			lazyFlagType = t_ADC8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) - oldcf;
			lazyFlagType = t_SBB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_AND8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_SUB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_XOR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_CMP8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0081P66() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32) ;
			lazyFlagType = t_ADD32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) | ((uint32_t)LazyFlagVarB32) ;
			lazyFlagType = t_OR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32) + oldcf;
			lazyFlagType = t_ADC32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) - oldcf;
			lazyFlagType = t_SBB32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) & ((uint32_t)LazyFlagVarB32) ;
			lazyFlagType = t_AND32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) ;
			lazyFlagType = t_SUB32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) ^ ((uint32_t)LazyFlagVarB32) ;
			lazyFlagType = t_XOR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) ;
			lazyFlagType = t_CMP32;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0081() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16) ;
			lazyFlagType = t_ADD16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) | ((uint16_t)LazyFlagVarB16) ;
			lazyFlagType = t_OR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16) + oldcf;
			lazyFlagType = t_ADC16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) - oldcf;
			lazyFlagType = t_SBB16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) & ((uint16_t)LazyFlagVarB16) ;
			lazyFlagType = t_AND16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) ;
			lazyFlagType = t_SUB16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) ^ ((uint16_t)LazyFlagVarB16) ;
			lazyFlagType = t_XOR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) ;
			lazyFlagType = t_CMP16;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0082() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) + ((int8_t)LazyFlagVarB8) ;
			lazyFlagType = t_ADD8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) | ((int8_t)LazyFlagVarB8) ;
			lazyFlagType = t_OR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) + ((int8_t)LazyFlagVarB8) + oldcf;
			lazyFlagType = t_ADC8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) - ((int8_t)LazyFlagVarB8) - oldcf;
			lazyFlagType = t_SBB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) & ((int8_t)LazyFlagVarB8) ;
			lazyFlagType = t_AND8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) - ((int8_t)LazyFlagVarB8) ;
			lazyFlagType = t_SUB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) ^ ((int8_t)LazyFlagVarB8) ;
			lazyFlagType = t_XOR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) - ((int8_t)LazyFlagVarB8) ;
			lazyFlagType = t_CMP8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0083P66() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) + ((int32_t)LazyFlagVarB32) ;
			lazyFlagType = t_ADD32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) | ((int32_t)LazyFlagVarB32) ;
			lazyFlagType = t_OR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) + ((int32_t)LazyFlagVarB32) + oldcf;
			lazyFlagType = t_ADC32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) - ((int32_t)LazyFlagVarB32) - oldcf;
			lazyFlagType = t_SBB32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) & ((int32_t)LazyFlagVarB32) ;
			lazyFlagType = t_AND32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) - ((int32_t)LazyFlagVarB32) ;
			lazyFlagType = t_SUB32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) ^ ((int32_t)LazyFlagVarB32) ;
			lazyFlagType = t_XOR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) - ((int32_t)LazyFlagVarB32) ;
			lazyFlagType = t_CMP32;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0083() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) + ((int16_t)LazyFlagVarB16) ;
			lazyFlagType = t_ADD16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) | ((int16_t)LazyFlagVarB16) ;
			lazyFlagType = t_OR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) + ((int16_t)LazyFlagVarB16) + oldcf;
			lazyFlagType = t_ADC16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) - ((int16_t)LazyFlagVarB16) - oldcf;
			lazyFlagType = t_SBB16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) & ((int16_t)LazyFlagVarB16) ;
			lazyFlagType = t_AND16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) - ((int16_t)LazyFlagVarB16) ;
			lazyFlagType = t_SUB16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) ^ ((int16_t)LazyFlagVarB16) ;
			lazyFlagType = t_XOR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) - ((int16_t)LazyFlagVarB16) ;
			lazyFlagType = t_CMP16;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//TEST
void handlerCommand16Code0084P66() {
	LOG("%s","TEST");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_TEST8;
}
//TEST
void handlerCommand16Code0084() {
	LOG("%s","TEST");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_TEST8;
}
//TEST
void handlerCommand16Code0085P66() {
	LOG("%s","TEST");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) & ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_TEST32;
}
//TEST
void handlerCommand16Code0085() {
	LOG("%s","TEST");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) & ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_TEST16;
}
//XCHG
void handlerCommand16Code0086P66() {
	LOG("%s","XCHG");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t tmp = *(uint16_t*)target;
	*(uint16_t*)target = *(uint16_t*)source;
	*(uint16_t*)source = tmp;
}
//XCHG
void handlerCommand16Code0086() {
	LOG("%s","XCHG");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t tmp = *(uint16_t*)target;
	*(uint16_t*)target = *(uint16_t*)source;
	*(uint16_t*)source = tmp;
}
//XCHG
void handlerCommand16Code0087P66() {
	LOG("%s","XCHG");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t tmp = *(uint16_t*)target;
	*(uint16_t*)target = *(uint16_t*)source;
	*(uint16_t*)source = tmp;
}
//XCHG
void handlerCommand16Code0087() {
	LOG("%s","XCHG");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t tmp = *(uint16_t*)target;
	*(uint16_t*)target = *(uint16_t*)source;
	*(uint16_t*)source = tmp;
}
//Move
void handlerCommand16Code0088P66() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code0088() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code0089P66() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	*(uint32_t*)target = *(uint32_t*)source;
}
//Move
void handlerCommand16Code0089() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand16Code008AP66() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code008A() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code008BP66() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	*(uint32_t*)target = *(uint32_t*)source;
}
//Move
void handlerCommand16Code008B() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand16Code008C() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readSegmentRegisterMRM(mrmByte);
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand16Code008E() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* target = (uint8_t*)readSegmentRegisterMRM(mrmByte);
	*(uint16_t*)target = *(uint16_t*)source;
}
//Lea
void handlerCommand16Code008DP66P67() {
	LOG("%s","Lea");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint16_t target = effectiveAddressMRM16For16(mrmByte);
	*((uint32_t*)source) = (uint32_t)(target & 0xFFFFFFFF);
}
//Lea
void handlerCommand16Code008DP67() {
	LOG("%s","Lea");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t target = effectiveAddressMRM16For16(mrmByte);
	*((uint16_t*)source) = (uint16_t)(target & 0xFFFF);
}
//Lea
void handlerCommand16Code008DP66() {
	LOG("%s","Lea");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint16_t target = effectiveAddressMRM16For16(mrmByte);
	*((uint32_t*)source) = (uint32_t)(target & 0xFFFFFFFF);
}
//Lea
void handlerCommand16Code008D() {
	LOG("%s","Lea");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t target = effectiveAddressMRM16For16(mrmByte);
	*((uint16_t*)source) = (uint16_t)(target & 0xFFFF);
}
//Pop
void handlerCommand16Code008FP66P67() {
	LOG("%s","Pop");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			*(uint32_t*)target = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
			reg_SP_32u += 32 / 8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Pop
void handlerCommand16Code008FP67() {
	LOG("%s","Pop");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			*(uint16_t*)target = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
			reg_SP_32u += 16 / 8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Pop
void handlerCommand16Code008FP66() {
	LOG("%s","Pop");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			*(uint32_t*)target = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
			reg_SP_16u += 32 / 8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Pop
void handlerCommand16Code008F() {
	LOG("%s","Pop");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			*(uint16_t*)target = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
			reg_SP_16u += 16 / 8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//XCHG
void handlerCommand16Code0090P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x00;
	// NOP
}
//XCHG
void handlerCommand16Code0090() {
	LOG("%s","XCHG");
	uint8_t reg = 0x00;
	// NOP
}
//XCHG
void handlerCommand16Code0091P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x01;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x01_16u;
	reg_0x01_16u = tmp;
}
//XCHG
void handlerCommand16Code0091() {
	LOG("%s","XCHG");
	uint8_t reg = 0x01;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x01_16u;
	reg_0x01_16u = tmp;
}
//XCHG
void handlerCommand16Code0092P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x02;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x02_16u;
	reg_0x02_16u = tmp;
}
//XCHG
void handlerCommand16Code0092() {
	LOG("%s","XCHG");
	uint8_t reg = 0x02;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x02_16u;
	reg_0x02_16u = tmp;
}
//XCHG
void handlerCommand16Code0093P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x03;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x03_16u;
	reg_0x03_16u = tmp;
}
//XCHG
void handlerCommand16Code0093() {
	LOG("%s","XCHG");
	uint8_t reg = 0x03;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x03_16u;
	reg_0x03_16u = tmp;
}
//XCHG
void handlerCommand16Code0094P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x04;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x04_16u;
	reg_0x04_16u = tmp;
}
//XCHG
void handlerCommand16Code0094() {
	LOG("%s","XCHG");
	uint8_t reg = 0x04;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x04_16u;
	reg_0x04_16u = tmp;
}
//XCHG
void handlerCommand16Code0095P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x05;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x05_16u;
	reg_0x05_16u = tmp;
}
//XCHG
void handlerCommand16Code0095() {
	LOG("%s","XCHG");
	uint8_t reg = 0x05;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x05_16u;
	reg_0x05_16u = tmp;
}
//XCHG
void handlerCommand16Code0096P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x06;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x06_16u;
	reg_0x06_16u = tmp;
}
//XCHG
void handlerCommand16Code0096() {
	LOG("%s","XCHG");
	uint8_t reg = 0x06;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x06_16u;
	reg_0x06_16u = tmp;
}
//XCHG
void handlerCommand16Code0097P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x07;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x07_16u;
	reg_0x07_16u = tmp;
}
//XCHG
void handlerCommand16Code0097() {
	LOG("%s","XCHG");
	uint8_t reg = 0x07;
	uint16_t tmp = reg_AX_16u;
	reg_AX_16u = reg_0x07_16u;
	reg_0x07_16u = tmp;
}
//CBW
void handlerCommand16Code0098P66() {
	LOG("%s","CBW");
	reg_AX_32 = reg_AX_16;
}
//CBW
void handlerCommand16Code0098() {
	LOG("%s","CBW");
	reg_AX_16 = reg_AL_8;
}
//CBW
void handlerCommand16Code0099P66() {
	LOG("%s","CBW");
	if (reg_AX_32 & 0x80000000) reg_DX_32=0xffffffff; else reg_DX_32=0;
}
//CBW
void handlerCommand16Code0099() {
	LOG("%s","CBW");
	if (reg_AX_16 & 0x8000) reg_DX_16=0xffff;else reg_DX_16=0;
}
//PUSHF
void handlerCommand16Code009CP66() {
	LOG("%s","PUSHF");
	FillFlags();
	reg_SP_16u -= 32 / 8;
	EncodeFlagsRegister();
	uint32_t value = reg_flags & 0xFCFFFF;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = *((uint32_t*)&value);
}
//PUSHF
void handlerCommand16Code009C() {
	LOG("%s","PUSHF");
	FillFlags();
	reg_SP_16u -= 16 / 8;
	EncodeFlagsRegister();
	uint32_t value = reg_flags & 0xFCFFFF;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = *((uint16_t*)&value);
}
//POPF
void handlerCommand16Code009DP66() {
	LOG("%s","POPF");
	lazyFlagType = t_UNKNOWN;
	*(uint32_t*)(&reg_flags) = (*(uint32_t*)(mem(SR_SS) + reg_SP_16u));
	reg_SP_16u += 32 / 8;
	DecodeFlagsRegister32();
}
//POPF
void handlerCommand16Code009D() {
	LOG("%s","POPF");
	lazyFlagType = t_UNKNOWN;
	*(uint16_t*)(&reg_flags) = (*(uint16_t*)(mem(SR_SS) + reg_SP_16u));
	reg_SP_16u += 16 / 8;
	DecodeFlagsRegister16();
}
//Move
void handlerCommand16Code00A0P66P67() {
	LOG("%s","Move");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	uint8_t* source = (uint8_t*)(mem(SR_DS) + read32());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code00A0P66() {
	LOG("%s","Move");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	uint8_t* source = (uint8_t*)(mem(SR_DS) + read16());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code00A0P67() {
	LOG("%s","Move");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	uint8_t* source = (uint8_t*)(mem(SR_DS) + read32());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code00A0() {
	LOG("%s","Move");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	uint8_t* source = (uint8_t*)(mem(SR_DS) + read16());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code00A1P66P67() {
	LOG("%s","Move");
	uint32_t* target = (uint32_t*)register32u(BR_AX);
	uint32_t* source = (uint32_t*)(mem(SR_DS) + read32());
	*(uint32_t*)target = *(uint32_t*)source;
}
//Move
void handlerCommand16Code00A1P66() {
	LOG("%s","Move");
	uint32_t* target = (uint32_t*)register32u(BR_AX);
	uint32_t* source = (uint32_t*)(mem(SR_DS) + read16());
	*(uint32_t*)target = *(uint32_t*)source;
}
//Move
void handlerCommand16Code00A1P67() {
	LOG("%s","Move");
	uint16_t* target = (uint16_t*)register16u(BR_AX);
	uint16_t* source = (uint16_t*)(mem(SR_DS) + read32());
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand16Code00A1() {
	LOG("%s","Move");
	uint16_t* target = (uint16_t*)register16u(BR_AX);
	uint16_t* source = (uint16_t*)(mem(SR_DS) + read16());
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand16Code00A2P66P67() {
	LOG("%s","Move");
	uint8_t* source = (uint8_t*)register8u(BR_AX);
	uint8_t* target = (uint8_t*)(mem(SR_DS) + read32());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code00A2P66() {
	LOG("%s","Move");
	uint8_t* source = (uint8_t*)register8u(BR_AX);
	uint8_t* target = (uint8_t*)(mem(SR_DS) + read16());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code00A2P67() {
	LOG("%s","Move");
	uint8_t* source = (uint8_t*)register8u(BR_AX);
	uint8_t* target = (uint8_t*)(mem(SR_DS) + read32());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code00A2() {
	LOG("%s","Move");
	uint8_t* source = (uint8_t*)register8u(BR_AX);
	uint8_t* target = (uint8_t*)(mem(SR_DS) + read16());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand16Code00A3P66P67() {
	LOG("%s","Move");
	uint32_t* source = (uint32_t*)register32u(BR_AX);
	uint32_t* target = (uint32_t*)(mem(SR_DS) + read32());
	*(uint32_t*)target = *(uint32_t*)source;
}
//Move
void handlerCommand16Code00A3P66() {
	LOG("%s","Move");
	uint32_t* source = (uint32_t*)register32u(BR_AX);
	uint32_t* target = (uint32_t*)(mem(SR_DS) + read16());
	*(uint32_t*)target = *(uint32_t*)source;
}
//Move
void handlerCommand16Code00A3P67() {
	LOG("%s","Move");
	uint16_t* source = (uint16_t*)register16u(BR_AX);
	uint16_t* target = (uint16_t*)(mem(SR_DS) + read32());
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand16Code00A3() {
	LOG("%s","Move");
	uint16_t* source = (uint16_t*)register16u(BR_AX);
	uint16_t* target = (uint16_t*)(mem(SR_DS) + read16());
	*(uint16_t*)target = *(uint16_t*)source;
}
//MOVS
void handlerCommand16Code00A4P66P67() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
		}
	}
}
//MOVS
void handlerCommand16Code00A4P66() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
		}
	}
}
//MOVS
void handlerCommand16Code00A4P67() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
		}
	}
}
//MOVS
void handlerCommand16Code00A4() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
		}
	}
}
//MOVS
void handlerCommand16Code00A5P66P67() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_32) = *(uint32_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 -= 32 / 8;reg_SI_32 -= 32 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_32) = *(uint32_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 -= 32 / 8;reg_SI_32 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_32) = *(uint32_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 += 32 / 8;reg_SI_32 += 32 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_32) = *(uint32_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 += 32 / 8;reg_SI_32 += 32 / 8;
		}
	}
}
//MOVS
void handlerCommand16Code00A5P66() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_16) = *(uint32_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 -= 32 / 8;reg_SI_16 -= 32 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_16) = *(uint32_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 -= 32 / 8;reg_SI_16 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_16) = *(uint32_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 += 32 / 8;reg_SI_16 += 32 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_16) = *(uint32_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 += 32 / 8;reg_SI_16 += 32 / 8;
		}
	}
}
//MOVS
void handlerCommand16Code00A5P67() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_32) = *(uint16_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 -= 16 / 8;reg_SI_32 -= 16 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_32) = *(uint16_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 -= 16 / 8;reg_SI_32 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_32) = *(uint16_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 += 16 / 8;reg_SI_32 += 16 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_32) = *(uint16_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 += 16 / 8;reg_SI_32 += 16 / 8;
		}
	}
}
//MOVS
void handlerCommand16Code00A5() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_16) = *(uint16_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 -= 16 / 8;reg_SI_16 -= 16 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_16) = *(uint16_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 -= 16 / 8;reg_SI_16 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_16) = *(uint16_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 += 16 / 8;reg_SI_16 += 16 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_16) = *(uint16_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 += 16 / 8;reg_SI_16 += 16 / 8;
		}
	}
}
//CMPS
void handlerCommand16Code00A6P66P67() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
		}
	}
}
//CMPS
void handlerCommand16Code00A6P66() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
		}
	}
}
//CMPS
void handlerCommand16Code00A6P67() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
		}
	}
}
//CMPS
void handlerCommand16Code00A6() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
		}
	}
}
//CMPS
void handlerCommand16Code00A7P66P67() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) == *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_32) - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 -= 32 / 8;reg_SI_32 -= 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) != *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_32) - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 -= 32 / 8;reg_SI_32 -= 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_32) - *(uint32_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP32;
			reg_DI_32 -= 32 / 8;reg_SI_32 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) == *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_32) - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 += 32 / 8;reg_SI_32 += 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) != *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_32) - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 += 32 / 8;reg_SI_32 += 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_32) - *(uint32_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP32;
			reg_DI_32 += 32 / 8;reg_SI_32 += 32 / 8;
		}
	}
}
//CMPS
void handlerCommand16Code00A7P66() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) == *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_16) - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 -= 32 / 8;reg_SI_16 -= 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) != *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_16) - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 -= 32 / 8;reg_SI_16 -= 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_16) - *(uint32_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP32;
			reg_DI_16 -= 32 / 8;reg_SI_16 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) == *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_16) - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 += 32 / 8;reg_SI_16 += 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) != *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_16) - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 += 32 / 8;reg_SI_16 += 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_16) - *(uint32_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP32;
			reg_DI_16 += 32 / 8;reg_SI_16 += 32 / 8;
		}
	}
}
//CMPS
void handlerCommand16Code00A7P67() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) == *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_32) - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 -= 16 / 8;reg_SI_32 -= 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) != *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_32) - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 -= 16 / 8;reg_SI_32 -= 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_32) - *(uint16_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP16;
			reg_DI_32 -= 16 / 8;reg_SI_32 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) == *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_32) - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 += 16 / 8;reg_SI_32 += 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) != *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_32) - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 += 16 / 8;reg_SI_32 += 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_32) - *(uint16_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP16;
			reg_DI_32 += 16 / 8;reg_SI_32 += 16 / 8;
		}
	}
}
//CMPS
void handlerCommand16Code00A7() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) == *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_16) - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 -= 16 / 8;reg_SI_16 -= 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) != *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_16) - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 -= 16 / 8;reg_SI_16 -= 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_16) - *(uint16_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP16;
			reg_DI_16 -= 16 / 8;reg_SI_16 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) == *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_16) - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 += 16 / 8;reg_SI_16 += 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) != *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_16) - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 += 16 / 8;reg_SI_16 += 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_16) - *(uint16_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP16;
			reg_DI_16 += 16 / 8;reg_SI_16 += 16 / 8;
		}
	}
}
//TEST
void handlerCommand16Code00A8P66() {
	LOG("%s","TEST");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_TEST8;
}
//TEST
void handlerCommand16Code00A8() {
	LOG("%s","TEST");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_TEST8;
}
//TEST
void handlerCommand16Code00A9P66() {
	LOG("%s","TEST");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) & ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_TEST32;
}
//TEST
void handlerCommand16Code00A9() {
	LOG("%s","TEST");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) & ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_TEST16;
}
//STOS
void handlerCommand16Code00AAP66P67() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
				reg_DI_32 -= 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
			reg_DI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
				reg_DI_32 += 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
			reg_DI_32 += 8 / 8;
		}
	}
}
//STOS
void handlerCommand16Code00AAP66() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
				reg_DI_16 -= 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
			reg_DI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
				reg_DI_16 += 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
			reg_DI_16 += 8 / 8;
		}
	}
}
//STOS
void handlerCommand16Code00AAP67() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
				reg_DI_32 -= 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
			reg_DI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
				reg_DI_32 += 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
			reg_DI_32 += 8 / 8;
		}
	}
}
//STOS
void handlerCommand16Code00AA() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
				reg_DI_16 -= 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
			reg_DI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
				reg_DI_16 += 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
			reg_DI_16 += 8 / 8;
		}
	}
}
//STOS
void handlerCommand16Code00ABP66P67() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_32) = reg_0x00_32u;
				reg_DI_32 -= 32 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_32) = reg_0x00_32u;
			reg_DI_32 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_32) = reg_0x00_32u;
				reg_DI_32 += 32 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_32) = reg_0x00_32u;
			reg_DI_32 += 32 / 8;
		}
	}
}
//STOS
void handlerCommand16Code00ABP66() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_16) = reg_0x00_32u;
				reg_DI_16 -= 32 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_16) = reg_0x00_32u;
			reg_DI_16 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_16) = reg_0x00_32u;
				reg_DI_16 += 32 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_16) = reg_0x00_32u;
			reg_DI_16 += 32 / 8;
		}
	}
}
//STOS
void handlerCommand16Code00ABP67() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_32) = reg_0x00_16u;
				reg_DI_32 -= 16 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_32) = reg_0x00_16u;
			reg_DI_32 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_32) = reg_0x00_16u;
				reg_DI_32 += 16 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_32) = reg_0x00_16u;
			reg_DI_32 += 16 / 8;
		}
	}
}
//STOS
void handlerCommand16Code00AB() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_16) = reg_0x00_16u;
				reg_DI_16 -= 16 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_16) = reg_0x00_16u;
			reg_DI_16 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_16) = reg_0x00_16u;
				reg_DI_16 += 16 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_16) = reg_0x00_16u;
			reg_DI_16 += 16 / 8;
		}
	}
}
//LOADS
void handlerCommand16Code00ACP66P67() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 += 8 / 8;
		}
	}
}
//LOADS
void handlerCommand16Code00ACP66() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 += 8 / 8;
		}
	}
}
//LOADS
void handlerCommand16Code00ACP67() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 += 8 / 8;
		}
	}
}
//LOADS
void handlerCommand16Code00AC() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 += 8 / 8;
		}
	}
}
//LOADS
void handlerCommand16Code00ADP66P67() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 -= 32 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 += 32 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 += 32 / 8;
		}
	}
}
//LOADS
void handlerCommand16Code00ADP66() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 -= 32 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 += 32 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 += 32 / 8;
		}
	}
}
//LOADS
void handlerCommand16Code00ADP67() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 -= 16 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 += 16 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 += 16 / 8;
		}
	}
}
//LOADS
void handlerCommand16Code00AD() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 -= 16 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 += 16 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 += 16 / 8;
		}
	}
}
//SCAS
void handlerCommand16Code00AEP66P67() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 += 8 / 8;
		}
	}
}
//SCAS
void handlerCommand16Code00AEP66() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 += 8 / 8;
		}
	}
}
//SCAS
void handlerCommand16Code00AEP67() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 += 8 / 8;
		}
	}
}
//SCAS
void handlerCommand16Code00AE() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 += 8 / 8;
		}
	}
}
//SCAS
void handlerCommand16Code00AFP66P67() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) == reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 -= 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) != reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 -= 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = reg_0x00_32u;
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP32;
			reg_DI_32 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) == reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 += 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) != reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 += 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = reg_0x00_32u;
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP32;
			reg_DI_32 += 32 / 8;
		}
	}
}
//SCAS
void handlerCommand16Code00AFP66() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) == reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 -= 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) != reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 -= 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = reg_0x00_32u;
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP32;
			reg_DI_16 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) == reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 += 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) != reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 += 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = reg_0x00_32u;
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP32;
			reg_DI_16 += 32 / 8;
		}
	}
}
//SCAS
void handlerCommand16Code00AFP67() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) == reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 -= 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) != reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 -= 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = reg_0x00_16u;
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP16;
			reg_DI_32 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) == reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 += 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) != reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 += 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = reg_0x00_16u;
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP16;
			reg_DI_32 += 16 / 8;
		}
	}
}
//SCAS
void handlerCommand16Code00AF() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) == reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 -= 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) != reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 -= 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = reg_0x00_16u;
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP16;
			reg_DI_16 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) == reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 += 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) != reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 += 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = reg_0x00_16u;
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP16;
			reg_DI_16 += 16 / 8;
		}
	}
}
//Move
void handlerCommand16Code00B0P66() {
	LOG("%s","Move");
	reg_0x00_8u = read8u();
}
//Move
void handlerCommand16Code00B0() {
	LOG("%s","Move");
	reg_0x00_8u = read8u();
}
//Move
void handlerCommand16Code00B1P66() {
	LOG("%s","Move");
	reg_0x01_8u = read8u();
}
//Move
void handlerCommand16Code00B1() {
	LOG("%s","Move");
	reg_0x01_8u = read8u();
}
//Move
void handlerCommand16Code00B2P66() {
	LOG("%s","Move");
	reg_0x02_8u = read8u();
}
//Move
void handlerCommand16Code00B2() {
	LOG("%s","Move");
	reg_0x02_8u = read8u();
}
//Move
void handlerCommand16Code00B3P66() {
	LOG("%s","Move");
	reg_0x03_8u = read8u();
}
//Move
void handlerCommand16Code00B3() {
	LOG("%s","Move");
	reg_0x03_8u = read8u();
}
//Move
void handlerCommand16Code00B4P66() {
	LOG("%s","Move");
	reg_0x04_8u = read8u();
}
//Move
void handlerCommand16Code00B4() {
	LOG("%s","Move");
	reg_0x04_8u = read8u();
}
//Move
void handlerCommand16Code00B5P66() {
	LOG("%s","Move");
	reg_0x05_8u = read8u();
}
//Move
void handlerCommand16Code00B5() {
	LOG("%s","Move");
	reg_0x05_8u = read8u();
}
//Move
void handlerCommand16Code00B6P66() {
	LOG("%s","Move");
	reg_0x06_8u = read8u();
}
//Move
void handlerCommand16Code00B6() {
	LOG("%s","Move");
	reg_0x06_8u = read8u();
}
//Move
void handlerCommand16Code00B7P66() {
	LOG("%s","Move");
	reg_0x07_8u = read8u();
}
//Move
void handlerCommand16Code00B7() {
	LOG("%s","Move");
	reg_0x07_8u = read8u();
}
//Move
void handlerCommand16Code00B8P66() {
	LOG("%s","Move");
	reg_0x00_32u = read32u();
}
//Move
void handlerCommand16Code00B8() {
	LOG("%s","Move");
	reg_0x00_16u = read16u();
}
//Move
void handlerCommand16Code00B9P66() {
	LOG("%s","Move");
	reg_0x01_32u = read32u();
}
//Move
void handlerCommand16Code00B9() {
	LOG("%s","Move");
	reg_0x01_16u = read16u();
}
//Move
void handlerCommand16Code00BAP66() {
	LOG("%s","Move");
	reg_0x02_32u = read32u();
}
//Move
void handlerCommand16Code00BA() {
	LOG("%s","Move");
	reg_0x02_16u = read16u();
}
//Move
void handlerCommand16Code00BBP66() {
	LOG("%s","Move");
	reg_0x03_32u = read32u();
}
//Move
void handlerCommand16Code00BB() {
	LOG("%s","Move");
	reg_0x03_16u = read16u();
}
//Move
void handlerCommand16Code00BCP66() {
	LOG("%s","Move");
	reg_0x04_32u = read32u();
}
//Move
void handlerCommand16Code00BC() {
	LOG("%s","Move");
	reg_0x04_16u = read16u();
}
//Move
void handlerCommand16Code00BDP66() {
	LOG("%s","Move");
	reg_0x05_32u = read32u();
}
//Move
void handlerCommand16Code00BD() {
	LOG("%s","Move");
	reg_0x05_16u = read16u();
}
//Move
void handlerCommand16Code00BEP66() {
	LOG("%s","Move");
	reg_0x06_32u = read32u();
}
//Move
void handlerCommand16Code00BE() {
	LOG("%s","Move");
	reg_0x06_16u = read16u();
}
//Move
void handlerCommand16Code00BFP66() {
	LOG("%s","Move");
	reg_0x07_32u = read32u();
}
//Move
void handlerCommand16Code00BF() {
	LOG("%s","Move");
	reg_0x07_16u = read16u();
}
//Move bits
void handlerCommand16Code00C0P66() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (8 / 8))), 0, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(uint8_t*)target) % 2);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(int8_t*)target) < 0);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp + (8 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			(*(uint8_t*)target) = (*(uint8_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			(*(uint8_t*)target) = (*(uint8_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			uint64_t tmp = ((*(int8_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint8_t*)(((uint8_t*)&tmp) + 4) = (*(uint8_t*)target);
			tmp = tmp >> value;
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand16Code00C0() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (8 / 8))), 0, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(uint8_t*)target) % 2);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(int8_t*)target) < 0);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp + (8 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			(*(uint8_t*)target) = (*(uint8_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			(*(uint8_t*)target) = (*(uint8_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = read8u();
			uint64_t tmp = ((*(int8_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint8_t*)(((uint8_t*)&tmp) + 4) = (*(uint8_t*)target);
			tmp = tmp >> value;
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand16Code00C1P66() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = read8u();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp << (value % 32);
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = read8u();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp >> (value % 32);
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (32 / 8))), 0, GET_FLAG(CF));
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			SET_FLAG(CF, (*(uint32_t*)target) % 2);
			tmp = tmp << (value % 32);
			(*(uint32_t*)target) = *(uint32_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			SET_FLAG(CF, (*(int32_t*)target) < 0);
			tmp = tmp >> (value % 32);
			(*(uint32_t*)target) = *(uint32_t*)((uint8_t*)&tmp + (32 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = read8u();
			(*(uint32_t*)target) = (*(uint32_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = read8u();
			(*(uint32_t*)target) = (*(uint32_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = read8u();
			uint64_t tmp = ((*(int32_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint32_t*)(((uint8_t*)&tmp) + 4) = (*(uint32_t*)target);
			tmp = tmp >> value;
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand16Code00C1() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = read8u();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp << (value % 16);
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = read8u();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp >> (value % 16);
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (16 / 8))), 0, GET_FLAG(CF));
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			SET_FLAG(CF, (*(uint16_t*)target) % 2);
			tmp = tmp << (value % 16);
			(*(uint16_t*)target) = *(uint16_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			SET_FLAG(CF, (*(int16_t*)target) < 0);
			tmp = tmp >> (value % 16);
			(*(uint16_t*)target) = *(uint16_t*)((uint8_t*)&tmp + (16 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = read8u();
			(*(uint16_t*)target) = (*(uint16_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = read8u();
			(*(uint16_t*)target) = (*(uint16_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = read8u();
			uint64_t tmp = ((*(int16_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint16_t*)(((uint8_t*)&tmp) + 4) = (*(uint16_t*)target);
			tmp = tmp >> value;
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Ret
void handlerCommand16Code00C3() {
	LOG("%s","Ret");
	uint16_t* sp = register16u(BR_SP);
	context.index = mem(1) + *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8;
}
//Load SR_ES
void handlerCommand16Code00C4() {
	LOG("%s","Load SR_ES");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	setMem(SR_ES, *(uint16_t*)(target + 2));
	*(uint16_t*)source = *(uint16_t*)(target);
}
//Load SR_DS
void handlerCommand16Code00C5() {
	LOG("%s","Load SR_DS");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	setMem(SR_DS, *(uint16_t*)(target + 2));
	*(uint16_t*)source = *(uint16_t*)(target);
}
//Move
void handlerCommand16Code00C6P66() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	*(uint8_t*)target = read8u();
}
//Move
void handlerCommand16Code00C6() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	*(uint8_t*)target = read8u();
}
//Move
void handlerCommand16Code00C7P66() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	*(uint32_t*)target = read32u();
}
//Move
void handlerCommand16Code00C7() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	*(uint16_t*)target = read16u();
}
//Enter
void handlerCommand16Code00C8P66P67() {
	LOG("%s","Enter");
	uint16_t size = read16u();
	uint8_t levels = read8u() % 32;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_BP_32u;
	uint32_t tmp = reg_SP_32u;
	if (levels > 0) {
		for (int i = 1; i < levels; ++i) {
			reg_BP_32u = reg_BP_32u - 32 / 8;
			reg_SP_32u -= 32 / 8;
			*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_BP_32u;
		}
		reg_SP_32u -= 32 / 8;
		*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_SP_32u;
	}
	reg_BP_32u = tmp;
	reg_SP_32u = reg_BP_32u - size;
}
//Enter
void handlerCommand16Code00C8P67() {
	LOG("%s","Enter");
	uint16_t size = read16u();
	uint8_t levels = read8u() % 32;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_BP_32u;
	uint32_t tmp = reg_SP_32u;
	if (levels > 0) {
		for (int i = 1; i < levels; ++i) {
			reg_BP_32u = reg_BP_32u - 16 / 8;
			reg_SP_32u -= 32 / 8;
			*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_BP_32u;
		}
		reg_SP_32u -= 32 / 8;
		*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_SP_32u;
	}
	reg_BP_32u = tmp;
	reg_SP_32u = reg_BP_32u - size;
}
//Enter
void handlerCommand16Code00C8P66() {
	LOG("%s","Enter");
	uint16_t size = read16u();
	uint8_t levels = read8u() % 32;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_BP_16u;
	uint16_t tmp = reg_SP_16u;
	if (levels > 0) {
		for (int i = 1; i < levels; ++i) {
			reg_BP_16u = reg_BP_16u - 32 / 8;
			reg_SP_16u -= 16 / 8;
			*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_BP_16u;
		}
		reg_SP_16u -= 16 / 8;
		*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_SP_16u;
	}
	reg_BP_16u = tmp;
	reg_SP_16u = reg_BP_16u - size;
}
//Enter
void handlerCommand16Code00C8() {
	LOG("%s","Enter");
	uint16_t size = read16u();
	uint8_t levels = read8u() % 32;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_BP_16u;
	uint16_t tmp = reg_SP_16u;
	if (levels > 0) {
		for (int i = 1; i < levels; ++i) {
			reg_BP_16u = reg_BP_16u - 16 / 8;
			reg_SP_16u -= 16 / 8;
			*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_BP_16u;
		}
		reg_SP_16u -= 16 / 8;
		*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_SP_16u;
	}
	reg_BP_16u = tmp;
	reg_SP_16u = reg_BP_16u - size;
}
//Leave
void handlerCommand16Code00C9P66P67() {
	LOG("%s","Leave");
	reg_SP_32u = reg_BP_32u;
	reg_BP_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Leave
void handlerCommand16Code00C9P67() {
	LOG("%s","Leave");
	reg_SP_32u = reg_BP_32u;
	reg_BP_32u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Leave
void handlerCommand16Code00C9P66() {
	LOG("%s","Leave");
	reg_SP_16u = reg_BP_16u;
	reg_BP_16u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Leave
void handlerCommand16Code00C9() {
	LOG("%s","Leave");
	reg_SP_16u = reg_BP_16u;
	reg_BP_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Ret
void handlerCommand16Code00CB() {
	LOG("%s","Ret");
	uint16_t* sp = register16u(BR_SP);
	setMem(1, *(int16_t*)(mem(SR_SS) + *sp + 16 / 8));
	context.index = mem(1) + *(uint16_t*)(mem(SR_SS) + *sp);
	*sp += 16 / 8 + 2;
}
//Int
void handlerCommand16Code00CD() {
	LOG("%s","Int");
	uint8_t addr = read8u();
	context.functions[addr](addr);
}
//Move bits
void handlerCommand16Code00D0P66() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (8 / 8))), 0, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(uint8_t*)target) % 2);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(int8_t*)target) < 0);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp + (8 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			(*(uint8_t*)target) = (*(uint8_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			(*(uint8_t*)target) = (*(uint8_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			uint64_t tmp = ((*(int8_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint8_t*)(((uint8_t*)&tmp) + 4) = (*(uint8_t*)target);
			tmp = tmp >> value;
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand16Code00D0() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (8 / 8))), 0, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(uint8_t*)target) % 2);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(int8_t*)target) < 0);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp + (8 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			(*(uint8_t*)target) = (*(uint8_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			(*(uint8_t*)target) = (*(uint8_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = 1;
			uint64_t tmp = ((*(int8_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint8_t*)(((uint8_t*)&tmp) + 4) = (*(uint8_t*)target);
			tmp = tmp >> value;
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand16Code00D1P66() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = 1;
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp << (value % 32);
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = 1;
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp >> (value % 32);
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (32 / 8))), 0, GET_FLAG(CF));
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			SET_FLAG(CF, (*(uint32_t*)target) % 2);
			tmp = tmp << (value % 32);
			(*(uint32_t*)target) = *(uint32_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			SET_FLAG(CF, (*(int32_t*)target) < 0);
			tmp = tmp >> (value % 32);
			(*(uint32_t*)target) = *(uint32_t*)((uint8_t*)&tmp + (32 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = 1;
			(*(uint32_t*)target) = (*(uint32_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = 1;
			(*(uint32_t*)target) = (*(uint32_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = 1;
			uint64_t tmp = ((*(int32_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint32_t*)(((uint8_t*)&tmp) + 4) = (*(uint32_t*)target);
			tmp = tmp >> value;
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand16Code00D1() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = 1;
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp << (value % 16);
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = 1;
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp >> (value % 16);
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (16 / 8))), 0, GET_FLAG(CF));
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			SET_FLAG(CF, (*(uint16_t*)target) % 2);
			tmp = tmp << (value % 16);
			(*(uint16_t*)target) = *(uint16_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			SET_FLAG(CF, (*(int16_t*)target) < 0);
			tmp = tmp >> (value % 16);
			(*(uint16_t*)target) = *(uint16_t*)((uint8_t*)&tmp + (16 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = 1;
			(*(uint16_t*)target) = (*(uint16_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = 1;
			(*(uint16_t*)target) = (*(uint16_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = 1;
			uint64_t tmp = ((*(int16_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint16_t*)(((uint8_t*)&tmp) + 4) = (*(uint16_t*)target);
			tmp = tmp >> value;
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand16Code00D2P66() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (8 / 8))), 0, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(uint8_t*)target) % 2);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(int8_t*)target) < 0);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp + (8 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint8_t*)target) = (*(uint8_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint8_t*)target) = (*(uint8_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			uint64_t tmp = ((*(int8_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint8_t*)(((uint8_t*)&tmp) + 4) = (*(uint8_t*)target);
			tmp = tmp >> value;
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand16Code00D2() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (8 / 8))), 0, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(uint8_t*)target) % 2);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(int8_t*)target) < 0);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp + (8 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint8_t*)target) = (*(uint8_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint8_t*)target) = (*(uint8_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t value = reg_CL_8u;
			uint64_t tmp = ((*(int8_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint8_t*)(((uint8_t*)&tmp) + 4) = (*(uint8_t*)target);
			tmp = tmp >> value;
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand16Code00D3P66() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = reg_CL_8u;
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp << (value % 32);
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = reg_CL_8u;
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp >> (value % 32);
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (32 / 8))), 0, GET_FLAG(CF));
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			SET_FLAG(CF, (*(uint32_t*)target) % 2);
			tmp = tmp << (value % 32);
			(*(uint32_t*)target) = *(uint32_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			SET_FLAG(CF, (*(int32_t*)target) < 0);
			tmp = tmp >> (value % 32);
			(*(uint32_t*)target) = *(uint32_t*)((uint8_t*)&tmp + (32 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint32_t*)target) = (*(uint32_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint32_t*)target) = (*(uint32_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint8_t value = reg_CL_8u;
			uint64_t tmp = ((*(int32_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint32_t*)(((uint8_t*)&tmp) + 4) = (*(uint32_t*)target);
			tmp = tmp >> value;
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand16Code00D3() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = reg_CL_8u;
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp << (value % 16);
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = reg_CL_8u;
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp >> (value % 16);
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (16 / 8))), 0, GET_FLAG(CF));
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			SET_FLAG(CF, (*(uint16_t*)target) % 2);
			tmp = tmp << (value % 16);
			(*(uint16_t*)target) = *(uint16_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			SET_FLAG(CF, (*(int16_t*)target) < 0);
			tmp = tmp >> (value % 16);
			(*(uint16_t*)target) = *(uint16_t*)((uint8_t*)&tmp + (16 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint16_t*)target) = (*(uint16_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint16_t*)target) = (*(uint16_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t value = reg_CL_8u;
			uint64_t tmp = ((*(int16_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint16_t*)(((uint8_t*)&tmp) + 4) = (*(uint16_t*)target);
			tmp = tmp >> value;
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand16Code00D8() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 000, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			} else {
				// OPA 000, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM16For8(mrmByte);
				float* source = valueB;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 000, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			} else {
				// OPA 000, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM16For8(mrmByte);
				float* source = valueB;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 000, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			} else {
				// OPA 000, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM16For8(mrmByte);
				float* source = valueB;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 000, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			} else {
				// OPA 000, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM16For8(mrmByte);
				float* source = valueB;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 000, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			} else {
				// OPA 000, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM16For8(mrmByte);
				float* source = valueB;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 000, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			} else {
				// OPA 000, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM16For8(mrmByte);
				float* source = valueB;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand16Code00D9() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 001, OPB 000
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = *source;
			} else {
				// OPA 001, OPB 000
				// FPU Move
				fpuStackIndex -= 1;
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM16For8(mrmByte);
				float* source = valueB;
				*target = *source;
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 001, OPB 010
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				float* valueB = (float*)readAddressMRM16For8(mrmByte);
				float* target = valueB;
				*target = *source;
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 001, OPB 011
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				float* valueB = (float*)readAddressMRM16For8(mrmByte);
				float* target = valueB;
				fpuStackIndex += 1;
				*target = *source;
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				fpuRegControll = *(uint16_t*)readAddressMRM16For16(mrmByte);
			} else {
				fpuRegControll = *(uint16_t*)readAddressMRM16For16(mrmByte);
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				*(uint16_t*)readAddressMRM16For16(mrmByte) = fpuRegControll;
			} else {
				*(uint16_t*)readAddressMRM16For16(mrmByte) = fpuRegControll;
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand16Code00DA() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 010, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM16For8(mrmByte);
				int32_t* source = valueB;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 010, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM16For8(mrmByte);
				int32_t* source = valueB;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 010, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM16For8(mrmByte);
				int32_t* source = valueB;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 010, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM16For8(mrmByte);
				int32_t* source = valueB;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 010, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM16For8(mrmByte);
				int32_t* source = valueB;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 010, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM16For8(mrmByte);
				int32_t* source = valueB;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand16Code00DB() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 011, OPB 000
				// FPU Move
				fpuStackIndex -= 1;
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM16For8(mrmByte);
				int32_t* source = valueB;
				*target = *source;
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 011, OPB 010
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM16For8(mrmByte);
				int32_t* target = valueB;
				*target = *source;
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 011, OPB 011
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM16For8(mrmByte);
				int32_t* target = valueB;
				fpuStackIndex += 1;
				*target = *source;
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				fpuStackIndex = 7;
				fpuRegControll = 0x37F;
				fpuRegStatus = 0;
				fpuRegTag = 0xFFFF;
				fpuRegPointer = 0;
				fpuRegInstructionPointer = 0;
				fpuRegInstructionOpcode = 0;
			} else {
				fpuStackIndex = 7;
				fpuRegControll = 0x37F;
				fpuRegStatus = 0;
				fpuRegTag = 0xFFFF;
				fpuRegPointer = 0;
				fpuRegInstructionPointer = 0;
				fpuRegInstructionOpcode = 0;
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				*(uint16_t*)readAddressMRM16For16(mrmByte) = fpuRegControll;
			} else {
				*(uint16_t*)readAddressMRM16For16(mrmByte) = fpuRegControll;
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand16Code00DC() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 100, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			} else {
				// OPA 100, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM16For8(mrmByte);
				double* source = valueB;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 100, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			} else {
				// OPA 100, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM16For8(mrmByte);
				double* source = valueB;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 100, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			} else {
				// OPA 100, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM16For8(mrmByte);
				double* source = valueB;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 100, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			} else {
				// OPA 100, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM16For8(mrmByte);
				double* source = valueB;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 100, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			} else {
				// OPA 100, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM16For8(mrmByte);
				double* source = valueB;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 100, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			} else {
				// OPA 100, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM16For8(mrmByte);
				double* source = valueB;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand16Code00DD() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 101, OPB 000
				// FPU Move
				fpuStackIndex -= 1;
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM16For8(mrmByte);
				double* source = valueB;
				*target = *source;
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 101, OPB 010
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = (double*)readAddressMRM16For8(mrmByte);
				double* target = valueB;
				*target = *source;
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 101, OPB 011
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = (double*)readAddressMRM16For8(mrmByte);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = *source;
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				*(uint16_t*)readAddressMRM16For16(mrmByte) = fpuRegStatus;
			} else {
				*(uint16_t*)readAddressMRM16For16(mrmByte) = fpuRegStatus;
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand16Code00DE() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 110, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			} else {
				// OPA 110, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM16For8(mrmByte);
				int16_t* source = valueB;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 110, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			} else {
				// OPA 110, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM16For8(mrmByte);
				int16_t* source = valueB;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 110, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			} else {
				// OPA 110, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM16For8(mrmByte);
				int16_t* source = valueB;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 110, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			} else {
				// OPA 110, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM16For8(mrmByte);
				int16_t* source = valueB;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 110, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			} else {
				// OPA 110, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM16For8(mrmByte);
				int16_t* source = valueB;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 110, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			} else {
				// OPA 110, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM16For8(mrmByte);
				int16_t* source = valueB;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand16Code00DF() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 111, OPB 000
				// FPU Move
				fpuStackIndex -= 1;
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM16For8(mrmByte);
				int16_t* source = valueB;
				*target = *source;
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 111, OPB 010
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM16For8(mrmByte);
				int16_t* target = valueB;
				*target = *source;
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 111, OPB 011
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM16For8(mrmByte);
				int16_t* target = valueB;
				fpuStackIndex += 1;
				*target = *source;
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Loop
void handlerCommand16Code00E0() {
	LOG("%s","Loop");
	int8_t addr = read8();
	reg_0x01_16 -= 1;
	FillFlags();
	if (reg_0x01_16 != 0 && GET_FLAG(ZF) == 0) {
		context.index += addr;
	}
}
//Loop
void handlerCommand16Code00E1() {
	LOG("%s","Loop");
	int8_t addr = read8();
	reg_0x01_16 -= 1;
	FillFlags();
	if (reg_0x01_16 != 0 && GET_FLAG(ZF) == 1) {
		context.index += addr;
	}
}
//Loop
void handlerCommand16Code00E2() {
	LOG("%s","Loop");
	int8_t addr = read8();
	reg_0x01_16 -= 1;
	if (reg_0x01_16 != 0) {
		context.index += addr;
	}
}
//Loop
void handlerCommand16Code00E3() {
	LOG("%s","Loop");
	int8_t addr = read8();
	if (reg_0x01_16 == 0) {
		context.index += addr;
	}
}
//Call
void handlerCommand16Code00E8P66() {
	LOG("%s","Call");
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = (uint16_t)(context.index + 32 / 8 - mem(1));
	context.index += read32();
}
//Call
void handlerCommand16Code00E8() {
	LOG("%s","Call");
	uint16_t* sp = register16u(BR_SP);
	*sp -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + *sp) = (uint16_t)(context.index + 16 / 8 - mem(1));
	context.index += read16();
}
//Jmp
void handlerCommand16Code00E9P66() {
	LOG("%s","Jmp");
	context.index += read32();
}
//Jmp
void handlerCommand16Code00E9() {
	LOG("%s","Jmp");
	context.index += read16();
}
//Jmp
void handlerCommand16Code00EB() {
	LOG("%s","Jmp");
	context.index += read8();
}
//~CF
void handlerCommand16Code00F5() {
	LOG("%s","~CF");
	SET_FLAG(CF, !GET_FLAG(CF));
}
//Math
void handlerCommand16Code00F6P66() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// TEST
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 & ((uint8_t)LazyFlagVarB8);
			lazyFlagType = t_TEST8;
		}
		break;
		case 0x02: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// NOT
			*(int8_t*)target = ~(*(int8_t*)target);
		}
		break;
		case 0x03: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// NEG
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagResultContainer8 = 0 - LazyFlagVarA8;
			*(int8_t*)target = LazyFlagResultContainer8;
			lazyFlagType = t_NEG8;
		}
		break;
		case 0x04: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			reg_AX_16=((uint16_t)reg_AL_8)*((uint16_t)(*(uint8_t*)target));
			FillFlagsNoCFOF();
			SET_FLAG(ZF,reg_AL_8 == 0);
			SET_FLAG(PF,PARITY16(reg_AX_16));
			if (reg_AX_16 & 0xff00) {
				SET_FLAG(CF,1);SET_FLAG(OF,1);
			} else {
				SET_FLAG(CF,0);SET_FLAG(OF,0);
			}
		}
		break;
		case 0x05: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			reg_AX_16 = reg_AL_8 * (*((int8_t*)target));
			FillFlagsNoCFOF();
			SET_FLAG(ZF, reg_AX_16 == 0);
			SET_FLAG(SF, reg_AL_8 & 0x80);
			if ((reg_AX_16 & 0xff80)==0xff80 || (reg_AX_16 & 0xff80)==0x0000) {
				SET_FLAG(CF,0);SET_FLAG(OF,0);
			} else {
				SET_FLAG(CF,1);SET_FLAG(OF,1);
			}
		}
		break;
		case 0x06: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t val= *(uint8_t*)(target);
			uint16_t quo=reg_AX_16 / val;
			uint8_t rem=(uint8_t)(reg_AX_16 % val);
			uint8_t quo8=(uint8_t)(quo&0xff);
			reg_AH_8=rem;
			reg_AL_8=quo8;
			FillFlags();
			SET_FLAG(ZF,(rem==0)&&((quo8&1)!=0));
			SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
			SET_FLAG(PF,parity_lookup[rem&0xff]^parity_lookup[quo8&0xff]^GET_FLAG(PF));
		}
		break;
		case 0x07: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
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
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code00F6() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// TEST
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 & ((uint8_t)LazyFlagVarB8);
			lazyFlagType = t_TEST8;
		}
		break;
		case 0x02: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// NOT
			*(int8_t*)target = ~(*(int8_t*)target);
		}
		break;
		case 0x03: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// NEG
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagResultContainer8 = 0 - LazyFlagVarA8;
			*(int8_t*)target = LazyFlagResultContainer8;
			lazyFlagType = t_NEG8;
		}
		break;
		case 0x04: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			reg_AX_16=((uint16_t)reg_AL_8)*((uint16_t)(*(uint8_t*)target));
			FillFlagsNoCFOF();
			SET_FLAG(ZF,reg_AL_8 == 0);
			SET_FLAG(PF,PARITY16(reg_AX_16));
			if (reg_AX_16 & 0xff00) {
				SET_FLAG(CF,1);SET_FLAG(OF,1);
			} else {
				SET_FLAG(CF,0);SET_FLAG(OF,0);
			}
		}
		break;
		case 0x05: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			reg_AX_16 = reg_AL_8 * (*((int8_t*)target));
			FillFlagsNoCFOF();
			SET_FLAG(ZF, reg_AX_16 == 0);
			SET_FLAG(SF, reg_AL_8 & 0x80);
			if ((reg_AX_16 & 0xff80)==0xff80 || (reg_AX_16 & 0xff80)==0x0000) {
				SET_FLAG(CF,0);SET_FLAG(OF,0);
			} else {
				SET_FLAG(CF,1);SET_FLAG(OF,1);
			}
		}
		break;
		case 0x06: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			uint8_t val= *(uint8_t*)(target);
			uint16_t quo=reg_AX_16 / val;
			uint8_t rem=(uint8_t)(reg_AX_16 % val);
			uint8_t quo8=(uint8_t)(quo&0xff);
			reg_AH_8=rem;
			reg_AL_8=quo8;
			FillFlags();
			SET_FLAG(ZF,(rem==0)&&((quo8&1)!=0));
			SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
			SET_FLAG(PF,parity_lookup[rem&0xff]^parity_lookup[quo8&0xff]^GET_FLAG(PF));
		}
		break;
		case 0x07: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
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
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code00F7P66() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			// TEST
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 & ((uint32_t)LazyFlagVarB32);
			lazyFlagType = t_TEST32;
		}
		break;
		case 0x02: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			// NOT
			*(int32_t*)target = ~(*(int32_t*)target);
		}
		break;
		case 0x03: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			// NEG
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagResultContainer32 = 0 - LazyFlagVarA32;
			*(int32_t*)target = LazyFlagResultContainer32;
			lazyFlagType = t_NEG32;
		}
		break;
		case 0x04: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint64_t tempu=(uint64_t)reg_AX_32*(uint64_t)(*(uint32_t*)(target));
			reg_AX_32=(uint32_t)(tempu);
			reg_DX_32=(uint32_t)(tempu >> 32);
			FillFlagsNoCFOF();
			SET_FLAG(ZF,reg_AX_32 == 0);
			SET_FLAG(PF,PARITY32(reg_AX_32)^PARITY32(reg_DX_32)^GET_FLAG(PF));
			if (reg_DX_32) {
				SET_FLAG(CF,1);SET_FLAG(OF,1);
			} else {
				SET_FLAG(CF,0);SET_FLAG(OF,0);
			}
		}
		break;
		case 0x05: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
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
		}
		break;
		case 0x06: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			uint32_t val= *(uint32_t*)(target);
			uint64_t num=(((uint64_t)reg_DX_32)<<32)|reg_AX_32;
			uint64_t quo=num/val;
			uint32_t rem=(uint32_t)(num % val);
			uint32_t quo32=(uint32_t)(quo&0xffffffff);
			reg_DX_32=rem;
			reg_AX_32=quo32;
			FillFlags();
			SET_FLAG(ZF,(rem==0)&&((quo32&1)!=0));
			SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
			SET_FLAG(PF,PARITY32(rem&0xffffffff)^PARITY32(quo32&0xffffffff)^GET_FLAG(PF));
		}
		break;
		case 0x07: {
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
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
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code00F7() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			// TEST
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 & ((uint16_t)LazyFlagVarB16);
			lazyFlagType = t_TEST16;
		}
		break;
		case 0x02: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			// NOT
			*(int16_t*)target = ~(*(int16_t*)target);
		}
		break;
		case 0x03: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			// NEG
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagResultContainer16 = 0 - LazyFlagVarA16;
			*(int16_t*)target = LazyFlagResultContainer16;
			lazyFlagType = t_NEG16;
		}
		break;
		case 0x04: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint32_t tempu=(uint32_t)reg_AX_16*(uint32_t)(*(uint16_t*)(target));
			reg_AX_16=(uint16_t)(tempu);
			reg_DX_16=(uint16_t)(tempu >> 16);
			FillFlagsNoCFOF();
			SET_FLAG(ZF,reg_AX_16 == 0);
			SET_FLAG(PF,PARITY16(reg_AX_16)^PARITY16(reg_DX_16)^GET_FLAG(PF));
			if (reg_DX_16) {
				SET_FLAG(CF,1);SET_FLAG(OF,1);
			} else {
				SET_FLAG(CF,0);SET_FLAG(OF,0);
			}
		}
		break;
		case 0x05: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
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
		}
		break;
		case 0x06: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint16_t val= *(uint16_t*)(target);
			uint32_t num=((uint32_t)reg_DX_16<<16)|reg_AX_16;
			uint32_t quo=num/val;
			uint16_t rem=(uint16_t)(num % val);
			uint16_t quo16=(uint16_t)(quo&0xffff);
			reg_DX_16=rem;
			reg_AX_16=quo16;
			FillFlags();
			SET_FLAG(ZF,(rem==0)&&((quo16&1)!=0));
			SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
			SET_FLAG(PF,PARITY16(rem&0xffff)^PARITY16(quo16&0xffff)^GET_FLAG(PF));
		}
		break;
		case 0x07: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
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
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Flag CF set false
void handlerCommand16Code00F8() {
	LOG("%s","Flag CF set false");
	SET_FLAG(CF, 0);
}
//Flag CF set true
void handlerCommand16Code00F9() {
	LOG("%s","Flag CF set true");
	SET_FLAG(CF, 1);
}
//Flag IF set false
void handlerCommand16Code00FA() {
	LOG("%s","Flag IF set false");
	SET_FLAG(IF, 0);
}
//Flag IF set true
void handlerCommand16Code00FB() {
	LOG("%s","Flag IF set true");
	SET_FLAG(IF, 1);
}
//Flag DF set false
void handlerCommand16Code00FC() {
	LOG("%s","Flag DF set false");
	SET_FLAG(DF, 0);
}
//Flag DF set true
void handlerCommand16Code00FD() {
	LOG("%s","Flag DF set true");
	SET_FLAG(DF, 1);
}
//Ofther
void handlerCommand16Code00FFP66P67() {
	LOG("%s","Ofther");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			// INC
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			(*(uint8_t*)target)++;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_INC8;
		}
		break;
		case 0x01: {
			// DEC
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			(*(uint8_t*)target)--;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_DEC8;
		}
		break;
		case 0x4: {
			// JMP
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			context.index = mem(SR_CS) + (*((uint32_t*)target));
		}
		break;
		case 0x6: {
			// PUSH
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			reg_SP_32u -= 16 / 8;
			*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = *(uint16_t*)target;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Ofther
void handlerCommand16Code00FFP67() {
	LOG("%s","Ofther");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			// INC
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			(*(uint8_t*)target)++;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_INC8;
		}
		break;
		case 0x01: {
			// DEC
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			(*(uint8_t*)target)--;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_DEC8;
		}
		break;
		case 0x4: {
			// JMP
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			context.index = mem(SR_CS) + (*((uint16_t*)target));
		}
		break;
		case 0x6: {
			// PUSH
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			reg_SP_32u -= 16 / 8;
			*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = *(uint16_t*)target;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Ofther
void handlerCommand16Code00FFP66() {
	LOG("%s","Ofther");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			// INC
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			(*(uint8_t*)target)++;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_INC8;
		}
		break;
		case 0x01: {
			// DEC
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			(*(uint8_t*)target)--;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_DEC8;
		}
		break;
		case 0x4: {
			// JMP
			uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
			context.index = mem(SR_CS) + (*((uint32_t*)target));
		}
		break;
		case 0x6: {
			// PUSH
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			reg_SP_16u -= 16 / 8;
			*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = *(uint16_t*)target;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Ofther
void handlerCommand16Code00FF() {
	LOG("%s","Ofther");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			// INC
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			(*(uint8_t*)target)++;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_INC8;
		}
		break;
		case 0x01: {
			// DEC
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			(*(uint8_t*)target)--;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_DEC8;
		}
		break;
		case 0x4: {
			// JMP
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			context.index = mem(SR_CS) + (*((uint16_t*)target));
		}
		break;
		case 0x6: {
			// PUSH
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			reg_SP_16u -= 16 / 8;
			*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = *(uint16_t*)target;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//???
void handlerCommand16Code0101() {
	LOG("%s","???");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			*(uint16_t*)target = 0x0011;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//J(cond)
void handlerCommand16Code0180() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x00 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0181() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x01 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0182() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x02 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0183() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x03 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0184() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x04 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0185() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x05 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0186() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x06 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0187() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x07 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0188() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x08 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code0189() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x09 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code018A() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x0A {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code018B() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x0B {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code018C() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x0C {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code018D() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x0D {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code018E() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x0E {
		context.index += address;
	}
}
//J(cond)
void handlerCommand16Code018F() {
	LOG("%s","J(cond)");
	FillFlags();
	int16_t address = read16();
	if COND0x0F {
		context.index += address;
	}
}
//Math
void handlerCommand16Code0190P66() {
	LOG("%s","Math");
	uint8_t cond = 0x00;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x00 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0190() {
	LOG("%s","Math");
	uint8_t cond = 0x00;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x00 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0191P66() {
	LOG("%s","Math");
	uint8_t cond = 0x01;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x01 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0191() {
	LOG("%s","Math");
	uint8_t cond = 0x01;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x01 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0192P66() {
	LOG("%s","Math");
	uint8_t cond = 0x02;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x02 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0192() {
	LOG("%s","Math");
	uint8_t cond = 0x02;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x02 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0193P66() {
	LOG("%s","Math");
	uint8_t cond = 0x03;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x03 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0193() {
	LOG("%s","Math");
	uint8_t cond = 0x03;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x03 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0194P66() {
	LOG("%s","Math");
	uint8_t cond = 0x04;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x04 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0194() {
	LOG("%s","Math");
	uint8_t cond = 0x04;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x04 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0195P66() {
	LOG("%s","Math");
	uint8_t cond = 0x05;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x05 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0195() {
	LOG("%s","Math");
	uint8_t cond = 0x05;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x05 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0196P66() {
	LOG("%s","Math");
	uint8_t cond = 0x06;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x06 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0196() {
	LOG("%s","Math");
	uint8_t cond = 0x06;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x06 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0197P66() {
	LOG("%s","Math");
	uint8_t cond = 0x07;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x07 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0197() {
	LOG("%s","Math");
	uint8_t cond = 0x07;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x07 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0198P66() {
	LOG("%s","Math");
	uint8_t cond = 0x08;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x08 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0198() {
	LOG("%s","Math");
	uint8_t cond = 0x08;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x08 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0199P66() {
	LOG("%s","Math");
	uint8_t cond = 0x09;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x09 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code0199() {
	LOG("%s","Math");
	uint8_t cond = 0x09;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x09 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code019AP66() {
	LOG("%s","Math");
	uint8_t cond = 0x0A;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x0A ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code019A() {
	LOG("%s","Math");
	uint8_t cond = 0x0A;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x0A ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code019BP66() {
	LOG("%s","Math");
	uint8_t cond = 0x0B;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x0B ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code019B() {
	LOG("%s","Math");
	uint8_t cond = 0x0B;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x0B ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code019CP66() {
	LOG("%s","Math");
	uint8_t cond = 0x0C;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x0C ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code019C() {
	LOG("%s","Math");
	uint8_t cond = 0x0C;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x0C ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code019DP66() {
	LOG("%s","Math");
	uint8_t cond = 0x0D;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x0D ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code019D() {
	LOG("%s","Math");
	uint8_t cond = 0x0D;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x0D ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code019EP66() {
	LOG("%s","Math");
	uint8_t cond = 0x0E;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x0E ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code019E() {
	LOG("%s","Math");
	uint8_t cond = 0x0E;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x0E ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code019FP66() {
	LOG("%s","Math");
	uint8_t cond = 0x0F;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x0F ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand16Code019F() {
	LOG("%s","Math");
	uint8_t cond = 0x0F;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM16For8(mrmByte);
			// SET(cond)
			*target = COND0x0F ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//BT
void handlerCommand16Code01A3P66() {
	LOG("%s","BT");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t shift = *(uint16_t*)source;
	// BT
	FillFlags();
	uint16_t mask = 1 << shift;
	uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
}
//BT
void handlerCommand16Code01A3() {
	LOG("%s","BT");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t shift = *(uint16_t*)source;
	// BT
	FillFlags();
	uint16_t mask = 1 << shift;
	uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
}
//BTS
void handlerCommand16Code01ABP66() {
	LOG("%s","BTS");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t shift = *(uint16_t*)source;
	// BTS
	FillFlags();
	uint16_t mask = 1 << shift;
	uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
	(*(uint16_t*)target) = (*(uint16_t*)target) | mask;
}
//BTS
void handlerCommand16Code01AB() {
	LOG("%s","BTS");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t shift = *(uint16_t*)source;
	// BTS
	FillFlags();
	uint16_t mask = 1 << shift;
	uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
	(*(uint16_t*)target) = (*(uint16_t*)target) | mask;
}
//Mul
void handlerCommand16Code01AFP66() {
	LOG("%s","Mul");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	int32_t source1 = *(int32_t*)source;
	int32_t source2 = *(int32_t*)target;
	target = source;
	int64_t tmp = (int64_t)source1 * (int64_t)source2;
	int32_t value = source1 * source2;
	*((int32_t*)target) = value;
	SET_FLAG(ZF, value == 0);
	SET_FLAG(CF, value != tmp);
	SET_FLAG(OF, value != tmp);
	lazyFlagType = t_MUL;
}
//Mul
void handlerCommand16Code01AF() {
	LOG("%s","Mul");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	int16_t source1 = *(int16_t*)source;
	int16_t source2 = *(int16_t*)target;
	target = source;
	int32_t tmp = (int32_t)source1 * (int32_t)source2;
	int16_t value = source1 * source2;
	*((int16_t*)target) = value;
	SET_FLAG(ZF, value == 0);
	SET_FLAG(CF, value != tmp);
	SET_FLAG(OF, value != tmp);
	lazyFlagType = t_MUL;
}
//Load SR_SS
void handlerCommand16Code01B2() {
	LOG("%s","Load SR_SS");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	setMem(SR_SS, *(uint16_t*)(target + 2));
	*(uint16_t*)source = *(uint16_t*)(target);
}
//BTR
void handlerCommand16Code01B3P66() {
	LOG("%s","BTR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t shift = *(uint16_t*)source;
	// BTR
	FillFlags();
	uint16_t mask = 1 << shift;
	uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
	(*(uint16_t*)target) = (*(uint16_t*)target) & (~mask);
}
//BTR
void handlerCommand16Code01B3() {
	LOG("%s","BTR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t shift = *(uint16_t*)source;
	// BTR
	FillFlags();
	uint16_t mask = 1 << shift;
	uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
	(*(uint16_t*)target) = (*(uint16_t*)target) & (~mask);
}
//Load SR_FS
void handlerCommand16Code01B4() {
	LOG("%s","Load SR_FS");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	setMem(SR_FS, *(uint16_t*)(target + 2));
	*(uint16_t*)source = *(uint16_t*)(target);
}
//Load SR_GS
void handlerCommand16Code01B5() {
	LOG("%s","Load SR_GS");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	setMem(SR_GS, *(uint16_t*)(target + 2));
	*(uint16_t*)source = *(uint16_t*)(target);
}
//MOVZX
void handlerCommand16Code01B6P66() {
	LOG("%s","MOVZX");
	uint8_t mrmByte = read8u();
	uint32_t* target = (uint32_t*)readRegisterMRM32(mrmByte);
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	*target = (uint32_t)*source;
}
//MOVZX
void handlerCommand16Code01B6() {
	LOG("%s","MOVZX");
	uint8_t mrmByte = read8u();
	uint16_t* target = (uint16_t*)readRegisterMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	*target = (uint16_t)*source;
}
//MOVZX
void handlerCommand16Code01B7() {
	LOG("%s","MOVZX");
	uint8_t mrmByte = read8u();
	uint32_t* target = (uint32_t*)readRegisterMRM32(mrmByte);
	uint16_t* source = (uint16_t*)readAddressMRM32For16(mrmByte);
	*target = (uint32_t)*source;
}
//Bit scan
void handlerCommand16Code01BAP66() {
	LOG("%s","Bit scan");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t shift = read8u();
			// BT
			FillFlags();
			uint16_t mask = 1 << shift;
			uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t shift = read8u();
			// BTS
			FillFlags();
			uint16_t mask = 1 << shift;
			uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
			(*(uint16_t*)target) = (*(uint16_t*)target) | mask;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t shift = read8u();
			// BTR
			FillFlags();
			uint16_t mask = 1 << shift;
			uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
			(*(uint16_t*)target) = (*(uint16_t*)target) & (~mask);
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t shift = read8u();
			// BTC
			FillFlags();
			uint16_t mask = 1 << shift;
			uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
			if (value) {
				(*(uint16_t*)target) = (*(uint16_t*)target) & (~mask);
			} else {
				(*(uint16_t*)target) = (*(uint16_t*)target) | mask;
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Bit scan
void handlerCommand16Code01BA() {
	LOG("%s","Bit scan");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t shift = read8u();
			// BT
			FillFlags();
			uint16_t mask = 1 << shift;
			uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t shift = read8u();
			// BTS
			FillFlags();
			uint16_t mask = 1 << shift;
			uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
			(*(uint16_t*)target) = (*(uint16_t*)target) | mask;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t shift = read8u();
			// BTR
			FillFlags();
			uint16_t mask = 1 << shift;
			uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
			(*(uint16_t*)target) = (*(uint16_t*)target) & (~mask);
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
			uint8_t shift = read8u();
			// BTC
			FillFlags();
			uint16_t mask = 1 << shift;
			uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
			if (value) {
				(*(uint16_t*)target) = (*(uint16_t*)target) & (~mask);
			} else {
				(*(uint16_t*)target) = (*(uint16_t*)target) | mask;
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//BTC
void handlerCommand16Code01BBP66() {
	LOG("%s","BTC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t shift = *(uint16_t*)source;
	// BTC
	FillFlags();
	uint16_t mask = 1 << shift;
	uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
	if (value) {
		(*(uint16_t*)target) = (*(uint16_t*)target) & (~mask);
	} else {
		(*(uint16_t*)target) = (*(uint16_t*)target) | mask;
	}
}
//BTC
void handlerCommand16Code01BB() {
	LOG("%s","BTC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint16_t shift = *(uint16_t*)source;
	// BTC
	FillFlags();
	uint16_t mask = 1 << shift;
	uint8_t value = ((*(uint16_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
	if (value) {
		(*(uint16_t*)target) = (*(uint16_t*)target) & (~mask);
	} else {
		(*(uint16_t*)target) = (*(uint16_t*)target) | mask;
	}
}
//BFC
void handlerCommand16Code01BCP66() {
	LOG("%s","BFC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	FillFlags();
	uint32_t value = *(uint32_t*)source;
	if (value == 0) { SET_FLAG(ZF, 0); return; }
	uint32_t mask = 1;
	uint32_t len = 0;
	while ((mask & value) && (len < 32)) {
		value = value >> 1;
		len++;
	}
	SET_FLAG(ZF, 1);
	*(uint32_t*)target = len;
}
//BFC
void handlerCommand16Code01BC() {
	LOG("%s","BFC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	FillFlags();
	uint16_t value = *(uint16_t*)source;
	if (value == 0) { SET_FLAG(ZF, 0); return; }
	uint16_t mask = 1;
	uint16_t len = 0;
	while ((mask & value) && (len < 16)) {
		value = value >> 1;
		len++;
	}
	SET_FLAG(ZF, 1);
	*(uint16_t*)target = len;
}
//BSR
void handlerCommand16Code01BDP66() {
	LOG("%s","BSR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	FillFlags();
	uint32_t value = *(uint32_t*)source;
	if (value == 0) { SET_FLAG(ZF, 0); return; }
	uint32_t mask = 1 << (32 - 1);
	uint32_t len = 0;
	while ((mask & value) && (len < 32)) {
		value = value << 1;
		len++;
	}
	SET_FLAG(ZF, 1);
	*(uint32_t*)target = len;
}
//BSR
void handlerCommand16Code01BD() {
	LOG("%s","BSR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM16For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	FillFlags();
	uint16_t value = *(uint16_t*)source;
	if (value == 0) { SET_FLAG(ZF, 0); return; }
	uint16_t mask = 1 << (16 - 1);
	uint16_t len = 0;
	while ((mask & value) && (len < 16)) {
		value = value << 1;
		len++;
	}
	SET_FLAG(ZF, 1);
	*(uint16_t*)target = len;
}
//MOVSX
void handlerCommand16Code01BEP66() {
	LOG("%s","MOVSX");
	uint8_t mrmByte = read8u();
	int32_t* target = (int32_t*)readRegisterMRM32(mrmByte);
	int8_t* source = (int8_t*)readAddressMRM32For8(mrmByte);
	*target = (int32_t)*source;
}
//MOVSX
void handlerCommand16Code01BE() {
	LOG("%s","MOVSX");
	uint8_t mrmByte = read8u();
	int16_t* target = (int16_t*)readRegisterMRM16(mrmByte);
	int8_t* source = (int8_t*)readAddressMRM32For8(mrmByte);
	*target = (int16_t)*source;
}
//MOVSX
void handlerCommand16Code01BF() {
	LOG("%s","MOVSX");
	uint8_t mrmByte = read8u();
	int32_t* target = (int32_t*)readRegisterMRM32(mrmByte);
	int16_t* source = (int16_t*)readAddressMRM32For16(mrmByte);
	*target = (int32_t)*source;
}
//Swap
void handlerCommand16Code01C8() {
	LOG("%s","Swap");
	uint8_t reg = 0x00;
	uint32_t value = reg_0x00_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand16Code01C9() {
	LOG("%s","Swap");
	uint8_t reg = 0x01;
	uint32_t value = reg_0x01_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand16Code01CA() {
	LOG("%s","Swap");
	uint8_t reg = 0x02;
	uint32_t value = reg_0x02_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand16Code01CB() {
	LOG("%s","Swap");
	uint8_t reg = 0x03;
	uint32_t value = reg_0x03_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand16Code01CC() {
	LOG("%s","Swap");
	uint8_t reg = 0x04;
	uint32_t value = reg_0x04_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand16Code01CD() {
	LOG("%s","Swap");
	uint8_t reg = 0x05;
	uint32_t value = reg_0x05_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand16Code01CE() {
	LOG("%s","Swap");
	uint8_t reg = 0x06;
	uint32_t value = reg_0x06_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand16Code01CF() {
	LOG("%s","Swap");
	uint8_t reg = 0x07;
	uint32_t value = reg_0x07_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//ADD
void handlerCommand32Code0000P66() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand32Code0000() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand32Code0001P66() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_ADD16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//ADD
void handlerCommand32Code0001() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_ADD32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//ADD
void handlerCommand32Code0002P66() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand32Code0002() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_ADD8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand32Code0003P66() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_ADD16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//ADD
void handlerCommand32Code0003() {
	LOG("%s","ADD");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_ADD32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//ADD
void handlerCommand32Code0004P66() {
	LOG("%s","ADD");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_ADD8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand32Code0004() {
	LOG("%s","ADD");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_ADD8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//ADD
void handlerCommand32Code0005P66() {
	LOG("%s","ADD");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_ADD16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//ADD
void handlerCommand32Code0005() {
	LOG("%s","ADD");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_ADD32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//Push
void handlerCommand32Code0006() {
	LOG("%s","Push");
	uint8_t rg = 0x00;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = context.segmentRegisters[rg];
}
//Push
void handlerCommand32Code000E() {
	LOG("%s","Push");
	uint8_t rg = 0x01;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = context.segmentRegisters[rg];
}
//Push
void handlerCommand32Code0016() {
	LOG("%s","Push");
	uint8_t rg = 0x02;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = context.segmentRegisters[rg];
}
//Push
void handlerCommand32Code001E() {
	LOG("%s","Push");
	uint8_t rg = 0x03;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = context.segmentRegisters[rg];
}
//Pop
void handlerCommand32Code0007() {
	LOG("%s","Pop");
	uint8_t rg = 0x00;
	    context.segmentRegisters[rg] = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	    reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand32Code000F() {
	LOG("%s","Pop");
	uint8_t rg = 0x01;
	// 0f???
}
//Pop
void handlerCommand32Code0017() {
	LOG("%s","Pop");
	uint8_t rg = 0x02;
	    context.segmentRegisters[rg] = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	    reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand32Code001F() {
	LOG("%s","Pop");
	uint8_t rg = 0x03;
	    context.segmentRegisters[rg] = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	    reg_SP_32u += 16 / 8;
}
//OR
void handlerCommand32Code0008P66() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand32Code0008() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand32Code0009P66() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) | ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_OR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//OR
void handlerCommand32Code0009() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) | ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_OR32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//OR
void handlerCommand32Code000AP66() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand32Code000A() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_OR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand32Code000BP66() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) | ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_OR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//OR
void handlerCommand32Code000B() {
	LOG("%s","OR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) | ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_OR32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//OR
void handlerCommand32Code000CP66() {
	LOG("%s","OR");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_OR8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand32Code000C() {
	LOG("%s","OR");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_OR8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//OR
void handlerCommand32Code000DP66() {
	LOG("%s","OR");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) | ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_OR16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//OR
void handlerCommand32Code000D() {
	LOG("%s","OR");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) | ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_OR32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//ADC
void handlerCommand32Code0010P66() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) + oldcf;
	lazyFlagType = t_ADC8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADC
void handlerCommand32Code0010() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) + oldcf;
	lazyFlagType = t_ADC8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADC
void handlerCommand32Code0011P66() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16) + oldcf;
	lazyFlagType = t_ADC16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//ADC
void handlerCommand32Code0011() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32) + oldcf;
	lazyFlagType = t_ADC32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//ADC
void handlerCommand32Code0012P66() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) + oldcf;
	lazyFlagType = t_ADC8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADC
void handlerCommand32Code0012() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) + oldcf;
	lazyFlagType = t_ADC8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//ADC
void handlerCommand32Code0013P66() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16) + oldcf;
	lazyFlagType = t_ADC16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//ADC
void handlerCommand32Code0013() {
	LOG("%s","ADC");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32) + oldcf;
	lazyFlagType = t_ADC32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//ADC
void handlerCommand32Code0014P66() {
	LOG("%s","ADC");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8)) + oldcf;
	lazyFlagType = t_ADC8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//ADC
void handlerCommand32Code0014() {
	LOG("%s","ADC");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8)) + oldcf;
	lazyFlagType = t_ADC8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//ADC
void handlerCommand32Code0015P66() {
	LOG("%s","ADC");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16)) + oldcf;
	lazyFlagType = t_ADC16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//ADC
void handlerCommand32Code0015() {
	LOG("%s","ADC");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32)) + oldcf;
	lazyFlagType = t_ADC32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//SBB
void handlerCommand32Code0018P66() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) - oldcf;
	lazyFlagType = t_SBB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SBB
void handlerCommand32Code0018() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) - oldcf;
	lazyFlagType = t_SBB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SBB
void handlerCommand32Code0019P66() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) - oldcf;
	lazyFlagType = t_SBB16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//SBB
void handlerCommand32Code0019() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) - oldcf;
	lazyFlagType = t_SBB32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//SBB
void handlerCommand32Code001AP66() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) - oldcf;
	lazyFlagType = t_SBB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SBB
void handlerCommand32Code001A() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) - oldcf;
	lazyFlagType = t_SBB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SBB
void handlerCommand32Code001BP66() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) - oldcf;
	lazyFlagType = t_SBB16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//SBB
void handlerCommand32Code001B() {
	LOG("%s","SBB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) - oldcf;
	lazyFlagType = t_SBB32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//SBB
void handlerCommand32Code001CP66() {
	LOG("%s","SBB");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8)) - oldcf;
	lazyFlagType = t_SBB8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//SBB
void handlerCommand32Code001C() {
	LOG("%s","SBB");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8)) - oldcf;
	lazyFlagType = t_SBB8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//SBB
void handlerCommand32Code001DP66() {
	LOG("%s","SBB");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16)) - oldcf;
	lazyFlagType = t_SBB16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//SBB
void handlerCommand32Code001D() {
	LOG("%s","SBB");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	FillFlags();
	oldcf = GET_FLAG(CF);
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32)) - oldcf;
	lazyFlagType = t_SBB32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//AND
void handlerCommand32Code0020P66() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand32Code0020() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand32Code0021P66() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) & ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_AND16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//AND
void handlerCommand32Code0021() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) & ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_AND32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//AND
void handlerCommand32Code0022P66() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand32Code0022() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_AND8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand32Code0023P66() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) & ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_AND16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//AND
void handlerCommand32Code0023() {
	LOG("%s","AND");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) & ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_AND32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//AND
void handlerCommand32Code0024P66() {
	LOG("%s","AND");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_AND8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand32Code0024() {
	LOG("%s","AND");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_AND8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//AND
void handlerCommand32Code0025P66() {
	LOG("%s","AND");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) & ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_AND16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//AND
void handlerCommand32Code0025() {
	LOG("%s","AND");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) & ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_AND32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//SUB
void handlerCommand32Code0028P66() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand32Code0028() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand32Code0029P66() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_SUB16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//SUB
void handlerCommand32Code0029() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_SUB32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//SUB
void handlerCommand32Code002AP66() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand32Code002A() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_SUB8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand32Code002BP66() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_SUB16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//SUB
void handlerCommand32Code002B() {
	LOG("%s","SUB");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_SUB32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//SUB
void handlerCommand32Code002CP66() {
	LOG("%s","SUB");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_SUB8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand32Code002C() {
	LOG("%s","SUB");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_SUB8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//SUB
void handlerCommand32Code002DP66() {
	LOG("%s","SUB");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_SUB16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//SUB
void handlerCommand32Code002D() {
	LOG("%s","SUB");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_SUB32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//XOR
void handlerCommand32Code0030P66() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand32Code0030() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand32Code0031P66() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) ^ ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_XOR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//XOR
void handlerCommand32Code0031() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) ^ ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_XOR32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//XOR
void handlerCommand32Code0032P66() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand32Code0032() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_XOR8;
	*(int8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand32Code0033P66() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) ^ ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_XOR16;
	*(int16_t*)target = LazyFlagResultContainer16;
}
//XOR
void handlerCommand32Code0033() {
	LOG("%s","XOR");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) ^ ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_XOR32;
	*(int32_t*)target = LazyFlagResultContainer32;
}
//XOR
void handlerCommand32Code0034P66() {
	LOG("%s","XOR");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_XOR8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand32Code0034() {
	LOG("%s","XOR");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_XOR8;
	*(uint8_t*)target = LazyFlagResultContainer8;
}
//XOR
void handlerCommand32Code0035P66() {
	LOG("%s","XOR");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) ^ ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_XOR16;
	*(uint16_t*)target = LazyFlagResultContainer16;
}
//XOR
void handlerCommand32Code0035() {
	LOG("%s","XOR");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) ^ ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_XOR32;
	*(uint32_t*)target = LazyFlagResultContainer32;
}
//CMP
void handlerCommand32Code0038P66() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand32Code0038() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand32Code0039P66() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_CMP16;
}
//CMP
void handlerCommand32Code0039() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_CMP32;
}
//CMP
void handlerCommand32Code003AP66() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand32Code003A() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand32Code003BP66() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_CMP16;
}
//CMP
void handlerCommand32Code003B() {
	LOG("%s","CMP");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_CMP32;
}
//CMP
void handlerCommand32Code003CP66() {
	LOG("%s","CMP");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand32Code003C() {
	LOG("%s","CMP");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_CMP8;
}
//CMP
void handlerCommand32Code003DP66() {
	LOG("%s","CMP");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_CMP16;
}
//CMP
void handlerCommand32Code003D() {
	LOG("%s","CMP");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_CMP32;
}
//Inc
void handlerCommand32Code0040P66() {
	LOG("%s","Inc");
	reg_0x00_16u += 1;
	LazyFlagResultContainer16 = reg_0x00_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand32Code0040() {
	LOG("%s","Inc");
	reg_0x00_32u += 1;
	LazyFlagResultContainer32 = reg_0x00_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand32Code0041P66() {
	LOG("%s","Inc");
	reg_0x01_16u += 1;
	LazyFlagResultContainer16 = reg_0x01_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand32Code0041() {
	LOG("%s","Inc");
	reg_0x01_32u += 1;
	LazyFlagResultContainer32 = reg_0x01_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand32Code0042P66() {
	LOG("%s","Inc");
	reg_0x02_16u += 1;
	LazyFlagResultContainer16 = reg_0x02_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand32Code0042() {
	LOG("%s","Inc");
	reg_0x02_32u += 1;
	LazyFlagResultContainer32 = reg_0x02_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand32Code0043P66() {
	LOG("%s","Inc");
	reg_0x03_16u += 1;
	LazyFlagResultContainer16 = reg_0x03_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand32Code0043() {
	LOG("%s","Inc");
	reg_0x03_32u += 1;
	LazyFlagResultContainer32 = reg_0x03_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand32Code0044P66() {
	LOG("%s","Inc");
	reg_0x04_16u += 1;
	LazyFlagResultContainer16 = reg_0x04_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand32Code0044() {
	LOG("%s","Inc");
	reg_0x04_32u += 1;
	LazyFlagResultContainer32 = reg_0x04_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand32Code0045P66() {
	LOG("%s","Inc");
	reg_0x05_16u += 1;
	LazyFlagResultContainer16 = reg_0x05_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand32Code0045() {
	LOG("%s","Inc");
	reg_0x05_32u += 1;
	LazyFlagResultContainer32 = reg_0x05_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand32Code0046P66() {
	LOG("%s","Inc");
	reg_0x06_16u += 1;
	LazyFlagResultContainer16 = reg_0x06_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand32Code0046() {
	LOG("%s","Inc");
	reg_0x06_32u += 1;
	LazyFlagResultContainer32 = reg_0x06_32u;
	lazyFlagType = t_INC32;
}
//Inc
void handlerCommand32Code0047P66() {
	LOG("%s","Inc");
	reg_0x07_16u += 1;
	LazyFlagResultContainer16 = reg_0x07_16u;
	lazyFlagType = t_INC16;
}
//Inc
void handlerCommand32Code0047() {
	LOG("%s","Inc");
	reg_0x07_32u += 1;
	LazyFlagResultContainer32 = reg_0x07_32u;
	lazyFlagType = t_INC32;
}
//Dec
void handlerCommand32Code0048P66() {
	LOG("%s","Dec");
	reg_0x00_16u -= 1;
	LazyFlagResultContainer16 = reg_0x00_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand32Code0048() {
	LOG("%s","Dec");
	reg_0x00_32u -= 1;
	LazyFlagResultContainer32 = reg_0x00_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand32Code0049P66() {
	LOG("%s","Dec");
	reg_0x01_16u -= 1;
	LazyFlagResultContainer16 = reg_0x01_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand32Code0049() {
	LOG("%s","Dec");
	reg_0x01_32u -= 1;
	LazyFlagResultContainer32 = reg_0x01_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand32Code004AP66() {
	LOG("%s","Dec");
	reg_0x02_16u -= 1;
	LazyFlagResultContainer16 = reg_0x02_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand32Code004A() {
	LOG("%s","Dec");
	reg_0x02_32u -= 1;
	LazyFlagResultContainer32 = reg_0x02_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand32Code004BP66() {
	LOG("%s","Dec");
	reg_0x03_16u -= 1;
	LazyFlagResultContainer16 = reg_0x03_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand32Code004B() {
	LOG("%s","Dec");
	reg_0x03_32u -= 1;
	LazyFlagResultContainer32 = reg_0x03_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand32Code004CP66() {
	LOG("%s","Dec");
	reg_0x04_16u -= 1;
	LazyFlagResultContainer16 = reg_0x04_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand32Code004C() {
	LOG("%s","Dec");
	reg_0x04_32u -= 1;
	LazyFlagResultContainer32 = reg_0x04_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand32Code004DP66() {
	LOG("%s","Dec");
	reg_0x05_16u -= 1;
	LazyFlagResultContainer16 = reg_0x05_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand32Code004D() {
	LOG("%s","Dec");
	reg_0x05_32u -= 1;
	LazyFlagResultContainer32 = reg_0x05_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand32Code004EP66() {
	LOG("%s","Dec");
	reg_0x06_16u -= 1;
	LazyFlagResultContainer16 = reg_0x06_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand32Code004E() {
	LOG("%s","Dec");
	reg_0x06_32u -= 1;
	LazyFlagResultContainer32 = reg_0x06_32u;
	lazyFlagType = t_DEC32;
}
//Dec
void handlerCommand32Code004FP66() {
	LOG("%s","Dec");
	reg_0x07_16u -= 1;
	LazyFlagResultContainer16 = reg_0x07_16u;
	lazyFlagType = t_DEC16;
}
//Dec
void handlerCommand32Code004F() {
	LOG("%s","Dec");
	reg_0x07_32u -= 1;
	LazyFlagResultContainer32 = reg_0x07_32u;
	lazyFlagType = t_DEC32;
}
//Push
void handlerCommand32Code0050P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x00;
	uint16_t value = reg_0x00_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0050P67() {
	LOG("%s","Push");
	uint8_t reg = 0x00;
	uint32_t value = reg_0x00_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0050P66() {
	LOG("%s","Push");
	uint8_t reg = 0x00;
	uint16_t value = reg_0x00_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0050() {
	LOG("%s","Push");
	uint8_t reg = 0x00;
	uint32_t value = reg_0x00_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0051P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x01;
	uint16_t value = reg_0x01_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0051P67() {
	LOG("%s","Push");
	uint8_t reg = 0x01;
	uint32_t value = reg_0x01_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0051P66() {
	LOG("%s","Push");
	uint8_t reg = 0x01;
	uint16_t value = reg_0x01_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0051() {
	LOG("%s","Push");
	uint8_t reg = 0x01;
	uint32_t value = reg_0x01_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0052P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x02;
	uint16_t value = reg_0x02_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0052P67() {
	LOG("%s","Push");
	uint8_t reg = 0x02;
	uint32_t value = reg_0x02_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0052P66() {
	LOG("%s","Push");
	uint8_t reg = 0x02;
	uint16_t value = reg_0x02_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0052() {
	LOG("%s","Push");
	uint8_t reg = 0x02;
	uint32_t value = reg_0x02_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0053P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x03;
	uint16_t value = reg_0x03_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0053P67() {
	LOG("%s","Push");
	uint8_t reg = 0x03;
	uint32_t value = reg_0x03_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0053P66() {
	LOG("%s","Push");
	uint8_t reg = 0x03;
	uint16_t value = reg_0x03_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0053() {
	LOG("%s","Push");
	uint8_t reg = 0x03;
	uint32_t value = reg_0x03_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0054P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x04;
	uint16_t value = reg_0x04_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0054P67() {
	LOG("%s","Push");
	uint8_t reg = 0x04;
	uint32_t value = reg_0x04_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0054P66() {
	LOG("%s","Push");
	uint8_t reg = 0x04;
	uint16_t value = reg_0x04_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0054() {
	LOG("%s","Push");
	uint8_t reg = 0x04;
	uint32_t value = reg_0x04_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0055P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x05;
	uint16_t value = reg_0x05_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0055P67() {
	LOG("%s","Push");
	uint8_t reg = 0x05;
	uint32_t value = reg_0x05_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0055P66() {
	LOG("%s","Push");
	uint8_t reg = 0x05;
	uint16_t value = reg_0x05_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0055() {
	LOG("%s","Push");
	uint8_t reg = 0x05;
	uint32_t value = reg_0x05_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0056P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x06;
	uint16_t value = reg_0x06_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0056P67() {
	LOG("%s","Push");
	uint8_t reg = 0x06;
	uint32_t value = reg_0x06_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0056P66() {
	LOG("%s","Push");
	uint8_t reg = 0x06;
	uint16_t value = reg_0x06_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0056() {
	LOG("%s","Push");
	uint8_t reg = 0x06;
	uint32_t value = reg_0x06_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0057P66P67() {
	LOG("%s","Push");
	uint8_t reg = 0x07;
	uint16_t value = reg_0x07_16u;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0057P67() {
	LOG("%s","Push");
	uint8_t reg = 0x07;
	uint32_t value = reg_0x07_32u;
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = value;
}
//Push
void handlerCommand32Code0057P66() {
	LOG("%s","Push");
	uint8_t reg = 0x07;
	uint16_t value = reg_0x07_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Push
void handlerCommand32Code0057() {
	LOG("%s","Push");
	uint8_t reg = 0x07;
	uint32_t value = reg_0x07_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = value;
}
//Pop
void handlerCommand32Code0058P66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x00;
	reg_0x00_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand32Code0058P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x00;
	reg_0x00_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand32Code0058P66() {
	LOG("%s","Pop");
	uint8_t reg = 0x00;
	reg_0x00_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand32Code0058() {
	LOG("%s","Pop");
	uint8_t reg = 0x00;
	reg_0x00_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand32Code0059P66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x01;
	reg_0x01_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand32Code0059P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x01;
	reg_0x01_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand32Code0059P66() {
	LOG("%s","Pop");
	uint8_t reg = 0x01;
	reg_0x01_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand32Code0059() {
	LOG("%s","Pop");
	uint8_t reg = 0x01;
	reg_0x01_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand32Code005AP66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x02;
	reg_0x02_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand32Code005AP67() {
	LOG("%s","Pop");
	uint8_t reg = 0x02;
	reg_0x02_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand32Code005AP66() {
	LOG("%s","Pop");
	uint8_t reg = 0x02;
	reg_0x02_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand32Code005A() {
	LOG("%s","Pop");
	uint8_t reg = 0x02;
	reg_0x02_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand32Code005BP66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x03;
	reg_0x03_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand32Code005BP67() {
	LOG("%s","Pop");
	uint8_t reg = 0x03;
	reg_0x03_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand32Code005BP66() {
	LOG("%s","Pop");
	uint8_t reg = 0x03;
	reg_0x03_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand32Code005B() {
	LOG("%s","Pop");
	uint8_t reg = 0x03;
	reg_0x03_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand32Code005CP66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x04;
	reg_0x04_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand32Code005CP67() {
	LOG("%s","Pop");
	uint8_t reg = 0x04;
	reg_0x04_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand32Code005CP66() {
	LOG("%s","Pop");
	uint8_t reg = 0x04;
	reg_0x04_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand32Code005C() {
	LOG("%s","Pop");
	uint8_t reg = 0x04;
	reg_0x04_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand32Code005DP66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x05;
	reg_0x05_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand32Code005DP67() {
	LOG("%s","Pop");
	uint8_t reg = 0x05;
	reg_0x05_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand32Code005DP66() {
	LOG("%s","Pop");
	uint8_t reg = 0x05;
	reg_0x05_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand32Code005D() {
	LOG("%s","Pop");
	uint8_t reg = 0x05;
	reg_0x05_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand32Code005EP66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x06;
	reg_0x06_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand32Code005EP67() {
	LOG("%s","Pop");
	uint8_t reg = 0x06;
	reg_0x06_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand32Code005EP66() {
	LOG("%s","Pop");
	uint8_t reg = 0x06;
	reg_0x06_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand32Code005E() {
	LOG("%s","Pop");
	uint8_t reg = 0x06;
	reg_0x06_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Pop
void handlerCommand32Code005FP66P67() {
	LOG("%s","Pop");
	uint8_t reg = 0x07;
	reg_0x07_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Pop
void handlerCommand32Code005FP67() {
	LOG("%s","Pop");
	uint8_t reg = 0x07;
	reg_0x07_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Pop
void handlerCommand32Code005FP66() {
	LOG("%s","Pop");
	uint8_t reg = 0x07;
	reg_0x07_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Pop
void handlerCommand32Code005F() {
	LOG("%s","Pop");
	uint8_t reg = 0x07;
	reg_0x07_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//PUSHA
void handlerCommand32Code0060P66() {
	LOG("%s","PUSHA");
	uint16_t tmp = reg_SP_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = reg_AX_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = reg_CX_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = reg_DX_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = reg_BX_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = tmp;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = reg_BP_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = reg_SI_16u;
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = reg_DI_16u;
}
//PUSHA
void handlerCommand32Code0060() {
	LOG("%s","PUSHA");
	uint32_t tmp = reg_SP_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_AX_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_CX_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_DX_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_BX_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = tmp;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_BP_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_SI_32u;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_DI_32u;
}
//POPA
void handlerCommand32Code0061P66() {
	LOG("%s","POPA");
	reg_DI_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
	reg_SI_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
	reg_BP_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
	reg_SP_32u += 16 / 8;
	reg_BX_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
	reg_DX_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
	reg_CX_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
	reg_AX_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//POPA
void handlerCommand32Code0061() {
	LOG("%s","POPA");
	reg_DI_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
	reg_SI_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
	reg_BP_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
	reg_SP_32u += 32 / 8;
	reg_BX_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
	reg_DX_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
	reg_CX_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
	reg_AX_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Push
void handlerCommand32Code0068P66P67() {
	LOG("%s","Push");
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = read16u();
}
//Push
void handlerCommand32Code0068P67() {
	LOG("%s","Push");
	reg_SP_16u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = read32u();
}
//Push
void handlerCommand32Code0068P66() {
	LOG("%s","Push");
	reg_SP_32u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = read16u();
}
//Push
void handlerCommand32Code0068() {
	LOG("%s","Push");
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = read32u();
}
//Mul
void handlerCommand32Code0069P66() {
	LOG("%s","Mul");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	int16_t source1 = read16();
	int16_t source2 = *(int16_t*)target;
	target = source;
	int32_t tmp = (int32_t)source1 * (int32_t)source2;
	int16_t value = source1 * source2;
	*((int16_t*)target) = value;
	SET_FLAG(ZF, value == 0);
	SET_FLAG(CF, value != tmp);
	SET_FLAG(OF, value != tmp);
	lazyFlagType = t_MUL;
}
//Mul
void handlerCommand32Code0069() {
	LOG("%s","Mul");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	int32_t source1 = read32();
	int32_t source2 = *(int32_t*)target;
	target = source;
	int64_t tmp = (int64_t)source1 * (int64_t)source2;
	int32_t value = source1 * source2;
	*((int32_t*)target) = value;
	SET_FLAG(ZF, value == 0);
	SET_FLAG(CF, value != tmp);
	SET_FLAG(OF, value != tmp);
	lazyFlagType = t_MUL;
}
//Push
void handlerCommand32Code006AP66P67() {
	LOG("%s","Push");
	reg_SP_16u -= 16 / 8;
	*(int16_t*)(mem(SR_SS) + reg_SP_16u) = (int16_t)read8();
}
//Push
void handlerCommand32Code006AP67() {
	LOG("%s","Push");
	reg_SP_16u -= 32 / 8;
	*(int32_t*)(mem(SR_SS) + reg_SP_16u) = (int32_t)read8();
}
//Push
void handlerCommand32Code006AP66() {
	LOG("%s","Push");
	reg_SP_32u -= 16 / 8;
	*(int16_t*)(mem(SR_SS) + reg_SP_32u) = (int16_t)read8();
}
//Push
void handlerCommand32Code006A() {
	LOG("%s","Push");
	reg_SP_32u -= 32 / 8;
	*(int32_t*)(mem(SR_SS) + reg_SP_32u) = (int32_t)read8();
}
//Mul
void handlerCommand32Code006B() {
	LOG("%s","Mul");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	int32_t source1 = (int32_t)read8();
	int32_t source2 = *(int32_t*)target;
	target = source;
	int64_t tmp = (int64_t)source1 * (int64_t)source2;
	int32_t value = source1 * source2;
	*((int32_t*)target) = value;
	SET_FLAG(ZF, value == 0);
	SET_FLAG(CF, value != tmp);
	SET_FLAG(OF, value != tmp);
	lazyFlagType = t_MUL;
}
//J(cond)
void handlerCommand32Code0070() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x00 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0071() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x01 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0072() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x02 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0073() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x03 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0074() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x04 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0075() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x05 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0076() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x06 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0077() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x07 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0078() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x08 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0079() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x09 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code007A() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x0A {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code007B() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x0B {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code007C() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x0C {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code007D() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x0D {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code007E() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x0E {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code007F() {
	LOG("%s","J(cond)");
	FillFlags();
	int8_t address = read8();
	if COND0x0F {
		context.index += address;
	}
}
//Math
void handlerCommand32Code0080P66() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_ADD8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_OR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) + oldcf;
			lazyFlagType = t_ADC8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) - oldcf;
			lazyFlagType = t_SBB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_AND8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_SUB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_XOR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_CMP8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0080() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_ADD8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) | ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_OR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) + ((uint8_t)LazyFlagVarB8) + oldcf;
			lazyFlagType = t_ADC8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) - oldcf;
			lazyFlagType = t_SBB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_AND8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_SUB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) ^ ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_XOR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((uint8_t)read8u());
			LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) - ((uint8_t)LazyFlagVarB8) ;
			lazyFlagType = t_CMP8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0081P66() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16) ;
			lazyFlagType = t_ADD16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) | ((uint16_t)LazyFlagVarB16) ;
			lazyFlagType = t_OR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) + ((uint16_t)LazyFlagVarB16) + oldcf;
			lazyFlagType = t_ADC16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) - oldcf;
			lazyFlagType = t_SBB16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) & ((uint16_t)LazyFlagVarB16) ;
			lazyFlagType = t_AND16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) ;
			lazyFlagType = t_SUB16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) ^ ((uint16_t)LazyFlagVarB16) ;
			lazyFlagType = t_XOR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((uint16_t)read16u());
			LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) - ((uint16_t)LazyFlagVarB16) ;
			lazyFlagType = t_CMP16;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0081() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32) ;
			lazyFlagType = t_ADD32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) | ((uint32_t)LazyFlagVarB32) ;
			lazyFlagType = t_OR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) + ((uint32_t)LazyFlagVarB32) + oldcf;
			lazyFlagType = t_ADC32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) - oldcf;
			lazyFlagType = t_SBB32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) & ((uint32_t)LazyFlagVarB32) ;
			lazyFlagType = t_AND32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) ;
			lazyFlagType = t_SUB32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) ^ ((uint32_t)LazyFlagVarB32) ;
			lazyFlagType = t_XOR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((uint32_t)read32u());
			LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) - ((uint32_t)LazyFlagVarB32) ;
			lazyFlagType = t_CMP32;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0082() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) + ((int8_t)LazyFlagVarB8) ;
			lazyFlagType = t_ADD8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) | ((int8_t)LazyFlagVarB8) ;
			lazyFlagType = t_OR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) + ((int8_t)LazyFlagVarB8) + oldcf;
			lazyFlagType = t_ADC8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) - ((int8_t)LazyFlagVarB8) - oldcf;
			lazyFlagType = t_SBB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) & ((int8_t)LazyFlagVarB8) ;
			lazyFlagType = t_AND8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) - ((int8_t)LazyFlagVarB8) ;
			lazyFlagType = t_SUB8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) ^ ((int8_t)LazyFlagVarB8) ;
			lazyFlagType = t_XOR8;
			*(int8_t*)target = LazyFlagResultContainer8;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = ((int8_t)read8());
			LazyFlagResultContainer8 = ((int8_t)LazyFlagVarA8) - ((int8_t)LazyFlagVarB8) ;
			lazyFlagType = t_CMP8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0083P66() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) + ((int16_t)LazyFlagVarB16) ;
			lazyFlagType = t_ADD16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) | ((int16_t)LazyFlagVarB16) ;
			lazyFlagType = t_OR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) + ((int16_t)LazyFlagVarB16) + oldcf;
			lazyFlagType = t_ADC16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) - ((int16_t)LazyFlagVarB16) - oldcf;
			lazyFlagType = t_SBB16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) & ((int16_t)LazyFlagVarB16) ;
			lazyFlagType = t_AND16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) - ((int16_t)LazyFlagVarB16) ;
			lazyFlagType = t_SUB16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) ^ ((int16_t)LazyFlagVarB16) ;
			lazyFlagType = t_XOR16;
			*(int16_t*)target = LazyFlagResultContainer16;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = ((int16_t)read8());
			LazyFlagResultContainer16 = ((int16_t)LazyFlagVarA16) - ((int16_t)LazyFlagVarB16) ;
			lazyFlagType = t_CMP16;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0083() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) + ((int32_t)LazyFlagVarB32) ;
			lazyFlagType = t_ADD32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) | ((int32_t)LazyFlagVarB32) ;
			lazyFlagType = t_OR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) + ((int32_t)LazyFlagVarB32) + oldcf;
			lazyFlagType = t_ADC32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			FillFlags();
			oldcf = GET_FLAG(CF);
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) - ((int32_t)LazyFlagVarB32) - oldcf;
			lazyFlagType = t_SBB32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) & ((int32_t)LazyFlagVarB32) ;
			lazyFlagType = t_AND32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) - ((int32_t)LazyFlagVarB32) ;
			lazyFlagType = t_SUB32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) ^ ((int32_t)LazyFlagVarB32) ;
			lazyFlagType = t_XOR32;
			*(int32_t*)target = LazyFlagResultContainer32;
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = ((int32_t)read8());
			LazyFlagResultContainer32 = ((int32_t)LazyFlagVarA32) - ((int32_t)LazyFlagVarB32) ;
			lazyFlagType = t_CMP32;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//TEST
void handlerCommand32Code0084P66() {
	LOG("%s","TEST");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_TEST8;
}
//TEST
void handlerCommand32Code0084() {
	LOG("%s","TEST");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	LazyFlagVarA8 = *(int8_t*)target;
	LazyFlagVarB8 = *(int8_t*)source;
	LazyFlagResultContainer8 = ((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8) ;
	lazyFlagType = t_TEST8;
}
//TEST
void handlerCommand32Code0085P66() {
	LOG("%s","TEST");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	LazyFlagVarA16 = *(int16_t*)target;
	LazyFlagVarB16 = *(int16_t*)source;
	LazyFlagResultContainer16 = ((uint16_t)LazyFlagVarA16) & ((uint16_t)LazyFlagVarB16) ;
	lazyFlagType = t_TEST16;
}
//TEST
void handlerCommand32Code0085() {
	LOG("%s","TEST");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	LazyFlagVarA32 = *(int32_t*)target;
	LazyFlagVarB32 = *(int32_t*)source;
	LazyFlagResultContainer32 = ((uint32_t)LazyFlagVarA32) & ((uint32_t)LazyFlagVarB32) ;
	lazyFlagType = t_TEST32;
}
//XCHG
void handlerCommand32Code0086P66() {
	LOG("%s","XCHG");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t tmp = *(uint32_t*)target;
	*(uint32_t*)target = *(uint32_t*)source;
	*(uint32_t*)source = tmp;
}
//XCHG
void handlerCommand32Code0086() {
	LOG("%s","XCHG");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t tmp = *(uint32_t*)target;
	*(uint32_t*)target = *(uint32_t*)source;
	*(uint32_t*)source = tmp;
}
//XCHG
void handlerCommand32Code0087P66() {
	LOG("%s","XCHG");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t tmp = *(uint32_t*)target;
	*(uint32_t*)target = *(uint32_t*)source;
	*(uint32_t*)source = tmp;
}
//XCHG
void handlerCommand32Code0087() {
	LOG("%s","XCHG");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t tmp = *(uint32_t*)target;
	*(uint32_t*)target = *(uint32_t*)source;
	*(uint32_t*)source = tmp;
}
//Move
void handlerCommand32Code0088P66() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code0088() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code0089P66() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand32Code0089() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	*(uint32_t*)target = *(uint32_t*)source;
}
//Move
void handlerCommand32Code008AP66() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code008A() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM8(mrmByte);
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code008BP66() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM16(mrmByte);
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand32Code008B() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* target = (uint8_t*)readRegisterMRM32(mrmByte);
	*(uint32_t*)target = *(uint32_t*)source;
}
//Move
void handlerCommand32Code008C() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readSegmentRegisterMRM(mrmByte);
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand32Code008E() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* target = (uint8_t*)readSegmentRegisterMRM(mrmByte);
	*(uint16_t*)target = *(uint16_t*)source;
}
//Lea
void handlerCommand32Code008DP66P67() {
	LOG("%s","Lea");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint32_t target = effectiveAddressMRM32For32(mrmByte);
	*((uint16_t*)source) = (uint16_t)(target & 0xFFFF);
}
//Lea
void handlerCommand32Code008DP67() {
	LOG("%s","Lea");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t target = effectiveAddressMRM32For32(mrmByte);
	*((uint32_t*)source) = (uint32_t)(target & 0xFFFFFFFF);
}
//Lea
void handlerCommand32Code008DP66() {
	LOG("%s","Lea");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	uint32_t target = effectiveAddressMRM32For32(mrmByte);
	*((uint16_t*)source) = (uint16_t)(target & 0xFFFF);
}
//Lea
void handlerCommand32Code008D() {
	LOG("%s","Lea");
	uint8_t mrmByte = read8u();
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t target = effectiveAddressMRM32For32(mrmByte);
	*((uint32_t*)source) = (uint32_t)(target & 0xFFFFFFFF);
}
//Pop
void handlerCommand32Code008FP66P67() {
	LOG("%s","Pop");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			*(uint16_t*)target = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
			reg_SP_16u += 16 / 8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Pop
void handlerCommand32Code008FP67() {
	LOG("%s","Pop");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			*(uint32_t*)target = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
			reg_SP_16u += 32 / 8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Pop
void handlerCommand32Code008FP66() {
	LOG("%s","Pop");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			*(uint16_t*)target = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
			reg_SP_32u += 16 / 8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Pop
void handlerCommand32Code008F() {
	LOG("%s","Pop");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			*(uint32_t*)target = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
			reg_SP_32u += 32 / 8;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//XCHG
void handlerCommand32Code0090P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x00;
	// NOP
}
//XCHG
void handlerCommand32Code0090() {
	LOG("%s","XCHG");
	uint8_t reg = 0x00;
	// NOP
}
//XCHG
void handlerCommand32Code0091P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x01;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x01_32u;
	reg_0x01_32u = tmp;
}
//XCHG
void handlerCommand32Code0091() {
	LOG("%s","XCHG");
	uint8_t reg = 0x01;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x01_32u;
	reg_0x01_32u = tmp;
}
//XCHG
void handlerCommand32Code0092P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x02;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x02_32u;
	reg_0x02_32u = tmp;
}
//XCHG
void handlerCommand32Code0092() {
	LOG("%s","XCHG");
	uint8_t reg = 0x02;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x02_32u;
	reg_0x02_32u = tmp;
}
//XCHG
void handlerCommand32Code0093P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x03;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x03_32u;
	reg_0x03_32u = tmp;
}
//XCHG
void handlerCommand32Code0093() {
	LOG("%s","XCHG");
	uint8_t reg = 0x03;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x03_32u;
	reg_0x03_32u = tmp;
}
//XCHG
void handlerCommand32Code0094P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x04;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x04_32u;
	reg_0x04_32u = tmp;
}
//XCHG
void handlerCommand32Code0094() {
	LOG("%s","XCHG");
	uint8_t reg = 0x04;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x04_32u;
	reg_0x04_32u = tmp;
}
//XCHG
void handlerCommand32Code0095P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x05;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x05_32u;
	reg_0x05_32u = tmp;
}
//XCHG
void handlerCommand32Code0095() {
	LOG("%s","XCHG");
	uint8_t reg = 0x05;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x05_32u;
	reg_0x05_32u = tmp;
}
//XCHG
void handlerCommand32Code0096P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x06;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x06_32u;
	reg_0x06_32u = tmp;
}
//XCHG
void handlerCommand32Code0096() {
	LOG("%s","XCHG");
	uint8_t reg = 0x06;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x06_32u;
	reg_0x06_32u = tmp;
}
//XCHG
void handlerCommand32Code0097P66() {
	LOG("%s","XCHG");
	uint8_t reg = 0x07;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x07_32u;
	reg_0x07_32u = tmp;
}
//XCHG
void handlerCommand32Code0097() {
	LOG("%s","XCHG");
	uint8_t reg = 0x07;
	uint32_t tmp = reg_AX_32u;
	reg_AX_32u = reg_0x07_32u;
	reg_0x07_32u = tmp;
}
//CBW
void handlerCommand32Code0098P66() {
	LOG("%s","CBW");
	reg_AX_16 = reg_AL_8;
}
//CBW
void handlerCommand32Code0098() {
	LOG("%s","CBW");
	reg_AX_32 = reg_AX_16;
}
//CBW
void handlerCommand32Code0099P66() {
	LOG("%s","CBW");
	if (reg_AX_16 & 0x8000) reg_DX_16=0xffff;else reg_DX_16=0;
}
//CBW
void handlerCommand32Code0099() {
	LOG("%s","CBW");
	if (reg_AX_32 & 0x80000000) reg_DX_32=0xffffffff; else reg_DX_32=0;
}
//PUSHF
void handlerCommand32Code009CP66() {
	LOG("%s","PUSHF");
	FillFlags();
	reg_SP_32u -= 16 / 8;
	EncodeFlagsRegister();
	uint32_t value = reg_flags & 0xFCFFFF;
	*(uint16_t*)(mem(SR_SS) + reg_SP_32u) = *((uint16_t*)&value);
}
//PUSHF
void handlerCommand32Code009C() {
	LOG("%s","PUSHF");
	FillFlags();
	reg_SP_32u -= 32 / 8;
	EncodeFlagsRegister();
	uint32_t value = reg_flags & 0xFCFFFF;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = *((uint32_t*)&value);
}
//POPF
void handlerCommand32Code009DP66() {
	LOG("%s","POPF");
	lazyFlagType = t_UNKNOWN;
	*(uint16_t*)(&reg_flags) = (*(uint16_t*)(mem(SR_SS) + reg_SP_32u));
	reg_SP_32u += 16 / 8;
	DecodeFlagsRegister16();
}
//POPF
void handlerCommand32Code009D() {
	LOG("%s","POPF");
	lazyFlagType = t_UNKNOWN;
	*(uint32_t*)(&reg_flags) = (*(uint32_t*)(mem(SR_SS) + reg_SP_32u));
	reg_SP_32u += 32 / 8;
	DecodeFlagsRegister32();
}
//Move
void handlerCommand32Code00A0P66P67() {
	LOG("%s","Move");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	uint8_t* source = (uint8_t*)(mem(SR_DS) + read16());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code00A0P66() {
	LOG("%s","Move");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	uint8_t* source = (uint8_t*)(mem(SR_DS) + read32());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code00A0P67() {
	LOG("%s","Move");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	uint8_t* source = (uint8_t*)(mem(SR_DS) + read16());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code00A0() {
	LOG("%s","Move");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	uint8_t* source = (uint8_t*)(mem(SR_DS) + read32());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code00A1P66P67() {
	LOG("%s","Move");
	uint16_t* target = (uint16_t*)register16u(BR_AX);
	uint16_t* source = (uint16_t*)(mem(SR_DS) + read16());
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand32Code00A1P66() {
	LOG("%s","Move");
	uint16_t* target = (uint16_t*)register16u(BR_AX);
	uint16_t* source = (uint16_t*)(mem(SR_DS) + read32());
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand32Code00A1P67() {
	LOG("%s","Move");
	uint32_t* target = (uint32_t*)register32u(BR_AX);
	uint32_t* source = (uint32_t*)(mem(SR_DS) + read16());
	*(uint32_t*)target = *(uint32_t*)source;
}
//Move
void handlerCommand32Code00A1() {
	LOG("%s","Move");
	uint32_t* target = (uint32_t*)register32u(BR_AX);
	uint32_t* source = (uint32_t*)(mem(SR_DS) + read32());
	*(uint32_t*)target = *(uint32_t*)source;
}
//Move
void handlerCommand32Code00A2P66P67() {
	LOG("%s","Move");
	uint8_t* source = (uint8_t*)register8u(BR_AX);
	uint8_t* target = (uint8_t*)(mem(SR_DS) + read16());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code00A2P66() {
	LOG("%s","Move");
	uint8_t* source = (uint8_t*)register8u(BR_AX);
	uint8_t* target = (uint8_t*)(mem(SR_DS) + read32());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code00A2P67() {
	LOG("%s","Move");
	uint8_t* source = (uint8_t*)register8u(BR_AX);
	uint8_t* target = (uint8_t*)(mem(SR_DS) + read16());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code00A2() {
	LOG("%s","Move");
	uint8_t* source = (uint8_t*)register8u(BR_AX);
	uint8_t* target = (uint8_t*)(mem(SR_DS) + read32());
	*(uint8_t*)target = *(uint8_t*)source;
}
//Move
void handlerCommand32Code00A3P66P67() {
	LOG("%s","Move");
	uint16_t* source = (uint16_t*)register16u(BR_AX);
	uint16_t* target = (uint16_t*)(mem(SR_DS) + read16());
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand32Code00A3P66() {
	LOG("%s","Move");
	uint16_t* source = (uint16_t*)register16u(BR_AX);
	uint16_t* target = (uint16_t*)(mem(SR_DS) + read32());
	*(uint16_t*)target = *(uint16_t*)source;
}
//Move
void handlerCommand32Code00A3P67() {
	LOG("%s","Move");
	uint32_t* source = (uint32_t*)register32u(BR_AX);
	uint32_t* target = (uint32_t*)(mem(SR_DS) + read16());
	*(uint32_t*)target = *(uint32_t*)source;
}
//Move
void handlerCommand32Code00A3() {
	LOG("%s","Move");
	uint32_t* source = (uint32_t*)register32u(BR_AX);
	uint32_t* target = (uint32_t*)(mem(SR_DS) + read32());
	*(uint32_t*)target = *(uint32_t*)source;
}
//MOVS
void handlerCommand32Code00A4P66P67() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
		}
	}
}
//MOVS
void handlerCommand32Code00A4P66() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
		}
	}
}
//MOVS
void handlerCommand32Code00A4P67() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
		}
	}
}
//MOVS
void handlerCommand32Code00A4() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
		}
	}
}
//MOVS
void handlerCommand32Code00A5P66P67() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_16) = *(uint16_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 -= 16 / 8;reg_SI_16 -= 16 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_16) = *(uint16_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 -= 16 / 8;reg_SI_16 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_16) = *(uint16_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 += 16 / 8;reg_SI_16 += 16 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_16) = *(uint16_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 += 16 / 8;reg_SI_16 += 16 / 8;
		}
	}
}
//MOVS
void handlerCommand32Code00A5P66() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_32) = *(uint16_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 -= 16 / 8;reg_SI_32 -= 16 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_32) = *(uint16_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 -= 16 / 8;reg_SI_32 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_32) = *(uint16_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 += 16 / 8;reg_SI_32 += 16 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_32) = *(uint16_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 += 16 / 8;reg_SI_32 += 16 / 8;
		}
	}
}
//MOVS
void handlerCommand32Code00A5P67() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_16) = *(uint32_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 -= 32 / 8;reg_SI_16 -= 32 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_16) = *(uint32_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 -= 32 / 8;reg_SI_16 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_16) = *(uint32_t*)(sourceSegment + reg_SI_16);
				reg_DI_16 += 32 / 8;reg_SI_16 += 32 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_16) = *(uint32_t*)(sourceSegment + reg_SI_16);
			reg_DI_16 += 32 / 8;reg_SI_16 += 32 / 8;
		}
	}
}
//MOVS
void handlerCommand32Code00A5() {
	LOG("%s","MOVS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_32) = *(uint32_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 -= 32 / 8;reg_SI_32 -= 32 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_32) = *(uint32_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 -= 32 / 8;reg_SI_32 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_32) = *(uint32_t*)(sourceSegment + reg_SI_32);
				reg_DI_32 += 32 / 8;reg_SI_32 += 32 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_32) = *(uint32_t*)(sourceSegment + reg_SI_32);
			reg_DI_32 += 32 / 8;reg_SI_32 += 32 / 8;
		}
	}
}
//CMPS
void handlerCommand32Code00A6P66P67() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
		}
	}
}
//CMPS
void handlerCommand32Code00A6P66() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
		}
	}
}
//CMPS
void handlerCommand32Code00A6P67() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 -= 8 / 8;reg_SI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_16) - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 += 8 / 8;reg_SI_16 += 8 / 8;
		}
	}
}
//CMPS
void handlerCommand32Code00A6() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 -= 8 / 8;reg_SI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = *(uint8_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = *(uint8_t*)(sourceSegment + reg_SI_32) - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 += 8 / 8;reg_SI_32 += 8 / 8;
		}
	}
}
//CMPS
void handlerCommand32Code00A7P66P67() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) == *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_16) - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 -= 16 / 8;reg_SI_16 -= 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) != *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_16) - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 -= 16 / 8;reg_SI_16 -= 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_16) - *(uint16_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP16;
			reg_DI_16 -= 16 / 8;reg_SI_16 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) == *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_16) - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 += 16 / 8;reg_SI_16 += 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) != *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_16) - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 += 16 / 8;reg_SI_16 += 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_16) - *(uint16_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP16;
			reg_DI_16 += 16 / 8;reg_SI_16 += 16 / 8;
		}
	}
}
//CMPS
void handlerCommand32Code00A7P66() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) == *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_32) - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 -= 16 / 8;reg_SI_32 -= 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) != *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_32) - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 -= 16 / 8;reg_SI_32 -= 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_32) - *(uint16_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP16;
			reg_DI_32 -= 16 / 8;reg_SI_32 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) == *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_32) - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 += 16 / 8;reg_SI_32 += 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) != *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_32) - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 += 16 / 8;reg_SI_32 += 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = *(uint16_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer16 = *(uint16_t*)(sourceSegment + reg_SI_32) - *(uint16_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP16;
			reg_DI_32 += 16 / 8;reg_SI_32 += 16 / 8;
		}
	}
}
//CMPS
void handlerCommand32Code00A7P67() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) == *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_16) - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 -= 32 / 8;reg_SI_16 -= 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) != *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_16) - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 -= 32 / 8;reg_SI_16 -= 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_16) - *(uint32_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP32;
			reg_DI_16 -= 32 / 8;reg_SI_16 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) == *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_16) - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 += 32 / 8;reg_SI_16 += 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) != *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_16);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_16) - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 += 32 / 8;reg_SI_16 += 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_16);
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_16) - *(uint32_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP32;
			reg_DI_16 += 32 / 8;reg_SI_16 += 32 / 8;
		}
	}
}
//CMPS
void handlerCommand32Code00A7() {
	LOG("%s","CMPS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) == *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_32) - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 -= 32 / 8;reg_SI_32 -= 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) != *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_32) - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 -= 32 / 8;reg_SI_32 -= 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_32) - *(uint32_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP32;
			reg_DI_32 -= 32 / 8;reg_SI_32 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) == *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_32) - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 += 32 / 8;reg_SI_32 += 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) != *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_32);
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_32) - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 += 32 / 8;reg_SI_32 += 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = *(uint32_t*)(sourceSegment + reg_SI_32);
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer32 = *(uint32_t*)(sourceSegment + reg_SI_32) - *(uint32_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP32;
			reg_DI_32 += 32 / 8;reg_SI_32 += 32 / 8;
		}
	}
}
//TEST
void handlerCommand32Code00A8P66() {
	LOG("%s","TEST");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_TEST8;
}
//TEST
void handlerCommand32Code00A8() {
	LOG("%s","TEST");
	uint8_t* target = (uint8_t*)register8u(BR_AX);
	LazyFlagVarA8 = *(uint8_t*)target;
	LazyFlagVarB8 = read8u();
	LazyFlagResultContainer8 = (((uint8_t)LazyFlagVarA8) & ((uint8_t)LazyFlagVarB8)) ;
	lazyFlagType = t_TEST8;
}
//TEST
void handlerCommand32Code00A9P66() {
	LOG("%s","TEST");
	uint8_t* target = (uint8_t*)register16u(BR_AX);
	LazyFlagVarA16 = *(uint16_t*)target;
	LazyFlagVarB16 = read16u();
	LazyFlagResultContainer16 = (((uint16_t)LazyFlagVarA16) & ((uint16_t)LazyFlagVarB16)) ;
	lazyFlagType = t_TEST16;
}
//TEST
void handlerCommand32Code00A9() {
	LOG("%s","TEST");
	uint8_t* target = (uint8_t*)register32u(BR_AX);
	LazyFlagVarA32 = *(uint32_t*)target;
	LazyFlagVarB32 = read32u();
	LazyFlagResultContainer32 = (((uint32_t)LazyFlagVarA32) & ((uint32_t)LazyFlagVarB32)) ;
	lazyFlagType = t_TEST32;
}
//STOS
void handlerCommand32Code00AAP66P67() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
				reg_DI_16 -= 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
			reg_DI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
				reg_DI_16 += 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
			reg_DI_16 += 8 / 8;
		}
	}
}
//STOS
void handlerCommand32Code00AAP66() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
				reg_DI_32 -= 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
			reg_DI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
				reg_DI_32 += 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
			reg_DI_32 += 8 / 8;
		}
	}
}
//STOS
void handlerCommand32Code00AAP67() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
				reg_DI_16 -= 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
			reg_DI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
				reg_DI_16 += 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_16) = reg_0x00_8u;
			reg_DI_16 += 8 / 8;
		}
	}
}
//STOS
void handlerCommand32Code00AA() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
				reg_DI_32 -= 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
			reg_DI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
				reg_DI_32 += 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint8_t*)(targetSegment + reg_DI_32) = reg_0x00_8u;
			reg_DI_32 += 8 / 8;
		}
	}
}
//STOS
void handlerCommand32Code00ABP66P67() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_16) = reg_0x00_16u;
				reg_DI_16 -= 16 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_16) = reg_0x00_16u;
			reg_DI_16 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_16) = reg_0x00_16u;
				reg_DI_16 += 16 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_16) = reg_0x00_16u;
			reg_DI_16 += 16 / 8;
		}
	}
}
//STOS
void handlerCommand32Code00ABP66() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_32) = reg_0x00_16u;
				reg_DI_32 -= 16 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_32) = reg_0x00_16u;
			reg_DI_32 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint16_t*)(targetSegment + reg_DI_32) = reg_0x00_16u;
				reg_DI_32 += 16 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint16_t*)(targetSegment + reg_DI_32) = reg_0x00_16u;
			reg_DI_32 += 16 / 8;
		}
	}
}
//STOS
void handlerCommand32Code00ABP67() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_16) = reg_0x00_32u;
				reg_DI_16 -= 32 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_16) = reg_0x00_32u;
			reg_DI_16 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_16) = reg_0x00_32u;
				reg_DI_16 += 32 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_16) = reg_0x00_32u;
			reg_DI_16 += 32 / 8;
		}
	}
}
//STOS
void handlerCommand32Code00AB() {
	LOG("%s","STOS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_32) = reg_0x00_32u;
				reg_DI_32 -= 32 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_32) = reg_0x00_32u;
			reg_DI_32 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				*(uint32_t*)(targetSegment + reg_DI_32) = reg_0x00_32u;
				reg_DI_32 += 32 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			*(uint32_t*)(targetSegment + reg_DI_32) = reg_0x00_32u;
			reg_DI_32 += 32 / 8;
		}
	}
}
//LOADS
void handlerCommand32Code00ACP66P67() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 += 8 / 8;
		}
	}
}
//LOADS
void handlerCommand32Code00ACP66() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 += 8 / 8;
		}
	}
}
//LOADS
void handlerCommand32Code00ACP67() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 -= 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 += 8 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 += 8 / 8;
		}
	}
}
//LOADS
void handlerCommand32Code00AC() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 -= 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 += 8 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_8u = *(uint8_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 += 8 / 8;
		}
	}
}
//LOADS
void handlerCommand32Code00ADP66P67() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 -= 16 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 += 16 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 += 16 / 8;
		}
	}
}
//LOADS
void handlerCommand32Code00ADP66() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 -= 16 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 += 16 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_16u = *(uint16_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 += 16 / 8;
		}
	}
}
//LOADS
void handlerCommand32Code00ADP67() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 -= 32 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_16 != 0) {
				reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_16);
				reg_SI_16 += 32 / 8;
				reg_CX_16 -= 1;
			}
		} else {
			reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_16);
			reg_SI_16 += 32 / 8;
		}
	}
}
//LOADS
void handlerCommand32Code00AD() {
	LOG("%s","LOADS");
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 -= 32 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix != 0) {
			while (reg_CX_32 != 0) {
				reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_32);
				reg_SI_32 += 32 / 8;
				reg_CX_32 -= 1;
			}
		} else {
			reg_0x00_32u = *(uint32_t*)(sourceSegment + reg_SI_32);
			reg_SI_32 += 32 / 8;
		}
	}
}
//SCAS
void handlerCommand32Code00AEP66P67() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 += 8 / 8;
		}
	}
}
//SCAS
void handlerCommand32Code00AEP66() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 += 8 / 8;
		}
	}
}
//SCAS
void handlerCommand32Code00AEP67() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 -= 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_16) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP8;
				reg_DI_16 += 8 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP8;
			reg_DI_16 += 8 / 8;
		}
	}
}
//SCAS
void handlerCommand32Code00AE() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 -= 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 -= 8 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) == reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint8_t*)(targetSegment + reg_DI_32) != reg_0x00_8u;
				LazyFlagVarA8 = reg_0x00_8u;
				LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP8;
				reg_DI_32 += 8 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA8 = reg_0x00_8u;
			LazyFlagVarB8 = *(uint8_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer8 = reg_0x00_8u - *(uint8_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP8;
			reg_DI_32 += 8 / 8;
		}
	}
}
//SCAS
void handlerCommand32Code00AFP66P67() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) == reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 -= 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) != reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 -= 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = reg_0x00_16u;
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP16;
			reg_DI_16 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) == reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 += 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_16) != reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP16;
				reg_DI_16 += 16 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = reg_0x00_16u;
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP16;
			reg_DI_16 += 16 / 8;
		}
	}
}
//SCAS
void handlerCommand32Code00AFP66() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) == reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 -= 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) != reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 -= 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = reg_0x00_16u;
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP16;
			reg_DI_32 -= 16 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) == reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 += 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint16_t*)(targetSegment + reg_DI_32) != reg_0x00_16u;
				LazyFlagVarA16 = reg_0x00_16u;
				LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP16;
				reg_DI_32 += 16 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA16 = reg_0x00_16u;
			LazyFlagVarB16 = *(uint16_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer16 = reg_0x00_16u - *(uint16_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP16;
			reg_DI_32 += 16 / 8;
		}
	}
}
//SCAS
void handlerCommand32Code00AFP67() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) == reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 -= 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) != reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 -= 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = reg_0x00_32u;
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP32;
			reg_DI_16 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) == reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 += 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_16 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_16) != reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_16);
				lazyFlagType = t_CMP32;
				reg_DI_16 += 32 / 8;
				reg_CX_16 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = reg_0x00_32u;
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_16);
			LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_16);
			lazyFlagType = t_CMP32;
			reg_DI_16 += 32 / 8;
		}
	}
}
//SCAS
void handlerCommand32Code00AF() {
	LOG("%s","SCAS");
	lazyFlagType = t_UNKNOWN;
	uint8_t* sourceSegment = context.lastCommandInfo.prefixInfo.changeSegmentPrefix;
	sourceSegment = ((sourceSegment == NULL) ? mem(SR_DS) : sourceSegment);
	uint8_t* targetSegment = mem(SR_ES);
	if (GET_FLAG(DF)) {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) == reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 -= 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) != reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 -= 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = reg_0x00_32u;
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP32;
			reg_DI_32 -= 32 / 8;
		}
	} else {
		if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF2) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) == reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 += 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 == 1));  return; }
			}
		} else if (context.lastCommandInfo.prefixInfo.commandPrefix == 0xF3) {
			while (reg_CX_32 != 0) {
				uint8_t result = *(uint32_t*)(targetSegment + reg_DI_32) != reg_0x00_32u;
				LazyFlagVarA32 = reg_0x00_32u;
				LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
				LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_32);
				lazyFlagType = t_CMP32;
				reg_DI_32 += 32 / 8;
				reg_CX_32 -= 1;
				if (result) { SET_FLAG(ZF, (1 != 1));  return; }
			}
		} else {
			LazyFlagVarA32 = reg_0x00_32u;
			LazyFlagVarB32 = *(uint32_t*)(targetSegment + reg_DI_32);
			LazyFlagResultContainer32 = reg_0x00_32u - *(uint32_t*)(targetSegment + reg_DI_32);
			lazyFlagType = t_CMP32;
			reg_DI_32 += 32 / 8;
		}
	}
}
//Move
void handlerCommand32Code00B0P66() {
	LOG("%s","Move");
	reg_0x00_8u = read8u();
}
//Move
void handlerCommand32Code00B0() {
	LOG("%s","Move");
	reg_0x00_8u = read8u();
}
//Move
void handlerCommand32Code00B1P66() {
	LOG("%s","Move");
	reg_0x01_8u = read8u();
}
//Move
void handlerCommand32Code00B1() {
	LOG("%s","Move");
	reg_0x01_8u = read8u();
}
//Move
void handlerCommand32Code00B2P66() {
	LOG("%s","Move");
	reg_0x02_8u = read8u();
}
//Move
void handlerCommand32Code00B2() {
	LOG("%s","Move");
	reg_0x02_8u = read8u();
}
//Move
void handlerCommand32Code00B3P66() {
	LOG("%s","Move");
	reg_0x03_8u = read8u();
}
//Move
void handlerCommand32Code00B3() {
	LOG("%s","Move");
	reg_0x03_8u = read8u();
}
//Move
void handlerCommand32Code00B4P66() {
	LOG("%s","Move");
	reg_0x04_8u = read8u();
}
//Move
void handlerCommand32Code00B4() {
	LOG("%s","Move");
	reg_0x04_8u = read8u();
}
//Move
void handlerCommand32Code00B5P66() {
	LOG("%s","Move");
	reg_0x05_8u = read8u();
}
//Move
void handlerCommand32Code00B5() {
	LOG("%s","Move");
	reg_0x05_8u = read8u();
}
//Move
void handlerCommand32Code00B6P66() {
	LOG("%s","Move");
	reg_0x06_8u = read8u();
}
//Move
void handlerCommand32Code00B6() {
	LOG("%s","Move");
	reg_0x06_8u = read8u();
}
//Move
void handlerCommand32Code00B7P66() {
	LOG("%s","Move");
	reg_0x07_8u = read8u();
}
//Move
void handlerCommand32Code00B7() {
	LOG("%s","Move");
	reg_0x07_8u = read8u();
}
//Move
void handlerCommand32Code00B8P66() {
	LOG("%s","Move");
	reg_0x00_16u = read16u();
}
//Move
void handlerCommand32Code00B8() {
	LOG("%s","Move");
	reg_0x00_32u = read32u();
}
//Move
void handlerCommand32Code00B9P66() {
	LOG("%s","Move");
	reg_0x01_16u = read16u();
}
//Move
void handlerCommand32Code00B9() {
	LOG("%s","Move");
	reg_0x01_32u = read32u();
}
//Move
void handlerCommand32Code00BAP66() {
	LOG("%s","Move");
	reg_0x02_16u = read16u();
}
//Move
void handlerCommand32Code00BA() {
	LOG("%s","Move");
	reg_0x02_32u = read32u();
}
//Move
void handlerCommand32Code00BBP66() {
	LOG("%s","Move");
	reg_0x03_16u = read16u();
}
//Move
void handlerCommand32Code00BB() {
	LOG("%s","Move");
	reg_0x03_32u = read32u();
}
//Move
void handlerCommand32Code00BCP66() {
	LOG("%s","Move");
	reg_0x04_16u = read16u();
}
//Move
void handlerCommand32Code00BC() {
	LOG("%s","Move");
	reg_0x04_32u = read32u();
}
//Move
void handlerCommand32Code00BDP66() {
	LOG("%s","Move");
	reg_0x05_16u = read16u();
}
//Move
void handlerCommand32Code00BD() {
	LOG("%s","Move");
	reg_0x05_32u = read32u();
}
//Move
void handlerCommand32Code00BEP66() {
	LOG("%s","Move");
	reg_0x06_16u = read16u();
}
//Move
void handlerCommand32Code00BE() {
	LOG("%s","Move");
	reg_0x06_32u = read32u();
}
//Move
void handlerCommand32Code00BFP66() {
	LOG("%s","Move");
	reg_0x07_16u = read16u();
}
//Move
void handlerCommand32Code00BF() {
	LOG("%s","Move");
	reg_0x07_32u = read32u();
}
//Move bits
void handlerCommand32Code00C0P66() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (8 / 8))), 0, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(uint8_t*)target) % 2);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(int8_t*)target) < 0);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp + (8 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			(*(uint8_t*)target) = (*(uint8_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			(*(uint8_t*)target) = (*(uint8_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			uint64_t tmp = ((*(int8_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint8_t*)(((uint8_t*)&tmp) + 4) = (*(uint8_t*)target);
			tmp = tmp >> value;
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand32Code00C0() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (8 / 8))), 0, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(uint8_t*)target) % 2);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(int8_t*)target) < 0);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp + (8 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			(*(uint8_t*)target) = (*(uint8_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			(*(uint8_t*)target) = (*(uint8_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = read8u();
			uint64_t tmp = ((*(int8_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint8_t*)(((uint8_t*)&tmp) + 4) = (*(uint8_t*)target);
			tmp = tmp >> value;
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand32Code00C1P66() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = read8u();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp << (value % 16);
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = read8u();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp >> (value % 16);
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (16 / 8))), 0, GET_FLAG(CF));
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			SET_FLAG(CF, (*(uint16_t*)target) % 2);
			tmp = tmp << (value % 16);
			(*(uint16_t*)target) = *(uint16_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			SET_FLAG(CF, (*(int16_t*)target) < 0);
			tmp = tmp >> (value % 16);
			(*(uint16_t*)target) = *(uint16_t*)((uint8_t*)&tmp + (16 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = read8u();
			(*(uint16_t*)target) = (*(uint16_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = read8u();
			(*(uint16_t*)target) = (*(uint16_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = read8u();
			uint64_t tmp = ((*(int16_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint16_t*)(((uint8_t*)&tmp) + 4) = (*(uint16_t*)target);
			tmp = tmp >> value;
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand32Code00C1() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = read8u();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp << (value % 32);
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = read8u();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp >> (value % 32);
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (32 / 8))), 0, GET_FLAG(CF));
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			SET_FLAG(CF, (*(uint32_t*)target) % 2);
			tmp = tmp << (value % 32);
			(*(uint32_t*)target) = *(uint32_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = read8u();
			FillFlags();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			SET_FLAG(CF, (*(int32_t*)target) < 0);
			tmp = tmp >> (value % 32);
			(*(uint32_t*)target) = *(uint32_t*)((uint8_t*)&tmp + (32 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = read8u();
			(*(uint32_t*)target) = (*(uint32_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = read8u();
			(*(uint32_t*)target) = (*(uint32_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = read8u();
			uint64_t tmp = ((*(int32_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint32_t*)(((uint8_t*)&tmp) + 4) = (*(uint32_t*)target);
			tmp = tmp >> value;
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Ret
void handlerCommand32Code00C3() {
	LOG("%s","Ret");
	uint32_t* sp = register32u(BR_SP);
	context.index = mem(1) + *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8;
}
//Load SR_ES
void handlerCommand32Code00C4() {
	LOG("%s","Load SR_ES");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	setMem(SR_ES, *(uint16_t*)(target + 2));
	*(uint32_t*)source = *(uint32_t*)(target);
}
//Load SR_DS
void handlerCommand32Code00C5() {
	LOG("%s","Load SR_DS");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	setMem(SR_DS, *(uint16_t*)(target + 2));
	*(uint32_t*)source = *(uint32_t*)(target);
}
//Move
void handlerCommand32Code00C6P66() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	*(uint8_t*)target = read8u();
}
//Move
void handlerCommand32Code00C6() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	*(uint8_t*)target = read8u();
}
//Move
void handlerCommand32Code00C7P66() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	*(uint16_t*)target = read16u();
}
//Move
void handlerCommand32Code00C7() {
	LOG("%s","Move");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	*(uint32_t*)target = read32u();
}
//Enter
void handlerCommand32Code00C8P66P67() {
	LOG("%s","Enter");
	uint16_t size = read16u();
	uint8_t levels = read8u() % 32;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_BP_16u;
	uint16_t tmp = reg_SP_16u;
	if (levels > 0) {
		for (int i = 1; i < levels; ++i) {
			reg_BP_16u = reg_BP_16u - 16 / 8;
			reg_SP_16u -= 16 / 8;
			*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_BP_16u;
		}
		reg_SP_16u -= 16 / 8;
		*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_SP_16u;
	}
	reg_BP_16u = tmp;
	reg_SP_16u = reg_BP_16u - size;
}
//Enter
void handlerCommand32Code00C8P67() {
	LOG("%s","Enter");
	uint16_t size = read16u();
	uint8_t levels = read8u() % 32;
	reg_SP_16u -= 16 / 8;
	*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_BP_16u;
	uint16_t tmp = reg_SP_16u;
	if (levels > 0) {
		for (int i = 1; i < levels; ++i) {
			reg_BP_16u = reg_BP_16u - 32 / 8;
			reg_SP_16u -= 16 / 8;
			*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_BP_16u;
		}
		reg_SP_16u -= 16 / 8;
		*(uint16_t*)(mem(SR_SS) + reg_SP_16u) = reg_SP_16u;
	}
	reg_BP_16u = tmp;
	reg_SP_16u = reg_BP_16u - size;
}
//Enter
void handlerCommand32Code00C8P66() {
	LOG("%s","Enter");
	uint16_t size = read16u();
	uint8_t levels = read8u() % 32;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_BP_32u;
	uint32_t tmp = reg_SP_32u;
	if (levels > 0) {
		for (int i = 1; i < levels; ++i) {
			reg_BP_32u = reg_BP_32u - 16 / 8;
			reg_SP_32u -= 32 / 8;
			*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_BP_32u;
		}
		reg_SP_32u -= 32 / 8;
		*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_SP_32u;
	}
	reg_BP_32u = tmp;
	reg_SP_32u = reg_BP_32u - size;
}
//Enter
void handlerCommand32Code00C8() {
	LOG("%s","Enter");
	uint16_t size = read16u();
	uint8_t levels = read8u() % 32;
	reg_SP_32u -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_BP_32u;
	uint32_t tmp = reg_SP_32u;
	if (levels > 0) {
		for (int i = 1; i < levels; ++i) {
			reg_BP_32u = reg_BP_32u - 32 / 8;
			reg_SP_32u -= 32 / 8;
			*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_BP_32u;
		}
		reg_SP_32u -= 32 / 8;
		*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = reg_SP_32u;
	}
	reg_BP_32u = tmp;
	reg_SP_32u = reg_BP_32u - size;
}
//Leave
void handlerCommand32Code00C9P66P67() {
	LOG("%s","Leave");
	reg_SP_16u = reg_BP_16u;
	reg_BP_16u = *(uint16_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 16 / 8;
}
//Leave
void handlerCommand32Code00C9P67() {
	LOG("%s","Leave");
	reg_SP_16u = reg_BP_16u;
	reg_BP_16u = *(uint32_t*)(mem(SR_SS) + reg_SP_16u);
	reg_SP_16u += 32 / 8;
}
//Leave
void handlerCommand32Code00C9P66() {
	LOG("%s","Leave");
	reg_SP_32u = reg_BP_32u;
	reg_BP_32u = *(uint16_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 16 / 8;
}
//Leave
void handlerCommand32Code00C9() {
	LOG("%s","Leave");
	reg_SP_32u = reg_BP_32u;
	reg_BP_32u = *(uint32_t*)(mem(SR_SS) + reg_SP_32u);
	reg_SP_32u += 32 / 8;
}
//Ret
void handlerCommand32Code00CB() {
	LOG("%s","Ret");
	uint32_t* sp = register32u(BR_SP);
	setMem(1, *(int16_t*)(mem(SR_SS) + *sp + 32 / 8));
	context.index = mem(1) + *(uint32_t*)(mem(SR_SS) + *sp);
	*sp += 32 / 8 + 2;
}
//Int
void handlerCommand32Code00CD() {
	LOG("%s","Int");
	uint8_t addr = read8u();
	context.functions[addr](addr);
}
//Move bits
void handlerCommand32Code00D0P66() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (8 / 8))), 0, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(uint8_t*)target) % 2);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(int8_t*)target) < 0);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp + (8 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			(*(uint8_t*)target) = (*(uint8_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			(*(uint8_t*)target) = (*(uint8_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			uint64_t tmp = ((*(int8_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint8_t*)(((uint8_t*)&tmp) + 4) = (*(uint8_t*)target);
			tmp = tmp >> value;
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand32Code00D0() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (8 / 8))), 0, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(uint8_t*)target) % 2);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(int8_t*)target) < 0);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp + (8 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			(*(uint8_t*)target) = (*(uint8_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			(*(uint8_t*)target) = (*(uint8_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = 1;
			uint64_t tmp = ((*(int8_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint8_t*)(((uint8_t*)&tmp) + 4) = (*(uint8_t*)target);
			tmp = tmp >> value;
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand32Code00D1P66() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = 1;
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp << (value % 16);
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = 1;
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp >> (value % 16);
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (16 / 8))), 0, GET_FLAG(CF));
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			SET_FLAG(CF, (*(uint16_t*)target) % 2);
			tmp = tmp << (value % 16);
			(*(uint16_t*)target) = *(uint16_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			SET_FLAG(CF, (*(int16_t*)target) < 0);
			tmp = tmp >> (value % 16);
			(*(uint16_t*)target) = *(uint16_t*)((uint8_t*)&tmp + (16 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = 1;
			(*(uint16_t*)target) = (*(uint16_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = 1;
			(*(uint16_t*)target) = (*(uint16_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = 1;
			uint64_t tmp = ((*(int16_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint16_t*)(((uint8_t*)&tmp) + 4) = (*(uint16_t*)target);
			tmp = tmp >> value;
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand32Code00D1() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = 1;
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp << (value % 32);
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = 1;
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp >> (value % 32);
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (32 / 8))), 0, GET_FLAG(CF));
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			SET_FLAG(CF, (*(uint32_t*)target) % 2);
			tmp = tmp << (value % 32);
			(*(uint32_t*)target) = *(uint32_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = 1;
			FillFlags();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			SET_FLAG(CF, (*(int32_t*)target) < 0);
			tmp = tmp >> (value % 32);
			(*(uint32_t*)target) = *(uint32_t*)((uint8_t*)&tmp + (32 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = 1;
			(*(uint32_t*)target) = (*(uint32_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = 1;
			(*(uint32_t*)target) = (*(uint32_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = 1;
			uint64_t tmp = ((*(int32_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint32_t*)(((uint8_t*)&tmp) + 4) = (*(uint32_t*)target);
			tmp = tmp >> value;
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand32Code00D2P66() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (8 / 8))), 0, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(uint8_t*)target) % 2);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(int8_t*)target) < 0);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp + (8 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint8_t*)target) = (*(uint8_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint8_t*)target) = (*(uint8_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			uint64_t tmp = ((*(int8_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint8_t*)(((uint8_t*)&tmp) + 4) = (*(uint8_t*)target);
			tmp = tmp >> value;
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand32Code00D2() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (8 / 8))), 0, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(uint8_t*)target) % 2);
			tmp = tmp << (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint16_t tmp = 0;
			*(uint8_t*)(((uint8_t*)&tmp)) = (*(uint8_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint8_t*)(((uint8_t*)&tmp) + (8 / 8)) = (*(uint8_t*)target);
			SET_FLAG(CF, (*(int8_t*)target) < 0);
			tmp = tmp >> (value % 8);
			(*(uint8_t*)target) = *(uint8_t*)((uint8_t*)&tmp + (8 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint8_t*)target) = (*(uint8_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint8_t*)target) = (*(uint8_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t value = reg_CL_8u;
			uint64_t tmp = ((*(int8_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint8_t*)(((uint8_t*)&tmp) + 4) = (*(uint8_t*)target);
			tmp = tmp >> value;
			(*(uint8_t*)target) = (*(uint8_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand32Code00D3P66() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = reg_CL_8u;
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp << (value % 16);
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = reg_CL_8u;
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp >> (value % 16);
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (16 / 8))), 0, GET_FLAG(CF));
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			SET_FLAG(CF, (*(uint16_t*)target) % 2);
			tmp = tmp << (value % 16);
			(*(uint16_t*)target) = *(uint16_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint32_t tmp = 0;
			*(uint16_t*)(((uint8_t*)&tmp)) = (*(uint16_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint16_t*)(((uint8_t*)&tmp) + (16 / 8)) = (*(uint16_t*)target);
			SET_FLAG(CF, (*(int16_t*)target) < 0);
			tmp = tmp >> (value % 16);
			(*(uint16_t*)target) = *(uint16_t*)((uint8_t*)&tmp + (16 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint16_t*)target) = (*(uint16_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint16_t*)target) = (*(uint16_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint8_t value = reg_CL_8u;
			uint64_t tmp = ((*(int16_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint16_t*)(((uint8_t*)&tmp) + 4) = (*(uint16_t*)target);
			tmp = tmp >> value;
			(*(uint16_t*)target) = (*(uint16_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Move bits
void handlerCommand32Code00D3() {
	LOG("%s","Move bits");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = reg_CL_8u;
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp << (value % 32);
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp)));
		}
		break;
		case 1: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = reg_CL_8u;
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp >> (value % 32);
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp + 4)));
		}
		break;
		case 2: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			tmp = tmp >> 1;
			SET_BIT((*(((uint8_t*)&tmp) + (32 / 8))), 0, GET_FLAG(CF));
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			SET_FLAG(CF, (*(uint32_t*)target) % 2);
			tmp = tmp << (value % 32);
			(*(uint32_t*)target) = *(uint32_t*)((uint8_t*)&tmp);
		}
		break;
		case 3: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = reg_CL_8u;
			FillFlags();
			uint64_t tmp = 0;
			*(uint32_t*)(((uint8_t*)&tmp)) = (*(uint32_t*)target);
			tmp = tmp << 1;
			SET_BIT((*(((uint8_t*)&tmp))), 7, GET_FLAG(CF));
			*(uint32_t*)(((uint8_t*)&tmp) + (32 / 8)) = (*(uint32_t*)target);
			SET_FLAG(CF, (*(int32_t*)target) < 0);
			tmp = tmp >> (value % 32);
			(*(uint32_t*)target) = *(uint32_t*)((uint8_t*)&tmp + (32 / 8));
		}
		break;
		case 4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint32_t*)target) = (*(uint32_t*)target) << value;
		}
		break;
		case 5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = reg_CL_8u;
			(*(uint32_t*)target) = (*(uint32_t*)target) >> value;
		}
		break;
		case 7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t value = reg_CL_8u;
			uint64_t tmp = ((*(int32_t*)target) < 0) ? 0xFFFFFFFFFFFFFFFF : 0;
			*(uint32_t*)(((uint8_t*)&tmp) + 4) = (*(uint32_t*)target);
			tmp = tmp >> value;
			(*(uint32_t*)target) = (*(uint32_t*)(((uint8_t*)&tmp) + 4));
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand32Code00D8() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 000, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			} else {
				// OPA 000, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM32For8(mrmByte);
				float* source = valueB;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 000, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			} else {
				// OPA 000, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM32For8(mrmByte);
				float* source = valueB;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 000, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			} else {
				// OPA 000, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM32For8(mrmByte);
				float* source = valueB;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 000, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			} else {
				// OPA 000, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM32For8(mrmByte);
				float* source = valueB;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 000, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			} else {
				// OPA 000, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM32For8(mrmByte);
				float* source = valueB;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 000, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			} else {
				// OPA 000, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM32For8(mrmByte);
				float* source = valueB;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand32Code00D9() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 001, OPB 000
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* source = valueB;
				*target = *source;
			} else {
				// OPA 001, OPB 000
				// FPU Move
				fpuStackIndex -= 1;
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				float* valueB = (float*)readAddressMRM32For8(mrmByte);
				float* source = valueB;
				*target = *source;
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 001, OPB 010
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				float* valueB = (float*)readAddressMRM32For8(mrmByte);
				float* target = valueB;
				*target = *source;
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 001, OPB 011
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				float* valueB = (float*)readAddressMRM32For8(mrmByte);
				float* target = valueB;
				fpuStackIndex += 1;
				*target = *source;
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				fpuRegControll = *(uint16_t*)readAddressMRM32For16(mrmByte);
			} else {
				fpuRegControll = *(uint16_t*)readAddressMRM32For16(mrmByte);
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				*(uint16_t*)readAddressMRM32For16(mrmByte) = fpuRegControll;
			} else {
				*(uint16_t*)readAddressMRM32For16(mrmByte) = fpuRegControll;
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand32Code00DA() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 010, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM32For8(mrmByte);
				int32_t* source = valueB;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 010, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM32For8(mrmByte);
				int32_t* source = valueB;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 010, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM32For8(mrmByte);
				int32_t* source = valueB;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 010, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM32For8(mrmByte);
				int32_t* source = valueB;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 010, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM32For8(mrmByte);
				int32_t* source = valueB;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 010, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM32For8(mrmByte);
				int32_t* source = valueB;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand32Code00DB() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 011, OPB 000
				// FPU Move
				fpuStackIndex -= 1;
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM32For8(mrmByte);
				int32_t* source = valueB;
				*target = *source;
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 011, OPB 010
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM32For8(mrmByte);
				int32_t* target = valueB;
				*target = *source;
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 011, OPB 011
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				int32_t* valueB = (int32_t*)readAddressMRM32For8(mrmByte);
				int32_t* target = valueB;
				fpuStackIndex += 1;
				*target = *source;
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				fpuStackIndex = 7;
				fpuRegControll = 0x37F;
				fpuRegStatus = 0;
				fpuRegTag = 0xFFFF;
				fpuRegPointer = 0;
				fpuRegInstructionPointer = 0;
				fpuRegInstructionOpcode = 0;
			} else {
				fpuStackIndex = 7;
				fpuRegControll = 0x37F;
				fpuRegStatus = 0;
				fpuRegTag = 0xFFFF;
				fpuRegPointer = 0;
				fpuRegInstructionPointer = 0;
				fpuRegInstructionOpcode = 0;
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				*(uint16_t*)readAddressMRM32For16(mrmByte) = fpuRegControll;
			} else {
				*(uint16_t*)readAddressMRM32For16(mrmByte) = fpuRegControll;
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand32Code00DC() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 100, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			} else {
				// OPA 100, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM32For8(mrmByte);
				double* source = valueB;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 100, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			} else {
				// OPA 100, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM32For8(mrmByte);
				double* source = valueB;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 100, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			} else {
				// OPA 100, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM32For8(mrmByte);
				double* source = valueB;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 100, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			} else {
				// OPA 100, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM32For8(mrmByte);
				double* source = valueB;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 100, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			} else {
				// OPA 100, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM32For8(mrmByte);
				double* source = valueB;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 100, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			} else {
				// OPA 100, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM32For8(mrmByte);
				double* source = valueB;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand32Code00DD() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 101, OPB 000
				// FPU Move
				fpuStackIndex -= 1;
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				double* valueB = (double*)readAddressMRM32For8(mrmByte);
				double* source = valueB;
				*target = *source;
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 101, OPB 010
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = (double*)readAddressMRM32For8(mrmByte);
				double* target = valueB;
				*target = *source;
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 101, OPB 011
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = (double*)readAddressMRM32For8(mrmByte);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = *source;
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				*(uint16_t*)readAddressMRM16For16(mrmByte) = fpuRegStatus;
			} else {
				*(uint16_t*)readAddressMRM16For16(mrmByte) = fpuRegStatus;
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand32Code00DE() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 110, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			} else {
				// OPA 110, OPB 000
				// FPU Add
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM32For8(mrmByte);
				int16_t* source = valueB;
				*target = (double)(((double)*valueA) + ((double)*valueB));
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 110, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			} else {
				// OPA 110, OPB 001
				// FPU Mul
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM32For8(mrmByte);
				int16_t* source = valueB;
				*target = (double)(((double)*valueA) * ((double)*valueB));
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 110, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			} else {
				// OPA 110, OPB 100
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM32For8(mrmByte);
				int16_t* source = valueB;
				*target = (double)(((double)*valueA) - ((double)*valueB));
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 110, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			} else {
				// OPA 110, OPB 101
				// FPU Sub
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM32For8(mrmByte);
				int16_t* source = valueB;
				*target = (double)(((double)*valueB) + ((double)*valueA));
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 110, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			} else {
				// OPA 110, OPB 110
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM32For8(mrmByte);
				int16_t* source = valueB;
				*target = (double)(((double)*valueA) / ((double)*valueB));
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				// OPA 110, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);
				double* target = valueB;
				fpuStackIndex += 1;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			} else {
				// OPA 110, OPB 111
				// FPU Div
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM32For8(mrmByte);
				int16_t* source = valueB;
				*target = (double)(((double)*valueB) / ((double)*valueA));
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//FPU
void handlerCommand32Code00DF() {
	LOG("%s","FPU");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 111, OPB 000
				// FPU Move
				fpuStackIndex -= 1;
				double* valueA = fpuStack + fpuStackIndex;
				double* target = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM32For8(mrmByte);
				int16_t* source = valueB;
				*target = *source;
			}
		}
		break;
		case 0x01: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x02: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 111, OPB 010
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM32For8(mrmByte);
				int16_t* target = valueB;
				*target = *source;
			}
		}
		break;
		case 0x03: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// OPA 111, OPB 011
				// FPU Move
				double* valueA = fpuStack + fpuStackIndex;
				double* source = valueA;
				int16_t* valueB = (int16_t*)readAddressMRM32For8(mrmByte);
				int16_t* target = valueB;
				fpuStackIndex += 1;
				*target = *source;
			}
		}
		break;
		case 0x04: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x05: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x06: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		case 0x07: {
			if ((mrmByte >> 6 & 3) == 3) {
				// NON FUNCTION
				mCommandFunctionEmpty();
			} else {
				// NON FUNCTION
				mCommandFunctionEmpty();
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Loop
void handlerCommand32Code00E0() {
	LOG("%s","Loop");
	int8_t addr = read8();
	reg_0x01_32 -= 1;
	FillFlags();
	if (reg_0x01_32 != 0 && GET_FLAG(ZF) == 0) {
		context.index += addr;
	}
}
//Loop
void handlerCommand32Code00E1() {
	LOG("%s","Loop");
	int8_t addr = read8();
	reg_0x01_32 -= 1;
	FillFlags();
	if (reg_0x01_32 != 0 && GET_FLAG(ZF) == 1) {
		context.index += addr;
	}
}
//Loop
void handlerCommand32Code00E2() {
	LOG("%s","Loop");
	int8_t addr = read8();
	reg_0x01_32 -= 1;
	if (reg_0x01_32 != 0) {
		context.index += addr;
	}
}
//Loop
void handlerCommand32Code00E3() {
	LOG("%s","Loop");
	int8_t addr = read8();
	if (reg_0x01_32 == 0) {
		context.index += addr;
	}
}
//Call
void handlerCommand32Code00E8P66() {
	LOG("%s","Call");
	uint32_t* sp = register32u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = (uint32_t)(context.index + 16 / 8 - mem(1));
	context.index += read16();
}
//Call
void handlerCommand32Code00E8() {
	LOG("%s","Call");
	uint32_t* sp = register32u(BR_SP);
	*sp -= 32 / 8;
	*(uint32_t*)(mem(SR_SS) + *sp) = (uint32_t)(context.index + 32 / 8 - mem(1));
	context.index += read32();
}
//Jmp
void handlerCommand32Code00E9P66() {
	LOG("%s","Jmp");
	context.index += read16();
}
//Jmp
void handlerCommand32Code00E9() {
	LOG("%s","Jmp");
	context.index += read32();
}
//Jmp
void handlerCommand32Code00EB() {
	LOG("%s","Jmp");
	context.index += read8();
}
//~CF
void handlerCommand32Code00F5() {
	LOG("%s","~CF");
	SET_FLAG(CF, !GET_FLAG(CF));
}
//Math
void handlerCommand32Code00F6P66() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// TEST
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 & ((uint8_t)LazyFlagVarB8);
			lazyFlagType = t_TEST8;
		}
		break;
		case 0x02: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// NOT
			*(int8_t*)target = ~(*(int8_t*)target);
		}
		break;
		case 0x03: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// NEG
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagResultContainer8 = 0 - LazyFlagVarA8;
			*(int8_t*)target = LazyFlagResultContainer8;
			lazyFlagType = t_NEG8;
		}
		break;
		case 0x04: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			reg_AX_16=((uint16_t)reg_AL_8)*((uint16_t)(*(uint8_t*)target));
			FillFlagsNoCFOF();
			SET_FLAG(ZF,reg_AL_8 == 0);
			SET_FLAG(PF,PARITY16(reg_AX_16));
			if (reg_AX_16 & 0xff00) {
				SET_FLAG(CF,1);SET_FLAG(OF,1);
			} else {
				SET_FLAG(CF,0);SET_FLAG(OF,0);
			}
		}
		break;
		case 0x05: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			reg_AX_16 = reg_AL_8 * (*((int8_t*)target));
			FillFlagsNoCFOF();
			SET_FLAG(ZF, reg_AX_16 == 0);
			SET_FLAG(SF, reg_AL_8 & 0x80);
			if ((reg_AX_16 & 0xff80)==0xff80 || (reg_AX_16 & 0xff80)==0x0000) {
				SET_FLAG(CF,0);SET_FLAG(OF,0);
			} else {
				SET_FLAG(CF,1);SET_FLAG(OF,1);
			}
		}
		break;
		case 0x06: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t val= *(uint8_t*)(target);
			uint16_t quo=reg_AX_16 / val;
			uint8_t rem=(uint8_t)(reg_AX_16 % val);
			uint8_t quo8=(uint8_t)(quo&0xff);
			reg_AH_8=rem;
			reg_AL_8=quo8;
			FillFlags();
			SET_FLAG(ZF,(rem==0)&&((quo8&1)!=0));
			SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
			SET_FLAG(PF,parity_lookup[rem&0xff]^parity_lookup[quo8&0xff]^GET_FLAG(PF));
		}
		break;
		case 0x07: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
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
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code00F6() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// TEST
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagVarB8 = read8();
			LazyFlagResultContainer8 = LazyFlagVarA8 & ((uint8_t)LazyFlagVarB8);
			lazyFlagType = t_TEST8;
		}
		break;
		case 0x02: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// NOT
			*(int8_t*)target = ~(*(int8_t*)target);
		}
		break;
		case 0x03: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// NEG
			LazyFlagVarA8 = *(int8_t*)target;
			LazyFlagResultContainer8 = 0 - LazyFlagVarA8;
			*(int8_t*)target = LazyFlagResultContainer8;
			lazyFlagType = t_NEG8;
		}
		break;
		case 0x04: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			reg_AX_16=((uint16_t)reg_AL_8)*((uint16_t)(*(uint8_t*)target));
			FillFlagsNoCFOF();
			SET_FLAG(ZF,reg_AL_8 == 0);
			SET_FLAG(PF,PARITY16(reg_AX_16));
			if (reg_AX_16 & 0xff00) {
				SET_FLAG(CF,1);SET_FLAG(OF,1);
			} else {
				SET_FLAG(CF,0);SET_FLAG(OF,0);
			}
		}
		break;
		case 0x05: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			reg_AX_16 = reg_AL_8 * (*((int8_t*)target));
			FillFlagsNoCFOF();
			SET_FLAG(ZF, reg_AX_16 == 0);
			SET_FLAG(SF, reg_AL_8 & 0x80);
			if ((reg_AX_16 & 0xff80)==0xff80 || (reg_AX_16 & 0xff80)==0x0000) {
				SET_FLAG(CF,0);SET_FLAG(OF,0);
			} else {
				SET_FLAG(CF,1);SET_FLAG(OF,1);
			}
		}
		break;
		case 0x06: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			uint8_t val= *(uint8_t*)(target);
			uint16_t quo=reg_AX_16 / val;
			uint8_t rem=(uint8_t)(reg_AX_16 % val);
			uint8_t quo8=(uint8_t)(quo&0xff);
			reg_AH_8=rem;
			reg_AL_8=quo8;
			FillFlags();
			SET_FLAG(ZF,(rem==0)&&((quo8&1)!=0));
			SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
			SET_FLAG(PF,parity_lookup[rem&0xff]^parity_lookup[quo8&0xff]^GET_FLAG(PF));
		}
		break;
		case 0x07: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
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
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code00F7P66() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			// TEST
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagVarB16 = read16();
			LazyFlagResultContainer16 = LazyFlagVarA16 & ((uint16_t)LazyFlagVarB16);
			lazyFlagType = t_TEST16;
		}
		break;
		case 0x02: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			// NOT
			*(int16_t*)target = ~(*(int16_t*)target);
		}
		break;
		case 0x03: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			// NEG
			LazyFlagVarA16 = *(int16_t*)target;
			LazyFlagResultContainer16 = 0 - LazyFlagVarA16;
			*(int16_t*)target = LazyFlagResultContainer16;
			lazyFlagType = t_NEG16;
		}
		break;
		case 0x04: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint32_t tempu=(uint32_t)reg_AX_16*(uint32_t)(*(uint16_t*)(target));
			reg_AX_16=(uint16_t)(tempu);
			reg_DX_16=(uint16_t)(tempu >> 16);
			FillFlagsNoCFOF();
			SET_FLAG(ZF,reg_AX_16 == 0);
			SET_FLAG(PF,PARITY16(reg_AX_16)^PARITY16(reg_DX_16)^GET_FLAG(PF));
			if (reg_DX_16) {
				SET_FLAG(CF,1);SET_FLAG(OF,1);
			} else {
				SET_FLAG(CF,0);SET_FLAG(OF,0);
			}
		}
		break;
		case 0x05: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
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
		}
		break;
		case 0x06: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			uint16_t val= *(uint16_t*)(target);
			uint32_t num=((uint32_t)reg_DX_16<<16)|reg_AX_16;
			uint32_t quo=num/val;
			uint16_t rem=(uint16_t)(num % val);
			uint16_t quo16=(uint16_t)(quo&0xffff);
			reg_DX_16=rem;
			reg_AX_16=quo16;
			FillFlags();
			SET_FLAG(ZF,(rem==0)&&((quo16&1)!=0));
			SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
			SET_FLAG(PF,PARITY16(rem&0xffff)^PARITY16(quo16&0xffff)^GET_FLAG(PF));
		}
		break;
		case 0x07: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
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
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code00F7() {
	LOG("%s","Math");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			// TEST
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagVarB32 = read32();
			LazyFlagResultContainer32 = LazyFlagVarA32 & ((uint32_t)LazyFlagVarB32);
			lazyFlagType = t_TEST32;
		}
		break;
		case 0x02: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			// NOT
			*(int32_t*)target = ~(*(int32_t*)target);
		}
		break;
		case 0x03: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			// NEG
			LazyFlagVarA32 = *(int32_t*)target;
			LazyFlagResultContainer32 = 0 - LazyFlagVarA32;
			*(int32_t*)target = LazyFlagResultContainer32;
			lazyFlagType = t_NEG32;
		}
		break;
		case 0x04: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint64_t tempu=(uint64_t)reg_AX_32*(uint64_t)(*(uint32_t*)(target));
			reg_AX_32=(uint32_t)(tempu);
			reg_DX_32=(uint32_t)(tempu >> 32);
			FillFlagsNoCFOF();
			SET_FLAG(ZF,reg_AX_32 == 0);
			SET_FLAG(PF,PARITY32(reg_AX_32)^PARITY32(reg_DX_32)^GET_FLAG(PF));
			if (reg_DX_32) {
				SET_FLAG(CF,1);SET_FLAG(OF,1);
			} else {
				SET_FLAG(CF,0);SET_FLAG(OF,0);
			}
		}
		break;
		case 0x05: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
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
		}
		break;
		case 0x06: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint32_t val= *(uint32_t*)(target);
			uint64_t num=(((uint64_t)reg_DX_32)<<32)|reg_AX_32;
			uint64_t quo=num/val;
			uint32_t rem=(uint32_t)(num % val);
			uint32_t quo32=(uint32_t)(quo&0xffffffff);
			reg_DX_32=rem;
			reg_AX_32=quo32;
			FillFlags();
			SET_FLAG(ZF,(rem==0)&&((quo32&1)!=0));
			SET_FLAG(CF,((rem&3) >= 1 && (rem&3) <= 2));
			SET_FLAG(PF,PARITY32(rem&0xffffffff)^PARITY32(quo32&0xffffffff)^GET_FLAG(PF));
		}
		break;
		case 0x07: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
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
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Flag CF set false
void handlerCommand32Code00F8() {
	LOG("%s","Flag CF set false");
	SET_FLAG(CF, 0);
}
//Flag CF set true
void handlerCommand32Code00F9() {
	LOG("%s","Flag CF set true");
	SET_FLAG(CF, 1);
}
//Flag IF set false
void handlerCommand32Code00FA() {
	LOG("%s","Flag IF set false");
	SET_FLAG(IF, 0);
}
//Flag IF set true
void handlerCommand32Code00FB() {
	LOG("%s","Flag IF set true");
	SET_FLAG(IF, 1);
}
//Flag DF set false
void handlerCommand32Code00FC() {
	LOG("%s","Flag DF set false");
	SET_FLAG(DF, 0);
}
//Flag DF set true
void handlerCommand32Code00FD() {
	LOG("%s","Flag DF set true");
	SET_FLAG(DF, 1);
}
//Ofther
void handlerCommand32Code00FFP66P67() {
	LOG("%s","Ofther");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			// INC
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			(*(uint8_t*)target)++;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_INC8;
		}
		break;
		case 0x01: {
			// DEC
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			(*(uint8_t*)target)--;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_DEC8;
		}
		break;
		case 0x4: {
			// JMP
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			context.index = mem(SR_CS) + (*((uint16_t*)target));
		}
		break;
		case 0x6: {
			// PUSH
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			reg_SP_16u -= 32 / 8;
			*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = *(uint32_t*)target;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Ofther
void handlerCommand32Code00FFP67() {
	LOG("%s","Ofther");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			// INC
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			(*(uint8_t*)target)++;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_INC8;
		}
		break;
		case 0x01: {
			// DEC
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			(*(uint8_t*)target)--;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_DEC8;
		}
		break;
		case 0x4: {
			// JMP
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			context.index = mem(SR_CS) + (*((uint32_t*)target));
		}
		break;
		case 0x6: {
			// PUSH
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			reg_SP_16u -= 32 / 8;
			*(uint32_t*)(mem(SR_SS) + reg_SP_16u) = *(uint32_t*)target;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Ofther
void handlerCommand32Code00FFP66() {
	LOG("%s","Ofther");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			// INC
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			(*(uint8_t*)target)++;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_INC8;
		}
		break;
		case 0x01: {
			// DEC
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			(*(uint8_t*)target)--;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_DEC8;
		}
		break;
		case 0x4: {
			// JMP
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			context.index = mem(SR_CS) + (*((uint16_t*)target));
		}
		break;
		case 0x6: {
			// PUSH
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			reg_SP_32u -= 32 / 8;
			*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = *(uint32_t*)target;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Ofther
void handlerCommand32Code00FF() {
	LOG("%s","Ofther");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			// INC
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			(*(uint8_t*)target)++;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_INC8;
		}
		break;
		case 0x01: {
			// DEC
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			(*(uint8_t*)target)--;
			LazyFlagResultContainer8 = *(uint8_t*)target;
			lazyFlagType = t_DEC8;
		}
		break;
		case 0x4: {
			// JMP
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			context.index = mem(SR_CS) + (*((uint32_t*)target));
		}
		break;
		case 0x6: {
			// PUSH
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			reg_SP_32u -= 32 / 8;
			*(uint32_t*)(mem(SR_SS) + reg_SP_32u) = *(uint32_t*)target;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//???
void handlerCommand32Code0101() {
	LOG("%s","???");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
			*(uint16_t*)target = 0x0011;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//J(cond)
void handlerCommand32Code0180() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x00 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0181() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x01 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0182() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x02 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0183() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x03 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0184() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x04 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0185() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x05 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0186() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x06 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0187() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x07 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0188() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x08 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code0189() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x09 {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code018A() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x0A {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code018B() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x0B {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code018C() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x0C {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code018D() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x0D {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code018E() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x0E {
		context.index += address;
	}
}
//J(cond)
void handlerCommand32Code018F() {
	LOG("%s","J(cond)");
	FillFlags();
	int32_t address = read32();
	if COND0x0F {
		context.index += address;
	}
}
//Math
void handlerCommand32Code0190P66() {
	LOG("%s","Math");
	uint8_t cond = 0x00;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x00 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0190() {
	LOG("%s","Math");
	uint8_t cond = 0x00;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x00 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0191P66() {
	LOG("%s","Math");
	uint8_t cond = 0x01;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x01 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0191() {
	LOG("%s","Math");
	uint8_t cond = 0x01;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x01 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0192P66() {
	LOG("%s","Math");
	uint8_t cond = 0x02;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x02 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0192() {
	LOG("%s","Math");
	uint8_t cond = 0x02;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x02 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0193P66() {
	LOG("%s","Math");
	uint8_t cond = 0x03;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x03 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0193() {
	LOG("%s","Math");
	uint8_t cond = 0x03;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x03 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0194P66() {
	LOG("%s","Math");
	uint8_t cond = 0x04;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x04 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0194() {
	LOG("%s","Math");
	uint8_t cond = 0x04;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x04 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0195P66() {
	LOG("%s","Math");
	uint8_t cond = 0x05;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x05 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0195() {
	LOG("%s","Math");
	uint8_t cond = 0x05;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x05 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0196P66() {
	LOG("%s","Math");
	uint8_t cond = 0x06;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x06 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0196() {
	LOG("%s","Math");
	uint8_t cond = 0x06;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x06 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0197P66() {
	LOG("%s","Math");
	uint8_t cond = 0x07;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x07 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0197() {
	LOG("%s","Math");
	uint8_t cond = 0x07;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x07 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0198P66() {
	LOG("%s","Math");
	uint8_t cond = 0x08;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x08 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0198() {
	LOG("%s","Math");
	uint8_t cond = 0x08;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x08 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0199P66() {
	LOG("%s","Math");
	uint8_t cond = 0x09;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x09 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code0199() {
	LOG("%s","Math");
	uint8_t cond = 0x09;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x09 ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code019AP66() {
	LOG("%s","Math");
	uint8_t cond = 0x0A;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x0A ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code019A() {
	LOG("%s","Math");
	uint8_t cond = 0x0A;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x0A ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code019BP66() {
	LOG("%s","Math");
	uint8_t cond = 0x0B;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x0B ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code019B() {
	LOG("%s","Math");
	uint8_t cond = 0x0B;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x0B ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code019CP66() {
	LOG("%s","Math");
	uint8_t cond = 0x0C;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x0C ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code019C() {
	LOG("%s","Math");
	uint8_t cond = 0x0C;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x0C ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code019DP66() {
	LOG("%s","Math");
	uint8_t cond = 0x0D;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x0D ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code019D() {
	LOG("%s","Math");
	uint8_t cond = 0x0D;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x0D ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code019EP66() {
	LOG("%s","Math");
	uint8_t cond = 0x0E;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x0E ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code019E() {
	LOG("%s","Math");
	uint8_t cond = 0x0E;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x0E ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code019FP66() {
	LOG("%s","Math");
	uint8_t cond = 0x0F;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x0F ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Math
void handlerCommand32Code019F() {
	LOG("%s","Math");
	uint8_t cond = 0x0F;
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x00: {
			uint8_t* target = (uint8_t*)readAddressMRM32For8(mrmByte);
			// SET(cond)
			*target = COND0x0F ? 1 : 0;
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//BT
void handlerCommand32Code01A3P66() {
	LOG("%s","BT");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t shift = *(uint32_t*)source;
	// BT
	FillFlags();
	uint32_t mask = 1 << shift;
	uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
}
//BT
void handlerCommand32Code01A3() {
	LOG("%s","BT");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t shift = *(uint32_t*)source;
	// BT
	FillFlags();
	uint32_t mask = 1 << shift;
	uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
}
//BTS
void handlerCommand32Code01ABP66() {
	LOG("%s","BTS");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t shift = *(uint32_t*)source;
	// BTS
	FillFlags();
	uint32_t mask = 1 << shift;
	uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
	(*(uint32_t*)target) = (*(uint32_t*)target) | mask;
}
//BTS
void handlerCommand32Code01AB() {
	LOG("%s","BTS");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t shift = *(uint32_t*)source;
	// BTS
	FillFlags();
	uint32_t mask = 1 << shift;
	uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
	(*(uint32_t*)target) = (*(uint32_t*)target) | mask;
}
//Mul
void handlerCommand32Code01AFP66() {
	LOG("%s","Mul");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	int16_t source1 = *(int16_t*)source;
	int16_t source2 = *(int16_t*)target;
	target = source;
	int32_t tmp = (int32_t)source1 * (int32_t)source2;
	int16_t value = source1 * source2;
	*((int16_t*)target) = value;
	SET_FLAG(ZF, value == 0);
	SET_FLAG(CF, value != tmp);
	SET_FLAG(OF, value != tmp);
	lazyFlagType = t_MUL;
}
//Mul
void handlerCommand32Code01AF() {
	LOG("%s","Mul");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	int32_t source1 = *(int32_t*)source;
	int32_t source2 = *(int32_t*)target;
	target = source;
	int64_t tmp = (int64_t)source1 * (int64_t)source2;
	int32_t value = source1 * source2;
	*((int32_t*)target) = value;
	SET_FLAG(ZF, value == 0);
	SET_FLAG(CF, value != tmp);
	SET_FLAG(OF, value != tmp);
	lazyFlagType = t_MUL;
}
//Load SR_SS
void handlerCommand32Code01B2() {
	LOG("%s","Load SR_SS");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	setMem(SR_SS, *(uint16_t*)(target + 2));
	*(uint32_t*)source = *(uint32_t*)(target);
}
//BTR
void handlerCommand32Code01B3P66() {
	LOG("%s","BTR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t shift = *(uint32_t*)source;
	// BTR
	FillFlags();
	uint32_t mask = 1 << shift;
	uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
	(*(uint32_t*)target) = (*(uint32_t*)target) & (~mask);
}
//BTR
void handlerCommand32Code01B3() {
	LOG("%s","BTR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t shift = *(uint32_t*)source;
	// BTR
	FillFlags();
	uint32_t mask = 1 << shift;
	uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
	(*(uint32_t*)target) = (*(uint32_t*)target) & (~mask);
}
//Load SR_FS
void handlerCommand32Code01B4() {
	LOG("%s","Load SR_FS");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	setMem(SR_FS, *(uint16_t*)(target + 2));
	*(uint32_t*)source = *(uint32_t*)(target);
}
//Load SR_GS
void handlerCommand32Code01B5() {
	LOG("%s","Load SR_GS");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	setMem(SR_GS, *(uint16_t*)(target + 2));
	*(uint32_t*)source = *(uint32_t*)(target);
}
//MOVZX
void handlerCommand32Code01B6P66() {
	LOG("%s","MOVZX");
	uint8_t mrmByte = read8u();
	uint16_t* target = (uint16_t*)readRegisterMRM16(mrmByte);
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	*target = (uint16_t)*source;
}
//MOVZX
void handlerCommand32Code01B6() {
	LOG("%s","MOVZX");
	uint8_t mrmByte = read8u();
	uint32_t* target = (uint32_t*)readRegisterMRM32(mrmByte);
	uint8_t* source = (uint8_t*)readAddressMRM32For8(mrmByte);
	*target = (uint32_t)*source;
}
//MOVZX
void handlerCommand32Code01B7() {
	LOG("%s","MOVZX");
	uint8_t mrmByte = read8u();
	uint32_t* target = (uint32_t*)readRegisterMRM32(mrmByte);
	uint16_t* source = (uint16_t*)readAddressMRM32For16(mrmByte);
	*target = (uint32_t)*source;
}
//Bit scan
void handlerCommand32Code01BAP66() {
	LOG("%s","Bit scan");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t shift = read8u();
			// BT
			FillFlags();
			uint32_t mask = 1 << shift;
			uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t shift = read8u();
			// BTS
			FillFlags();
			uint32_t mask = 1 << shift;
			uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
			(*(uint32_t*)target) = (*(uint32_t*)target) | mask;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t shift = read8u();
			// BTR
			FillFlags();
			uint32_t mask = 1 << shift;
			uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
			(*(uint32_t*)target) = (*(uint32_t*)target) & (~mask);
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t shift = read8u();
			// BTC
			FillFlags();
			uint32_t mask = 1 << shift;
			uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
			if (value) {
				(*(uint32_t*)target) = (*(uint32_t*)target) & (~mask);
			} else {
				(*(uint32_t*)target) = (*(uint32_t*)target) | mask;
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//Bit scan
void handlerCommand32Code01BA() {
	LOG("%s","Bit scan");
	uint8_t mrmByte = read8u();
	uint8_t nnn = readMiddle3Bit(mrmByte);
	switch (nnn) {
		case 0x4: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t shift = read8u();
			// BT
			FillFlags();
			uint32_t mask = 1 << shift;
			uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
		}
		break;
		case 0x5: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t shift = read8u();
			// BTS
			FillFlags();
			uint32_t mask = 1 << shift;
			uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
			(*(uint32_t*)target) = (*(uint32_t*)target) | mask;
		}
		break;
		case 0x6: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t shift = read8u();
			// BTR
			FillFlags();
			uint32_t mask = 1 << shift;
			uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
			(*(uint32_t*)target) = (*(uint32_t*)target) & (~mask);
		}
		break;
		case 0x7: {
			uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
			uint8_t shift = read8u();
			// BTC
			FillFlags();
			uint32_t mask = 1 << shift;
			uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
			SET_FLAG(CF, value);
			if (value) {
				(*(uint32_t*)target) = (*(uint32_t*)target) & (~mask);
			} else {
				(*(uint32_t*)target) = (*(uint32_t*)target) | mask;
			}
		}
		break;
		default:
		mCommandFunctionEmpty();
	}
}
//BTC
void handlerCommand32Code01BBP66() {
	LOG("%s","BTC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t shift = *(uint32_t*)source;
	// BTC
	FillFlags();
	uint32_t mask = 1 << shift;
	uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
	if (value) {
		(*(uint32_t*)target) = (*(uint32_t*)target) & (~mask);
	} else {
		(*(uint32_t*)target) = (*(uint32_t*)target) | mask;
	}
}
//BTC
void handlerCommand32Code01BB() {
	LOG("%s","BTC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	uint32_t shift = *(uint32_t*)source;
	// BTC
	FillFlags();
	uint32_t mask = 1 << shift;
	uint8_t value = ((*(uint32_t*)target) & mask) ? 1 : 0;
	SET_FLAG(CF, value);
	if (value) {
		(*(uint32_t*)target) = (*(uint32_t*)target) & (~mask);
	} else {
		(*(uint32_t*)target) = (*(uint32_t*)target) | mask;
	}
}
//BFC
void handlerCommand32Code01BCP66() {
	LOG("%s","BFC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	FillFlags();
	uint16_t value = *(uint16_t*)source;
	if (value == 0) { SET_FLAG(ZF, 0); return; }
	uint16_t mask = 1;
	uint16_t len = 0;
	while ((mask & value) && (len < 16)) {
		value = value >> 1;
		len++;
	}
	SET_FLAG(ZF, 1);
	*(uint16_t*)target = len;
}
//BFC
void handlerCommand32Code01BC() {
	LOG("%s","BFC");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	FillFlags();
	uint32_t value = *(uint32_t*)source;
	if (value == 0) { SET_FLAG(ZF, 0); return; }
	uint32_t mask = 1;
	uint32_t len = 0;
	while ((mask & value) && (len < 32)) {
		value = value >> 1;
		len++;
	}
	SET_FLAG(ZF, 1);
	*(uint32_t*)target = len;
}
//BSR
void handlerCommand32Code01BDP66() {
	LOG("%s","BSR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For16(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);
	FillFlags();
	uint16_t value = *(uint16_t*)source;
	if (value == 0) { SET_FLAG(ZF, 0); return; }
	uint16_t mask = 1 << (16 - 1);
	uint16_t len = 0;
	while ((mask & value) && (len < 16)) {
		value = value << 1;
		len++;
	}
	SET_FLAG(ZF, 1);
	*(uint16_t*)target = len;
}
//BSR
void handlerCommand32Code01BD() {
	LOG("%s","BSR");
	uint8_t mrmByte = read8u();
	uint8_t* target = (uint8_t*)readAddressMRM32For32(mrmByte);
	uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);
	FillFlags();
	uint32_t value = *(uint32_t*)source;
	if (value == 0) { SET_FLAG(ZF, 0); return; }
	uint32_t mask = 1 << (32 - 1);
	uint32_t len = 0;
	while ((mask & value) && (len < 32)) {
		value = value << 1;
		len++;
	}
	SET_FLAG(ZF, 1);
	*(uint32_t*)target = len;
}
//MOVSX
void handlerCommand32Code01BEP66() {
	LOG("%s","MOVSX");
	uint8_t mrmByte = read8u();
	int16_t* target = (int16_t*)readRegisterMRM16(mrmByte);
	int8_t* source = (int8_t*)readAddressMRM32For8(mrmByte);
	*target = (int16_t)*source;
}
//MOVSX
void handlerCommand32Code01BE() {
	LOG("%s","MOVSX");
	uint8_t mrmByte = read8u();
	int32_t* target = (int32_t*)readRegisterMRM32(mrmByte);
	int8_t* source = (int8_t*)readAddressMRM32For8(mrmByte);
	*target = (int32_t)*source;
}
//MOVSX
void handlerCommand32Code01BF() {
	LOG("%s","MOVSX");
	uint8_t mrmByte = read8u();
	int32_t* target = (int32_t*)readRegisterMRM32(mrmByte);
	int16_t* source = (int16_t*)readAddressMRM32For16(mrmByte);
	*target = (int32_t)*source;
}
//Swap
void handlerCommand32Code01C8() {
	LOG("%s","Swap");
	uint8_t reg = 0x00;
	uint32_t value = reg_0x00_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand32Code01C9() {
	LOG("%s","Swap");
	uint8_t reg = 0x01;
	uint32_t value = reg_0x01_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand32Code01CA() {
	LOG("%s","Swap");
	uint8_t reg = 0x02;
	uint32_t value = reg_0x02_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand32Code01CB() {
	LOG("%s","Swap");
	uint8_t reg = 0x03;
	uint32_t value = reg_0x03_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand32Code01CC() {
	LOG("%s","Swap");
	uint8_t reg = 0x04;
	uint32_t value = reg_0x04_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand32Code01CD() {
	LOG("%s","Swap");
	uint8_t reg = 0x05;
	uint32_t value = reg_0x05_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand32Code01CE() {
	LOG("%s","Swap");
	uint8_t reg = 0x06;
	uint32_t value = reg_0x06_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
//Swap
void handlerCommand32Code01CF() {
	LOG("%s","Swap");
	uint8_t reg = 0x07;
	uint32_t value = reg_0x07_32u;
	uint8_t b1 = value & 0x000000FF;
	uint8_t b2 = value >> 8 & 0x000000FF;
	uint8_t b3 = value >> 16 & 0x000000FF;
	uint8_t b4 = value >> 24 & 0x000000FF;
	value = 0;
	value |= (((uint32_t)b1) << 24) & 0xFF000000;
	value |= (((uint32_t)b3) << 16) & 0x00FF0000;
	value |= (((uint32_t)b2) << 8)  & 0x0000FF00;
	value |= ((uint32_t)b4)      & 0x000000FF;
}
 

void installCommandFunction() {
	for(int i = 0; i < 256 * 8; i++) {
		commandFunctions16[i] = mCommandFunctionEmpty;
		commandFunctions32[i] = mCommandFunctionEmpty;
	}
	commandFunctions16[0] = handlerCommand16Code0000;
	commandFunctions16[0 | 0x0400] = handlerCommand16Code0000P66;
	commandFunctions16[1] = handlerCommand16Code0001;
	commandFunctions16[1 | 0x0400] = handlerCommand16Code0001P66;
	commandFunctions16[2] = handlerCommand16Code0002;
	commandFunctions16[2 | 0x0400] = handlerCommand16Code0002P66;
	commandFunctions16[3] = handlerCommand16Code0003;
	commandFunctions16[3 | 0x0400] = handlerCommand16Code0003P66;
	commandFunctions16[4] = handlerCommand16Code0004;
	commandFunctions16[4 | 0x0400] = handlerCommand16Code0004P66;
	commandFunctions16[5] = handlerCommand16Code0005;
	commandFunctions16[5 | 0x0400] = handlerCommand16Code0005P66;
	commandFunctions16[6] = handlerCommand16Code0006;
	commandFunctions16[14] = handlerCommand16Code000E;
	commandFunctions16[22] = handlerCommand16Code0016;
	commandFunctions16[30] = handlerCommand16Code001E;
	commandFunctions16[7] = handlerCommand16Code0007;
	commandFunctions16[15] = handlerCommand16Code000F;
	commandFunctions16[23] = handlerCommand16Code0017;
	commandFunctions16[31] = handlerCommand16Code001F;
	commandFunctions16[8] = handlerCommand16Code0008;
	commandFunctions16[8 | 0x0400] = handlerCommand16Code0008P66;
	commandFunctions16[9] = handlerCommand16Code0009;
	commandFunctions16[9 | 0x0400] = handlerCommand16Code0009P66;
	commandFunctions16[10] = handlerCommand16Code000A;
	commandFunctions16[10 | 0x0400] = handlerCommand16Code000AP66;
	commandFunctions16[11] = handlerCommand16Code000B;
	commandFunctions16[11 | 0x0400] = handlerCommand16Code000BP66;
	commandFunctions16[12] = handlerCommand16Code000C;
	commandFunctions16[12 | 0x0400] = handlerCommand16Code000CP66;
	commandFunctions16[13] = handlerCommand16Code000D;
	commandFunctions16[13 | 0x0400] = handlerCommand16Code000DP66;
	commandFunctions16[16] = handlerCommand16Code0010;
	commandFunctions16[16 | 0x0400] = handlerCommand16Code0010P66;
	commandFunctions16[17] = handlerCommand16Code0011;
	commandFunctions16[17 | 0x0400] = handlerCommand16Code0011P66;
	commandFunctions16[18] = handlerCommand16Code0012;
	commandFunctions16[18 | 0x0400] = handlerCommand16Code0012P66;
	commandFunctions16[19] = handlerCommand16Code0013;
	commandFunctions16[19 | 0x0400] = handlerCommand16Code0013P66;
	commandFunctions16[20] = handlerCommand16Code0014;
	commandFunctions16[20 | 0x0400] = handlerCommand16Code0014P66;
	commandFunctions16[21] = handlerCommand16Code0015;
	commandFunctions16[21 | 0x0400] = handlerCommand16Code0015P66;
	commandFunctions16[24] = handlerCommand16Code0018;
	commandFunctions16[24 | 0x0400] = handlerCommand16Code0018P66;
	commandFunctions16[25] = handlerCommand16Code0019;
	commandFunctions16[25 | 0x0400] = handlerCommand16Code0019P66;
	commandFunctions16[26] = handlerCommand16Code001A;
	commandFunctions16[26 | 0x0400] = handlerCommand16Code001AP66;
	commandFunctions16[27] = handlerCommand16Code001B;
	commandFunctions16[27 | 0x0400] = handlerCommand16Code001BP66;
	commandFunctions16[28] = handlerCommand16Code001C;
	commandFunctions16[28 | 0x0400] = handlerCommand16Code001CP66;
	commandFunctions16[29] = handlerCommand16Code001D;
	commandFunctions16[29 | 0x0400] = handlerCommand16Code001DP66;
	commandFunctions16[32] = handlerCommand16Code0020;
	commandFunctions16[32 | 0x0400] = handlerCommand16Code0020P66;
	commandFunctions16[33] = handlerCommand16Code0021;
	commandFunctions16[33 | 0x0400] = handlerCommand16Code0021P66;
	commandFunctions16[34] = handlerCommand16Code0022;
	commandFunctions16[34 | 0x0400] = handlerCommand16Code0022P66;
	commandFunctions16[35] = handlerCommand16Code0023;
	commandFunctions16[35 | 0x0400] = handlerCommand16Code0023P66;
	commandFunctions16[36] = handlerCommand16Code0024;
	commandFunctions16[36 | 0x0400] = handlerCommand16Code0024P66;
	commandFunctions16[37] = handlerCommand16Code0025;
	commandFunctions16[37 | 0x0400] = handlerCommand16Code0025P66;
	commandFunctions16[40] = handlerCommand16Code0028;
	commandFunctions16[40 | 0x0400] = handlerCommand16Code0028P66;
	commandFunctions16[41] = handlerCommand16Code0029;
	commandFunctions16[41 | 0x0400] = handlerCommand16Code0029P66;
	commandFunctions16[42] = handlerCommand16Code002A;
	commandFunctions16[42 | 0x0400] = handlerCommand16Code002AP66;
	commandFunctions16[43] = handlerCommand16Code002B;
	commandFunctions16[43 | 0x0400] = handlerCommand16Code002BP66;
	commandFunctions16[44] = handlerCommand16Code002C;
	commandFunctions16[44 | 0x0400] = handlerCommand16Code002CP66;
	commandFunctions16[45] = handlerCommand16Code002D;
	commandFunctions16[45 | 0x0400] = handlerCommand16Code002DP66;
	commandFunctions16[48] = handlerCommand16Code0030;
	commandFunctions16[48 | 0x0400] = handlerCommand16Code0030P66;
	commandFunctions16[49] = handlerCommand16Code0031;
	commandFunctions16[49 | 0x0400] = handlerCommand16Code0031P66;
	commandFunctions16[50] = handlerCommand16Code0032;
	commandFunctions16[50 | 0x0400] = handlerCommand16Code0032P66;
	commandFunctions16[51] = handlerCommand16Code0033;
	commandFunctions16[51 | 0x0400] = handlerCommand16Code0033P66;
	commandFunctions16[52] = handlerCommand16Code0034;
	commandFunctions16[52 | 0x0400] = handlerCommand16Code0034P66;
	commandFunctions16[53] = handlerCommand16Code0035;
	commandFunctions16[53 | 0x0400] = handlerCommand16Code0035P66;
	commandFunctions16[56] = handlerCommand16Code0038;
	commandFunctions16[56 | 0x0400] = handlerCommand16Code0038P66;
	commandFunctions16[57] = handlerCommand16Code0039;
	commandFunctions16[57 | 0x0400] = handlerCommand16Code0039P66;
	commandFunctions16[58] = handlerCommand16Code003A;
	commandFunctions16[58 | 0x0400] = handlerCommand16Code003AP66;
	commandFunctions16[59] = handlerCommand16Code003B;
	commandFunctions16[59 | 0x0400] = handlerCommand16Code003BP66;
	commandFunctions16[60] = handlerCommand16Code003C;
	commandFunctions16[60 | 0x0400] = handlerCommand16Code003CP66;
	commandFunctions16[61] = handlerCommand16Code003D;
	commandFunctions16[61 | 0x0400] = handlerCommand16Code003DP66;
	commandFunctions16[64] = handlerCommand16Code0040;
	commandFunctions16[64 | 0x0400] = handlerCommand16Code0040P66;
	commandFunctions16[65] = handlerCommand16Code0041;
	commandFunctions16[65 | 0x0400] = handlerCommand16Code0041P66;
	commandFunctions16[66] = handlerCommand16Code0042;
	commandFunctions16[66 | 0x0400] = handlerCommand16Code0042P66;
	commandFunctions16[67] = handlerCommand16Code0043;
	commandFunctions16[67 | 0x0400] = handlerCommand16Code0043P66;
	commandFunctions16[68] = handlerCommand16Code0044;
	commandFunctions16[68 | 0x0400] = handlerCommand16Code0044P66;
	commandFunctions16[69] = handlerCommand16Code0045;
	commandFunctions16[69 | 0x0400] = handlerCommand16Code0045P66;
	commandFunctions16[70] = handlerCommand16Code0046;
	commandFunctions16[70 | 0x0400] = handlerCommand16Code0046P66;
	commandFunctions16[71] = handlerCommand16Code0047;
	commandFunctions16[71 | 0x0400] = handlerCommand16Code0047P66;
	commandFunctions16[72] = handlerCommand16Code0048;
	commandFunctions16[72 | 0x0400] = handlerCommand16Code0048P66;
	commandFunctions16[73] = handlerCommand16Code0049;
	commandFunctions16[73 | 0x0400] = handlerCommand16Code0049P66;
	commandFunctions16[74] = handlerCommand16Code004A;
	commandFunctions16[74 | 0x0400] = handlerCommand16Code004AP66;
	commandFunctions16[75] = handlerCommand16Code004B;
	commandFunctions16[75 | 0x0400] = handlerCommand16Code004BP66;
	commandFunctions16[76] = handlerCommand16Code004C;
	commandFunctions16[76 | 0x0400] = handlerCommand16Code004CP66;
	commandFunctions16[77] = handlerCommand16Code004D;
	commandFunctions16[77 | 0x0400] = handlerCommand16Code004DP66;
	commandFunctions16[78] = handlerCommand16Code004E;
	commandFunctions16[78 | 0x0400] = handlerCommand16Code004EP66;
	commandFunctions16[79] = handlerCommand16Code004F;
	commandFunctions16[79 | 0x0400] = handlerCommand16Code004FP66;
	commandFunctions16[80] = handlerCommand16Code0050;
	commandFunctions16[80 | 0x0200 ] = handlerCommand16Code0050P67;
	commandFunctions16[80 | 0x0400] = handlerCommand16Code0050P66;
	commandFunctions16[80 | 0x0200 | 0x0400] = handlerCommand16Code0050P66P67;
	commandFunctions16[81] = handlerCommand16Code0051;
	commandFunctions16[81 | 0x0200 ] = handlerCommand16Code0051P67;
	commandFunctions16[81 | 0x0400] = handlerCommand16Code0051P66;
	commandFunctions16[81 | 0x0200 | 0x0400] = handlerCommand16Code0051P66P67;
	commandFunctions16[82] = handlerCommand16Code0052;
	commandFunctions16[82 | 0x0200 ] = handlerCommand16Code0052P67;
	commandFunctions16[82 | 0x0400] = handlerCommand16Code0052P66;
	commandFunctions16[82 | 0x0200 | 0x0400] = handlerCommand16Code0052P66P67;
	commandFunctions16[83] = handlerCommand16Code0053;
	commandFunctions16[83 | 0x0200 ] = handlerCommand16Code0053P67;
	commandFunctions16[83 | 0x0400] = handlerCommand16Code0053P66;
	commandFunctions16[83 | 0x0200 | 0x0400] = handlerCommand16Code0053P66P67;
	commandFunctions16[84] = handlerCommand16Code0054;
	commandFunctions16[84 | 0x0200 ] = handlerCommand16Code0054P67;
	commandFunctions16[84 | 0x0400] = handlerCommand16Code0054P66;
	commandFunctions16[84 | 0x0200 | 0x0400] = handlerCommand16Code0054P66P67;
	commandFunctions16[85] = handlerCommand16Code0055;
	commandFunctions16[85 | 0x0200 ] = handlerCommand16Code0055P67;
	commandFunctions16[85 | 0x0400] = handlerCommand16Code0055P66;
	commandFunctions16[85 | 0x0200 | 0x0400] = handlerCommand16Code0055P66P67;
	commandFunctions16[86] = handlerCommand16Code0056;
	commandFunctions16[86 | 0x0200 ] = handlerCommand16Code0056P67;
	commandFunctions16[86 | 0x0400] = handlerCommand16Code0056P66;
	commandFunctions16[86 | 0x0200 | 0x0400] = handlerCommand16Code0056P66P67;
	commandFunctions16[87] = handlerCommand16Code0057;
	commandFunctions16[87 | 0x0200 ] = handlerCommand16Code0057P67;
	commandFunctions16[87 | 0x0400] = handlerCommand16Code0057P66;
	commandFunctions16[87 | 0x0200 | 0x0400] = handlerCommand16Code0057P66P67;
	commandFunctions16[88] = handlerCommand16Code0058;
	commandFunctions16[88 | 0x0200 ] = handlerCommand16Code0058P67;
	commandFunctions16[88 | 0x0400] = handlerCommand16Code0058P66;
	commandFunctions16[88 | 0x0200 | 0x0400] = handlerCommand16Code0058P66P67;
	commandFunctions16[89] = handlerCommand16Code0059;
	commandFunctions16[89 | 0x0200 ] = handlerCommand16Code0059P67;
	commandFunctions16[89 | 0x0400] = handlerCommand16Code0059P66;
	commandFunctions16[89 | 0x0200 | 0x0400] = handlerCommand16Code0059P66P67;
	commandFunctions16[90] = handlerCommand16Code005A;
	commandFunctions16[90 | 0x0200 ] = handlerCommand16Code005AP67;
	commandFunctions16[90 | 0x0400] = handlerCommand16Code005AP66;
	commandFunctions16[90 | 0x0200 | 0x0400] = handlerCommand16Code005AP66P67;
	commandFunctions16[91] = handlerCommand16Code005B;
	commandFunctions16[91 | 0x0200 ] = handlerCommand16Code005BP67;
	commandFunctions16[91 | 0x0400] = handlerCommand16Code005BP66;
	commandFunctions16[91 | 0x0200 | 0x0400] = handlerCommand16Code005BP66P67;
	commandFunctions16[92] = handlerCommand16Code005C;
	commandFunctions16[92 | 0x0200 ] = handlerCommand16Code005CP67;
	commandFunctions16[92 | 0x0400] = handlerCommand16Code005CP66;
	commandFunctions16[92 | 0x0200 | 0x0400] = handlerCommand16Code005CP66P67;
	commandFunctions16[93] = handlerCommand16Code005D;
	commandFunctions16[93 | 0x0200 ] = handlerCommand16Code005DP67;
	commandFunctions16[93 | 0x0400] = handlerCommand16Code005DP66;
	commandFunctions16[93 | 0x0200 | 0x0400] = handlerCommand16Code005DP66P67;
	commandFunctions16[94] = handlerCommand16Code005E;
	commandFunctions16[94 | 0x0200 ] = handlerCommand16Code005EP67;
	commandFunctions16[94 | 0x0400] = handlerCommand16Code005EP66;
	commandFunctions16[94 | 0x0200 | 0x0400] = handlerCommand16Code005EP66P67;
	commandFunctions16[95] = handlerCommand16Code005F;
	commandFunctions16[95 | 0x0200 ] = handlerCommand16Code005FP67;
	commandFunctions16[95 | 0x0400] = handlerCommand16Code005FP66;
	commandFunctions16[95 | 0x0200 | 0x0400] = handlerCommand16Code005FP66P67;
	commandFunctions16[96] = handlerCommand16Code0060;
	commandFunctions16[96 | 0x0400] = handlerCommand16Code0060P66;
	commandFunctions16[97] = handlerCommand16Code0061;
	commandFunctions16[97 | 0x0400] = handlerCommand16Code0061P66;
	commandFunctions16[104] = handlerCommand16Code0068;
	commandFunctions16[104 | 0x0200 ] = handlerCommand16Code0068P67;
	commandFunctions16[104 | 0x0400] = handlerCommand16Code0068P66;
	commandFunctions16[104 | 0x0200 | 0x0400] = handlerCommand16Code0068P66P67;
	commandFunctions16[105] = handlerCommand16Code0069;
	commandFunctions16[105 | 0x0400] = handlerCommand16Code0069P66;
	commandFunctions16[106] = handlerCommand16Code006A;
	commandFunctions16[106 | 0x0200 ] = handlerCommand16Code006AP67;
	commandFunctions16[106 | 0x0400] = handlerCommand16Code006AP66;
	commandFunctions16[106 | 0x0200 | 0x0400] = handlerCommand16Code006AP66P67;
	commandFunctions16[107] = handlerCommand16Code006B;
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
	commandFunctions16[128] = handlerCommand16Code0080;
	commandFunctions16[128 | 0x0400] = handlerCommand16Code0080P66;
	commandFunctions16[129] = handlerCommand16Code0081;
	commandFunctions16[129 | 0x0400] = handlerCommand16Code0081P66;
	commandFunctions16[130] = handlerCommand16Code0082;
	commandFunctions16[131] = handlerCommand16Code0083;
	commandFunctions16[132] = handlerCommand16Code0084;
	commandFunctions16[132 | 0x0400] = handlerCommand16Code0084P66;
	commandFunctions16[133] = handlerCommand16Code0085;
	commandFunctions16[133 | 0x0400] = handlerCommand16Code0085P66;
	commandFunctions16[134] = handlerCommand16Code0086;
	commandFunctions16[134 | 0x0400] = handlerCommand16Code0086P66;
	commandFunctions16[135] = handlerCommand16Code0087;
	commandFunctions16[135 | 0x0400] = handlerCommand16Code0087P66;
	commandFunctions16[136] = handlerCommand16Code0088;
	commandFunctions16[136 | 0x0400] = handlerCommand16Code0088P66;
	commandFunctions16[137] = handlerCommand16Code0089;
	commandFunctions16[137 | 0x0400] = handlerCommand16Code0089P66;
	commandFunctions16[138] = handlerCommand16Code008A;
	commandFunctions16[138 | 0x0400] = handlerCommand16Code008AP66;
	commandFunctions16[139] = handlerCommand16Code008B;
	commandFunctions16[139 | 0x0400] = handlerCommand16Code008BP66;
	commandFunctions16[140] = handlerCommand16Code008C;
	commandFunctions16[142] = handlerCommand16Code008E;
	commandFunctions16[141] = handlerCommand16Code008D;
	commandFunctions16[141 | 0x0200 ] = handlerCommand16Code008DP67;
	commandFunctions16[141 | 0x0400] = handlerCommand16Code008DP66;
	commandFunctions16[141 | 0x0200 | 0x0400] = handlerCommand16Code008DP66P67;
	commandFunctions16[143] = handlerCommand16Code008F;
	commandFunctions16[143 | 0x0200 ] = handlerCommand16Code008FP67;
	commandFunctions16[143 | 0x0400] = handlerCommand16Code008FP66;
	commandFunctions16[143 | 0x0200 | 0x0400] = handlerCommand16Code008FP66P67;
	commandFunctions16[144] = handlerCommand16Code0090;
	commandFunctions16[144 | 0x0400] = handlerCommand16Code0090P66;
	commandFunctions16[145] = handlerCommand16Code0091;
	commandFunctions16[145 | 0x0400] = handlerCommand16Code0091P66;
	commandFunctions16[146] = handlerCommand16Code0092;
	commandFunctions16[146 | 0x0400] = handlerCommand16Code0092P66;
	commandFunctions16[147] = handlerCommand16Code0093;
	commandFunctions16[147 | 0x0400] = handlerCommand16Code0093P66;
	commandFunctions16[148] = handlerCommand16Code0094;
	commandFunctions16[148 | 0x0400] = handlerCommand16Code0094P66;
	commandFunctions16[149] = handlerCommand16Code0095;
	commandFunctions16[149 | 0x0400] = handlerCommand16Code0095P66;
	commandFunctions16[150] = handlerCommand16Code0096;
	commandFunctions16[150 | 0x0400] = handlerCommand16Code0096P66;
	commandFunctions16[151] = handlerCommand16Code0097;
	commandFunctions16[151 | 0x0400] = handlerCommand16Code0097P66;
	commandFunctions16[152] = handlerCommand16Code0098;
	commandFunctions16[152 | 0x0400] = handlerCommand16Code0098P66;
	commandFunctions16[153] = handlerCommand16Code0099;
	commandFunctions16[153 | 0x0400] = handlerCommand16Code0099P66;
	commandFunctions16[156] = handlerCommand16Code009C;
	commandFunctions16[156 | 0x0400] = handlerCommand16Code009CP66;
	commandFunctions16[157] = handlerCommand16Code009D;
	commandFunctions16[157 | 0x0400] = handlerCommand16Code009DP66;
	commandFunctions16[160] = handlerCommand16Code00A0;
	commandFunctions16[160 | 0x0200 ] = handlerCommand16Code00A0P67;
	commandFunctions16[160 | 0x0400] = handlerCommand16Code00A0P66;
	commandFunctions16[160 | 0x0200 | 0x0400] = handlerCommand16Code00A0P66P67;
	commandFunctions16[161] = handlerCommand16Code00A1;
	commandFunctions16[161 | 0x0200 ] = handlerCommand16Code00A1P67;
	commandFunctions16[161 | 0x0400] = handlerCommand16Code00A1P66;
	commandFunctions16[161 | 0x0200 | 0x0400] = handlerCommand16Code00A1P66P67;
	commandFunctions16[162] = handlerCommand16Code00A2;
	commandFunctions16[162 | 0x0200 ] = handlerCommand16Code00A2P67;
	commandFunctions16[162 | 0x0400] = handlerCommand16Code00A2P66;
	commandFunctions16[162 | 0x0200 | 0x0400] = handlerCommand16Code00A2P66P67;
	commandFunctions16[163] = handlerCommand16Code00A3;
	commandFunctions16[163 | 0x0200 ] = handlerCommand16Code00A3P67;
	commandFunctions16[163 | 0x0400] = handlerCommand16Code00A3P66;
	commandFunctions16[163 | 0x0200 | 0x0400] = handlerCommand16Code00A3P66P67;
	commandFunctions16[164] = handlerCommand16Code00A4;
	commandFunctions16[164 | 0x0200 ] = handlerCommand16Code00A4P67;
	commandFunctions16[164 | 0x0400] = handlerCommand16Code00A4P66;
	commandFunctions16[164 | 0x0200 | 0x0400] = handlerCommand16Code00A4P66P67;
	commandFunctions16[165] = handlerCommand16Code00A5;
	commandFunctions16[165 | 0x0200 ] = handlerCommand16Code00A5P67;
	commandFunctions16[165 | 0x0400] = handlerCommand16Code00A5P66;
	commandFunctions16[165 | 0x0200 | 0x0400] = handlerCommand16Code00A5P66P67;
	commandFunctions16[166] = handlerCommand16Code00A6;
	commandFunctions16[166 | 0x0200 ] = handlerCommand16Code00A6P67;
	commandFunctions16[166 | 0x0400] = handlerCommand16Code00A6P66;
	commandFunctions16[166 | 0x0200 | 0x0400] = handlerCommand16Code00A6P66P67;
	commandFunctions16[167] = handlerCommand16Code00A7;
	commandFunctions16[167 | 0x0200 ] = handlerCommand16Code00A7P67;
	commandFunctions16[167 | 0x0400] = handlerCommand16Code00A7P66;
	commandFunctions16[167 | 0x0200 | 0x0400] = handlerCommand16Code00A7P66P67;
	commandFunctions16[168] = handlerCommand16Code00A8;
	commandFunctions16[168 | 0x0400] = handlerCommand16Code00A8P66;
	commandFunctions16[169] = handlerCommand16Code00A9;
	commandFunctions16[169 | 0x0400] = handlerCommand16Code00A9P66;
	commandFunctions16[170] = handlerCommand16Code00AA;
	commandFunctions16[170 | 0x0200 ] = handlerCommand16Code00AAP67;
	commandFunctions16[170 | 0x0400] = handlerCommand16Code00AAP66;
	commandFunctions16[170 | 0x0200 | 0x0400] = handlerCommand16Code00AAP66P67;
	commandFunctions16[171] = handlerCommand16Code00AB;
	commandFunctions16[171 | 0x0200 ] = handlerCommand16Code00ABP67;
	commandFunctions16[171 | 0x0400] = handlerCommand16Code00ABP66;
	commandFunctions16[171 | 0x0200 | 0x0400] = handlerCommand16Code00ABP66P67;
	commandFunctions16[172] = handlerCommand16Code00AC;
	commandFunctions16[172 | 0x0200 ] = handlerCommand16Code00ACP67;
	commandFunctions16[172 | 0x0400] = handlerCommand16Code00ACP66;
	commandFunctions16[172 | 0x0200 | 0x0400] = handlerCommand16Code00ACP66P67;
	commandFunctions16[173] = handlerCommand16Code00AD;
	commandFunctions16[173 | 0x0200 ] = handlerCommand16Code00ADP67;
	commandFunctions16[173 | 0x0400] = handlerCommand16Code00ADP66;
	commandFunctions16[173 | 0x0200 | 0x0400] = handlerCommand16Code00ADP66P67;
	commandFunctions16[174] = handlerCommand16Code00AE;
	commandFunctions16[174 | 0x0200 ] = handlerCommand16Code00AEP67;
	commandFunctions16[174 | 0x0400] = handlerCommand16Code00AEP66;
	commandFunctions16[174 | 0x0200 | 0x0400] = handlerCommand16Code00AEP66P67;
	commandFunctions16[175] = handlerCommand16Code00AF;
	commandFunctions16[175 | 0x0200 ] = handlerCommand16Code00AFP67;
	commandFunctions16[175 | 0x0400] = handlerCommand16Code00AFP66;
	commandFunctions16[175 | 0x0200 | 0x0400] = handlerCommand16Code00AFP66P67;
	commandFunctions16[176] = handlerCommand16Code00B0;
	commandFunctions16[176 | 0x0400] = handlerCommand16Code00B0P66;
	commandFunctions16[177] = handlerCommand16Code00B1;
	commandFunctions16[177 | 0x0400] = handlerCommand16Code00B1P66;
	commandFunctions16[178] = handlerCommand16Code00B2;
	commandFunctions16[178 | 0x0400] = handlerCommand16Code00B2P66;
	commandFunctions16[179] = handlerCommand16Code00B3;
	commandFunctions16[179 | 0x0400] = handlerCommand16Code00B3P66;
	commandFunctions16[180] = handlerCommand16Code00B4;
	commandFunctions16[180 | 0x0400] = handlerCommand16Code00B4P66;
	commandFunctions16[181] = handlerCommand16Code00B5;
	commandFunctions16[181 | 0x0400] = handlerCommand16Code00B5P66;
	commandFunctions16[182] = handlerCommand16Code00B6;
	commandFunctions16[182 | 0x0400] = handlerCommand16Code00B6P66;
	commandFunctions16[183] = handlerCommand16Code00B7;
	commandFunctions16[183 | 0x0400] = handlerCommand16Code00B7P66;
	commandFunctions16[184] = handlerCommand16Code00B8;
	commandFunctions16[184 | 0x0400] = handlerCommand16Code00B8P66;
	commandFunctions16[185] = handlerCommand16Code00B9;
	commandFunctions16[185 | 0x0400] = handlerCommand16Code00B9P66;
	commandFunctions16[186] = handlerCommand16Code00BA;
	commandFunctions16[186 | 0x0400] = handlerCommand16Code00BAP66;
	commandFunctions16[187] = handlerCommand16Code00BB;
	commandFunctions16[187 | 0x0400] = handlerCommand16Code00BBP66;
	commandFunctions16[188] = handlerCommand16Code00BC;
	commandFunctions16[188 | 0x0400] = handlerCommand16Code00BCP66;
	commandFunctions16[189] = handlerCommand16Code00BD;
	commandFunctions16[189 | 0x0400] = handlerCommand16Code00BDP66;
	commandFunctions16[190] = handlerCommand16Code00BE;
	commandFunctions16[190 | 0x0400] = handlerCommand16Code00BEP66;
	commandFunctions16[191] = handlerCommand16Code00BF;
	commandFunctions16[191 | 0x0400] = handlerCommand16Code00BFP66;
	commandFunctions16[192] = handlerCommand16Code00C0;
	commandFunctions16[192 | 0x0400] = handlerCommand16Code00C0P66;
	commandFunctions16[193] = handlerCommand16Code00C1;
	commandFunctions16[193 | 0x0400] = handlerCommand16Code00C1P66;
	commandFunctions16[195] = handlerCommand16Code00C3;
	commandFunctions16[196] = handlerCommand16Code00C4;
	commandFunctions16[197] = handlerCommand16Code00C5;
	commandFunctions16[198] = handlerCommand16Code00C6;
	commandFunctions16[198 | 0x0400] = handlerCommand16Code00C6P66;
	commandFunctions16[199] = handlerCommand16Code00C7;
	commandFunctions16[199 | 0x0400] = handlerCommand16Code00C7P66;
	commandFunctions16[200] = handlerCommand16Code00C8;
	commandFunctions16[200 | 0x0200 ] = handlerCommand16Code00C8P67;
	commandFunctions16[200 | 0x0400] = handlerCommand16Code00C8P66;
	commandFunctions16[200 | 0x0200 | 0x0400] = handlerCommand16Code00C8P66P67;
	commandFunctions16[201] = handlerCommand16Code00C9;
	commandFunctions16[201 | 0x0200 ] = handlerCommand16Code00C9P67;
	commandFunctions16[201 | 0x0400] = handlerCommand16Code00C9P66;
	commandFunctions16[201 | 0x0200 | 0x0400] = handlerCommand16Code00C9P66P67;
	commandFunctions16[203] = handlerCommand16Code00CB;
	commandFunctions16[205] = handlerCommand16Code00CD;
	commandFunctions16[208] = handlerCommand16Code00D0;
	commandFunctions16[208 | 0x0400] = handlerCommand16Code00D0P66;
	commandFunctions16[209] = handlerCommand16Code00D1;
	commandFunctions16[209 | 0x0400] = handlerCommand16Code00D1P66;
	commandFunctions16[210] = handlerCommand16Code00D2;
	commandFunctions16[210 | 0x0400] = handlerCommand16Code00D2P66;
	commandFunctions16[211] = handlerCommand16Code00D3;
	commandFunctions16[211 | 0x0400] = handlerCommand16Code00D3P66;
	commandFunctions16[216] = handlerCommand16Code00D8;
	commandFunctions16[217] = handlerCommand16Code00D9;
	commandFunctions16[218] = handlerCommand16Code00DA;
	commandFunctions16[219] = handlerCommand16Code00DB;
	commandFunctions16[220] = handlerCommand16Code00DC;
	commandFunctions16[221] = handlerCommand16Code00DD;
	commandFunctions16[222] = handlerCommand16Code00DE;
	commandFunctions16[223] = handlerCommand16Code00DF;
	commandFunctions16[224] = handlerCommand16Code00E0;
	commandFunctions16[225] = handlerCommand16Code00E1;
	commandFunctions16[226] = handlerCommand16Code00E2;
	commandFunctions16[227] = handlerCommand16Code00E3;
	commandFunctions16[232] = handlerCommand16Code00E8;
	commandFunctions16[232 | 0x0400] = handlerCommand16Code00E8P66;
	commandFunctions16[233] = handlerCommand16Code00E9;
	commandFunctions16[233 | 0x0400] = handlerCommand16Code00E9P66;
	commandFunctions16[235] = handlerCommand16Code00EB;
	commandFunctions16[245] = handlerCommand16Code00F5;
	commandFunctions16[246] = handlerCommand16Code00F6;
	commandFunctions16[246 | 0x0400] = handlerCommand16Code00F6P66;
	commandFunctions16[247] = handlerCommand16Code00F7;
	commandFunctions16[247 | 0x0400] = handlerCommand16Code00F7P66;
	commandFunctions16[248] = handlerCommand16Code00F8;
	commandFunctions16[249] = handlerCommand16Code00F9;
	commandFunctions16[250] = handlerCommand16Code00FA;
	commandFunctions16[251] = handlerCommand16Code00FB;
	commandFunctions16[252] = handlerCommand16Code00FC;
	commandFunctions16[253] = handlerCommand16Code00FD;
	commandFunctions16[255] = handlerCommand16Code00FF;
	commandFunctions16[255 | 0x0200 ] = handlerCommand16Code00FFP67;
	commandFunctions16[255 | 0x0400] = handlerCommand16Code00FFP66;
	commandFunctions16[255 | 0x0200 | 0x0400] = handlerCommand16Code00FFP66P67;
	commandFunctions16[257] = handlerCommand16Code0101;
	commandFunctions16[384] = handlerCommand16Code0180;
	commandFunctions16[385] = handlerCommand16Code0181;
	commandFunctions16[386] = handlerCommand16Code0182;
	commandFunctions16[387] = handlerCommand16Code0183;
	commandFunctions16[388] = handlerCommand16Code0184;
	commandFunctions16[389] = handlerCommand16Code0185;
	commandFunctions16[390] = handlerCommand16Code0186;
	commandFunctions16[391] = handlerCommand16Code0187;
	commandFunctions16[392] = handlerCommand16Code0188;
	commandFunctions16[393] = handlerCommand16Code0189;
	commandFunctions16[394] = handlerCommand16Code018A;
	commandFunctions16[395] = handlerCommand16Code018B;
	commandFunctions16[396] = handlerCommand16Code018C;
	commandFunctions16[397] = handlerCommand16Code018D;
	commandFunctions16[398] = handlerCommand16Code018E;
	commandFunctions16[399] = handlerCommand16Code018F;
	commandFunctions16[400] = handlerCommand16Code0190;
	commandFunctions16[400 | 0x0400] = handlerCommand16Code0190P66;
	commandFunctions16[401] = handlerCommand16Code0191;
	commandFunctions16[401 | 0x0400] = handlerCommand16Code0191P66;
	commandFunctions16[402] = handlerCommand16Code0192;
	commandFunctions16[402 | 0x0400] = handlerCommand16Code0192P66;
	commandFunctions16[403] = handlerCommand16Code0193;
	commandFunctions16[403 | 0x0400] = handlerCommand16Code0193P66;
	commandFunctions16[404] = handlerCommand16Code0194;
	commandFunctions16[404 | 0x0400] = handlerCommand16Code0194P66;
	commandFunctions16[405] = handlerCommand16Code0195;
	commandFunctions16[405 | 0x0400] = handlerCommand16Code0195P66;
	commandFunctions16[406] = handlerCommand16Code0196;
	commandFunctions16[406 | 0x0400] = handlerCommand16Code0196P66;
	commandFunctions16[407] = handlerCommand16Code0197;
	commandFunctions16[407 | 0x0400] = handlerCommand16Code0197P66;
	commandFunctions16[408] = handlerCommand16Code0198;
	commandFunctions16[408 | 0x0400] = handlerCommand16Code0198P66;
	commandFunctions16[409] = handlerCommand16Code0199;
	commandFunctions16[409 | 0x0400] = handlerCommand16Code0199P66;
	commandFunctions16[410] = handlerCommand16Code019A;
	commandFunctions16[410 | 0x0400] = handlerCommand16Code019AP66;
	commandFunctions16[411] = handlerCommand16Code019B;
	commandFunctions16[411 | 0x0400] = handlerCommand16Code019BP66;
	commandFunctions16[412] = handlerCommand16Code019C;
	commandFunctions16[412 | 0x0400] = handlerCommand16Code019CP66;
	commandFunctions16[413] = handlerCommand16Code019D;
	commandFunctions16[413 | 0x0400] = handlerCommand16Code019DP66;
	commandFunctions16[414] = handlerCommand16Code019E;
	commandFunctions16[414 | 0x0400] = handlerCommand16Code019EP66;
	commandFunctions16[415] = handlerCommand16Code019F;
	commandFunctions16[415 | 0x0400] = handlerCommand16Code019FP66;
	commandFunctions16[419] = handlerCommand16Code01A3;
	commandFunctions16[419 | 0x0400] = handlerCommand16Code01A3P66;
	commandFunctions16[427] = handlerCommand16Code01AB;
	commandFunctions16[427 | 0x0400] = handlerCommand16Code01ABP66;
	commandFunctions16[431] = handlerCommand16Code01AF;
	commandFunctions16[431 | 0x0400] = handlerCommand16Code01AFP66;
	commandFunctions16[434] = handlerCommand16Code01B2;
	commandFunctions16[435] = handlerCommand16Code01B3;
	commandFunctions16[435 | 0x0400] = handlerCommand16Code01B3P66;
	commandFunctions16[436] = handlerCommand16Code01B4;
	commandFunctions16[437] = handlerCommand16Code01B5;
	commandFunctions16[438] = handlerCommand16Code01B6;
	commandFunctions16[439] = handlerCommand16Code01B7;
	commandFunctions16[442] = handlerCommand16Code01BA;
	commandFunctions16[442 | 0x0400] = handlerCommand16Code01BAP66;
	commandFunctions16[443] = handlerCommand16Code01BB;
	commandFunctions16[443 | 0x0400] = handlerCommand16Code01BBP66;
	commandFunctions16[444] = handlerCommand16Code01BC;
	commandFunctions16[444 | 0x0400] = handlerCommand16Code01BCP66;
	commandFunctions16[445] = handlerCommand16Code01BD;
	commandFunctions16[445 | 0x0400] = handlerCommand16Code01BDP66;
	commandFunctions16[446] = handlerCommand16Code01BE;
	commandFunctions16[447] = handlerCommand16Code01BF;
	commandFunctions16[456] = handlerCommand16Code01C8;
	commandFunctions16[457] = handlerCommand16Code01C9;
	commandFunctions16[458] = handlerCommand16Code01CA;
	commandFunctions16[459] = handlerCommand16Code01CB;
	commandFunctions16[460] = handlerCommand16Code01CC;
	commandFunctions16[461] = handlerCommand16Code01CD;
	commandFunctions16[462] = handlerCommand16Code01CE;
	commandFunctions16[463] = handlerCommand16Code01CF;
	commandFunctions32[0] = handlerCommand32Code0000;
	commandFunctions32[0 | 0x0400] = handlerCommand32Code0000P66;
	commandFunctions32[1] = handlerCommand32Code0001;
	commandFunctions32[1 | 0x0400] = handlerCommand32Code0001P66;
	commandFunctions32[2] = handlerCommand32Code0002;
	commandFunctions32[2 | 0x0400] = handlerCommand32Code0002P66;
	commandFunctions32[3] = handlerCommand32Code0003;
	commandFunctions32[3 | 0x0400] = handlerCommand32Code0003P66;
	commandFunctions32[4] = handlerCommand32Code0004;
	commandFunctions32[4 | 0x0400] = handlerCommand32Code0004P66;
	commandFunctions32[5] = handlerCommand32Code0005;
	commandFunctions32[5 | 0x0400] = handlerCommand32Code0005P66;
	commandFunctions32[6] = handlerCommand32Code0006;
	commandFunctions32[14] = handlerCommand32Code000E;
	commandFunctions32[22] = handlerCommand32Code0016;
	commandFunctions32[30] = handlerCommand32Code001E;
	commandFunctions32[7] = handlerCommand32Code0007;
	commandFunctions32[15] = handlerCommand32Code000F;
	commandFunctions32[23] = handlerCommand32Code0017;
	commandFunctions32[31] = handlerCommand32Code001F;
	commandFunctions32[8] = handlerCommand32Code0008;
	commandFunctions32[8 | 0x0400] = handlerCommand32Code0008P66;
	commandFunctions32[9] = handlerCommand32Code0009;
	commandFunctions32[9 | 0x0400] = handlerCommand32Code0009P66;
	commandFunctions32[10] = handlerCommand32Code000A;
	commandFunctions32[10 | 0x0400] = handlerCommand32Code000AP66;
	commandFunctions32[11] = handlerCommand32Code000B;
	commandFunctions32[11 | 0x0400] = handlerCommand32Code000BP66;
	commandFunctions32[12] = handlerCommand32Code000C;
	commandFunctions32[12 | 0x0400] = handlerCommand32Code000CP66;
	commandFunctions32[13] = handlerCommand32Code000D;
	commandFunctions32[13 | 0x0400] = handlerCommand32Code000DP66;
	commandFunctions32[16] = handlerCommand32Code0010;
	commandFunctions32[16 | 0x0400] = handlerCommand32Code0010P66;
	commandFunctions32[17] = handlerCommand32Code0011;
	commandFunctions32[17 | 0x0400] = handlerCommand32Code0011P66;
	commandFunctions32[18] = handlerCommand32Code0012;
	commandFunctions32[18 | 0x0400] = handlerCommand32Code0012P66;
	commandFunctions32[19] = handlerCommand32Code0013;
	commandFunctions32[19 | 0x0400] = handlerCommand32Code0013P66;
	commandFunctions32[20] = handlerCommand32Code0014;
	commandFunctions32[20 | 0x0400] = handlerCommand32Code0014P66;
	commandFunctions32[21] = handlerCommand32Code0015;
	commandFunctions32[21 | 0x0400] = handlerCommand32Code0015P66;
	commandFunctions32[24] = handlerCommand32Code0018;
	commandFunctions32[24 | 0x0400] = handlerCommand32Code0018P66;
	commandFunctions32[25] = handlerCommand32Code0019;
	commandFunctions32[25 | 0x0400] = handlerCommand32Code0019P66;
	commandFunctions32[26] = handlerCommand32Code001A;
	commandFunctions32[26 | 0x0400] = handlerCommand32Code001AP66;
	commandFunctions32[27] = handlerCommand32Code001B;
	commandFunctions32[27 | 0x0400] = handlerCommand32Code001BP66;
	commandFunctions32[28] = handlerCommand32Code001C;
	commandFunctions32[28 | 0x0400] = handlerCommand32Code001CP66;
	commandFunctions32[29] = handlerCommand32Code001D;
	commandFunctions32[29 | 0x0400] = handlerCommand32Code001DP66;
	commandFunctions32[32] = handlerCommand32Code0020;
	commandFunctions32[32 | 0x0400] = handlerCommand32Code0020P66;
	commandFunctions32[33] = handlerCommand32Code0021;
	commandFunctions32[33 | 0x0400] = handlerCommand32Code0021P66;
	commandFunctions32[34] = handlerCommand32Code0022;
	commandFunctions32[34 | 0x0400] = handlerCommand32Code0022P66;
	commandFunctions32[35] = handlerCommand32Code0023;
	commandFunctions32[35 | 0x0400] = handlerCommand32Code0023P66;
	commandFunctions32[36] = handlerCommand32Code0024;
	commandFunctions32[36 | 0x0400] = handlerCommand32Code0024P66;
	commandFunctions32[37] = handlerCommand32Code0025;
	commandFunctions32[37 | 0x0400] = handlerCommand32Code0025P66;
	commandFunctions32[40] = handlerCommand32Code0028;
	commandFunctions32[40 | 0x0400] = handlerCommand32Code0028P66;
	commandFunctions32[41] = handlerCommand32Code0029;
	commandFunctions32[41 | 0x0400] = handlerCommand32Code0029P66;
	commandFunctions32[42] = handlerCommand32Code002A;
	commandFunctions32[42 | 0x0400] = handlerCommand32Code002AP66;
	commandFunctions32[43] = handlerCommand32Code002B;
	commandFunctions32[43 | 0x0400] = handlerCommand32Code002BP66;
	commandFunctions32[44] = handlerCommand32Code002C;
	commandFunctions32[44 | 0x0400] = handlerCommand32Code002CP66;
	commandFunctions32[45] = handlerCommand32Code002D;
	commandFunctions32[45 | 0x0400] = handlerCommand32Code002DP66;
	commandFunctions32[48] = handlerCommand32Code0030;
	commandFunctions32[48 | 0x0400] = handlerCommand32Code0030P66;
	commandFunctions32[49] = handlerCommand32Code0031;
	commandFunctions32[49 | 0x0400] = handlerCommand32Code0031P66;
	commandFunctions32[50] = handlerCommand32Code0032;
	commandFunctions32[50 | 0x0400] = handlerCommand32Code0032P66;
	commandFunctions32[51] = handlerCommand32Code0033;
	commandFunctions32[51 | 0x0400] = handlerCommand32Code0033P66;
	commandFunctions32[52] = handlerCommand32Code0034;
	commandFunctions32[52 | 0x0400] = handlerCommand32Code0034P66;
	commandFunctions32[53] = handlerCommand32Code0035;
	commandFunctions32[53 | 0x0400] = handlerCommand32Code0035P66;
	commandFunctions32[56] = handlerCommand32Code0038;
	commandFunctions32[56 | 0x0400] = handlerCommand32Code0038P66;
	commandFunctions32[57] = handlerCommand32Code0039;
	commandFunctions32[57 | 0x0400] = handlerCommand32Code0039P66;
	commandFunctions32[58] = handlerCommand32Code003A;
	commandFunctions32[58 | 0x0400] = handlerCommand32Code003AP66;
	commandFunctions32[59] = handlerCommand32Code003B;
	commandFunctions32[59 | 0x0400] = handlerCommand32Code003BP66;
	commandFunctions32[60] = handlerCommand32Code003C;
	commandFunctions32[60 | 0x0400] = handlerCommand32Code003CP66;
	commandFunctions32[61] = handlerCommand32Code003D;
	commandFunctions32[61 | 0x0400] = handlerCommand32Code003DP66;
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
	commandFunctions32[96] = handlerCommand32Code0060;
	commandFunctions32[96 | 0x0400] = handlerCommand32Code0060P66;
	commandFunctions32[97] = handlerCommand32Code0061;
	commandFunctions32[97 | 0x0400] = handlerCommand32Code0061P66;
	commandFunctions32[104] = handlerCommand32Code0068;
	commandFunctions32[104 | 0x0200 ] = handlerCommand32Code0068P67;
	commandFunctions32[104 | 0x0400] = handlerCommand32Code0068P66;
	commandFunctions32[104 | 0x0200 | 0x0400] = handlerCommand32Code0068P66P67;
	commandFunctions32[105] = handlerCommand32Code0069;
	commandFunctions32[105 | 0x0400] = handlerCommand32Code0069P66;
	commandFunctions32[106] = handlerCommand32Code006A;
	commandFunctions32[106 | 0x0200 ] = handlerCommand32Code006AP67;
	commandFunctions32[106 | 0x0400] = handlerCommand32Code006AP66;
	commandFunctions32[106 | 0x0200 | 0x0400] = handlerCommand32Code006AP66P67;
	commandFunctions32[107] = handlerCommand32Code006B;
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
	commandFunctions32[128] = handlerCommand32Code0080;
	commandFunctions32[128 | 0x0400] = handlerCommand32Code0080P66;
	commandFunctions32[129] = handlerCommand32Code0081;
	commandFunctions32[129 | 0x0400] = handlerCommand32Code0081P66;
	commandFunctions32[130] = handlerCommand32Code0082;
	commandFunctions32[131] = handlerCommand32Code0083;
	commandFunctions32[132] = handlerCommand32Code0084;
	commandFunctions32[132 | 0x0400] = handlerCommand32Code0084P66;
	commandFunctions32[133] = handlerCommand32Code0085;
	commandFunctions32[133 | 0x0400] = handlerCommand32Code0085P66;
	commandFunctions32[134] = handlerCommand32Code0086;
	commandFunctions32[134 | 0x0400] = handlerCommand32Code0086P66;
	commandFunctions32[135] = handlerCommand32Code0087;
	commandFunctions32[135 | 0x0400] = handlerCommand32Code0087P66;
	commandFunctions32[136] = handlerCommand32Code0088;
	commandFunctions32[136 | 0x0400] = handlerCommand32Code0088P66;
	commandFunctions32[137] = handlerCommand32Code0089;
	commandFunctions32[137 | 0x0400] = handlerCommand32Code0089P66;
	commandFunctions32[138] = handlerCommand32Code008A;
	commandFunctions32[138 | 0x0400] = handlerCommand32Code008AP66;
	commandFunctions32[139] = handlerCommand32Code008B;
	commandFunctions32[139 | 0x0400] = handlerCommand32Code008BP66;
	commandFunctions32[140] = handlerCommand32Code008C;
	commandFunctions32[142] = handlerCommand32Code008E;
	commandFunctions32[141] = handlerCommand32Code008D;
	commandFunctions32[141 | 0x0200 ] = handlerCommand32Code008DP67;
	commandFunctions32[141 | 0x0400] = handlerCommand32Code008DP66;
	commandFunctions32[141 | 0x0200 | 0x0400] = handlerCommand32Code008DP66P67;
	commandFunctions32[143] = handlerCommand32Code008F;
	commandFunctions32[143 | 0x0200 ] = handlerCommand32Code008FP67;
	commandFunctions32[143 | 0x0400] = handlerCommand32Code008FP66;
	commandFunctions32[143 | 0x0200 | 0x0400] = handlerCommand32Code008FP66P67;
	commandFunctions32[144] = handlerCommand32Code0090;
	commandFunctions32[144 | 0x0400] = handlerCommand32Code0090P66;
	commandFunctions32[145] = handlerCommand32Code0091;
	commandFunctions32[145 | 0x0400] = handlerCommand32Code0091P66;
	commandFunctions32[146] = handlerCommand32Code0092;
	commandFunctions32[146 | 0x0400] = handlerCommand32Code0092P66;
	commandFunctions32[147] = handlerCommand32Code0093;
	commandFunctions32[147 | 0x0400] = handlerCommand32Code0093P66;
	commandFunctions32[148] = handlerCommand32Code0094;
	commandFunctions32[148 | 0x0400] = handlerCommand32Code0094P66;
	commandFunctions32[149] = handlerCommand32Code0095;
	commandFunctions32[149 | 0x0400] = handlerCommand32Code0095P66;
	commandFunctions32[150] = handlerCommand32Code0096;
	commandFunctions32[150 | 0x0400] = handlerCommand32Code0096P66;
	commandFunctions32[151] = handlerCommand32Code0097;
	commandFunctions32[151 | 0x0400] = handlerCommand32Code0097P66;
	commandFunctions32[152] = handlerCommand32Code0098;
	commandFunctions32[152 | 0x0400] = handlerCommand32Code0098P66;
	commandFunctions32[153] = handlerCommand32Code0099;
	commandFunctions32[153 | 0x0400] = handlerCommand32Code0099P66;
	commandFunctions32[156] = handlerCommand32Code009C;
	commandFunctions32[156 | 0x0400] = handlerCommand32Code009CP66;
	commandFunctions32[157] = handlerCommand32Code009D;
	commandFunctions32[157 | 0x0400] = handlerCommand32Code009DP66;
	commandFunctions32[160] = handlerCommand32Code00A0;
	commandFunctions32[160 | 0x0200 ] = handlerCommand32Code00A0P67;
	commandFunctions32[160 | 0x0400] = handlerCommand32Code00A0P66;
	commandFunctions32[160 | 0x0200 | 0x0400] = handlerCommand32Code00A0P66P67;
	commandFunctions32[161] = handlerCommand32Code00A1;
	commandFunctions32[161 | 0x0200 ] = handlerCommand32Code00A1P67;
	commandFunctions32[161 | 0x0400] = handlerCommand32Code00A1P66;
	commandFunctions32[161 | 0x0200 | 0x0400] = handlerCommand32Code00A1P66P67;
	commandFunctions32[162] = handlerCommand32Code00A2;
	commandFunctions32[162 | 0x0200 ] = handlerCommand32Code00A2P67;
	commandFunctions32[162 | 0x0400] = handlerCommand32Code00A2P66;
	commandFunctions32[162 | 0x0200 | 0x0400] = handlerCommand32Code00A2P66P67;
	commandFunctions32[163] = handlerCommand32Code00A3;
	commandFunctions32[163 | 0x0200 ] = handlerCommand32Code00A3P67;
	commandFunctions32[163 | 0x0400] = handlerCommand32Code00A3P66;
	commandFunctions32[163 | 0x0200 | 0x0400] = handlerCommand32Code00A3P66P67;
	commandFunctions32[164] = handlerCommand32Code00A4;
	commandFunctions32[164 | 0x0200 ] = handlerCommand32Code00A4P67;
	commandFunctions32[164 | 0x0400] = handlerCommand32Code00A4P66;
	commandFunctions32[164 | 0x0200 | 0x0400] = handlerCommand32Code00A4P66P67;
	commandFunctions32[165] = handlerCommand32Code00A5;
	commandFunctions32[165 | 0x0200 ] = handlerCommand32Code00A5P67;
	commandFunctions32[165 | 0x0400] = handlerCommand32Code00A5P66;
	commandFunctions32[165 | 0x0200 | 0x0400] = handlerCommand32Code00A5P66P67;
	commandFunctions32[166] = handlerCommand32Code00A6;
	commandFunctions32[166 | 0x0200 ] = handlerCommand32Code00A6P67;
	commandFunctions32[166 | 0x0400] = handlerCommand32Code00A6P66;
	commandFunctions32[166 | 0x0200 | 0x0400] = handlerCommand32Code00A6P66P67;
	commandFunctions32[167] = handlerCommand32Code00A7;
	commandFunctions32[167 | 0x0200 ] = handlerCommand32Code00A7P67;
	commandFunctions32[167 | 0x0400] = handlerCommand32Code00A7P66;
	commandFunctions32[167 | 0x0200 | 0x0400] = handlerCommand32Code00A7P66P67;
	commandFunctions32[168] = handlerCommand32Code00A8;
	commandFunctions32[168 | 0x0400] = handlerCommand32Code00A8P66;
	commandFunctions32[169] = handlerCommand32Code00A9;
	commandFunctions32[169 | 0x0400] = handlerCommand32Code00A9P66;
	commandFunctions32[170] = handlerCommand32Code00AA;
	commandFunctions32[170 | 0x0200 ] = handlerCommand32Code00AAP67;
	commandFunctions32[170 | 0x0400] = handlerCommand32Code00AAP66;
	commandFunctions32[170 | 0x0200 | 0x0400] = handlerCommand32Code00AAP66P67;
	commandFunctions32[171] = handlerCommand32Code00AB;
	commandFunctions32[171 | 0x0200 ] = handlerCommand32Code00ABP67;
	commandFunctions32[171 | 0x0400] = handlerCommand32Code00ABP66;
	commandFunctions32[171 | 0x0200 | 0x0400] = handlerCommand32Code00ABP66P67;
	commandFunctions32[172] = handlerCommand32Code00AC;
	commandFunctions32[172 | 0x0200 ] = handlerCommand32Code00ACP67;
	commandFunctions32[172 | 0x0400] = handlerCommand32Code00ACP66;
	commandFunctions32[172 | 0x0200 | 0x0400] = handlerCommand32Code00ACP66P67;
	commandFunctions32[173] = handlerCommand32Code00AD;
	commandFunctions32[173 | 0x0200 ] = handlerCommand32Code00ADP67;
	commandFunctions32[173 | 0x0400] = handlerCommand32Code00ADP66;
	commandFunctions32[173 | 0x0200 | 0x0400] = handlerCommand32Code00ADP66P67;
	commandFunctions32[174] = handlerCommand32Code00AE;
	commandFunctions32[174 | 0x0200 ] = handlerCommand32Code00AEP67;
	commandFunctions32[174 | 0x0400] = handlerCommand32Code00AEP66;
	commandFunctions32[174 | 0x0200 | 0x0400] = handlerCommand32Code00AEP66P67;
	commandFunctions32[175] = handlerCommand32Code00AF;
	commandFunctions32[175 | 0x0200 ] = handlerCommand32Code00AFP67;
	commandFunctions32[175 | 0x0400] = handlerCommand32Code00AFP66;
	commandFunctions32[175 | 0x0200 | 0x0400] = handlerCommand32Code00AFP66P67;
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
	commandFunctions32[192] = handlerCommand32Code00C0;
	commandFunctions32[192 | 0x0400] = handlerCommand32Code00C0P66;
	commandFunctions32[193] = handlerCommand32Code00C1;
	commandFunctions32[193 | 0x0400] = handlerCommand32Code00C1P66;
	commandFunctions32[195] = handlerCommand32Code00C3;
	commandFunctions32[196] = handlerCommand32Code00C4;
	commandFunctions32[197] = handlerCommand32Code00C5;
	commandFunctions32[198] = handlerCommand32Code00C6;
	commandFunctions32[198 | 0x0400] = handlerCommand32Code00C6P66;
	commandFunctions32[199] = handlerCommand32Code00C7;
	commandFunctions32[199 | 0x0400] = handlerCommand32Code00C7P66;
	commandFunctions32[200] = handlerCommand32Code00C8;
	commandFunctions32[200 | 0x0200 ] = handlerCommand32Code00C8P67;
	commandFunctions32[200 | 0x0400] = handlerCommand32Code00C8P66;
	commandFunctions32[200 | 0x0200 | 0x0400] = handlerCommand32Code00C8P66P67;
	commandFunctions32[201] = handlerCommand32Code00C9;
	commandFunctions32[201 | 0x0200 ] = handlerCommand32Code00C9P67;
	commandFunctions32[201 | 0x0400] = handlerCommand32Code00C9P66;
	commandFunctions32[201 | 0x0200 | 0x0400] = handlerCommand32Code00C9P66P67;
	commandFunctions32[203] = handlerCommand32Code00CB;
	commandFunctions32[205] = handlerCommand32Code00CD;
	commandFunctions32[208] = handlerCommand32Code00D0;
	commandFunctions32[208 | 0x0400] = handlerCommand32Code00D0P66;
	commandFunctions32[209] = handlerCommand32Code00D1;
	commandFunctions32[209 | 0x0400] = handlerCommand32Code00D1P66;
	commandFunctions32[210] = handlerCommand32Code00D2;
	commandFunctions32[210 | 0x0400] = handlerCommand32Code00D2P66;
	commandFunctions32[211] = handlerCommand32Code00D3;
	commandFunctions32[211 | 0x0400] = handlerCommand32Code00D3P66;
	commandFunctions32[216] = handlerCommand32Code00D8;
	commandFunctions32[217] = handlerCommand32Code00D9;
	commandFunctions32[218] = handlerCommand32Code00DA;
	commandFunctions32[219] = handlerCommand32Code00DB;
	commandFunctions32[220] = handlerCommand32Code00DC;
	commandFunctions32[221] = handlerCommand32Code00DD;
	commandFunctions32[222] = handlerCommand32Code00DE;
	commandFunctions32[223] = handlerCommand32Code00DF;
	commandFunctions32[224] = handlerCommand32Code00E0;
	commandFunctions32[225] = handlerCommand32Code00E1;
	commandFunctions32[226] = handlerCommand32Code00E2;
	commandFunctions32[227] = handlerCommand32Code00E3;
	commandFunctions32[232] = handlerCommand32Code00E8;
	commandFunctions32[232 | 0x0400] = handlerCommand32Code00E8P66;
	commandFunctions32[233] = handlerCommand32Code00E9;
	commandFunctions32[233 | 0x0400] = handlerCommand32Code00E9P66;
	commandFunctions32[235] = handlerCommand32Code00EB;
	commandFunctions32[245] = handlerCommand32Code00F5;
	commandFunctions32[246] = handlerCommand32Code00F6;
	commandFunctions32[246 | 0x0400] = handlerCommand32Code00F6P66;
	commandFunctions32[247] = handlerCommand32Code00F7;
	commandFunctions32[247 | 0x0400] = handlerCommand32Code00F7P66;
	commandFunctions32[248] = handlerCommand32Code00F8;
	commandFunctions32[249] = handlerCommand32Code00F9;
	commandFunctions32[250] = handlerCommand32Code00FA;
	commandFunctions32[251] = handlerCommand32Code00FB;
	commandFunctions32[252] = handlerCommand32Code00FC;
	commandFunctions32[253] = handlerCommand32Code00FD;
	commandFunctions32[255] = handlerCommand32Code00FF;
	commandFunctions32[255 | 0x0200 ] = handlerCommand32Code00FFP67;
	commandFunctions32[255 | 0x0400] = handlerCommand32Code00FFP66;
	commandFunctions32[255 | 0x0200 | 0x0400] = handlerCommand32Code00FFP66P67;
	commandFunctions32[257] = handlerCommand32Code0101;
	commandFunctions32[384] = handlerCommand32Code0180;
	commandFunctions32[385] = handlerCommand32Code0181;
	commandFunctions32[386] = handlerCommand32Code0182;
	commandFunctions32[387] = handlerCommand32Code0183;
	commandFunctions32[388] = handlerCommand32Code0184;
	commandFunctions32[389] = handlerCommand32Code0185;
	commandFunctions32[390] = handlerCommand32Code0186;
	commandFunctions32[391] = handlerCommand32Code0187;
	commandFunctions32[392] = handlerCommand32Code0188;
	commandFunctions32[393] = handlerCommand32Code0189;
	commandFunctions32[394] = handlerCommand32Code018A;
	commandFunctions32[395] = handlerCommand32Code018B;
	commandFunctions32[396] = handlerCommand32Code018C;
	commandFunctions32[397] = handlerCommand32Code018D;
	commandFunctions32[398] = handlerCommand32Code018E;
	commandFunctions32[399] = handlerCommand32Code018F;
	commandFunctions32[400] = handlerCommand32Code0190;
	commandFunctions32[400 | 0x0400] = handlerCommand32Code0190P66;
	commandFunctions32[401] = handlerCommand32Code0191;
	commandFunctions32[401 | 0x0400] = handlerCommand32Code0191P66;
	commandFunctions32[402] = handlerCommand32Code0192;
	commandFunctions32[402 | 0x0400] = handlerCommand32Code0192P66;
	commandFunctions32[403] = handlerCommand32Code0193;
	commandFunctions32[403 | 0x0400] = handlerCommand32Code0193P66;
	commandFunctions32[404] = handlerCommand32Code0194;
	commandFunctions32[404 | 0x0400] = handlerCommand32Code0194P66;
	commandFunctions32[405] = handlerCommand32Code0195;
	commandFunctions32[405 | 0x0400] = handlerCommand32Code0195P66;
	commandFunctions32[406] = handlerCommand32Code0196;
	commandFunctions32[406 | 0x0400] = handlerCommand32Code0196P66;
	commandFunctions32[407] = handlerCommand32Code0197;
	commandFunctions32[407 | 0x0400] = handlerCommand32Code0197P66;
	commandFunctions32[408] = handlerCommand32Code0198;
	commandFunctions32[408 | 0x0400] = handlerCommand32Code0198P66;
	commandFunctions32[409] = handlerCommand32Code0199;
	commandFunctions32[409 | 0x0400] = handlerCommand32Code0199P66;
	commandFunctions32[410] = handlerCommand32Code019A;
	commandFunctions32[410 | 0x0400] = handlerCommand32Code019AP66;
	commandFunctions32[411] = handlerCommand32Code019B;
	commandFunctions32[411 | 0x0400] = handlerCommand32Code019BP66;
	commandFunctions32[412] = handlerCommand32Code019C;
	commandFunctions32[412 | 0x0400] = handlerCommand32Code019CP66;
	commandFunctions32[413] = handlerCommand32Code019D;
	commandFunctions32[413 | 0x0400] = handlerCommand32Code019DP66;
	commandFunctions32[414] = handlerCommand32Code019E;
	commandFunctions32[414 | 0x0400] = handlerCommand32Code019EP66;
	commandFunctions32[415] = handlerCommand32Code019F;
	commandFunctions32[415 | 0x0400] = handlerCommand32Code019FP66;
	commandFunctions32[419] = handlerCommand32Code01A3;
	commandFunctions32[419 | 0x0400] = handlerCommand32Code01A3P66;
	commandFunctions32[427] = handlerCommand32Code01AB;
	commandFunctions32[427 | 0x0400] = handlerCommand32Code01ABP66;
	commandFunctions32[431] = handlerCommand32Code01AF;
	commandFunctions32[431 | 0x0400] = handlerCommand32Code01AFP66;
	commandFunctions32[434] = handlerCommand32Code01B2;
	commandFunctions32[435] = handlerCommand32Code01B3;
	commandFunctions32[435 | 0x0400] = handlerCommand32Code01B3P66;
	commandFunctions32[436] = handlerCommand32Code01B4;
	commandFunctions32[437] = handlerCommand32Code01B5;
	commandFunctions32[438] = handlerCommand32Code01B6;
	commandFunctions32[439] = handlerCommand32Code01B7;
	commandFunctions32[442] = handlerCommand32Code01BA;
	commandFunctions32[442 | 0x0400] = handlerCommand32Code01BAP66;
	commandFunctions32[443] = handlerCommand32Code01BB;
	commandFunctions32[443 | 0x0400] = handlerCommand32Code01BBP66;
	commandFunctions32[444] = handlerCommand32Code01BC;
	commandFunctions32[444 | 0x0400] = handlerCommand32Code01BCP66;
	commandFunctions32[445] = handlerCommand32Code01BD;
	commandFunctions32[445 | 0x0400] = handlerCommand32Code01BDP66;
	commandFunctions32[446] = handlerCommand32Code01BE;
	commandFunctions32[447] = handlerCommand32Code01BF;
	commandFunctions32[456] = handlerCommand32Code01C8;
	commandFunctions32[457] = handlerCommand32Code01C9;
	commandFunctions32[458] = handlerCommand32Code01CA;
	commandFunctions32[459] = handlerCommand32Code01CB;
	commandFunctions32[460] = handlerCommand32Code01CC;
	commandFunctions32[461] = handlerCommand32Code01CD;
	commandFunctions32[462] = handlerCommand32Code01CE;
	commandFunctions32[463] = handlerCommand32Code01CF;
}
