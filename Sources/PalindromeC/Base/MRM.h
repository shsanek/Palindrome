//
//  MRM.h
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#ifndef MRM_h
#define MRM_h

#include <stdio.h>
#include "Models.h"
#include "Read.h"
#include "Registers.h"
#include "../Support/Log.h"

uint8_t* readAddressMRM32For8(uint8_t mrmByte);
uint8_t* readAddressMRM32For16(uint8_t mrmByte);
uint8_t* readAddressMRM32For32(uint8_t mrmByte);

uint8_t* readAddressMRM16For8(uint8_t mrmByte);
uint8_t* readAddressMRM16For16(uint8_t mrmByte);
uint8_t* readAddressMRM16For32(uint8_t mrmByte);

int32_t effectiveAddressMRM32For32(uint8_t mrmByte);
int16_t effectiveAddressMRM16For16(uint8_t mrmByte);

#endif /* MRM_h */
