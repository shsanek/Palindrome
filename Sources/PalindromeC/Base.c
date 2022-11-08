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


void getCommand() {
    uint16_t command = 0;
    uint8_t commandPrefix = 0;
    //Код F0 - префикс блокировки шины, команда LOCK ("lock" - запирать). Этот префикс употребляется только с теми командами, которые поддерживают такую возможность - возможность блокировки шины.
    //
    //Коды F2, F3 - префиксы повторения, команда REP ("repeat" - повторять) и другие команды этой группы. Такие префиксы употребляются только с цепочечными командами. Префиксы группы REP позволяют организовать циклическое выполнение цепочечной команды. Смотрите страницу   Цепочечные команды.
    //
    //Код F1 - нет такого префикса и нет такой команды. Тут следует заметить, что это единственный код для первого байта команды, который все еще остается свободным. Поневоле напрашивается мысль о существовании некоторой недокументированной возможности ...
    if (*(context.index) == 0xF0 || *(context.index) == 0xF2 || *(context.index) == 0xF3) {
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


    uint8_t changeSegmentPrefix = 0;
    //    Код 26 - сегмент по умолчанию заменяется на сегмент ES.
    //    Код 2E - сегмент по умолчанию заменяется на сегмент CS.
    //    Код 36 - сегмент по умолчанию заменяется на сегмент SS.
    //    Код 3E - сегмент по умолчанию заменяется на сегмент DS.
    //    Код 64 - сегмент по умолчанию заменяется на сегмент FS.
    //    Код 65 - сегмент по умолчанию заменяется на сегмент GS.
    if (
        *(context.index) == 0x26 ||
        *(context.index) == 0x2E ||
        *(context.index) == 0x36 ||
        *(context.index) == 0x3E ||
        *(context.index) == 0x64 ||
        *(context.index) == 0x65
    ) {
        changeSegmentPrefix = *(context.index);
        context.index++;
    }

    if (*(context.index) == 0x0F) {
        context.index++;
        command |= 0x0100;
    }

    command |= (uint16_t)(*context.index);
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
    if (context.mod) {
        runCommand32();
    } else {
        runCommand16();
    }
}
