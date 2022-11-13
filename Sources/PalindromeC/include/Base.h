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

extern uint8_t *debugCommands;

void installCommandFunction();
void runCommand();

void resetStack();

void pushInStack32u(uint32_t value);
void pushInStack32(int32_t value);

void run32ToEnd();
void run16ToEnd();

#endif /* Base_h */
