//
//  Read.c
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#include "Read.h"

int8_t read8(Context* context) {
    int8_t read = *((int8_t*)context->index);
    context->index++;
    return read;
}

uint8_t read8u(Context* context) {
    uint8_t read = *((uint8_t*)context->index);
    context->index++;
    return read;
}

int16_t read16(Context* context) {
    int16_t read = *((int16_t*)context->index);
    context->index += 2;
    return read;
}

uint16_t read16u(Context* context) {
    uint16_t read = *((uint16_t*)context->index);
    context->index += 2;
    return read;
}

int32_t read32(Context* context) {
    int32_t read = *((int32_t*)context->index);
    context->index += 4;
    return read;
}

uint32_t read32u(Context* context) {
    uint16_t read = *((uint32_t*)context->index);
    context->index += 4;
    return read;
}

uint8_t* mem(Context* context, uint8_t reg) {
    return context->memory + context->segmentRegisters[reg];
}
