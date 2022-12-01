//
//  Flags.c
//  
//
//  Created by Alex Shipin on 11/6/22.
//

#include "Flags.h"
#include "Registers.h"
#include "Read.h"


/// Carry Flag    Флаг переноса    Состояние
uint8_t CF = 0;

/// Parity Flag    Флаг чётности    Состояние
uint8_t PF = 0;

/// Auxiliary Carry Flag    Вспомогательный флаг переноса    Состояние
uint8_t AF = 0;

/// Zero Flag    Флаг нуля    Состояние
uint8_t ZF = 0;

/// Sign Flag    Флаг знака    Состояние
uint8_t SF = 0;

/// Trap Flag    Флаг трассировки (пошаговое выполнение)    Системный
uint8_t TF = 0;

/// Interrupt Enable Flag    Флаг разрешения прерываний    Системный
uint8_t IF = 0;

/// Direction Flag    Флаг направления    Управляющий
uint8_t DF = 0;

/// Overflow Flag    Флаг переполнения    Состояние
uint8_t OF = 0;

/// I/O Privilege Level    Уровень приоритета ввода-вывода    Системный
uint8_t IOPL = 0;

/// NT    Nested Task    Флаг вложенности задач    Системный    80286
uint8_t NT = 0;

uint8_t AC = 0;

uint8_t ID = 0;

uint8_t VM = 0;

int32_t reg_flags = 0;

uint32_t RegFlagBaseValue = 0;
uint8_t LazyFlagResultContainer8 = 0;
uint16_t LazyFlagResultContainer16 = 0;
uint32_t LazyFlagResultContainer32 = 0;

uint8_t LazyFlagVarA8 = 0;
uint16_t LazyFlagVarA16 = 0;
uint32_t LazyFlagVarA32 = 0;

uint8_t LazyFlagVarB8 = 0;
uint16_t LazyFlagVarB16 = 0;
uint32_t LazyFlagVarB32 = 0;

LazyFlagType lazyFlagType = 0;
uint8_t oldcf = 0;

uint16_t parity_lookup[256] = {
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0,
  1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1
  };

#define DOFLAG_PF    SET_FLAG(PF, (parity_lookup[LazyFlagResultContainer8]));

#define DOFLAG_AF    SET_FLAG(AF, (((LazyFlagVarA8 ^ LazyFlagVarB8) ^ LazyFlagResultContainer8) & 0x10U));

#define DOFLAG_ZFb    SET_FLAG(ZF, LazyFlagResultContainer8==0);
#define DOFLAG_ZFw    SET_FLAG(ZF, LazyFlagResultContainer16==0);
#define DOFLAG_ZFd    SET_FLAG(ZF, LazyFlagResultContainer32==0);

#define DOFLAG_SFb    SET_FLAG(SF, (LazyFlagResultContainer8 & 0x80U));
#define DOFLAG_SFw    SET_FLAG(SF, (LazyFlagResultContainer16 & 0x8000U));
#define DOFLAG_SFd    SET_FLAG(SF, (LazyFlagResultContainer32 & 0x80000000U));

void FillFlags() {
    switch (lazyFlagType) {
    case t_UNKNOWN:
        break;
    case t_ADD8:
        SET_FLAG(CF,(LazyFlagResultContainer8<LazyFlagVarA8));
        DOFLAG_AF;
        DOFLAG_ZFb;
        DOFLAG_SFb;
        SET_FLAG(OF,((LazyFlagVarA8 ^ LazyFlagVarB8 ^ 0x80) & (LazyFlagResultContainer8 ^ LazyFlagVarA8)) & 0x80);
        DOFLAG_PF;
        break;
    case t_ADD16:
        SET_FLAG(CF,(LazyFlagResultContainer16<LazyFlagVarA16));
        DOFLAG_AF;
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,((LazyFlagVarA16 ^ LazyFlagVarB16 ^ 0x8000) & (LazyFlagResultContainer16 ^ LazyFlagVarA16)) & 0x8000);
        DOFLAG_PF;
        break;
    case t_ADD32:
        SET_FLAG(CF,(LazyFlagResultContainer32<LazyFlagVarA32));
        DOFLAG_AF;
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,((LazyFlagVarA32 ^ LazyFlagVarB32 ^ 0x80000000) & (LazyFlagResultContainer32 ^ LazyFlagVarA32)) & 0x80000000);
        DOFLAG_PF;
        break;
    case t_ADC8:
        SET_FLAG(CF,(LazyFlagResultContainer8 < LazyFlagVarA8 || LazyFlagResultContainer8 < LazyFlagVarB8) ||
                 (oldcf && (LazyFlagResultContainer8 < LazyFlagVarA8 + 1 || LazyFlagResultContainer8 < LazyFlagVarB8 + 1)))
        DOFLAG_AF;
        DOFLAG_ZFb;
        DOFLAG_SFb;
        SET_FLAG(OF,((LazyFlagVarA8 ^ LazyFlagVarB8 ^ 0x80) & (LazyFlagResultContainer8 ^ LazyFlagVarA8)) & 0x80);
        DOFLAG_PF;
        break;
    case t_ADC16:
        SET_FLAG(CF,(LazyFlagResultContainer16 < LazyFlagVarA16 || LazyFlagResultContainer16 < LazyFlagVarB16) ||
                 (oldcf && (LazyFlagResultContainer16 < LazyFlagVarA16 + 1 || LazyFlagResultContainer16 < LazyFlagVarB16 + 1)));
        DOFLAG_AF;
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,((LazyFlagVarA16 ^ LazyFlagVarB16 ^ 0x8000) & (LazyFlagResultContainer16 ^ LazyFlagVarA16)) & 0x8000);
        DOFLAG_PF;
        break;
    case t_ADC32:
        SET_FLAG(CF,(LazyFlagResultContainer32 < LazyFlagVarA32 || LazyFlagResultContainer32 < LazyFlagVarB32) ||
                 (oldcf && (LazyFlagResultContainer32 < LazyFlagVarA32 + 1 || LazyFlagResultContainer32 < LazyFlagVarB32 + 1)));
        DOFLAG_AF;
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,((LazyFlagVarA32 ^ LazyFlagVarB32 ^ 0x80000000) & (LazyFlagResultContainer32 ^ LazyFlagVarA32)) & 0x80000000);
        DOFLAG_PF;
        break;


    case t_SBB8:
        SET_FLAG(CF,(LazyFlagVarA8 < LazyFlagResultContainer8) || (oldcf && (LazyFlagVarB8==0xff)));
        DOFLAG_AF;
        DOFLAG_ZFb;
        DOFLAG_SFb;
        SET_FLAG(OF,(LazyFlagVarA8 ^ LazyFlagVarB8) & (LazyFlagVarA8 ^ LazyFlagResultContainer8) & 0x80);
        DOFLAG_PF;
        break;
    case t_SBB16:
        SET_FLAG(CF,(LazyFlagVarA16 < LazyFlagResultContainer16) || (oldcf && (LazyFlagVarB16==0xffff)));
        DOFLAG_AF;
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,(LazyFlagVarA16 ^ LazyFlagVarB16) & (LazyFlagVarA16 ^ LazyFlagResultContainer16) & 0x8000);
        DOFLAG_PF;
        break;
    case t_SBB32:
        SET_FLAG(CF,(LazyFlagVarA32 < LazyFlagResultContainer32) || (oldcf && (LazyFlagVarB32==0xffffffff)));
        DOFLAG_AF;
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,(LazyFlagVarA32 ^ LazyFlagVarB32) & (LazyFlagVarA32 ^ LazyFlagResultContainer32) & 0x80000000);
        DOFLAG_PF;
        break;


    case t_SUB8:
    case t_CMP8:
        SET_FLAG(CF,(LazyFlagVarA8<LazyFlagVarB8));
        DOFLAG_AF;
        DOFLAG_ZFb;
        DOFLAG_SFb;
        SET_FLAG(OF,(LazyFlagVarA8 ^ LazyFlagVarB8) & (LazyFlagVarA8 ^ LazyFlagResultContainer8) & 0x80);
        DOFLAG_PF;
        break;
    case t_SUB16:
    case t_CMP16:
        SET_FLAG(CF,(LazyFlagVarA16<LazyFlagVarB16));
        DOFLAG_AF;
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,(LazyFlagVarA16 ^ LazyFlagVarB16) & (LazyFlagVarA16 ^ LazyFlagResultContainer16) & 0x8000);
        DOFLAG_PF;
        break;
    case t_SUB32:
    case t_CMP32:
        SET_FLAG(CF,(LazyFlagVarA32<LazyFlagVarB32));
        DOFLAG_AF;
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,(LazyFlagVarA32 ^ LazyFlagVarB32) & (LazyFlagVarA32 ^ LazyFlagResultContainer32) & 0x80000000);
        DOFLAG_PF;
        break;


    case t_OR8:
        SET_FLAG(CF,0);
        SET_FLAG(AF,0);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        SET_FLAG(OF,0);
        DOFLAG_PF;
        break;
    case t_OR16:
        SET_FLAG(CF,0);
        SET_FLAG(AF,0);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,0);
        DOFLAG_PF;
        break;
    case t_OR32:
        SET_FLAG(CF,0);
        SET_FLAG(AF,0);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,0);
        DOFLAG_PF;
        break;


    case t_TEST8:
    case t_AND8:
        SET_FLAG(CF,0);
        SET_FLAG(AF,0);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        SET_FLAG(OF,0);
        DOFLAG_PF;
        break;
    case t_TEST16:
    case t_AND16:
        SET_FLAG(CF,0);
        SET_FLAG(AF,0);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,0);
        DOFLAG_PF;
        break;
    case t_TEST32:
    case t_AND32:
        SET_FLAG(CF,0);
        SET_FLAG(AF,0);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,0);
        DOFLAG_PF;
        break;


    case t_XOR8:
        SET_FLAG(CF,0);
        SET_FLAG(AF,0);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        SET_FLAG(OF,0);
        DOFLAG_PF;
        break;
    case t_XOR16:
        SET_FLAG(CF,0);
        SET_FLAG(AF,0);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,0);
        DOFLAG_PF;
        break;
    case t_XOR32:
        SET_FLAG(CF,0);
        SET_FLAG(AF,0);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,0);
        DOFLAG_PF;
        break;


    case t_SHL8:
        if (LazyFlagVarB8>8) { SET_FLAG(CF,0); }
        else { SET_FLAG(CF,(LazyFlagVarA8 >> (8-LazyFlagVarB8)) & 1); }
        DOFLAG_ZFb;
        DOFLAG_SFb;
        SET_FLAG(OF,((unsigned int)LazyFlagResultContainer8 >> 7U) ^ GET_FLAG(CF)); /* MSB of result XOR CF. WARNING: This only works because FLAGS_CF == 1 */
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB8&0x1f));
        break;
    case t_SHL16:
        if (LazyFlagVarB8>16) { SET_FLAG(CF,0); }
        else { SET_FLAG(CF,(LazyFlagVarA16 >> (16-LazyFlagVarB8)) & 1); }
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,((unsigned int)LazyFlagResultContainer16 >> 15U) ^ GET_FLAG(CF)); /* MSB of result XOR CF. WARNING: This only works because FLAGS_CF == 1 */
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB16&0x1f));
        break;
    case t_SHL32:
        SET_FLAG(CF,(LazyFlagVarA32 >> (32 - LazyFlagVarB8)) & 1);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,((unsigned int)LazyFlagResultContainer32 >> 31U) ^ GET_FLAG(CF)); /* MSB of result XOR CF. WARNING: This only works because FLAGS_CF == 1 */
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB32&0x1f));
        break;


    case t_DSHL16:
        SET_FLAG(CF,(LazyFlagVarA32 >> (32 - LazyFlagVarB8)) & 1);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,(LazyFlagResultContainer16 ^ LazyFlagVarA16) & 0x8000);
        DOFLAG_PF;
        break;
    case t_DSHL32:
        SET_FLAG(CF,(LazyFlagVarA32 >> (32 - LazyFlagVarB8)) & 1);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,(LazyFlagResultContainer32 ^ LazyFlagVarA32) & 0x80000000);
        DOFLAG_PF;
        break;


    case t_SHR8:
        SET_FLAG(CF,(LazyFlagVarA8 >> (LazyFlagVarB8 - 1)) & 1);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        if ((LazyFlagVarB8&0x1f)==1) { SET_FLAG(OF,(LazyFlagVarA8 >= 0x80)); }
        else { SET_FLAG(OF,0); }
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB8&0x1f));
        break;
    case t_SHR16:
        SET_FLAG(CF,(LazyFlagVarA16 >> (LazyFlagVarB8 - 1)) & 1);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        if ((LazyFlagVarB16&0x1f)==1) { SET_FLAG(OF,(LazyFlagVarA16 >= 0x8000)); }
        else { SET_FLAG(OF,0); }
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB16&0x1f));
        break;
    case t_SHR32:
        SET_FLAG(CF,(LazyFlagVarA32 >> (LazyFlagVarB8 - 1)) & 1);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        if ((LazyFlagVarB32&0x1f)==1) { SET_FLAG(OF,(LazyFlagVarA32 >= 0x80000000)); }
        else { SET_FLAG(OF,0); }
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB32&0x1f));
        break;


    case t_DSHR16:    /* Hmm this is not correct for shift higher than 16 */
        SET_FLAG(CF,(LazyFlagVarA32 >> (LazyFlagVarB8 - 1)) & 1);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,(LazyFlagResultContainer16 ^ LazyFlagVarA16) & 0x8000);
        DOFLAG_PF;
        break;
    case t_DSHR32:
        SET_FLAG(CF,(LazyFlagVarA32 >> (LazyFlagVarB8 - 1)) & 1);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,(LazyFlagResultContainer32 ^ LazyFlagVarA32) & 0x80000000);
        DOFLAG_PF;
        break;


    case t_SAR8:
        SET_FLAG(CF,(((int8_t) LazyFlagVarA8) >> (LazyFlagVarB8 - 1)) & 1);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        SET_FLAG(OF,0);
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB8&0x1f));
        break;
    case t_SAR16:
        SET_FLAG(CF,(((int16_t) LazyFlagVarA16) >> (LazyFlagVarB8 - 1)) & 1);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,0);
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB16&0x1f));
        break;
    case t_SAR32:
        SET_FLAG(CF,(((int32_t) LazyFlagVarA32) >> (LazyFlagVarB8 - 1)) & 1);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,0);
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB32&0x1f));
        break;

    case t_INC8:
        SET_FLAG(AF,(LazyFlagResultContainer8 & 0x0f) == 0);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        SET_FLAG(OF,(LazyFlagResultContainer8 == 0x80));
        DOFLAG_PF;
        break;
    case t_INC16:
        SET_FLAG(AF,(LazyFlagResultContainer16 & 0x0f) == 0);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,(LazyFlagResultContainer16 == 0x8000));
        DOFLAG_PF;
        break;
    case t_INC32:
        SET_FLAG(AF,(LazyFlagResultContainer32 & 0x0f) == 0);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,(LazyFlagResultContainer32 == 0x80000000));
        DOFLAG_PF;
        break;

    case t_DEC8:
        SET_FLAG(AF,(LazyFlagResultContainer8 & 0x0f) == 0x0f);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        SET_FLAG(OF,(LazyFlagResultContainer8 == 0x7f));
        DOFLAG_PF;
        break;
    case t_DEC16:
        SET_FLAG(AF,(LazyFlagResultContainer16 & 0x0f) == 0x0f);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,(LazyFlagResultContainer16 == 0x7fff));
        DOFLAG_PF;
        break;
    case t_DEC32:
        SET_FLAG(AF,(LazyFlagResultContainer32 & 0x0f) == 0x0f);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,(LazyFlagResultContainer32 == 0x7fffffff));
        DOFLAG_PF;
        break;

    case t_NEG8:
        SET_FLAG(CF,(LazyFlagVarA8!=0));
        SET_FLAG(AF,(LazyFlagResultContainer8 & 0x0f) != 0);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        SET_FLAG(OF,(LazyFlagVarA8 == 0x80));
        DOFLAG_PF;
        break;
    case t_NEG16:
        SET_FLAG(CF,(LazyFlagVarA16!=0));
        SET_FLAG(AF,(LazyFlagResultContainer16 & 0x0f) != 0);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        SET_FLAG(OF,(LazyFlagVarA16 == 0x8000));
        DOFLAG_PF;
        break;
    case t_NEG32:
        SET_FLAG(CF,(LazyFlagVarA32!=0));
        SET_FLAG(AF,(LazyFlagResultContainer32 & 0x0f) != 0);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        SET_FLAG(OF,(LazyFlagVarA32 == 0x80000000));
        DOFLAG_PF;
        break;
    case t_VALUE8:
        DOFLAG_ZFb;
        DOFLAG_SFb;
        break;
    case t_VALUE16:
        DOFLAG_ZFw;
        DOFLAG_SFw;
        break;
    case t_VALUE32:
        DOFLAG_ZFd;
        DOFLAG_SFd;
        break;
    case t_DIV:
    case t_MUL:
        break;

    default:
        return 0;
    }
    lazyFlagType=t_UNKNOWN;
}


void FillFlagsNoCFOF(void) {
    switch (lazyFlagType) {
    case t_UNKNOWN:
        return;
    case t_ADD8:
        DOFLAG_AF;
        DOFLAG_ZFb;
        DOFLAG_SFb;
        DOFLAG_PF;
        break;
    case t_ADD16:
        DOFLAG_AF;
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        break;
    case t_ADD32:
        DOFLAG_AF;
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        break;
    case t_ADC8:
        DOFLAG_AF;
        DOFLAG_ZFb;
        DOFLAG_SFb;
        DOFLAG_PF;
        break;
    case t_ADC16:
        DOFLAG_AF;
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        break;
    case t_ADC32:
        DOFLAG_AF;
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        break;


    case t_SBB8:
        DOFLAG_AF;
        DOFLAG_ZFb;
        DOFLAG_SFb;
        DOFLAG_PF;
        break;
    case t_SBB16:
        DOFLAG_AF;
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        break;
    case t_SBB32:
        DOFLAG_AF;
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        break;


    case t_SUB8:
    case t_CMP8:
        DOFLAG_AF;
        DOFLAG_ZFb;
        DOFLAG_SFb;
        DOFLAG_PF;
        break;
    case t_SUB16:
    case t_CMP16:
        DOFLAG_AF;
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        break;
    case t_SUB32:
    case t_CMP32:
        DOFLAG_AF;
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        break;


    case t_OR8:
        SET_FLAG(AF,0);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        DOFLAG_PF;
        break;
    case t_OR16:
        SET_FLAG(AF,0);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        break;
    case t_OR32:
        SET_FLAG(AF,0);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        break;


    case t_TEST8:
    case t_AND8:
        SET_FLAG(AF,0);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        DOFLAG_PF;
        break;
    case t_TEST16:
    case t_AND16:
        SET_FLAG(AF,0);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        break;
    case t_TEST32:
    case t_AND32:
        SET_FLAG(AF,0);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        break;


    case t_XOR8:
        SET_FLAG(AF,0);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        DOFLAG_PF;
        break;
    case t_XOR16:
        SET_FLAG(AF,0);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        break;
    case t_XOR32:
        SET_FLAG(AF,0);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        break;


    case t_SHL8:
        DOFLAG_ZFb;
        DOFLAG_SFb;
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB8&0x1f));
        break;
    case t_SHL16:
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB16&0x1f));
        break;
    case t_SHL32:
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB32&0x1f));
        break;


    case t_DSHL16:
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        break;
    case t_DSHL32:
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        break;


    case t_SHR8:
        DOFLAG_ZFb;
        DOFLAG_SFb;
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB8&0x1f));
        break;
    case t_SHR16:
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB16&0x1f));
        break;
    case t_SHR32:
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB32&0x1f));
        break;


    case t_DSHR16:    /* Hmm this is not correct for shift higher than 16 */
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        break;
    case t_DSHR32:
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        break;


    case t_SAR8:
        DOFLAG_ZFb;
        DOFLAG_SFb;
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB8&0x1f));
        break;
    case t_SAR16:
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB16&0x1f));
        break;
    case t_SAR32:
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        SET_FLAG(AF,(LazyFlagVarB32&0x1f));
        break;

    case t_INC8:
        SET_FLAG(AF,(LazyFlagResultContainer8 & 0x0f) == 0);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        DOFLAG_PF;
        break;
    case t_INC16:
        SET_FLAG(AF,(LazyFlagResultContainer16 & 0x0f) == 0);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        break;
    case t_INC32:
        SET_FLAG(AF,(LazyFlagResultContainer32 & 0x0f) == 0);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        break;

    case t_DEC8:
        SET_FLAG(AF,(LazyFlagResultContainer8 & 0x0f) == 0x0f);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        DOFLAG_PF;
        break;
    case t_DEC16:
        SET_FLAG(AF,(LazyFlagResultContainer16 & 0x0f) == 0x0f);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        break;
    case t_DEC32:
        SET_FLAG(AF,(LazyFlagResultContainer32 & 0x0f) == 0x0f);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        break;

    case t_NEG8:
        SET_FLAG(AF,(LazyFlagResultContainer8 & 0x0f) != 0);
        DOFLAG_ZFb;
        DOFLAG_SFb;
        DOFLAG_PF;
        break;
    case t_NEG16:
        SET_FLAG(AF,(LazyFlagResultContainer16 & 0x0f) != 0);
        DOFLAG_ZFw;
        DOFLAG_SFw;
        DOFLAG_PF;
        break;
    case t_NEG32:
        SET_FLAG(AF,(LazyFlagResultContainer32 & 0x0f) != 0);
        DOFLAG_ZFd;
        DOFLAG_SFd;
        DOFLAG_PF;
        break;
    case t_VALUE8:
        DOFLAG_ZFb;
        DOFLAG_SFb;
        break;
    case t_VALUE16:
        DOFLAG_ZFw;
        DOFLAG_SFw;
        break;
    case t_VALUE32:
        DOFLAG_ZFd;
        DOFLAG_SFd;
        break;

    case t_DIV:
    case t_MUL:
        break;

    default:
        break;
    }
    lazyFlagType=t_UNKNOWN;
}

#define ENCODE_FLAG(F) if (F) { reg_flags |= FLAG_##F; }
#define DECODE_FLAG(F) { F = (reg_flags & FLAG_##F) ? 1 : 0; }

//uint8_t CF = 0;
//uint8_t PF = 0;
//uint8_t AF = 0;
//uint8_t ZF = 0;
//uint8_t SF = 0;
//uint8_t TF = 0;
//uint8_t IF = 0;
//uint8_t DF = 0;
//uint8_t OF = 0;
//uint8_t IOPL = 0;
//uint8_t NT = 0;

void EncodeFlagsRegister() {
    FillFlags();
    reg_flags = RegFlagBaseValue;
    ENCODE_FLAG(CF)
    ENCODE_FLAG(PF)
    ENCODE_FLAG(AF)
    ENCODE_FLAG(ZF)
    ENCODE_FLAG(SF)
    ENCODE_FLAG(OF)

    ENCODE_FLAG(TF)
    ENCODE_FLAG(IF)
    ENCODE_FLAG(DF)

    ENCODE_FLAG(NT)
    ENCODE_FLAG(AC)
    ENCODE_FLAG(ID)
    ENCODE_FLAG(VM)

    reg_flags |= (((uint16_t)IOPL) << 12);
}

void DecodeFlagsRegister16() {
    DECODE_FLAG(CF)
    DECODE_FLAG(PF)
    DECODE_FLAG(AF)
    DECODE_FLAG(ZF)
    DECODE_FLAG(SF)
    DECODE_FLAG(OF)

    // должно быть условие на протекшен мод и уровень привелегий
    // в досбоксе выглядит вот так (cpu.pmode && !GETFLAG(VM) && (GETFLAG_IOPL<cpu.cpl))
    // в функции CPU_POPF
    DECODE_FLAG(IF)

    DECODE_FLAG(TF)
    DECODE_FLAG(DF)
    DECODE_FLAG(NT)

    lazyFlagType=t_UNKNOWN;
}

void DecodeFlagsRegister32() {
    DECODE_FLAG(CF)
    DECODE_FLAG(PF)
    DECODE_FLAG(AF)
    DECODE_FLAG(ZF)
    DECODE_FLAG(SF)
    DECODE_FLAG(OF)

    DECODE_FLAG(TF)
    DECODE_FLAG(IF)
    DECODE_FLAG(DF)

    DECODE_FLAG(NT)
    // DECODE_FLAG(ID)

    lazyFlagType=t_UNKNOWN;
}
