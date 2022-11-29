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
#include "Support/Log.h"

uint8_t *debugCommands = NULL;

void clearDebugCommands() {
    if (!debugCommands) {
        debugCommands = malloc(512);
    }
    for (int i = 0; i < 512; i++) {
        debugCommands[i] = 0;
    }
}

void getCommand() {
    LOG("%llX:", (uint64_t)(context.index - context.memory));

    uint16_t command = 0;
    uint8_t commandPrefix = 0;
    uint8_t value = read8u();
    //Код F0 - префикс блокировки шины, команда LOCK ("lock" - запирать). Этот префикс употребляется только с теми командами, которые поддерживают такую возможность - возможность блокировки шины.
    //
    //Коды F2, F3 - префиксы повторения, команда REP ("repeat" - повторять) и другие команды этой группы. Такие префиксы употребляются только с цепочечными командами. Префиксы группы REP позволяют организовать циклическое выполнение цепочечной команды. Смотрите страницу   Цепочечные команды.
    //
    //Код F1 - нет такого префикса и нет такой команды. Тут следует заметить, что это единственный код для первого байта команды, который все еще остается свободным. Поневоле напрашивается мысль о существовании некоторой недокументированной возможности ...
    if (value == 0xF2 || value == 0xF3) {
        commandPrefix = value;
        value = read8u();
    }

    uint8_t addressSizePrefix = 0;
    //    Код 67.
    //
    //    Если общий режим выполнения программы равен "32 бита", то для команды, перед которой есть префикс 67, устанавливается атрибут размера адреса "16" бит.
    //
    //    Если общий режим выполнения программы равен "16 бит", то для команды, перед которой есть префикс 67, устанавливается атрибут размера адреса "32" бита.
    //
    //    Действие префикса зависит от конкретной команды.
    if (value == 0x67) {
        command |= 0x0200;
        value = read8u();
    }

    uint8_t operandSizePrefix = 0;
    //    Код 66.
    //
    //    Если общий режим выполнения программы равен "32 бита", то для команды, перед которой есть префикс 66, устанавливается атрибут размера операнда "16" бит.
    //
    //    Если общий режим выполнения программы равен "16 бит", то для команды, перед которой есть префикс 66, устанавливается атрибут размера операнда "32" бита.
    //
    //    Действие префикса зависит от конкретной команды.
    if (value == 0x66) {
        command |= 0x0400;
        value = read8u();
    }


    uint8_t* changeSegmentPrefix = NULL;
    //    Код 26 - сегмент по умолчанию заменяется на сегмент ES.
    //    Код 2E - сегмент по умолчанию заменяется на сегмент CS.
    //    Код 36 - сегмент по умолчанию заменяется на сегмент SS.
    //    Код 3E - сегмент по умолчанию заменяется на сегмент DS.
    //    Код 64 - сегмент по умолчанию заменяется на сегмент FS.
    //    Код 65 - сегмент по умолчанию заменяется на сегмент GS.
    switch (value) {
        case 0x26:
            changeSegmentPrefix = mem(SR_ES);
            value = read8u();
            break;
        case 0x2E:
            changeSegmentPrefix = mem(SR_CS);
            value = read8u();
            break;
        case 0x36:
            changeSegmentPrefix = mem(SR_SS);
            value = read8u();
            break;
        case 0x3E:
            changeSegmentPrefix = mem(SR_DS);
            value = read8u();
            break;
        case 0x64:
            changeSegmentPrefix = mem(SR_FS);
            value = read8u();
            break;
        case 0x65:
            changeSegmentPrefix = mem(SR_GS);
            value = read8u();
            break;
        default:
            break;
    }

    if (value == 0x0F) {
        value = read8u();
        command |= 0x0100;
    }

    command |= (uint16_t)(value);
    debugCommands[command] = 1;

    context.lastCommandInfo.prefixInfo.commandPrefix = commandPrefix;
    context.lastCommandInfo.prefixInfo.changeSegmentPrefix = changeSegmentPrefix;
    context.lastCommandInfo.command = command;

    DEBUG_RUN({
        printDebugLine();
    })

    LOG("%s", " ");
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
    clearDebugLine();
    while (context.end == 0) {
        runCommand32();
    }
}

void run16ToEnd() {
    context.mod = 0;
    clearDebugCommands();
    clearDebugLine();
    while (context.end == 0) {
        runCommand16();
    }
}

void run32ToEndWithStop(int count) {
    PRINT32_REGS
    context.mod = 1;
    clearDebugCommands();
    clearDebugLine();
    int index = 0;
    int last = *regESP;
    int first = *regESP;
    while (context.end == 0 && count > 0) {
        LOG("step %d|", index);
        runCommand32();
        LOG("%s", " ");
        DEBUG_RUN({
            printDebugLine();
        })
        LOG("%s", "\n\n");
        LOG("stack=%d(%d)(%d)\n", *regESP, (last - *regESP), (first - *regESP));
        last = *regESP;
        PRINT32_REGS
        count--;
        index += 1;
    }
}

void run16ToEndWithStop(int count) {
    LOG("%s","\n\n");
    PRINT16_REGS
    context.mod = 0;
    clearDebugCommands();
    clearDebugLine();
    int index = 0;
    while (context.end == 0 && count > 0) {
        LOG("step %d|", index);
        runCommand16();
        LOG("%s", " ");
        DEBUG_RUN({
            printDebugLine();
        })
        LOG("%s", "\n\n");
        PRINT16_REGS
        index += 1;
        count--;
    }
}
// 39 
char* run16AndSaveToEndWithStop(int count) {
    char *out = malloc(count * REG16_PRINT_SIZE + 1);
    context.mod = 0;
    clearDebugCommands();
    clearDebugLine();
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
    clearDebugLine();
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
