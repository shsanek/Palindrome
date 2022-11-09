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

Context context;

void emptyInterruptCallFunction(uint8_t a) {
}


void printSymbol(uint8_t a) {
    context.text[context.cursor] = *register8(BR_AL);
    context.cursor += 1;
}


void endCallFunction(uint8_t a) {
    context.end = 1;
}

void setBaseFunction() {
    for (int i = 0; i < 256; i++) {
        context.functions[i] = emptyInterruptCallFunction;
    }
    context.functions[0x20] = endCallFunction;
    context.functions[0x10] = printSymbol;
}

void resetStack() {
    for (int i = 0; i < 8; i++) {
        context.registers[i] = 0;
        context.segmentRegisters[i] = 0;
    }

    for (int i = 0; i < 8; i++) {
        context.segmentRegisters[0] = 0;
        ((uint32_t*)context.segmentRegisters)[0] = 0;
    }

    context.currentStack = context.stack;
    context.currentCallStack = context.callStack;

    context.currentCallStack[0] = context.outInstruction;
    context.currentCallStack += 1;

    reg_flags = 0;
    context.segmentRegisters[SR_SS] = 0;
    *register32u(BR_SP) = context.memorySize;

    context.cursor = 0;
    context.end = 0;
    context.index = context.program;
}

int isInstall = 0;

Context* resetContext(uint16_t memorySize) {
    freeContext();
    isInstall = 1;
    uint16_t* segmentRegisters = malloc(sizeof(uint16_t) * 8);
    uint8_t* registers = malloc(sizeof(uint32_t) * 8);

    uint8_t* memory = malloc(memorySize);
    uint8_t mod = 0;

    setBaseFunction();

    context.segmentRegisters = segmentRegisters;
    context.registers = registers;
    context.memory = memory;
    context.program = memory;
    context.index = memory;
    context.mod = mod;
    context.end = 0;
    context.additionalContext = NULL;

    context.text = malloc(255 * 255);
    for (int i = 0; i < 255 * 255; i++) {
        context.text[i] = 0;
    }

    context.outInstruction = malloc(2);
    context.outInstruction[0] = 0xCD;
    context.outInstruction[1] = 0x20;

    context.memorySize = memorySize;

    int stackSize = 1024 * sizeof(void*);
    context.stack = malloc(1024 * sizeof(void*));
    context.callStack = malloc(1048 * sizeof(void*));

    resetStack();
    setRegisterPointers();

    return &context;
}


void freeContext() {
    if (!isInstall) {
        return;
    }
    free(context.memory);
    free(context.registers);
    free(context.segmentRegisters);
    free(context.outInstruction);
    free(context.stack);
    free(context.callStack);
    free(context.text);
    isInstall = 0;
}
