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

#define VirtualModMemoryMASK(value) (value >> 2)
#define MAX_HANDLER (0xFF - 1)

typedef struct VirtualMemoryItem {
    uint8_t isAllocate;
    uint16_t limit;
    uint32_t base;
    uint8_t size;
    uint8_t UDX;
    uint8_t info;
    uint16_t index;
    uint8_t *pointer;

    struct VirtualMemoryItem *next;
} VirtualMemoryItem;

extern uint8_t* VirtualMemoryPointerMap[0x3FFF];
typedef uint16_t HANDLER;
void installVirtualMemoryGlobalTable();
void installVirtualMemoryTableForProcess(HANDLER handler);
void activeVirtualMemoryTableForProcess(HANDLER handler);
//
//int virtualModMemoryConvertFromRealMemory(uint8_t* block, uint8_t isRoot);
//
//uint8_t* virtualModMemoryGetPointerForBlock(uint16_t block);

#define GET_VIRTUAL_MOD_MEMORY_POINTER(block) (VirtualMemoryPointerMap[VirtualModMemoryMASK(block)])

#endif /* VirtualMemoryManager_h */
