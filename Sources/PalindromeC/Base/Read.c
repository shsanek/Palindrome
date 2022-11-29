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

void dumpLog(int32_t address, uint8_t* target, int size) {
    printf("[");
    printHexWithSize((uint8_t*)&address, 4);
    printf(":");
    printHexWithSize(target, size);
    printf("]");
}

uint16_t debugSegmentShift = 0;
