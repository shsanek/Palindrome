//
//  BaseFunction.h
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#ifndef BaseFunction_h
#define BaseFunction_h

#include <stdio.h>
#include "../Base/Models.h"
#include "../Base/Read.h"
#include "../Base/Registers.h"
#include "../Base/MRM.h"
#include "../Base/Flags.h"

#define MCOMMAND_INTERFACE(NAME) \
void mCommandFunction32##NAME(CommandInfo info); \
void mCommandFunction16##NAME(CommandInfo info);

#define MCOMMAND_MRM_FUNCTION(NAME, D, W, F8, F16, F32)\
void mCommandFunction16##NAME(CommandInfo info) {\
    uint8_t mrmByte = read8u();\
    uint8_t* destination = (uint8_t*)readAddressMRM16(mrmByte);\
    if (W && (info.command & 0x0001)) {\
        uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);\
        if (1 && (info.command & 0x0002)) { swipe(source, destination); }\
        F16;\
    } else {\
        uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);\
        if (1 && (info.command & 0x0002)) { swipe(source, destination); }\
        F8;\
    }\
}\
void mCommandFunction32##NAME(CommandInfo info) {\
    uint8_t mrmByte = read8u();\
    uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);\
    uint8_t* destination = (uint8_t*)readAddressMRM32(mrmByte);\
    if (W && (info.command & 0x0001)) {\
        if (info.prefixInfo.addressSizePrefix) {\
            uint8_t* source = (uint8_t*)readRegisterMRM16(mrmByte);\
            if (1 && (info.command & 0x0002)) { swipe(source, destination); }\
            F16;\
        } else {\
            uint8_t* source = (uint8_t*)readRegisterMRM32(mrmByte);\
            if (1 && (info.command & 0x0002)) { swipe(source, destination); }\
            F32;\
        }\
    } else {\
        uint8_t* source = (uint8_t*)readRegisterMRM8(mrmByte);\
        if (1 && (info.command & 0x0002)) { swipe(source, destination); }\
        F8;\
    }\
}

#define swipe(a, b) { void* tmp = a; a = b; b = tmp; } ;

#endif /* BaseFunction_h */
