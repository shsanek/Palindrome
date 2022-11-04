//
//  Models.c
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#include "Models.h"
#include "Registers.h"
#include <stdlib.h>

void emptyInterruptCallFunction(void* context, uint8_t a) {
}

void endCallFunction(void* context, uint8_t a) {
    ((Context*)context)->end = 1;
}

Context* makeContext(uint16_t memorySize) {
    uint16_t* segmentRegisters = malloc(sizeof(uint16_t) * 8);
    uint8_t* registers = malloc(sizeof(uint32_t) * 8);
    uint8_t* memory = malloc(memorySize);
    uint8_t mod = 0;

    InterruptCallFunction* functions = malloc(sizeof(void*) * 256);
    for (int i = 0; i < 256; i++) {
        functions[i] = emptyInterruptCallFunction;
    }
    functions[0x20] = endCallFunction;
    char end = 0;

    Context* context = malloc(sizeof(Context));
    context->segmentRegisters = segmentRegisters;
    context->registers = registers;
    context->memory = memory;
    context->program = memory;
    context->index = memory;
    context->mod = mod;
    context->end = 0;
    context->functions = functions;
    context->additionalContext = NULL;

    context->outInstruction = malloc(2);
    context->outInstruction[0] = 0xCD;
    context->outInstruction[1] = 0x20;

    int stackSize = 1024 * sizeof(void*);
    context->stack = malloc(1024 * sizeof(void*));
    context->callStack = malloc(1048 * sizeof(void*));

    context->currentStack = context->stack;
    context->currentCallStack = context->callStack;

    context->currentCallStack += 1;
    context->currentCallStack[0] = context->outInstruction;

    context->segmentRegisters[SR_SS] = 0;
    *register32u(context, BR_SP) = memorySize;

    for (int i = 0; i < 8; i++) {
        segmentRegisters[0] = 0;
        ((uint32_t*)segmentRegisters)[0] = 0;
    }

    return context;
}

void freeContext(Context* context) {
    free(context->memory);
    free(context->registers);
    free(context->segmentRegisters);
    free(context->functions);
    free(context->outInstruction);
    free(context->stack);
    free(context->callStack);
    free(context);
}
