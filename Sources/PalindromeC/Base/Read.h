//
//  Read.h
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#ifndef Read_h
#define Read_h

#include <stdio.h>
#include "Models.h"
#include "Read.h"

int8_t read8();
uint8_t read8u();
int16_t read16();
uint16_t read16u();
int32_t read32();
uint32_t read32u();


extern uint16_t debugSegmentShift;

uint8_t* memWithReplace(uint8_t reg);
uint8_t* mem(uint8_t reg);
void setMem(uint8_t reg, uint16_t mem);

#endif /* Read_h */
