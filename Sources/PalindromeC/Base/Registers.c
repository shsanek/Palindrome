//
//  Registers.c
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#include "Registers.h"

uint8_t register8Address(uint8_t registerIndex) {
    uint8_t registerSize = 4;
    uint8_t byteShift = registerSize - 1 - (registerIndex > 3 ? 1 : 0);
    uint8_t byteIndex = registerIndex % 4 * registerSize;
    return byteIndex + byteShift;
}

uint16_t register16Address(uint8_t registerIndex) {
    uint8_t registerSize = 4;
    uint8_t byteShift = registerSize - 2;
    uint8_t byteIndex = registerIndex * registerSize;
    return byteIndex + byteShift;
}

uint32_t register32Address(uint8_t registerIndex) {
    uint8_t registerSize = 4;
    uint8_t byteIndex = registerIndex * registerSize;
    return byteIndex;
}

int8_t* register8(Context* context, uint8_t registerIndex) {
    return (int8_t*)(context->registers + register8Address(registerIndex));
}

int16_t* register16(Context* context, uint8_t registerIndex) {
    return (int16_t*)(context->registers + register16Address(registerIndex));
}

int32_t* register32(Context* context, uint8_t registerIndex) {
    return (int32_t*)(context->registers + register32Address(registerIndex));
}

uint8_t* register8u(Context* context, uint8_t registerIndex) {
    return (uint8_t*)(context->registers + register8Address(registerIndex));
}

uint16_t* register16u(Context* context, uint8_t registerIndex) {
    return (uint16_t*)(context->registers + register16Address(registerIndex));
}

uint32_t* register32u(Context* context, uint8_t registerIndex) {
    return (uint32_t*)(context->registers + register32Address(registerIndex));
}
