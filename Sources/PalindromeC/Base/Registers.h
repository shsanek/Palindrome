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

#endif /* Header_h */
