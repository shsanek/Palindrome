//
//  ExternalInterruptBaseHandler.c
//  
//
//  Created by Alex Shipin on 12/6/22.
//

#include "ExternalInterruptBaseHandler.h"
#include "../Models.h"
#include "../Registers.h"
#include "../Read.h"
#include "../Flags.h"
#include "../../Function/BaseFunction.h"

void inProtectedMode() {
    if (context.pmode) {
        assert(0);
        return;
    }
    assert(0);

    VM = 0;
    context.pmode = 1;
    context.end = 0x0A;
}

void DPMIFunction(uint16_t a) {
}

void endCallFunction(uint16_t a) {
    if (*regAXu == 255) {
        inProtectedMode();
    } else {
        context.end = 1;
    }
}

void other15InformationFunction(uint16_t a) {
    if (*regAHu == 0xBF) {
        *regAHu = 0x86;
        SET_FLAG(CF, 1);
        return;
    }
    ExternalCallFunctionEmpty(a);
}

void other2fInformationFunction(uint16_t a) {
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
    ExternalCallFunctionEmpty(a);
}

void ExternalInterruptBaseHandlerInstall() {
    context.functions[0x15] = other15InformationFunction;
    context.functions[0x20] = endCallFunction;
    context.functions[0x2f] = other2fInformationFunction;
    context.functions[0x31] = DPMIFunction;
}
