//
//  BaseFunction.h
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#ifndef Models_h
#define Models_h

#include <stdio.h>

typedef void (*ASM_FUNCTION)(
    uint8_t mod,
    uint8_t commandPrefix,
    uint8_t operandSizePrefix,
    uint8_t changeSegmentPrefix
);

typedef struct ASMFunction {
    ASM_FUNCTION function;
    char mrmActive;
    char addr;
    char data;
    char name[3];
} ASMFunction;

typedef struct CommandPrefixInfo {
    uint8_t commandPrefix;
    uint8_t addressSizePrefix;
    uint8_t operandSizePrefix;
    uint8_t changeSegmentPrefix;
} CommandPrefixInfo;

typedef struct ASMMRMInfo {

} ASMMRMInfo;

typedef struct CommandInfo {
    CommandPrefixInfo prefixInfo;
    uint16_t command;
} CommandInfo;

typedef void (*InterruptCallFunction)(
    void* context, uint8_t index
);

typedef struct Context {
    uint16_t* segmentRegisters;
    uint8_t* program;
    uint8_t* index;
    uint8_t* registers;
    uint8_t* memory;

    uint8_t* currentStack;
    void** currentCallStack;

    uint8_t* stack;
    void** callStack;
    uint8_t* outInstruction;

    uint8_t mod;


    CommandInfo lastCommandInfo;

    InterruptCallFunction* functions;

    char end;

    void *additionalContext;

} Context;

Context* makeContext(uint16_t memorySize);
void freeContext(Context* context);

#endif /* Models_h */
