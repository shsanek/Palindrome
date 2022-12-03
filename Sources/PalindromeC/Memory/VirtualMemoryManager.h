//
//  VirtualMemoryManager.h
//  
//
//  Created by Alex Shipin on 12/2/22.
//

#ifndef VirtualMemoryManager_h
#define VirtualMemoryManager_h

#include <stdio.h>

#include "../Function/BaseFunction.h"
#include "../Support/Log.h"
#include "RealMemoryManager.h"

#define VirtualModMemoryMASK 0x1FFF

extern uint8_t* VirtualModMemoryTable[0x1FFF];

int virtualModMemoryAllocate(uint32_t size);
int virtualModMemoryRelocate(uint16_t block, uint32_t size);
int virtualModMemoryFree(uint16_t block);

int virtualModMemoryConvertFromRealMemory(uint8_t* block, uint8_t isRoot);

void installVirtualModMemory();

uint8_t* virtualModMemoryGetPointerForBlock(uint16_t block);

#define GET_VIRTUAL_MOD_MEMORY_POINTER(block) (VirtualModMemoryTable[(block) & 0x1FFF])

#endif /* VirtualMemoryManager_h */
