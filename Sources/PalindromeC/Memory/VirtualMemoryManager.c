//
//  VirtualMemoryManager.c
//  
//
//  Created by Alex Shipin on 12/2/22.
//

#include "VirtualMemoryManager.h"

uint8_t* VirtualModMemoryTable[0x1FFF];

typedef struct VirtualModMemoryItem {
    uint8_t isRoot;
} VirtualModMemoryItem;

VirtualModMemoryItem VirtualModMemoryItems[0x1FFF];
uint isFirst = 1;

ARRAY_STACK_IMP(FreePoolVirtualModMemory, uint16_t);

void installVirtualModMemory() {
    if (!isFirst) {
        for (int i = 0; i < 0x1FFF; i++) {
            if (VirtualModMemoryItems[i].isRoot && VirtualModMemoryTable[i]) {
                free(VirtualModMemoryTable[i]);
            }
        }
    }
    isFirst = 0;
    FreePoolVirtualModMemorySetCount(0x1FFF);
    for (int i = 0; i < 0x1FFF; i++) {
        VirtualModMemoryItems[i].isRoot = 1;
        VirtualModMemoryTable[i] = NULL;
        FreePoolVirtualModMemory[i] = i;
    }
    FreePoolVirtualModMemoryIndex = 0x1FFF - 1;
}

int virtualModMemoryAllocate(uint32_t size) {
    uint8_t* block = malloc(size);
    uint16_t id = FreePoolVirtualModMemoryPop();
    VirtualModMemoryTable[id] = block;
    VirtualModMemoryItems[id].isRoot = 1;
    return id;
}

int virtualModMemoryRelocate(uint16_t block, uint32_t size) {
    block = block & VirtualModMemoryMASK;
    if (!(VirtualModMemoryTable[block] && VirtualModMemoryItems[block].isRoot)) {
        assert(0);
        return 0;
    }
    VirtualModMemoryTable[block] = realloc(VirtualModMemoryTable[block], size);
    return size;
}

int virtualModMemoryConvertFromRealMemory(uint8_t* block, uint8_t isRoot) {
    uint16_t id = FreePoolVirtualModMemoryPop();
    VirtualModMemoryTable[id] = block;
    VirtualModMemoryItems[id].isRoot = isRoot;
}

int virtualModMemoryFree(uint16_t block) {
    block = block & VirtualModMemoryMASK;
    if (!(VirtualModMemoryTable[block])) {
        assert(0);
        return -1;
    }
    if (!(VirtualModMemoryItems[block].isRoot)) {
        FreePoolVirtualModMemoryPush(block);
        return 0;
    }
    free(VirtualModMemoryTable[block]);
    VirtualModMemoryTable[block] = NULL;
    FreePoolVirtualModMemoryPush(block);
}

int onlyVirtualModMemoryAllocate(uint32_t size) {
    uint8_t* block = malloc(size);
    uint16_t id = FreePoolVirtualModMemoryPop();
    VirtualModMemoryTable[id] = block;
}

int onlyVirtualModMemoryRelocate(uint16_t block, uint32_t size) {
    VirtualModMemoryTable[block] = realloc(VirtualModMemoryTable[block], size);
    return size;
}

int onlyVirtualModMemoryFree(uint16_t block) {
    free(VirtualModMemoryTable[block]);
    VirtualModMemoryTable[block] = NULL;
    FreePoolVirtualModMemoryPush(block);
}

uint8_t* virtualModMemoryGetPointerForBlock(uint16_t block) {
    return VirtualModMemoryTable[block & VirtualModMemoryMASK];
}
