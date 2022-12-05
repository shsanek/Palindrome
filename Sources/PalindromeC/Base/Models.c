//
//  Models.c
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#include "Models.h"
#include "Registers.h"
#include "Flags.h"
#include <stdlib.h>
#include "../Dos/DOSFileSystem.h"
#include "../Function/BaseFunction.h"
#include "../Dos/VideoServiceInterrupt.h"
#include "../Memory/VirtualMemoryManager.h"
Context context;

void emptyInterruptCallFunction(uint8_t a) {
    printf(", call %X-%X", a, *regAH);
}

void inProtectedMode() {
    if (context.pmode) {
        assert(0);
        return;
    }
    assert(0);
    // installVirtualModMemory();

//    SET_VALUE_IN_SEGMENT_P(SR_FS, 0);
//    SET_VALUE_IN_SEGMENT_P(SR_GS, 0);
//
//    SET_VALUE_IN_SEGMENT_P(SR_SS, virtualModMemoryConvertFromRealMemory(GET_SEGMENT_POINTER(SR_SS), 0));
//    SET_VALUE_IN_SEGMENT_P(SR_ES, virtualModMemoryConvertFromRealMemory(GET_SEGMENT_POINTER(SR_ES), 0));
//    SET_VALUE_IN_SEGMENT_P(SR_DS, virtualModMemoryConvertFromRealMemory(GET_SEGMENT_POINTER(SR_DS), 0));
//
//    if (context.mod) {
//        uint16_t* stack = (uint16_t*)(GET_SEGMENT_POINTER(SR_SS) + *regESPu + 4);
//        uint16_t cs = virtualModMemoryConvertFromRealMemory(GET_REAL_MOD_MEMORY_POINTER(*stack), 0);
//        (*stack) = cs;
//    } else {
//        uint16_t* stack = (uint16_t*)(GET_SEGMENT_POINTER(SR_SS) + *regSPu + 2);
//        uint16_t cs = virtualModMemoryConvertFromRealMemory(GET_REAL_MOD_MEMORY_POINTER(*stack), 0);
//        (*stack) = cs;
//    }

    VM = 0;
    context.pmode = 1;
    context.end = 0x14;
}

void DPMIFunction(uint8_t a) {
}

void endCallFunction(uint8_t a) {
    if (*regAXu == 255) {
        inProtectedMode();
    } else {
        context.end = 1;
    }
}

void other15InformationFunction(uint8_t a) {
    if (*regAHu == 0xBF) {
        *regAHu = 0x86;
        SET_FLAG(CF, 1);
        return;
    }
    emptyInterruptCallFunction(a);
}

void other2fInformationFunction(uint8_t a) {
    if (*regAXu == 0x1687) {
        if (context.pmode) {
            *regAXu = 0x0001;
            return;
        }
        *regAXu = 0x0000;
        *regBXu = 0x0001;
        *regCXu = 0x0104;
        *regDXu = 0x005A;
        *regSIu = 0x0029;
        *regDIu = 0x2F97;
        SET_VALUE_IN_SEGMENT(SR_ES, 0xFCB8);
        return;
    }
    if (*regAXu == 0x1600) {
        *regAX = 0x0004;
        return;
    }
    emptyInterruptCallFunction(a);
}


void setBaseFunction() {
    for (int i = 0; i < 256; i++) {
        context.functions[i] = emptyInterruptCallFunction;
    }
    context.functions[0x10] = callVideoServiceInterrupt;
    context.functions[0x15] = other15InformationFunction;
    context.functions[0x20] = endCallFunction;
    context.functions[0x21] = systemDOSFunction;
    context.functions[0x2f] = other2fInformationFunction;
    context.functions[0x31] = DPMIFunction;
}

void resetStack() {
    for (int i = 0; i < 8; i++) {
        *(((uint32_t*)context.registers) + i) = 0;
        *(((uint16_t*)context.segmentRegisters) + i) = 0;
        context.segmentRegistersValue[i] = 0;
    }

    fpuStackIndex = 8;

    reg_flags = 0;
    DecodeFlagsRegister32();

    context.cursor = 0;
    context.end = 0;
    context.index = context.program;
}

int isInstall = 0;

Context* resetContext() {
    freeContext();
    isInstall = 1;

    uint8_t mod = 0;

    setBaseFunction();

    context.mod = mod;
    context.end = 0;
    context.additionalContext = NULL;

    context.text = malloc(255 * 255);
    for (int i = 0; i < 255 * 255; i++) {
        context.text[i] = 0;
    }

    context.pmode = 0;
    resetStack();
    setRegisterPointers();

    return &context;
}


void freeContext() {
    if (!isInstall) {
        return;
    }
    free(context.text);
    isInstall = 0;
}
