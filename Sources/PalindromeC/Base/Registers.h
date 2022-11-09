//
//  Header.h
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#ifndef Header_h
#define Header_h

#include "Models.h"
#include <stdio.h>

extern uint8_t *regALu;
extern uint8_t *regCLu;
extern uint8_t *regDLu;
extern uint8_t *regBLu;
extern uint8_t *regAHu;
extern uint8_t *regCHu;
extern uint8_t *regDHu;
extern uint8_t *regBHu;

extern uint32_t *regEAXu;
extern uint32_t *regECXu;
extern uint32_t *regEDXu;
extern uint32_t *regEBXu;
extern uint32_t *regESPu;
extern uint32_t *regEBPu;
extern uint32_t *regESIu;
extern uint32_t *regEDIu;

extern uint16_t *regAXu;
extern uint16_t *regCXu;
extern uint16_t *regDXu;
extern uint16_t *regBXu;
extern uint16_t *regSPu;
extern uint16_t *regBPu;
extern uint16_t *regSIu;
extern uint16_t *regDIu;

extern int8_t *regAL;
extern int8_t *regCL;
extern int8_t *regDL;
extern int8_t *regBL;
extern int8_t *regAH;
extern int8_t *regCH;
extern int8_t *regDH;
extern int8_t *regBH;

extern int32_t *regEAX;
extern int32_t *regECX;
extern int32_t *regEDX;
extern int32_t *regEBX;
extern int32_t *regESP;
extern int32_t *regEBP;
extern int32_t *regESI;
extern int32_t *regEDI;

extern int16_t *regAX;
extern int16_t *regCX;
extern int16_t *regDX;
extern int16_t *regBX;
extern int16_t *regSP;
extern int16_t *regBP;
extern int16_t *regSI;
extern int16_t *regDI;

#define reg_0x00_32u (*regEAXu)
#define reg_0x01_32u (*regECXu)
#define reg_0x02_32u (*regEDXu)
#define reg_0x03_32u (*regEBXu)
#define reg_0x04_32u (*regESPu)
#define reg_0x05_32u (*regEBPu)
#define reg_0x06_32u (*regESIu)
#define reg_0x07_32u (*regEDIu)

#define reg_0x00_32 (*regEAX)
#define reg_0x01_32 (*regECX)
#define reg_0x02_32 (*regEDX)
#define reg_0x03_32 (*regEBX)
#define reg_0x04_32 (*regESP)
#define reg_0x05_32 (*regEBP)
#define reg_0x06_32 (*regESI)
#define reg_0x07_32 (*regEDI)

#define reg_0x00_16u (*regAXu)
#define reg_0x01_16u (*regCXu)
#define reg_0x02_16u (*regDXu)
#define reg_0x03_16u (*regBXu)
#define reg_0x04_16u (*regSPu)
#define reg_0x05_16u (*regBPu)
#define reg_0x06_16u (*regSIu)
#define reg_0x07_16u (*regDIu)

#define reg_0x00_16 (*regAX)
#define reg_0x01_16 (*regCX)
#define reg_0x02_16 (*regDX)
#define reg_0x03_16 (*regBX)
#define reg_0x04_16 (*regSP)
#define reg_0x05_16 (*regBP)
#define reg_0x06_16 (*regSI)
#define reg_0x07_16 (*regDI)

#define reg_0x00_8u (*regALu)
#define reg_0x01_8u (*regCLu)
#define reg_0x02_8u (*regDLu)
#define reg_0x03_8u (*regBLu)
#define reg_0x04_8u (*regAHu)
#define reg_0x05_8u (*regCHu)
#define reg_0x06_8u (*regDHu)
#define reg_0x07_8u (*regBHu)

#define reg_0x00_8 (*regAL)
#define reg_0x01_8 (*regCL)
#define reg_0x02_8 (*regDL)
#define reg_0x03_8 (*regBL)
#define reg_0x04_8 (*regAH)
#define reg_0x05_8 (*regCH)
#define reg_0x06_8 (*regDH)
#define reg_0x07_8 (*regBH)

#define reg_AX_16u (*regAXu)
#define reg_CX_16u (*regCXu)
#define reg_DX_16u (*regDXu)
#define reg_BX_16u (*regBXu)
#define reg_SP_16u (*regSPu)
#define reg_BP_16u (*regBPu)
#define reg_SI_16u (*regSIu)
#define reg_DI_16u (*regDIu)

#define reg_AX_16 (*regAX)
#define reg_CX_16 (*regCX)
#define reg_DX_16 (*regDX)
#define reg_BX_16 (*regBX)
#define reg_SP_16 (*regSP)
#define reg_BP_16 (*regBP)
#define reg_SI_16 (*regSI)
#define reg_DI_16 (*regDI)

#define reg_AX_32u (*regEAXu)
#define reg_CX_32u (*regECXu)
#define reg_DX_32u (*regEDXu)
#define reg_BX_32u (*regEBXu)
#define reg_SP_32u (*regESPu)
#define reg_BP_32u (*regEBPu)
#define reg_SI_32u (*regESIu)
#define reg_DI_32u (*regEDIu)

#define reg_AX_32 (*regEAX)
#define reg_CX_32 (*regECX)
#define reg_DX_32 (*regEDX)
#define reg_BX_32 (*regEBX)
#define reg_SP_32 (*regESP)
#define reg_BP_32 (*regEBP)
#define reg_SI_32 (*regESI)
#define reg_DI_32 (*regEDI)

#define reg_AL_8 (*regAL)
#define reg_CL_8 (*regCL)
#define reg_DL_8 (*regDL)
#define reg_BL_8 (*regBL)
#define reg_AH_8 (*regAH)
#define reg_CH_8 (*regCH)
#define reg_DH_8 (*regDH)
#define reg_BH_8 (*regBH)

#define reg_AL_8u (*regALu)
#define reg_CL_8u (*regCLu)
#define reg_DL_8u (*regDLu)
#define reg_BL_8u (*regBLu)
#define reg_AH_8u (*regAHu)
#define reg_CH_8u (*regCHu)
#define reg_DH_8u (*regDHu)
#define reg_BH_8u (*regBHu)

#define BR_EAX_F (0x00)
#define BR_ECX_F (0x01)
#define BR_EDX_F (0x02)
#define BR_EBX_F (0x03)

#define BR_ESP_F (0x04)
#define BR_EBP_F (0x05)
#define BR_ESI_F (0x06)
#define BR_EDI_F (0x07)

#define BR_EAX_F (0x00)
#define BR_ECX_F (0x01)
#define BR_EDX_F (0x02)
#define BR_EBX_F (0x03)

#define BR_ESP_F (0x04)
#define BR_EBP_F (0x05)
#define BR_ESI_F (0x06)
#define BR_EDI_F (0x07)

#define BR_AX_F (0x00 + 0x0F)
#define BR_CX_F (0x01 + 0x0F)
#define BR_DX_F (0x02 + 0x0F)
#define BR_BX_F (0x03 + 0x0F)
#define BR_SP_F (0x04 + 0x0F)
#define BR_BP_F (0x05 + 0x0F)
#define BR_SI_F (0x06 + 0x0F)
#define BR_DI_F (0x07 + 0x0F)

#define BR_AL_F (0x00 + 0x0F + 0x08)
#define BR_CL_F (0x01 + 0x0F + 0x08)
#define BR_DL_F (0x02 + 0x0F + 0x08)
#define BR_BL_F (0x03 + 0x0F + 0x08)
#define BR_AH_F (0x00 + 0x0F)
#define BR_CH_F (0x01 + 0x0F)
#define BR_DH_F (0x02 + 0x0F)
#define BR_BH_F (0x03 + 0x0F)

#define BR_AX (0x00)
#define BR_CX (0x01)
#define BR_DX (0x02)
#define BR_BX (0x03)

#define BR_SP (0x04)
#define BR_BP (0x05)
#define BR_SI (0x06)
#define BR_DI (0x07)

#define BR_AL (0x00)
#define BR_CL (0x01)
#define BR_DL (0x02)
#define BR_BL (0x03)
#define BR_AH (0x04)
#define BR_CH (0x05)
#define BR_DH (0x06)
#define BR_BH (0x07)

#define SR_ES (0x00)
#define SR_CS (0x01)
#define SR_SS (0x02)
#define SR_DS (0x03)
#define SR_FS (0x04)
#define SR_GS (0x05)

int8_t* register8(uint8_t registerIndex);
int16_t* register16(uint8_t registerIndex);
int32_t* register32(uint8_t registerIndex);
uint8_t* register8u(uint8_t registerIndex);
uint16_t* register16u(uint8_t registerIndex);
uint32_t* register32u(uint8_t registerIndex);

void setRegisterPointers();

#endif /* Header_h */
