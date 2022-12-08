//
//  VidioServiceInterrupt.c
//  
//
//  Created by Alex Shipin on 11/30/22.
//

#include "VideoServiceInterrupt.h"

uint8_t DebugOnlyPrint = 1;

uint8_t DisplayCurrentMode = 3;
uint8_t DisplayTextColumnCount = 0x50;
uint8_t DisplayActivePage = 0;

typedef struct VGACard {
    uint16_t memorySize; // value * 16
    uint8_t* memory;
} VGACard;

VGACard currentVGACard;

void VGACardInstall() {
    currentVGACard.memorySize = 16384;
    currentVGACard.memory = malloc(16384 * 16);
}

void callVGAFunction() {
    if (*regBL == 0x10) {
        *regBL = 3;
        *regBH = 0;
        return;
    }

    ExternalCallFunctionEmpty(0x10);
}

void callVideoServiceInterrupt(uint16_t a) {
    if (*regAHu == 0x0E || DebugOnlyPrint) {
        context.text[context.cursor] = *register8(BR_AL);
        context.cursor += 1;
        return;
    }
    if (*regAH == 0x00) {
        DisplayCurrentMode = *regAHu;
        return;
    }
    if (*regAHu == 0x0F) {
        *regAL = DisplayCurrentMode;
        *regAH = DisplayTextColumnCount;
        *regBH = DisplayActivePage;
        return;
    }
    if (*regAXu == 0x1A00) {
        *regBX = 0;
        *regAL = 0x08;
        return;
    }
    if (*regAHu == 0x12) {
        callVGAFunction();
        return;
    }
    ExternalCallFunctionEmpty(a);
}

void VideoServiceInstall() {
    VGACardInstall();
    context.functions[0x10] = callVideoServiceInterrupt;
}

// AX=5003  BX=0001  CX=3301  DX=0A01  SP=1476  BP=14F8  SI=00BC  DI=1026
