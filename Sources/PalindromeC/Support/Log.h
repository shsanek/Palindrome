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

#define DEBUG_RUN(a) a

void sprintHex(uint8_t* value, char* out);
void printHex(uint8_t* value);

void appendInDebugLineHex(uint8_t* value);
void appendString(char* value);
void printDebugLine();
void clearDebugLine();

#endif /* Log_h */
