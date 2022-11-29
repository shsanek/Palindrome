//
//  BaseFunction.h
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#ifndef Models_h
#define Models_h

#include <stdio.h>
#include "FPU.h"

typedef struct CommandPrefixInfo {
    uint8_t commandPrefix;
    uint8_t addressSizePrefix;
    uint8_t operandSizePrefix;
    uint8_t* changeSegmentPrefix;
} CommandPrefixInfo;

typedef struct ASMMRMInfo {

} ASMMRMInfo;

typedef struct CommandInfo {
    CommandPrefixInfo prefixInfo;
    uint16_t command;
} CommandInfo;

typedef void (*InterruptCallFunction)(
    uint8_t index
);

typedef struct Context {
    uint16_t* segmentRegisters;
    uint8_t* registers;
    uint8_t* flags;

    uint8_t* index;

    uint8_t* program;
    uint8_t* memory;

    uint8_t* currentStack;
    void** currentCallStack;

    uint8_t* stack;
    void** callStack;
    uint8_t* outInstruction;

    uint8_t mod;

    uint16_t cursor;
    uint8_t *text;


    void (*SetFlags)(struct Context* context, uint8_t index);
    CommandInfo lastCommandInfo;

    InterruptCallFunction functions[256];

    char end;

    void *additionalContext;

    uint32_t memorySize;

} Context;

extern Context context;

Context* resetContext(uint32_t memorySize);
void freeContext();
void emptyInterruptCallFunction(uint8_t a);

#endif /* Models_h */
