//
//  Interrupt.h
//  
//
//  Created by Alex Shipin on 12/6/22.
//

#ifndef Interrupt_h
#define Interrupt_h

#include <stdio.h>

typedef void (*ExternalCallFunction)(
    uint16_t index
);

void ExternalCallFunctionEmpty(uint16_t a);

void ExternalCallFunctionInstall();

void InterruptRun();

#endif /* Interrupt_h */
