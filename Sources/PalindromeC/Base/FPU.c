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
