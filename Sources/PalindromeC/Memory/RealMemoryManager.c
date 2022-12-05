//
//  RealModeMemoryManager.c
//  
//
//  Created by Alex Shipin on 11/30/22.
//

#include "RealMemoryManager.h"

uint8_t *RealModeMemory = NULL;

RealModeMemoryBlock *RealModeMemoryBlockHead = NULL;

RealModeMemoryBlock* getAllBlockRealModMemory() {
    return RealModeMemoryBlockHead;
}

void removeRealModeMemoryBlock(RealModeMemoryBlock *block) {
    if (block == NULL) {
        return;
    }
    RealModeMemoryBlock *next = block->next;
    RealModeMemoryBlock *back = block->back;

    if (next) { next->back = back; }
    if (back) { back->next = next; }

    if (RealModeMemoryBlockHead == block) { RealModeMemoryBlockHead = next; }

    free(block);
}

void insertRealModeMemoryBlock(RealModeMemoryBlock *new, RealModeMemoryBlock *current) {
    assert(current);
    assert(new);

    new->next = current;
    if (current) { new->back = current->back; } else { new->back = NULL;}
    if (current && current->back) { current->back->next = new; }
    if (current) { current->back = new; }


    if (current == RealModeMemoryBlockHead) { RealModeMemoryBlockHead = new; }
}

RealModeMemoryBlock* insertNewRealModeMemoryBlock(RealModeMemoryBlock *current) {
    RealModeMemoryBlock* new = malloc(sizeof(RealModeMemoryBlock));
    insertRealModeMemoryBlock(new, current);
    return new;
}

void realModMemorySetSize(uint16_t paragraphSize) {
    while (RealModeMemoryBlockHead) {
        removeRealModeMemoryBlock(RealModeMemoryBlockHead);
    }
    if (RealModeMemory != NULL) {
        free(RealModeMemory);
    }
    RealModeMemory = malloc(16 * (((int)(paragraphSize)) + 0x0FFF));
    for (int i = 0; i < 16 * (((int)(paragraphSize)) + 0x0FFF); i++) {
        RealModeMemory[i] = 0;
    }
    RealModeMemoryBlockHead = malloc(sizeof(RealModeMemoryBlock));
    RealModeMemoryBlockHead->paragraph = 0;
    RealModeMemoryBlockHead->paragraphSize = paragraphSize;
    RealModeMemoryBlockHead->isFree = 1;
    RealModeMemoryBlockHead->next = NULL;
    RealModeMemoryBlockHead->back = NULL;
    for (int i = 0; i < 8; i++) {
        SET_VALUE_IN_SEGMENT(i, SR_VALUE(i));
    }
}

int realModMemoryAllocateInBlock(uint16_t block, uint16_t paragraphSize, RealModeMemoryBlock* current);

int allocateMemoryLoadWithForceBlock(uint16_t paragraph, uint16_t paragraphSize) {
    RealModeMemoryBlock* current = RealModeMemoryBlockHead;
    while (current!= NULL && !(current->paragraph <= paragraph && paragraph < current->paragraphSize + current->paragraph)) {
        current = current->next;
    }
    realModMemoryAllocateInBlock(paragraph, paragraphSize, current);
    return paragraph;
}

int realModMemoryRelocate(uint16_t paragraph, uint16_t paragraphSize) {
    RealModeMemoryBlock* current = RealModeMemoryBlockHead;
    while (current!= NULL && !(current->paragraph == paragraph)) {
        current = current->next;
    }
    if (!current) { return 0; }

    if (current->paragraphSize == paragraphSize) {
        return paragraphSize;
    }
    if (current->paragraphSize > paragraphSize) {
        uint16_t diff = current->paragraphSize - paragraphSize;
        if (current->next && current->next->isFree) {
            current->next->paragraph -= diff;
            current->next->paragraphSize += diff;
            current->paragraphSize -= diff;
        } else {
            RealModeMemoryBlock* newStrongBlock = insertNewRealModeMemoryBlock(current);
            newStrongBlock->paragraph = paragraph;
            newStrongBlock->paragraphSize = paragraphSize;
            newStrongBlock->isFree = 0;

            current->paragraph += paragraphSize;
            current->paragraphSize = diff;
            current->isFree = 1;
        }
        return paragraphSize;
    }
    uint16_t diff = paragraphSize - current->paragraphSize;
    if (!(current->next && current->next->isFree)) {
        return -current->paragraphSize;
    }
    if (!(paragraphSize <= current->paragraphSize + current->next->paragraphSize)) {
        return -(current->paragraphSize + current->next->paragraphSize);
    }
    current->paragraphSize = paragraphSize;
    if (current->paragraphSize + current->next->paragraphSize == paragraphSize) {
        removeRealModeMemoryBlock(current->next);
        return paragraphSize;
    } else {
        current->next->paragraphSize -= diff;
    }
    return paragraphSize;
}

int realModMemoryAllocateInBlock(uint16_t block, uint16_t paragraphSize, RealModeMemoryBlock* current) {
    if (!current) { assert(0); return -1; }
    if (!current->isFree) { assert(0); return -2; }
    if (current->paragraphSize < paragraphSize) { assert(0); return -3; }
    if (!(current->paragraph <= block && block < current->paragraphSize + current->paragraph)) { assert(0); return -4; }

    if (current->paragraph != block) {
        RealModeMemoryBlock* firstFreeBlock = insertNewRealModeMemoryBlock(current);
        firstFreeBlock->paragraph = current->paragraph;
        firstFreeBlock->isFree = 1;
        firstFreeBlock->paragraphSize = block - current->paragraph;
    }
    RealModeMemoryBlock* newStrongBlock = insertNewRealModeMemoryBlock(current);
    newStrongBlock->paragraph = block;
    newStrongBlock->paragraphSize = paragraphSize;
    newStrongBlock->isFree = 0;
    if (current->paragraph + current->paragraphSize > block + paragraphSize) {
        uint16_t newSize = current->paragraph + current->paragraphSize - (block + paragraphSize);
        current->paragraphSize = newSize;
        current->paragraph = (block + paragraphSize);
    } else {
        removeRealModeMemoryBlock(current);
    }
}

int realModMemoryAllocate(uint16_t paragraphSize) {
    uint16_t max = 0;
    RealModeMemoryBlock* current = RealModeMemoryBlockHead;
    while (current!= NULL && !(current->isFree && current->paragraphSize >= paragraphSize)) {
        if (current->paragraphSize > max && current->isFree) { max = current->paragraphSize; }
        current = current->next;
    }
    if (!current) { return -max; }
    uint16_t result = current->paragraph;
    realModMemoryAllocateInBlock(result, paragraphSize, current);
    return result;
}

int realModMemoryFree(uint16_t block) {
    block = block;
    RealModeMemoryBlock* current = RealModeMemoryBlockHead;
    while (current!= NULL && !(current->paragraph >= block)) {
        current = current->next;
    }
    if (current == NULL) { return -1; }

    current->isFree = 1;

    if (current->next && current->next->isFree) {
        current->paragraphSize += current->next->paragraphSize;
        removeRealModeMemoryBlock(current->next);
    }

    if (current->back && current->back->isFree) {
        current->paragraphSize += current->back->paragraphSize;
        current->paragraph += current->back->paragraph;
        removeRealModeMemoryBlock(current->back);
    }

    return 0;
}

uint8_t* realModMemoryGetPointerForBlock(uint16_t block) {
    return RealModeMemory + (block * 16);
}
