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

extern uint32_t RegFlagBaseValue;

/// Carry Flag    Флаг переноса    Состояние
extern uint8_t CF;

/// Parity Flag    Флаг чётности    Состояние
extern uint8_t PF;

/// Auxiliary Carry Flag    Вспомогательный флаг переноса    Состояние
extern uint8_t AF;

/// Zero Flag    Флаг нуля    Состояние
extern uint8_t ZF;

/// Sign Flag    Флаг знака    Состояние
extern uint8_t SF;

/// Trap Flag    Флаг трассировки (пошаговое выполнение)    Системный
extern uint8_t TF;

/// Interrupt Enable Flag    Флаг разрешения прерываний    Системный
extern uint8_t IF;

/// Direction Flag    Флаг направления    Управляющий
extern uint8_t DF;

/// Overflow Flag    Флаг переполнения    Состояние
extern uint8_t OF;

/// I/O Privilege Level    Уровень приоритета ввода-вывода    Системный
extern uint8_t IOPL;

/// NT    Nested Task    Флаг вложенности задач    Системный    80286
extern uint8_t NT;

extern uint8_t AC;

extern uint8_t ID;

extern uint8_t VM;


#define GET_FLAG(flag) (flag)
#define SET_FLAG(flag, value) { flag = (((value) == 0) ? 0x0 : 1); }

#define SET_BIT(target, bit, value) { target ^= (-(int8_t)(((value) ? 1 : 0)) ^ target) & (1UL << bit); }

extern uint8_t parity_lookup[0x100];
extern uint8_t parity_lookup16[0x10000];

#define PARITY8(x)  (parity_lookup[((x)&0xff)])
#define PARITY16(x) (parity_lookup16[(x)&0xffff])
#define PARITY32(x) (!(PARITY16((x)&0xffff)^PARITY16(((x)>>16)&0xffff)))


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
    t_VALUE8, t_VALUE16, t_VALUE32,
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

#define FLAG_CF         0x00000001U
#define FLAG_PF         0x00000004U
#define FLAG_AF         0x00000010U
#define FLAG_ZF         0x00000040U
#define FLAG_SF         0x00000080U
#define FLAG_OF         0x00000800U

#define FLAG_TF         0x00000100U
#define FLAG_IF         0x00000200U
#define FLAG_DF         0x00000400U

#define FLAG_IOPL       0x00003000U
#define FLAG_NT         0x00004000U
#define FLAG_VM         0x00020000U
#define FLAG_AC         0x00040000U
#define FLAG_ID         0x00200000U

#define FMASK_TEST (FLAG_CF | FLAG_PF | FLAG_AF | FLAG_ZF | FLAG_SF | FLAG_OF)
#define FMASK_NORMAL (FMASK_TEST | FLAG_DF | FLAG_TF | FLAG_IF )
#define FMASK_ALL (FMASK_NORMAL | FLAG_IOPL | FLAG_NT)

void EncodeFlagsRegister();
void DecodeFlagsRegister16();
void DecodeFlagsRegister32();

void FlagInstall();

#endif /* Flags_h */
