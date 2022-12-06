//
//  Interrupt.c
//  
//
//  Created by Alex Shipin on 12/6/22.
//

#include "ExternalFunction.h"
#include "Registers.h"
#include "Models.h"
#include <pthread.h>
#include "Flags.h"
#include <stdlib.h>
#include <string.h>
#include "Read.h"
#include "../include/Base.h"

void ExternalCallFunctionEmpty(uint16_t a) {
    printf(", call %X-%X", a, *regAH);
}

void ExternalCallFunctionInstall() {
    for (int i = 0; i < 0xffff; i++) {
        context.functions[i] = ExternalCallFunctionEmpty;
    }
}

void InterruptCall(uint8_t value) {
    pthread_mutex_lock(&context.interruptImplementationLock);
    pthread_mutex_lock(&context.mainThreadLock);
    context.hasInterrupt = 1;
    pthread_mutex_lock(&context.interruptLock);
    LOG("%s", "start InterruptCall");

    FillFlags();
    EncodeFlagsRegister();

    uint32_t breg[8];
    uint16_t sreg[8];
    int32_t flags = reg_flags;
    memcpy(breg, context.registers, sizeof(uint32_t) * 8);
    memcpy(sreg, context.segmentRegisters, sizeof(uint16_t) * 8);

    uint16_t newIP = *(uint16_t*)(GET_REAL_MOD_MEMORY_POINTER(SR_CS) + value * 4);
    uint16_t newCS = *(uint16_t*)(GET_REAL_MOD_MEMORY_POINTER(SR_CS) + value * 4 + 2);

    pushInStack16u(SR_VALUE(SR_CS));
    pushInStack16u(((uint16_t)(context.index - GET_SEGMENT_POINTER(SR_CS))));

    SET_VALUE_IN_SEGMENT(SR_CS, newCS);
    context.index = GET_SEGMENT_POINTER(SR_CS) + newIP;

    InterruptRun();

    reg_flags = flags;
    memcpy(context.registers, breg, sizeof(uint32_t) * 8);
    for (int i = 0; i < 8; i++) {
        SET_VALUE_IN_SEGMENT(i, sreg[i]);
    }
    DecodeFlagsRegister32();

    context.hasInterrupt = 0;
    LOG("%s", "end InterruptCall");

    pthread_mutex_unlock(&context.mainThreadLock);
    pthread_mutex_unlock(&context.interruptLock);
    pthread_mutex_unlock(&context.interruptImplementationLock);
}
