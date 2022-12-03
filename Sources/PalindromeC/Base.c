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
    LOG("%llX:", (uint64_t)(context.index - context.program));

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

    uint16_t changeSegmentPrefix = 0;
    uint8_t hasSegmentPrefix = 0;
    //    Код 26 - сегмент по умолчанию заменяется на сегмент ES.
    //    Код 2E - сегмент по умолчанию заменяется на сегмент CS.
    //    Код 36 - сегмент по умолчанию заменяется на сегмент SS.
    //    Код 3E - сегмент по умолчанию заменяется на сегмент DS.
    //    Код 64 - сегмент по умолчанию заменяется на сегмент FS.
    //    Код 65 - сегмент по умолчанию заменяется на сегмент GS.
    switch (value) {
        case 0x26:
            changeSegmentPrefix = (SR_ES);
            hasSegmentPrefix = 1;
            value = read8u();
            break;
        case 0x2E:
            changeSegmentPrefix = (SR_CS);
            hasSegmentPrefix = 1;
            value = read8u();
            break;
        case 0x36:
            changeSegmentPrefix = (SR_SS);
            hasSegmentPrefix = 1;
            value = read8u();
            break;
        case 0x3E:
            changeSegmentPrefix = (SR_DS);
            hasSegmentPrefix = 1;
            value = read8u();
            break;
        case 0x64:
            changeSegmentPrefix = (SR_FS);
            hasSegmentPrefix = 1;
            value = read8u();
            break;
        case 0x65:
            changeSegmentPrefix = (SR_GS);
            hasSegmentPrefix = 1;
            value = read8u();
            break;
        default:
            break;
    }

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

    if (value == 0x0F) {
        value = read8u();
        command |= 0x0100;
    }

    command |= (uint16_t)(value);
    DEBUG_RUN({ debugCommands[command] = 1; })

    context.lastCommandInfo.prefixInfo.hasSegmentPrefix = hasSegmentPrefix;
    context.lastCommandInfo.prefixInfo.commandPrefix = commandPrefix;
    context.lastCommandInfo.prefixInfo.changeSegmentPrefix = changeSegmentPrefix;
    context.lastCommandInfo.command = command;

    DEBUG_RUN({
        printDebugLine();
    })

    LOG("%s", " ");
}

// readMRM

#define runCommand16() {\
    getCommand();\
    commandFunctions[context.lastCommandInfo.command]();\
}

#define runCommand32() { \
    getCommand(); \
    commandFunctions[context.lastCommandInfo.command](); \
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
    *(uint32_t*)(GET_SEGMENT_POINTER(SR_SS) + *sp) = value;
}

void pushInStack32(int32_t value) {
    uint32_t* sp = register32u(BR_SP);
    *sp -= 32 / 8;
    *(int32_t*)(GET_SEGMENT_POINTER(SR_SS) + *sp) = value;
}

void run16FromFullModeToEnd(int* count, int *index) {
    LOG("%s","\n\n");
    PRINT16_REGS
    while (context.end == 0 && (*count) > 0) {
        LOG("step %d|", *index);
        runCommand16();
        LOG("%s", " ");
        DEBUG_RUN({
            printDebugLine();
        })
        LOG("%s", "\n\n");
        PRINT16_REGS
        DEBUG_RUN({ (*index) += 1; })
        (*count)--;
    }
}

void run32FromFullModeToEnd(int* count, int *index) {
    LOG("%s","\n\n");
    PRINT32_REGS
    while (context.end == 0 && (*count) > 0) {
        LOG("step %d|", (*index));
        runCommand32();
        LOG("%s", " ");
        DEBUG_RUN({
            printDebugLine();
        })
        LOG("%s", "\n\n");
        PRINT32_REGS
        DEBUG_RUN({ (*index) += 1; })
        (*count)--;
    }
}

void runFullModeToEndWithStop(int count) {
    clearDebugCommands();
    clearDebugLine();
    int index = 0;
    while (context.end == 0 && count > 0) {
        installCommandFunction();
        if (context.mod) {
            run32FromFullModeToEnd(&count, &index);
        } else {
            run16FromFullModeToEnd(&count, &index);
        }
        if (context.end == 0x14) {
            context.end = 0;
        }
    }
}

void run16FromFullMode() {
    while (context.end == 0) {
        runCommand16();
    }
}

void run32FromFullMode() {
    while (context.end == 0) {
        runCommand32();
    }
}

void runFullMode(int count) {
    while (context.end == 0) {
        installCommandFunction();
        if (context.mod) {
            run32FromFullMode();
        } else {
            run16FromFullMode();
        }
        if (context.end == 0x14) {
            context.end = 0;
        }
    }
}

void run16FullModeToEndWithStopForTest(int* count, int* index, char** out) {
    while (context.end == 0 && (*count) > 0) {
        runCommand16();
        char* regs = print16Registers();
        sprintf(*out, "%s", regs);
        (*out) += REG16_PRINT_SIZE;
        free(regs);
        (*index)++;
        (*count)--;
    }
}

void run32FullModeToEndWithStopForTest(int* count, int* index, char** out) {
    while (context.end == 0 && (*count) > 0) {
        runCommand32();
        char* regs = print32Registers();
        sprintf(*out, "%s", regs);
        (*out) += REG32_PRINT_SIZE;
        free(regs);
        (*index)++;
        (*count)--;
    }
}

char* runFullModeToEndWithStopForTest(int count) {
    char *out = malloc((count + 2) * REG32_PRINT_SIZE + 1);
    char *result = out;
    clearDebugCommands();
    clearDebugLine();
    int index = 0;
    while (context.end == 0 && count > 0) {
        installCommandFunction();
        if (context.mod) {
            run32FullModeToEndWithStopForTest(&count, &index, &out);
        } else {
            run16FullModeToEndWithStopForTest(&count, &index, &out);
        }

        if (context.end == 0x14) {
            context.end = 0;
        }
    }
    return result;
}

void installCommandFunction() {
    if (context.pmode) {
        if (context.mod) {
            installCommandFunction32PM();
        } else {
            installCommandFunction16PM();
        }
    } else {
        if (context.mod) {
            installCommandFunction32RM();
        } else {
            installCommandFunction16RM();
        }
    }
}
