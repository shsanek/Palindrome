//
//  LogRegisters.c
//  
//
//  Created by Alex Shipin on 11/26/22.
//

#include "LogRegisters.h"

#include "../Base/Registers.h"
#include "../Base/Read.h"
#include <stdlib.h>

#define GET_BYTE(value, index) (((uint8_t*)(&reg)) + index)

void printRegister16(char *s, uint16_t reg, char* out) {
    sprintf(out, "%s=", s);
    sprintHex(GET_BYTE(reg, 1), out + 3);
    sprintHex(GET_BYTE(reg, 0), out + 5);
}

char* print16Registers() {
    char *out = malloc(REG16_PRINT_SIZE + 1);

    printRegister16("AX", *regAXu, out + 9 * 0); sprintf(out + 9 * 0 + 7, "  ");
    printRegister16("BX", *regBXu, out + 9 * 1); sprintf(out + 9 * 1 + 7, "  ");
    printRegister16("CX", *regCXu, out + 9 * 2); sprintf(out + 9 * 2 + 7, "  ");
    printRegister16("DX", *regDXu, out + 9 * 3); sprintf(out + 9 * 3 + 7, "  ");
    printRegister16("SP", *regSPu, out + 9 * 4); sprintf(out + 9 * 4 + 7, "  ");
    printRegister16("BP", *regBPu, out + 9 * 5); sprintf(out + 9 * 5 + 7, "  ");
    printRegister16("SI", *regSIu, out + 9 * 6); sprintf(out + 9 * 6 + 7, "  ");
    printRegister16("DI", *regDIu, out + 9 * 7); sprintf(out + 9 * 7 + 7, " \n");

    printRegister16("DS", context.segmentRegisters[SR_DS], out + 9 * 8); sprintf(out + 9 * 8 + 7, "  ");
    printRegister16("ES", context.segmentRegisters[SR_ES], out + 9 * 9); sprintf(out + 9 * 9 + 7, "  ");
    printRegister16("SS", context.segmentRegisters[SR_SS], out + 9 * 10); sprintf(out + 9 * 10 + 7, "  ");
    printRegister16("CS", context.segmentRegisters[SR_CS], out + 9 * 11); sprintf(out + 9 * 11 + 7, "  ");
    printRegister16("IP", (uint16_t)(context.index - mem(SR_CS)), out + 9 * 12); sprintf(out + 9 * 12 + 7, " \n");

    out[REG16_PRINT_SIZE] = 0;

    return out;
}

void printRegister32(char *s, uint16_t reg, char* out) {
    sprintf(out, "E%s=", s);
    sprintHex(GET_BYTE(reg, 3), out + 4);
    sprintHex(GET_BYTE(reg, 2), out + 6);
    sprintHex(GET_BYTE(reg, 1), out + 8);
    sprintHex(GET_BYTE(reg, 0), out + 10);
}

char* print32Registers() {
    char *out = malloc(REG32_PRINT_SIZE + 1);

    printRegister32("AX", *regEAXu, out + 14 * 0); sprintf(out + 14 * 0 + 12, "  ");
    printRegister32("BX", *regEBXu, out + 14 * 1); sprintf(out + 14 * 1 + 12, "  ");
    printRegister32("CX", *regECXu, out + 14 * 2); sprintf(out + 14 * 2 + 12, "  ");
    printRegister32("DX", *regEDXu, out + 14 * 3); sprintf(out + 14 * 3 + 12, "  ");
    printRegister32("SP", *regESPu, out + 14 * 4); sprintf(out + 14 * 4 + 12, "  ");
    printRegister32("BP", *regEBPu, out + 14 * 5); sprintf(out + 14 * 5 + 12, "  ");
    printRegister32("SI", *regESIu, out + 14 * 6); sprintf(out + 14 * 6 + 12, "  ");
    printRegister32("DI", *regEDIu, out + 14 * 7); sprintf(out + 14 * 7 + 12, " \n");

    printRegister32("DS", context.segmentRegisters[SR_DS], out + 14 * 8); sprintf(out + 14 * 8 + 12, "  ");
    printRegister32("ES", context.segmentRegisters[SR_ES], out + 14 * 9); sprintf(out + 14 * 9 + 12, "  ");
    printRegister32("SS", context.segmentRegisters[SR_SS], out + 14 * 10); sprintf(out + 14 * 10 + 12, "  ");
    printRegister32("CS", context.segmentRegisters[SR_CS], out + 14 * 11); sprintf(out + 14 * 11 + 12, "  ");
    printRegister32("IP", (uint32_t)(context.index - mem(SR_CS)), out + 14 * 12); sprintf(out + 14 * 12 + 12, " \n");

    out[REG32_PRINT_SIZE] = 0;

    return out;
}
