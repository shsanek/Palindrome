//
//  Log.h
//  
//
//  Created by Alex Shipin on 11/26/22.
//

#ifndef Log_h
#define Log_h

#include <stdio.h>
#include "LogRegisters.h"

#define LOG(F, ARG...) printf( F , ARG )

void printHex(uint8_t* value, char* out);

#endif /* Log_h */
