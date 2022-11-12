//
//  MRM.c
//  
//
//  Created by Alex Shipin on 10/16/22.
//

#include "MRM.h"
#include "Registers.h"
#include "Read.h"

uint8_t readFirst2Bit(uint8_t byte) {
    return (byte >> 6) & 0x03;
}

uint8_t readMiddle3Bit(uint8_t byte) {
    return (byte >> 3) & 0x07;
}

uint8_t readLast3Bit(uint8_t byte) {
    return byte & 0x07;
}


#define TWO_OPERAND_ADDRESS_MEMORY_MRM_16(BASE, sR, fR, lR) \
uint8_t* addressMemoryMRM16Base##BASE(uint8_t mod) {\
    int16_t shift = *register16u(fR) + *register16u(lR);\
    uint8_t* base = mem(sR) + shift;\
    switch(mod) {\
        case 0:\
            return base;\
        case 1:\
            return base + ((int16_t)read8());\
        case 2:\
            return base + read16();\
    }\
    return NULL;\
}\

#define ONE_OPERAND_ADDRESS_MEMORY_MRM_16(BASE, sR, fR) \
uint8_t* addressMemoryMRM16Base##BASE(uint8_t mod) {\
    int16_t shift = *register16u(fR);\
    uint8_t* base = mem(sR) + shift;\
    switch(mod) {\
        case 0:\
            return base;\
        case 1:\
            return base + ((int16_t)read8());\
        case 2:\
            return base + read16();\
    }\
    return NULL;\
}\

#define ONE_OPERAND_ADDRESS_MEMORY_MRM_32(BASE, sR, fR)\
uint8_t* addressMemoryMRM32Base##BASE(uint8_t mod) {\
    int16_t shift = *register32u(fR);\
    uint8_t* base = mem(sR) + shift;\
    switch(mod) {\
        case 0:\
            return base;\
        case 1:\
            return base + ((int16_t)read8());\
        case 2:\
            return base + read32();\
    }\
    return NULL;\
}

#define ADDRESS_MEMORY_SIB(BASE, sR, fR)\
uint8_t* addressMemoryMRM32IBBase##BASE(uint8_t mod, uint32_t shift) {\
    uint32_t rShift = *register32u(fR);\
    uint8_t* base = mem(sR) + rShift + shift;\
    switch(mod) {\
        case 0:\
            return base;\
        case 1:\
            return base + ((int16_t)read8());\
        case 2:\
            return base + read32();\
    }\
    return NULL;\
}

TWO_OPERAND_ADDRESS_MEMORY_MRM_16(0, SR_DS, BR_BX, BR_SI)
TWO_OPERAND_ADDRESS_MEMORY_MRM_16(1, SR_DS, BR_BX, BR_DI)
TWO_OPERAND_ADDRESS_MEMORY_MRM_16(2, SR_SS, BR_BP, BR_SI)
TWO_OPERAND_ADDRESS_MEMORY_MRM_16(3, SR_SS, BR_BP, BR_SI)
ONE_OPERAND_ADDRESS_MEMORY_MRM_16(4, SR_DS, BR_SI)
ONE_OPERAND_ADDRESS_MEMORY_MRM_16(5, SR_DS, BR_DI)
ONE_OPERAND_ADDRESS_MEMORY_MRM_16(7, SR_DS, BR_BX)

ONE_OPERAND_ADDRESS_MEMORY_MRM_32(0, SR_DS, BR_EAX_F)
ONE_OPERAND_ADDRESS_MEMORY_MRM_32(1, SR_DS, BR_ECX_F)
ONE_OPERAND_ADDRESS_MEMORY_MRM_32(2, SR_DS, BR_EDX_F)
ONE_OPERAND_ADDRESS_MEMORY_MRM_32(3, SR_DS, BR_EBX_F)
ONE_OPERAND_ADDRESS_MEMORY_MRM_32(6, SR_DS, BR_ESI_F)
ONE_OPERAND_ADDRESS_MEMORY_MRM_32(7, SR_DS, BR_EDI_F)


ADDRESS_MEMORY_SIB(0, SR_DS, BR_EAX_F)
ADDRESS_MEMORY_SIB(1, SR_DS, BR_ECX_F)
ADDRESS_MEMORY_SIB(2, SR_DS, BR_EDX_F)
ADDRESS_MEMORY_SIB(3, SR_DS, BR_EBX_F)
ADDRESS_MEMORY_SIB(4, SR_SS, BR_ESP_F)
ADDRESS_MEMORY_SIB(6, SR_DS, BR_ESI_F)
ADDRESS_MEMORY_SIB(7, SR_DS, BR_EDI_F)

uint8_t getScaleSIB(uint8_t scale, uint8_t index) {
    if (index == 0x04) {
        return 0;
    }
    switch (scale) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 8;
    }
    return 0;
}

int8_t* readRegisterMRM8(uint8_t mrmByte) {
    return register8(readMiddle3Bit(mrmByte));
}

int16_t* readRegisterMRM16(uint8_t mrmByte) {
    return register16(readMiddle3Bit(mrmByte));
}

int32_t* readRegisterMRM32(uint8_t mrmByte) {
    return register32(readMiddle3Bit(mrmByte));
}

uint8_t* addressMemoryMRM32IBBase5(uint8_t mod, uint32_t shift) {
    uint32_t rShift = *register32u(BR_EBP_F);
    uint8_t* base = mem(SR_SS) + rShift + shift;
    switch(mod) {
        case 0:
            return mem(SR_DS) + read32() + shift;
        case 1:
            return base + ((int16_t)read8());
        case 2:
            return base + read32();
    }
    return NULL;
}

uint8_t* addressMemoryMRM32IB(uint8_t mod) {
    uint8_t sibByte = read8u();
    uint8_t scaleByte = readFirst2Bit(sibByte);
    uint8_t indexByte = readMiddle3Bit(sibByte);
    uint8_t baseByte = readLast3Bit(sibByte);

    uint8_t scale = getScaleSIB(scaleByte, indexByte);
    uint32_t shift = context.registers[indexByte] * scale;

    switch(baseByte) {
        case 0:
            return addressMemoryMRM32IBBase0(mod, shift);
        case 1:
            return addressMemoryMRM32IBBase1(mod, shift);
        case 2:
            return addressMemoryMRM32IBBase2(mod, shift);
        case 3:
            return addressMemoryMRM32IBBase3(mod, shift);
        case 4:
            return addressMemoryMRM32IBBase4(mod, shift);
        case 5:
            return addressMemoryMRM32IBBase5(mod, shift);
        case 6:
            return addressMemoryMRM32IBBase6(mod, shift);
        case 7:
            return addressMemoryMRM32IBBase7(mod, shift);
        default:
            return NULL;
    }

    return NULL;
}

uint8_t* addressMemoryMRM32Base5(uint8_t mod) {
    int16_t shift = *register32u(BR_EBP_F);
    uint8_t* base = mem(SR_SS);
    switch(mod) {
        case 0:
            return mem(SR_DS) + read32();
        case 1:
            return base + shift + ((int16_t)read8());
        case 2:
            return base + shift + read32();
    }
    return NULL;
}

uint8_t* addressMemoryMRM16Base6(uint8_t mod) {
    int16_t shift = *register16u(BR_BP);
    uint8_t* base = mem(SR_SS);
    switch(mod) {
        case 0:
            return mem(SR_DS) + read16();
        case 1:
            return base + shift + ((int16_t)read8());
        case 2:
            return base + shift + read16();
    }
    return NULL;
}

uint8_t* readAddressMRM16For8(uint8_t mrmByte) {
    uint8_t mod = readFirst2Bit(mrmByte);
    uint8_t base = readLast3Bit(mrmByte);
    if (mod == 3) {
        return (uint8_t*)register8(base);
    }
    switch(base) {
        case 0:
            return addressMemoryMRM16Base0(mod);
        case 1:
            return addressMemoryMRM16Base1(mod);
        case 2:
            return addressMemoryMRM16Base2(mod);
        case 3:
            return addressMemoryMRM16Base3(mod);
        case 4:
            return addressMemoryMRM16Base4(mod);
        case 5:
            return addressMemoryMRM16Base5(mod);
        case 6:
            return addressMemoryMRM16Base6(mod);
        case 7:
            return addressMemoryMRM16Base7(mod);
        default:
            return NULL;
    }
}

uint8_t* readAddressMRM16For16(uint8_t mrmByte) {
    uint8_t mod = readFirst2Bit(mrmByte);
    uint8_t base = readLast3Bit(mrmByte);
    if (mod == 3) {
        return (uint8_t*)register16(base);
    }
    switch(base) {
        case 0:
            return addressMemoryMRM16Base0(mod);
        case 1:
            return addressMemoryMRM16Base1(mod);
        case 2:
            return addressMemoryMRM16Base2(mod);
        case 3:
            return addressMemoryMRM16Base3(mod);
        case 4:
            return addressMemoryMRM16Base4(mod);
        case 5:
            return addressMemoryMRM16Base5(mod);
        case 6:
            return addressMemoryMRM16Base6(mod);
        case 7:
            return addressMemoryMRM16Base7(mod);
        default:
            return NULL;
    }
}


uint8_t* readAddressMRM32For8(uint8_t mrmByte) {
    uint8_t mod = readFirst2Bit(mrmByte);
    uint8_t base = readLast3Bit(mrmByte);
    if (mod == 3) {
        return (uint8_t*)register8(base);
    }
    switch(base) {
        case 0:
            return addressMemoryMRM32Base0(mod);
        case 1:
            return addressMemoryMRM32Base1(mod);
        case 2:
            return addressMemoryMRM32Base2(mod);
        case 3:
            return addressMemoryMRM32Base3(mod);
        case 4:
            return addressMemoryMRM32IB(mod);
        case 5:
            return addressMemoryMRM32Base5(mod);
        case 6:
            return addressMemoryMRM32Base6(mod);
        case 7:
            return addressMemoryMRM32Base7(mod);
        default:
            return NULL;
    }
}

uint8_t* readAddressMRM32For16(uint8_t mrmByte) {
    uint8_t mod = readFirst2Bit(mrmByte);
    uint8_t base = readLast3Bit(mrmByte);
    if (mod == 3) {
        return (uint8_t*)register16(base);
    }
    switch(base) {
        case 0:
            return addressMemoryMRM32Base0(mod);
        case 1:
            return addressMemoryMRM32Base1(mod);
        case 2:
            return addressMemoryMRM32Base2(mod);
        case 3:
            return addressMemoryMRM32Base3(mod);
        case 4:
            return addressMemoryMRM32IB(mod);
        case 5:
            return addressMemoryMRM32Base5(mod);
        case 6:
            return addressMemoryMRM32Base6(mod);
        case 7:
            return addressMemoryMRM32Base7(mod);
        default:
            return NULL;
    }
}

uint8_t* readAddressMRM32For32(uint8_t mrmByte) {
    uint8_t mod = readFirst2Bit(mrmByte);
    uint8_t base = readLast3Bit(mrmByte);
    if (mod == 3) {
        return (uint8_t*)register32(base);
    }
    switch(base) {
        case 0:
            return addressMemoryMRM32Base0(mod);
        case 1:
            return addressMemoryMRM32Base1(mod);
        case 2:
            return addressMemoryMRM32Base2(mod);
        case 3:
            return addressMemoryMRM32Base3(mod);
        case 4:
            return addressMemoryMRM32IB(mod);
        case 5:
            return addressMemoryMRM32Base5(mod);
        case 6:
            return addressMemoryMRM32Base6(mod);
        case 7:
            return addressMemoryMRM32Base7(mod);
        default:
            return NULL;
    }
}
