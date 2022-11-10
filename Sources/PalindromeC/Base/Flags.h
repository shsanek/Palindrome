//
//  Flags.h
//  
//
//  Created by Alex Shipin on 11/6/22.
//

#ifndef Flags_h
#define Flags_h

#include <stdio.h>
#include "Models.h"

/// Carry Flag    Флаг переноса    Состояние
#define CF 0

/// Parity Flag    Флаг чётности    Состояние
#define PF 1

/// Auxiliary Carry Flag    Вспомогательный флаг переноса    Состояние
#define AF 4

/// Zero Flag    Флаг нуля    Состояние
#define ZF 6

/// Sign Flag    Флаг знака    Состояние
#define SF 7

/// Trap Flag    Флаг трассировки (пошаговое выполнение)    Системный
#define TF 8

/// Interrupt Enable Flag    Флаг разрешения прерываний    Системный
#define IF 9

/// Direction Flag    Флаг направления    Управляющий
#define DF 10

/// Overflow Flag    Флаг переполнения    Состояние
#define OF 11

/// I/O Privilege Level    Уровень приоритета ввода-вывода    Системный
#define IOPL 12

/// NT    Nested Task    Флаг вложенности задач    Системный    80286
#define NT 14

#define GET_FLAG(flag) ((uint8_t)((reg_flags >> flag) & 0x1))

#define SET_FLAG(flag, value) { reg_flags ^= (-(int32_t)((value ? 1 : 0)) ^ reg_flags) & (1UL << flag); }

#define PARITY16(x)  (parity_lookup[((x)>>8)&0xff]^parity_lookup[(x)&0xff]^GET_FLAG(PF))
#define PARITY32(x)  (PARITY16((x)&0xffff)^PARITY16(((x)>>16)&0xffff)^GET_FLAG(PF))
extern uint16_t parity_lookup[256];

typedef enum {
    t_UNKNOWN=0,
    t_ADD8,t_ADD16,t_ADD32,
    t_OR8,t_OR16,t_OR32,
    t_ADC8,t_ADC16,t_ADC32,
    t_SBB8,t_SBB16,t_SBB32,
    t_AND8,t_AND16,t_AND32,
    t_SUB8,t_SUB16,t_SUB32,
    t_XOR8,t_XOR16,t_XOR32,
    t_CMP8,t_CMP16,t_CMP32,
    t_INC8,t_INC16,t_INC32,
    t_DEC8,t_DEC16,t_DEC32,
    t_TEST8,t_TEST16,t_TEST32,
    t_SHL8,t_SHL16,t_SHL32,
    t_SHR8,t_SHR16,t_SHR32,
    t_SAR8,t_SAR16,t_SAR32,
    t_ROL8,t_ROL16,t_ROL32,
    t_ROR8,t_ROR16,t_ROR32,
    t_RCL8,t_RCL16,t_RCL32,
    t_RCR8,t_RCR16,t_RCR32,
    t_NEG8,t_NEG16,t_NEG32,

    t_DSHL16,t_DSHL32,
    t_DSHR16,t_DSHR32,
    t_MUL,t_DIV,
    t_NOTDONE,
    t_LASTFLAG
} LazyFlagType;

extern int32_t reg_flags;

extern uint8_t LazyFlagResultContainer8;
extern uint16_t LazyFlagResultContainer16;
extern uint32_t LazyFlagResultContainer32;

extern uint8_t LazyFlagVarA8;
extern uint16_t LazyFlagVarA16;
extern uint32_t LazyFlagVarA32;

extern uint8_t LazyFlagVarB8;
extern uint16_t LazyFlagVarB16;
extern uint32_t LazyFlagVarB32;

extern LazyFlagType lazyFlagType;
extern uint8_t oldcf;

void FillFlags();
void FillFlagsNoCFOF(void);

#define COND0x00 (GET_FLAG(OF) == 1)
#define COND0x01 (GET_FLAG(OF) == 0)
#define COND0x02 (GET_FLAG(CF) == 1)
#define COND0x03 (GET_FLAG(CF) == 0)

#define COND0x04 (GET_FLAG(ZF) == 1)
#define COND0x05 (GET_FLAG(ZF) == 0)
#define COND0x06 (GET_FLAG(ZF) == 1 || GET_FLAG(CF) == 1)
#define COND0x07 (GET_FLAG(ZF) == 0 && GET_FLAG(CF) == 0)

#define COND0x08 (GET_FLAG(SF) == 1)
#define COND0x09 (GET_FLAG(SF) == 0)
#define COND0x0A (GET_FLAG(PF) == 1)
#define COND0x0B (GET_FLAG(PF) == 0)

#define COND0x0C (GET_FLAG(SF) != GET_FLAG(OF))
#define COND0x0D (GET_FLAG(SF) == GET_FLAG(OF))
#define COND0x0E (GET_FLAG(ZF) == 1 || (GET_FLAG(SF) != GET_FLAG(OF)))
#define COND0x0F (GET_FLAG(ZF) == 0 && (GET_FLAG(SF) == GET_FLAG(OF)))

#endif /* Flags_h */
