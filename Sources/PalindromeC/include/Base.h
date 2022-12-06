//
//  Base.h
//  
//
//  Created by Alex Shipin on 10/14/22.
//

#ifndef Base_h
#define Base_h

#include <stdio.h>
#include "../Base/Models.h"
#include "../Base/Registers.h"
#include "../Dos/DosLoader.h"
#include "../Dos/VirtualFolder.h"
#include "../Memory/RealMemoryManager.h"
#include "../Dos/VideoServiceInterrupt.h"

extern uint8_t *debugCommands;

void resetStack();

void pushInStack32u(uint32_t value);
void pushInStack32(int32_t value);
void pushInStack16u(uint16_t value);
void pushInStack16(int16_t value);

char* runFullModeToEndWithStopForTest(int count);
void runFullModeToEndWithStop(int count);
void runFullMode(int count);

#endif /* Base_h */
