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

extern uint8_t *debugCommands;

void installCommandFunction();
void runCommand();

void resetStack();

void pushInStack32u(uint32_t value);
void pushInStack32(int32_t value);

void run32ToEnd();
void run16ToEnd();

void run32ToEndWithStop(int count);
void run16ToEndWithStop(int count);


int run16AndTestToEndWithStop(int count, char* in);
char* run16AndSaveToEndWithStop(int count);

#endif /* Base_h */
