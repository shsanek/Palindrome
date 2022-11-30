//
//  FPU.h
//  
//
//  Created by Alex Shipin on 11/14/22.
//

#ifndef FPU_h
#define FPU_h

#include <stdio.h>

extern double fpuStack[8];
extern uint8_t fpuStackIndex;

extern uint16_t fpuRegControll;
extern uint16_t fpuRegStatus;
extern uint16_t fpuRegTag;
extern uint16_t fpuRegPointer;
extern uint16_t fpuRegInstructionPointer;
extern uint16_t fpuRegInstructionOpcode;

#endif /* FPU_h */
