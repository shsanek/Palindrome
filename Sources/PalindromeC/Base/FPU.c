//
//  FPU.c
//  
//
//  Created by Alex Shipin on 11/14/22.
//

#include "FPU.h"

double fpuStack[8] = {0, 0, 0, 0, 0, 0, 0, 0};

uint8_t fpuStackIndex = 7;

uint16_t fpuRegControll = 0;
uint16_t fpuRegStatus = 0;
uint16_t fpuRegTag = 0;
uint16_t fpuRegPointer = 0;
uint16_t fpuRegInstructionPointer = 0;
uint16_t fpuRegInstructionOpcode = 0;
