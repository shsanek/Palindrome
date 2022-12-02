//
//  VidioServiceInterrupt.h
//  
//
//  Created by Alex Shipin on 11/30/22.
//

#ifndef VidioServiceInterrupt_h
#define VidioServiceInterrupt_h

#include <stdio.h>

#include "../Function/BaseFunction.h"
#include "../Base/Registers.h"
#include "../Base/Read.h"

extern uint8_t DebugOnlyPrint;

void callVideoServiceInterrupt(uint8_t a);

#endif /* VidioServiceInterrupt_h */
