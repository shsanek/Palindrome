//
//  DosMemoryMeneger.h
//  
//
//  Created by Alex Shipin on 11/30/22.
//

#ifndef DosMemoryMeneger_h
#define DosMemoryMeneger_h

#include <stdio.h>
#include "../Function/BaseFunction.h"

ARRAY_STACK(debugTestNewMemoryBlock, uint16_t)

void setDosMemoryCount(uint32_t size);
int setDosTestAllocateFor(uint16_t block, uint16_t size);
int dosAllocateBlockMemory(uint16_t size);
int dosFreeBlockMemory(uint16_t block);

#endif /* DosMemoryMeneger_h */
