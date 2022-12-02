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
    uint16_t changeSegmentPrefix;
    uint8_t hasSegmentPrefix;
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
    uint16_t segmentRegisters[8];
    uint8_t registers[256];

    uint8_t* index;

    uint8_t* program;

    uint8_t mod;

    uint16_t cursor;
    uint8_t *text;

    CommandInfo lastCommandInfo;

    InterruptCallFunction functions[256];

    char end;

    void *additionalContext;
} Context;

extern Context context;

Context* resetContext();
void freeContext();
void emptyInterruptCallFunction(uint8_t a);

#endif /* Models_h */
