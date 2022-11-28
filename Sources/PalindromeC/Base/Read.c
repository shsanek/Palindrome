//
//  Read.c
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#include "Read.h"
#include "Registers.h"
#include "../Support/Log.h"

int8_t read8() {
    int8_t read = *((int8_t*)context.index);
    context.index++;
    DEBUG_RUN({ appendInDebugLineHex((uint8_t*)&read); })
    return read;
}

uint8_t read8u() {
    uint8_t read = *((uint8_t*)context.index);
    context.index++;
    DEBUG_RUN({ appendInDebugLineHex((uint8_t*)&read); })
    return read;
}

int16_t read16() {
    int16_t read = *((int16_t*)context.index);
    context.index += 2;
    DEBUG_RUN({ appendInDebugLineHex(((uint8_t*)&read) ); })
    DEBUG_RUN({ appendInDebugLineHex(((uint8_t*)&read) + 1); })
    return read;
}

uint16_t read16u() {
    uint16_t read = *((uint16_t*)context.index);
    context.index += 2;
    DEBUG_RUN({ appendInDebugLineHex(((uint8_t*)&read) ); })
    DEBUG_RUN({ appendInDebugLineHex(((uint8_t*)&read) + 1); })
    return read;
}

int32_t read32() {
    int32_t read = *((int32_t*)context.index);
    context.index += 4;
    DEBUG_RUN({ appendInDebugLineHex(((uint8_t*)&read) ); })
    DEBUG_RUN({ appendInDebugLineHex(((uint8_t*)&read) + 1); })
    DEBUG_RUN({ appendInDebugLineHex(((uint8_t*)&read) + 2); })
    DEBUG_RUN({ appendInDebugLineHex(((uint8_t*)&read) + 3); })
    return read;
}

uint32_t read32u() {
    uint32_t read = *((uint32_t*)context.index);
    context.index += 4;
    DEBUG_RUN({ appendInDebugLineHex(((uint8_t*)&read) ); })
    DEBUG_RUN({ appendInDebugLineHex(((uint8_t*)&read) + 1); })
    DEBUG_RUN({ appendInDebugLineHex(((uint8_t*)&read) + 2); })
    DEBUG_RUN({ appendInDebugLineHex(((uint8_t*)&read) + 3); })
    return read;
}

uint16_t debugSegmentShift = 0;

#define DEBUG_SEGEMTN_SHIFT - debugSegmentShift

uint8_t* mem(uint8_t reg) {
    return context.program + (context.segmentRegisters[reg] DEBUG_SEGEMTN_SHIFT) * 16;
}

uint8_t* memWithReplace(uint8_t reg) {
    return (context.lastCommandInfo.prefixInfo.changeSegmentPrefix != NULL) ? context.lastCommandInfo.prefixInfo.changeSegmentPrefix: mem(reg);
}

void setMem(uint8_t reg, uint16_t mem) {
    context.segmentRegisters[reg] = mem;
}

int8_t* readRegisterMRM8(uint8_t mrmByte) {
    return register8(readMiddle3Bit(mrmByte));
}

int16_t* readRegisterMRM16(uint8_t mrmByte) {
    return register16(readMiddle3Bit(mrmByte));
}

int32_t* readRegisterMRM32(uint8_t mrmByte) {
    return register32(readMiddle3Bit(mrmByte));
}

uint16_t* readSegmentRegisterMRM(uint8_t mrmByte) {
    return context.segmentRegisters + readMiddle3Bit(mrmByte);
}
