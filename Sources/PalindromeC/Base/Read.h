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
#include "Registers.h"
#include "../Support/Log.h"
#include "../Memory/RealMemoryManager.h"

int8_t read8();
uint8_t read8u();
int16_t read16();
uint16_t read16u();
int32_t read32();
uint32_t read32u();

#define readFirst2Bit(byte) ((byte >> 6) & 0x03)
#define readMiddle3Bit(byte) ((byte >> 3) & 0x07)
#define readLast3Bit(byte) (byte & 0x07)

#define SR_VALUE(SR) (context.segmentRegisters[SR])

#define mem(reg) (GET_REAL_MOD_MEMORY_POINTER(SR_VALUE(reg)))
#define memWithReplace(reg) ((context.lastCommandInfo.prefixInfo.hasSegmentPrefix) ? mem(context.lastCommandInfo.prefixInfo.changeSegmentPrefix) : mem(reg))

#define setMem(reg, mem) { context.segmentRegisters[reg] = mem; }

#define readRegisterMRM8(mrmByte) register8(readMiddle3Bit(mrmByte))
#define readRegisterMRM16(mrmByte) register16(readMiddle3Bit(mrmByte))
#define readRegisterMRM32(mrmByte) register32(readMiddle3Bit(mrmByte))

#define readSegmentRegisterMRM(mrmByte) (context.segmentRegisters + readMiddle3Bit(mrmByte))

void dumpLog(int64_t address, uint8_t* target, int size);

#define DATA_LOG8(address, target) DEBUG_RUN({ dumpLog(address, target, 1); });
#define DATA_LOG16(address, target) DEBUG_RUN({ dumpLog(address, target, 2); });
#define DATA_LOG32(address, target) DEBUG_RUN({ dumpLog(address, target, 4); });

#endif /* Read_h */
