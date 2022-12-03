//
//  DosMemoryManager.h
//  
//
//  Created by Alex Shipin on 11/30/22.
//

#ifndef RealMemoryManager_h
#define RealMemoryManager_h

#include <stdio.h>

#include "../Function/BaseFunction.h"
#include "../Support/Log.h"

ARRAY_STACK(debugTestNewMemoryBlock, uint16_t)

extern uint8_t *RealModeMemory;

void realModMemorySetSize(uint16_t paragraphSize);

int realModMemoryAllocate(uint16_t paragraphSize);
int realModMemoryRelocate(uint16_t paragraph, uint16_t paragraphSize);
int realModMemoryFree(uint16_t block);

int allocateMemoryLoadWithForceBlock(uint16_t paragraph, uint16_t paragraphSize);

uint8_t* realModMemoryGetPointerForBlock(uint16_t block);

#define GET_REAL_MOD_MEMORY_POINTER(block) (RealModeMemory + ((block) * 16))

#endif /* DosMemoryManager_h */
