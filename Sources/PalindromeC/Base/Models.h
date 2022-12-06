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
#include "InOutPorts.h"
#include "ExternalFunction.h"


typedef struct CommandPrefixInfo {
    uint8_t commandPrefix;
    uint8_t addressSizePrefix;
    uint8_t operandSizePrefix;
    uint16_t changeSegmentPrefix;
    uint8_t hasSegmentPrefix;
} CommandPrefixInfo;

typedef struct CommandInfo {
    CommandPrefixInfo prefixInfo;
    uint16_t command;
} CommandInfo;

typedef struct Context {
    uint16_t segmentRegisters[8];
    uint8_t registers[256];

    uint8_t* segmentRegistersValue[8];

    uint8_t* index;

    uint8_t* program;

    uint8_t mod;

    uint16_t cursor;
    uint8_t *text;

    uint8_t pmode;
    uint8_t hasInterrupt;

    pthread_mutex_t mainThreadLock;
    pthread_mutex_t interruptLock;
    pthread_mutex_t interruptImplementationLock;

    CommandInfo lastCommandInfo;

    ExternalCallFunction functions[0xFFFF];
    IOPort ports[256];

    // продолжаем пока 0 если стало 0x14 обновляем мод
    char end;

    void *additionalContext;
} Context;

extern Context context;

Context* resetContext();
void freeContext();
void installCommandFunction();

#endif /* Models_h */
