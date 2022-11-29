//
//  Read.h
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#ifndef Read_h
#define Read_h

#include <stdio.h>
#include "Models.h"
#include "Read.h"

int8_t read8();
uint8_t read8u();
int16_t read16();
uint16_t read16u();
int32_t read32();
uint32_t read32u();

extern uint16_t debugSegmentShift;

#define DEBUG_SEGEMTN_SHIFT -debugSegmentShift

#define readFirst2Bit(byte) ((byte >> 6) & 0x03)
#define readMiddle3Bit(byte) ((byte >> 3) & 0x07)
#define readLast3Bit(byte) (byte & 0x07)

#define mem(reg) (context.program + (context.segmentRegisters[reg] DEBUG_SEGEMTN_SHIFT) * 16)
#define memWithReplace(reg) ((context.lastCommandInfo.prefixInfo.changeSegmentPrefix != NULL) ? context.lastCommandInfo.prefixInfo.changeSegmentPrefix: mem(reg))

#define setMem(reg, mem) { context.segmentRegisters[reg] = mem; }

#define readRegisterMRM8(mrmByte) register8(readMiddle3Bit(mrmByte))
#define readRegisterMRM16(mrmByte) register16(readMiddle3Bit(mrmByte))
#define readRegisterMRM32(mrmByte) register32(readMiddle3Bit(mrmByte))

#define readSegmentRegisterMRM(mrmByte) (context.segmentRegisters + readMiddle3Bit(mrmByte))

#endif /* Read_h */
