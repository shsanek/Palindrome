//
//  Registers.c
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#include "Registers.h"

uint8_t register8Address(uint8_t registerIndex) {
    uint8_t registerSize = 4;
    uint8_t byteShift = (registerIndex > 3 ? 1 : 0);
    uint8_t byteIndex = registerIndex % 4 * registerSize;
    return byteIndex + byteShift;
}

uint16_t register16Address(uint8_t registerIndex) {
    uint8_t registerSize = 4;
    uint8_t byteShift = 0;
    uint8_t byteIndex = registerIndex * registerSize;
    return byteIndex + byteShift;
}

uint32_t register32Address(uint8_t registerIndex) {
    uint8_t registerSize = 4;
    uint8_t byteIndex = registerIndex * registerSize;
    return byteIndex;
}

int8_t* fregister8(uint8_t registerIndex) {
    return (int8_t*)(context.registers + registerIndex % 4 * 4 + (registerIndex > 3 ? 1 : 0));
}

int16_t* fregister16(uint8_t registerIndex) {
    return (int16_t*)(context.registers + registerIndex % 4 * 4 + (registerIndex > 3 ? 1 : 0));
}

int32_t* fregister32(uint8_t registerIndex) {
    return (int32_t*)(context.registers + registerIndex * 4);
}

uint8_t* fregister8u(uint8_t registerIndex) {
    return (uint8_t*)(context.registers + registerIndex * 4);
}

uint16_t* fregister16u(uint8_t registerIndex) {
    return (uint16_t*)(context.registers + registerIndex * 4);
}

uint32_t* fregister32u(uint8_t registerIndex) {
    return (uint32_t*)(context.registers + registerIndex * 4);
}

uint8_t *regALu = NULL;
uint8_t *regCLu = NULL;
uint8_t *regDLu = NULL;
uint8_t *regBLu = NULL;
uint8_t *regAHu = NULL;
uint8_t *regCHu = NULL;
uint8_t *regDHu = NULL;
uint8_t *regBHu = NULL;

uint32_t *regEAXu = NULL;
uint32_t *regECXu = NULL;
uint32_t *regEDXu = NULL;
uint32_t *regEBXu = NULL;
uint32_t *regESPu = NULL;
uint32_t *regEBPu = NULL;
uint32_t *regESIu = NULL;
uint32_t *regEDIu = NULL;

uint16_t *regAXu = NULL;
uint16_t *regCXu = NULL;
uint16_t *regDXu = NULL;
uint16_t *regBXu = NULL;
uint16_t *regSPu = NULL;
uint16_t *regBPu = NULL;
uint16_t *regSIu = NULL;
uint16_t *regDIu = NULL;

int8_t *regAL = NULL;
int8_t *regCL = NULL;
int8_t *regDL = NULL;
int8_t *regBL = NULL;
int8_t *regAH = NULL;
int8_t *regCH = NULL;
int8_t *regDH = NULL;
int8_t *regBH = NULL;

int32_t *regEAX = NULL;
int32_t *regECX = NULL;
int32_t *regEDX = NULL;
int32_t *regEBX = NULL;
int32_t *regESP = NULL;
int32_t *regEBP = NULL;
int32_t *regESI = NULL;
int32_t *regEDI = NULL;

int16_t *regAX = NULL;
int16_t *regCX = NULL;
int16_t *regDX = NULL;
int16_t *regBX = NULL;
int16_t *regSP = NULL;
int16_t *regBP = NULL;
int16_t *regSI = NULL;
int16_t *regDI = NULL;

void setRegisterPointers() {
    regALu = register8u(0x00);
    regCLu = register8u(0x01);
    regDLu = register8u(0x02);
    regBLu = register8u(0x03);
    regAHu = register8u(0x04);
    regCHu = register8u(0x05);
    regDHu = register8u(0x06);
    regBHu = register8u(0x07);

    regAL = register8(0x00);
    regCL = register8(0x01);
    regDL = register8(0x02);
    regBL = register8(0x03);
    regAH = register8(0x04);
    regCH = register8(0x05);
    regDH = register8(0x06);
    regBH = register8(0x07);

    regEAXu = register32u(0x00);
    regECXu = register32u(0x01);
    regEDXu = register32u(0x02);
    regEBXu = register32u(0x03);
    regESPu = register32u(0x04);
    regEBPu = register32u(0x05);
    regESIu = register32u(0x06);
    regEDIu = register32u(0x07);

    regAXu = register16u(0x00);
    regCXu = register16u(0x01);
    regDXu = register16u(0x02);
    regBXu = register16u(0x03);
    regSPu = register16u(0x04);
    regBPu = register16u(0x05);
    regSIu = register16u(0x06);
    regDIu = register16u(0x07);

    regEAX = register32(0x00);
    regECX = register32(0x01);
    regEDX = register32(0x02);
    regEBX = register32(0x03);
    regESP = register32(0x04);
    regEBP = register32(0x05);
    regESI = register32(0x06);
    regEDI = register32(0x07);

    regAX = register16(0x00);
    regCX = register16(0x01);
    regDX = register16(0x02);
    regBX = register16(0x03);
    regSP = register16(0x04);
    regBP = register16(0x05);
    regSI = register16(0x06);
    regDI = register16(0x07);
}
