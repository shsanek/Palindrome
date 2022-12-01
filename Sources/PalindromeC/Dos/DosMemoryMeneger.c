//
//  DosMemoryMeneger.c
//  
//
//  Created by Alex Shipin on 11/30/22.
//

#include "DosMemoryMeneger.h"

ARRAY_STACK_IMP(debugTestNewMemoryBlock, uint16_t);

typedef struct DosMemoryBlock {
    uint16_t paragraph;
    uint16_t paragraphSize;
    uint8_t isFree;

    struct DosMemoryBlock* next;
    struct DosMemoryBlock* back;
} DosMemoryBlock;

DosMemoryBlock *DosMemoryBlockHead = NULL;

void removeDosMemoryBlock(DosMemoryBlock *block) {
    if (block == NULL) {
        return;
    }
    DosMemoryBlock *next = block->next;
    DosMemoryBlock *back = block->back;

    if (next) { next->back = back; }
    if (back) { back->next = next; }

    if (DosMemoryBlockHead == block) { DosMemoryBlockHead = next; }

    free(block);
}

void insertDosMemoryBlock(DosMemoryBlock *new, DosMemoryBlock *current) {
    assert(current);
    assert(new);

    new->next = current;
    if (current) { new->back = current->back; } else { new->back = NULL;}
    if (current && current->back) { current->back->next = new; }
    if (current) { current->back = new; }


    if (current == DosMemoryBlockHead) { DosMemoryBlockHead = new; }
}

DosMemoryBlock* insertNewDosMemoryBlock(DosMemoryBlock *current) {
    DosMemoryBlock* new = malloc(sizeof(DosMemoryBlock));
    insertDosMemoryBlock(new, current);
    return new;
}

void setDosMemoryCount(uint32_t size) {
    while (DosMemoryBlockHead) {
        removeDosMemoryBlock(DosMemoryBlockHead);
    }
    DosMemoryBlockHead = malloc(sizeof(DosMemoryBlock));
    DosMemoryBlockHead->paragraph = 0;
    DosMemoryBlockHead->paragraphSize = (size / 16 > 0x00FF) ? 0xFFFF : size / 16;
    DosMemoryBlockHead->isFree = 1;
    DosMemoryBlockHead->next = NULL;
    DosMemoryBlockHead->back = NULL;
}

int dosAllocateBlockMemoryInBlock(uint16_t block, uint16_t size, DosMemoryBlock* current);

int setDosTestAllocateFor(uint16_t block, uint16_t size) {
    block = block;
    DosMemoryBlock* current = DosMemoryBlockHead;
    while (current!= NULL && !(current->paragraph <= block && block < current->paragraphSize + current->paragraph)) {
        current = current->next;
    }
    return dosAllocateBlockMemoryInBlock(block, size, current);
}

int dosAllocateBlockMemoryInBlock(uint16_t block, uint16_t size, DosMemoryBlock* current) {
    if (!current) { assert(0); return -1; }
    if (!current->isFree) { assert(0); return -2; }
    if (current->paragraphSize < size) { assert(0); return -3; }
    if (!(current->paragraph <= block && block < current->paragraphSize + current->paragraph)) { assert(0); return -4; }

    if (current->paragraph != block) {
        DosMemoryBlock* firstFreeBlock = insertNewDosMemoryBlock(current);
        firstFreeBlock->paragraph = current->paragraph;
        firstFreeBlock->isFree = 1;
        firstFreeBlock->paragraphSize = block - current->paragraph;
    }
    DosMemoryBlock* newStrongBlock = insertNewDosMemoryBlock(current);
    newStrongBlock->paragraph = block;
    newStrongBlock->paragraphSize = size;
    newStrongBlock->isFree = 0;
    if (current->paragraph + current->paragraphSize > block + size) {
        uint16_t newSize = current->paragraph + current->paragraphSize - (block + size);
        current->paragraphSize = newSize;
        current->paragraph = (block + size);
    } else {
        removeDosMemoryBlock(current);
    }
}

int dosAllocateBlockMemory(uint16_t size) {
    DEBUG_RUN({
        if (debugTestNewMemoryBlockIndex > 0) {
            setDosTestAllocateFor(debugTestNewMemoryBlockPop(), size);
            return;
        }
    })
    uint16_t max = 0;
    DosMemoryBlock* current = DosMemoryBlockHead;
    while (current!= NULL && !(current->isFree && current->paragraphSize >= size + 1)) {
        if (current->paragraphSize > max && current->isFree) { max = current->paragraphSize; }
        current = current->next;
    }
    if (!current) { return -max; }
    uint16_t result = current->paragraph + 1;
    dosAllocateBlockMemoryInBlock(result, size, current);
    return result;
}

int dosFreeBlockMemory(uint16_t block) {
    block = block;
    DosMemoryBlock* current = DosMemoryBlockHead;
    while (current!= NULL && !(current->paragraph >= block)) {
        current = current->next;
    }
    if (current == NULL) { return -1; }

    current->isFree = 1;

    if (current->next && current->next->isFree) {
        current->paragraphSize += current->next->paragraphSize;
        removeDosMemoryBlock(current->next);
    }

    if (current->back && current->back->isFree) {
        current->paragraphSize += current->back->paragraphSize;
        current->paragraph += current->back->paragraph;
        removeDosMemoryBlock(current->back);
    }

    return 0;
}
