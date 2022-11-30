//
//  VidioServiceInterrupt.c
//  
//
//  Created by Alex Shipin on 11/30/22.
//

#include "VideoServiceInterrupt.h"
#include "../Function/BaseFunction.h"

uint8_t DebugOnlyPrint = 1;

uint8_t DisplayCurrentMode = 3;
uint8_t DisplayTextColumnCount = 0x50;
uint8_t DisplayActivePage = 0;

void callVideoServiceInterrupt(uint8_t a) {
    if (*regAHu == 0x0E || DebugOnlyPrint) {
        context.text[context.cursor] = *register8(BR_AL);
        context.cursor += 1;
        return;
    }
    if (*regAHu == 0x0F) {
        *regAL = DisplayCurrentMode;
        *regAH = DisplayTextColumnCount;
        *regBH = DisplayActivePage;
        return;
    }
    emptyInterruptCallFunction(a);
}

// AX=5003  BX=0001  CX=3301  DX=0A01  SP=1476  BP=14F8  SI=00BC  DI=1026