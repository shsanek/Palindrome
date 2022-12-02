//
//  BaseFunction.h
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#ifndef BaseFunction_h
#define BaseFunction_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ARRAY_STACK(NAME, TYPE) \
void NAME##SetCount(uint16_t count);\
void NAME##Push(TYPE value);\
TYPE NAME##Pop();\

#define ARRAY_STACK_IMP(NAME, TYPE) \
TYPE *NAME = NULL; \
uint16_t NAME##Index = 0; \
uint16_t NAME##Count = 0; \
void NAME##SetCount(uint16_t count) { if (NAME != NULL) { free(NAME); NAME = NULL; } if (count == 0) { return; } NAME = malloc(sizeof(TYPE) * count); NAME##Count = count; NAME##Index = 0; } \
void NAME##Push(TYPE value) { NAME[NAME##Index] = value; NAME##Index++; } \
TYPE NAME##Pop() { NAME##Index--; return NAME[NAME##Index]; } \

#endif /* BaseFunction_h */
