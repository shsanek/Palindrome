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
#include "ExternalFunction.h"
#include "External/ExternalInterruptBaseHandler.h"
#include <pthread.h>

Context context;

void ExternalFunctionFunction() {
    ExternalCallFunctionInstall();
    ExternalInterruptBaseHandlerInstall();
    VideoServiceInstall();
    SystemDOSInstall();
}

void resetStack() {
    for (int i = 0; i < 8; i++) {
        *(((uint32_t*)context.registers) + i) = 0;
        *(((uint16_t*)context.segmentRegisters) + i) = 0;
        context.segmentRegistersValue[i] = 0;
    }

    realModMemorySetSize(0xFFFF);

    fpuStackIndex = 8;

    reg_flags = 0;
    DecodeFlagsRegister32();

    context.cursor = 0;
    context.end = 0;
    context.index = context.program;

    IOPortInstall();
    ExternalFunctionFunction();
}

int isInstall = 0;

Context* resetContext() {
    freeContext();
    isInstall = 1;

    uint8_t mod = 0;

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

    pthread_mutex_init(&context.interruptLock, NULL);
    pthread_mutex_init(&context.mainThreadLock, NULL);
    pthread_mutex_init(&context.interruptImplementationLock, NULL);

    return &context;
}


void freeContext() {
    if (!isInstall) {
        return;
    }
    free(context.text);
    pthread_mutex_destroy(&context.interruptLock);
    pthread_mutex_destroy(&context.mainThreadLock);
    pthread_mutex_destroy(&context.interruptImplementationLock);

    isInstall = 0;
}
