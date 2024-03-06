//
//  VirtualMemoryManager.c
//  
//
//  Created by Alex Shipin on 12/2/22.
//

#include "VirtualMemoryManager.h"

typedef struct VirtualMemoryTable {
    VirtualMemoryItem items[0x1FFF];

    uint8_t isFree;

    VirtualMemoryItem *allocateStack;
    VirtualMemoryItem *freeStack;
} VirtualMemoryTable;

uint8_t* VirtualMemoryPointerMap[0x3FFF];

uint16_t BasePointerMapIndex = 0;
uint8_t* BasePointerMap[0x10000];
#define BASE_POINTER_MASK 0xFFFF0000;
#define OFFSET_POINTER_MASK 0x0000FFFF;

uint isFirst = 1;

VirtualMemoryTable VirtualMemoryTables[0xFF];

void freeVirtualMemoryTable(HANDLER handler) {
    if (VirtualMemoryTables[handler].isFree) {
        return;
    }
    VirtualMemoryItem* item = VirtualMemoryTables[handler].allocateStack;
    while (item) {
        if (item->isAllocate) {
            free(item->pointer);
        }
        item = item->next;
    }
}

void moveVirtualMemoryPointerForFastMap(HANDLER handler) {
    uint8_t shift = 1;
    uint8_t mult = 1;
    if (handler == 0) {
        shift = 0;
        mult = 2;
    }
    for (int i = 0; i < 0x1FFF; i++) {
        BasePointerMap[i * mult + shift] = VirtualMemoryTables[handler].items[i].pointer;
    }
}

void installVirtualMemoryGlobalTable() {
    if (!isFirst) {
        for (uint16_t i = 0; i < MAX_HANDLER + 1; i++){
            freeVirtualMemoryTable(i);
        }
    }
    for (uint16_t i = 0; i < 0xFFFF; i++) {
        BasePointerMap[i] = NULL;
    }
    BasePointerMapIndex = 0;
    for (uint16_t i = 0; i < MAX_HANDLER + 1; i++){
        VirtualMemoryTables[i].isFree = 1;
    }
    installVirtualMemoryTableForProcess(0);
    moveVirtualMemoryPointerForFastMap(0);
}

void installVirtualMemoryTableForProcess(HANDLER handler) {
    assert(VirtualMemoryTables[handler].isFree);
    VirtualMemoryTables[handler].isFree = 0;
    for (int i = 0; i < 0x1FF; i++) {
        VirtualMemoryTables[handler].items[i].isAllocate = 0;
        VirtualMemoryTables[handler].items[i].index = i;
        VirtualMemoryTables[handler].items[i].pointer = NULL;
        VirtualMemoryTables[handler].items[i].base = 0;
        VirtualMemoryTables[handler].items[i].limit = 0;
        VirtualMemoryTables[handler].items[i].next = (i < 0x1FE) ? (VirtualMemoryTables[handler].items + (i + 1)) : NULL;
    }
    VirtualMemoryTables[handler].allocateStack = NULL;

    VirtualMemoryTables[handler].freeStack = VirtualMemoryTables[handler].items;
}

HANDLER activeVirtualMemoryTable = 0;

void activeVirtualMemoryTableForProcess(HANDLER handler) {
    assert(!VirtualMemoryTables[handler].isFree);
    moveVirtualMemoryPointerForFastMap(handler);
    activeVirtualMemoryTable = handler;
}


uint64_t encodeVirtualMemoryItemDescriptor(VirtualMemoryItem item) {
    uint64_t result = 0;

    result = result | (((uint64_t)item.base & 0xFF000000) << (56 - 24));
    result = result | (((uint64_t)item.UDX & 0x03) << 52);
    result = result | (((uint64_t)item.size & 0x01) << 55);
    result = result | (((uint64_t)item.limit & 0xF000) << (48 - 4));
    result = result | (((uint64_t)item.info) << 40);
    result = result | (((uint64_t)item.base & 0x00FFFFFF) << (16));
    result = result | (((uint64_t)item.limit & 0x0FFF));

    return result;
}

VirtualMemoryItem decodeVirtualMemoryItemDescriptor(uint64_t item) {
    VirtualMemoryItem result;

    result.base = ((item >> (56 - 24)) & 0xFF000000) | ((item >> (16)) & 0x00FFFFFF);
    result.limit = ((item >> (48 - 4)) & 0xF000) | ((item) & 0x0FFF);

    result.UDX = ((item >> (52)) & 0x03);
    result.size = ((item >> (55)) & 0x01);
    result.info = ((item >> (40)) & 0xFF);

    result.pointer = BasePointerMap[(0xFFFF0000 & result.base) >> 16];
    if (result.pointer != NULL) {
        result.pointer += (result.base & 0x0000FFFF);
    }
    return result;
}

void allocateVirtualMemoryDescriptors(HANDLER handler, uint16_t count, uint16_t* resultID) {
    assert(!VirtualMemoryTables[handler].isFree);
    if (count == 0) {
        resultID = NULL;
    }
    while (VirtualMemoryTables[handler].freeStack && count != 0) {
        VirtualMemoryItem *item = VirtualMemoryTables[handler].freeStack;
        VirtualMemoryTables[handler].freeStack = item->next;
        item->next = VirtualMemoryTables[handler].allocateStack;
        VirtualMemoryTables[handler].allocateStack = item;
        item->isAllocate = 0;
        item->pointer = NULL;
        item->base = 0;
        item->limit = 0;
        item->size = 0;
        item->info = 0;
        item->UDX = 0;
    }
    resultID = VirtualMemoryTables[handler].allocateStack->index;
}

void setVirtualMemoryBlock(HANDLER handler, uint8_t allocate, uint8_t* memory, uint32_t size, uint16_t* resultID) {
    assert(!VirtualMemoryTables[handler].isFree);

    int sectionSize = (256 * 256);
    int section = size / sectionSize + (size % sectionSize ? 1 : 0);

    allocateVirtualMemoryDescriptors(handler, section, resultID);
    VirtualMemoryItem *item = VirtualMemoryTables[handler].items + *resultID;

    for (int i = 0; i < section; i++) {
        BasePointerMap[BasePointerMapIndex] = memory + sectionSize * i;
        item->pointer = memory + sectionSize * i;
        item->base = (((uint32_t)BasePointerMapIndex) * 0x100) + ((uint32_t)sectionSize * i);
        if (i == section - 1) {
            item->limit = ((size % sectionSize == 0) ? sectionSize : size % sectionSize);
        } else {
            item->limit = sectionSize;
        }
        item->info |= 0x80;
        item->isAllocate = allocate;
        item = item->next;
        BasePointerMapIndex += 1;
    }
}

void allocateVirtualMemoryBlock(HANDLER handler, uint32_t size, uint16_t* resultID) {
    assert(!VirtualMemoryTables[handler].isFree);


}
