//
//  DosLoader.h
//  
//
//  Created by Alex Shipin on 11/15/22.
//

#ifndef DosLoader_h
#define DosLoader_h

#include <stdio.h>
#include <stdlib.h>

#include "DosExeHeader.h"

#include "../Base/Read.h"
#include "../Function/BaseFunction.h"
#include "../Memory/RealMemoryManager.h"
#include "../Base/Registers.h"

void loadProgramWithShiftMemory(uint8_t *input, uint size, uint mod, uint16_t shift);
void loadProgramInZeroMemory(uint8_t *program, uint size, uint mod);
void returnToTopStack();
void loadDosProgram(uint8_t *program, uint size);

#endif /* DosLoader_h */
