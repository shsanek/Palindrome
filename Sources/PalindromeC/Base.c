//
//  Base.c
//  
//
//  Created by Alex Shipin on 10/14/22.
//

#include "Base.h"
#include "Base/Models.h"
#include "Base/Read.h"
#include "Base/Registers.h"
#include "Base/MRM.h"
#include "Function/GenerateFunctions.h"
#include <stdlib.h>

uint8_t *debugCommands = NULL;

void clearDebugCommands() {
    if (!debugCommands) {
        debugCommands = malloc(512);
    }
    for (int i = 0; i < 512; i++) {
        debugCommands[i] = 0;
    }
}

#define LOG(F, ARG...) printf( F , ARG )

void getCommand() {
    LOG("%llX:", (uint64_t)(context.index - context.memory));

    uint16_t command = 0;
    uint8_t commandPrefix = 0;
    //Код F0 - префикс блокировки шины, команда LOCK ("lock" - запирать). Этот префикс употребляется только с теми командами, которые поддерживают такую возможность - возможность блокировки шины.
    //
    //Коды F2, F3 - префиксы повторения, команда REP ("repeat" - повторять) и другие команды этой группы. Такие префиксы употребляются только с цепочечными командами. Префиксы группы REP позволяют организовать циклическое выполнение цепочечной команды. Смотрите страницу   Цепочечные команды.
    //
    //Код F1 - нет такого префикса и нет такой команды. Тут следует заметить, что это единственный код для первого байта команды, который все еще остается свободным. Поневоле напрашивается мысль о существовании некоторой недокументированной возможности ...
    if (*(context.index) == 0xF2 || *(context.index) == 0xF3) {
        commandPrefix = *(context.index);
        context.index++;
    }

    uint8_t addressSizePrefix = 0;
    //    Код 67.
    //
    //    Если общий режим выполнения программы равен "32 бита", то для команды, перед которой есть префикс 67, устанавливается атрибут размера адреса "16" бит.
    //
    //    Если общий режим выполнения программы равен "16 бит", то для команды, перед которой есть префикс 67, устанавливается атрибут размера адреса "32" бита.
    //
    //    Действие префикса зависит от конкретной команды.
    if (*(context.index) == 0x67) {
        command |= 0x0200;
        context.index++;
    }

    uint8_t operandSizePrefix = 0;
    //    Код 66.
    //
    //    Если общий режим выполнения программы равен "32 бита", то для команды, перед которой есть префикс 66, устанавливается атрибут размера операнда "16" бит.
    //
    //    Если общий режим выполнения программы равен "16 бит", то для команды, перед которой есть префикс 66, устанавливается атрибут размера операнда "32" бита.
    //
    //    Действие префикса зависит от конкретной команды.
    if (*(context.index) == 0x66) {
        command |= 0x0400;
        context.index++;
    }


    uint8_t* changeSegmentPrefix = NULL;
    //    Код 26 - сегмент по умолчанию заменяется на сегмент ES.
    //    Код 2E - сегмент по умолчанию заменяется на сегмент CS.
    //    Код 36 - сегмент по умолчанию заменяется на сегмент SS.
    //    Код 3E - сегмент по умолчанию заменяется на сегмент DS.
    //    Код 64 - сегмент по умолчанию заменяется на сегмент FS.
    //    Код 65 - сегмент по умолчанию заменяется на сегмент GS.
    switch (*context.index) {
        case 0x26:
            changeSegmentPrefix = mem(SR_ES);
            context.index++;
            break;
        case 0x2E:
            changeSegmentPrefix = mem(SR_CS);
            context.index++;
            break;
        case 0x36:
            changeSegmentPrefix = mem(SR_SS);
            context.index++;
            break;
        case 0x3E:
            changeSegmentPrefix = mem(SR_DS);
            context.index++;
            break;
        case 0x64:
            changeSegmentPrefix = mem(SR_FS);
            context.index++;
            break;
        case 0x65:
            changeSegmentPrefix = mem(SR_GS);
            context.index++;
            break;
        default:
            break;
    }

    LOG("%s", "0x");

    uint16_t debugCommand = 0;

    if (*(context.index) == 0x0F) {
        context.index++;
        LOG("%s", "0F");
        command |= 0x0100;
    }
    LOG("%X ", (*context.index));

    command |= (uint16_t)(*context.index);
    debugCommands[command] = 1;
    context.index++;

    context.lastCommandInfo.prefixInfo.commandPrefix = commandPrefix;
    context.lastCommandInfo.prefixInfo.changeSegmentPrefix = changeSegmentPrefix;
    context.lastCommandInfo.command = command;
}

// readMRM

void runCommand16() {
    getCommand();
    commandFunctions16[context.lastCommandInfo.command]();
}

void runCommand32() {
    getCommand();
    commandFunctions32[context.lastCommandInfo.command]();
}

void runCommand() {
    context.lastCommandInfo.command = 0;
    if (context.mod) {
        runCommand32();
    } else {
        runCommand16();
    }
}

void pushInStack32u(uint32_t value) {
    uint32_t* sp = register32u(BR_SP);
    *sp -= 32 / 8;
    *(uint32_t*)(mem(SR_SS) + *sp) = value;
}

void pushInStack32(int32_t value) {
    uint32_t* sp = register32u(BR_SP);
    *sp -= 32 / 8;
    *(int32_t*)(mem(SR_SS) + *sp) = value;
}

void run32ToEnd() {
    context.mod = 1;
    clearDebugCommands();
    while (context.end == 0) {
        runCommand32();
    }
}

void run16ToEnd() {
    context.mod = 0;
    clearDebugCommands();
    while (context.end == 0) {
        runCommand16();
    }
}

void run32ToEndWithStop(int count) {
    context.mod = 1;
    clearDebugCommands();
    while (context.end == 0 && count > 0) {
        runCommand32();
        count--;
    }
}

char* print16Registers();

#define REG16_PRINT_SIZE (9 * 13)
#define PRINT16_REGS { char* out = print16Registers(); printf("%s", out); free(out); }
void run16ToEndWithStop(int count) {
    PRINT16_REGS
    // step 82|
    context.mod = 0;
    clearDebugCommands();
    int index = 0;
    while (context.end == 0 && count > 0) {
        LOG("step %d|", index);
        runCommand16();
        LOG("%s", "\n\n");
        PRINT16_REGS
        index += 1;
        count--;
    }
}

char* run16AndSaveToEndWithStop(int count) {
    char *out = malloc(count * REG16_PRINT_SIZE + 1);
    context.mod = 0;
    clearDebugCommands();
    int index = 0;
    while (context.end == 0 && count > 0) {
        runCommand16();
        char* regs = print16Registers();
        sprintf(out + index * REG16_PRINT_SIZE, "%s", regs);
        free(regs);
        index++;
        count--;
    }
    return out;
}

int run16AndTestToEndWithStop(int count, char* in) {
    context.mod = 0;
    clearDebugCommands();
    int index = 0;
    while (context.end == 0 && count > 0) {
        runCommand16();
        char* regs = print16Registers();
        for (int i = 0; i < REG16_PRINT_SIZE; i++) {
            if (regs[i] != in[REG16_PRINT_SIZE * index + i]) {
                return index;
            }
        }
        index++;
        count--;
    }
    return -1;
}

#define GET_BYTE(value, index) (((uint8_t*)(&reg)) + index)
void printHex(uint8_t* value, char* out) {
    if (*value == 0) {
        sprintf(out, "00");
    } else if (*value < 16) {
        sprintf(out, "0%X", *value);
    } else {
        sprintf(out, "%X", *value);
    }
}
void printRegister16(char *s, uint16_t reg, char* out) {
    sprintf(out, "%s=", s);
    printHex(GET_BYTE(reg, 1), out + 3);
    printHex(GET_BYTE(reg, 0), out + 5);
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
