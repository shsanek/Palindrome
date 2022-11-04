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

int8_t read8(Context* context);
uint8_t read8u(Context* context);
int16_t read16(Context* context);
uint16_t read16u(Context* context);
int32_t read32(Context* context);
uint32_t read32u(Context* context);


uint8_t* mem(Context* context, uint8_t reg);

#endif /* Read_h */
