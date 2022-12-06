//
//  Interrupt.c
//  
//
//  Created by Alex Shipin on 12/6/22.
//

#include "ExternalFunction.h"
#include "Registers.h"
#include "Models.h"

void ExternalCallFunctionEmpty(uint16_t a) {
    printf(", call %X-%X", a, *regAH);
}

void ExternalCallFunctionInstall() {
    for (int i = 0; i < 0xffff; i++) {
        context.functions[i] = ExternalCallFunctionEmpty;
    }
}
