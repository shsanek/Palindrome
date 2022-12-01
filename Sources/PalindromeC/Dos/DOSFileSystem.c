//
//  DOSFileSystem.c
//  
//
//  Created by Alex Shipin on 11/29/22.
//

#include "DOSFileSystem.h"
#include "../Base/Read.h"
#include "../Base/Flags.h"
#include "../include/Base.h"
#include "../Function/BaseFunction.h"
#include "../Dos/DosMemoryMeneger.h"

void dosOpenFile() {
    FillFlags();
    char* name = (char*)(mem(SR_DS) + *regDX);
    int file = vfsOpenFile(name, *regAL);
    if (file < 0) {
        *regAX = (uint16_t)-file;
        SET_FLAG(CF, 1);
        return;
    }
    uint16_t description = file;
    *regAXu = description;
    SET_FLAG(CF, 0);
}

void dosReadFromFile() {
    FillFlags();
    uint16_t description = *regBXu;
    char isEnd = 0;
    int state = vfsReadFile(description, mem(SR_DS) + *regDX, *regCXu, &isEnd);
    if (state == *regCXu) {
        SET_FLAG(CF, 0);
    } else {
        SET_FLAG(CF, 1);
    }
    if (state > 0) {
        *regAX = state;
        return;
    }
    if (isEnd) {
        *regAX = 0;
        return;
    }
    *regAX = 1;
}

void dosCloseFile() {
    FillFlags();
    uint16_t description = *regBXu;
    *regAX = vfsCloseFile(description);
    SET_FLAG(CF, *regAX != 0);
}

void doslSeekFile() {
    FillFlags();
    uint16_t description = *regBXu;
    if (*regAL == 2 && *regCX == 0 && *regAX == 0) {
        emptyInterruptCallFunction(0x21);
    }
    int32_t offset = (*regCXu * 65536) + *regDXu;
    int32_t newOffset = vfsLseekFile(description, offset, *regAL);

    if (newOffset < 0) {
        *regAX = -newOffset;
        SET_FLAG(CF, 1);
        return;
    }

    SET_FLAG(CF, 0);
    *regDXu = newOffset / 65536;
    *regAXu = newOffset % 65536;
}

uint8_t ControlBreakState = 0;

void controlBreakFunction() {
    if (*regALu == 1) {
        ControlBreakState = (*regDL) ? 1 : 0;
    }
    *regDL = ControlBreakState;
}

void systemDOSFunction(uint8_t a) {
    if (*regAH == 0x33) {
        controlBreakFunction();
        return;
    }
    if (*regAH == 0x30) {
        *regBX = 0;
        *regCX = 0;
        *regAL = 7;
        *regAH = 10;
        *regBX = 0xFF00;
        return;
    }
    if (*regAH == 0x44 && *regAL == 0 && *regBX == 4) {
        *regDX = 0xA0C0;
        *regAX = 0xA0C0;
        SET_FLAG(CF, 0);
        return;
    }
    if (*regAH == 0x44 && *regAL == 0 && *regBX == 3) {
        *regDX = 0x80C0;
        *regAX = 0x80C0;
        SET_FLAG(CF, 0);
        return;
    }
    if (*regAH == 0x44 && *regAL == 0 && *regBXu < 3) {
        *regDX = 0x80D3;
        *regAX = 0x80D3;
        SET_FLAG(CF, 0);
        return;
    }
    if (*regAH == 0x38) {
        *regAX = 0x0001;
        *regBX = 0x0001;
        return;
    }
    if (*regAH == 0x4A) {
        *regAX = 0x178E;
        return;
    }
    if (*regAH == 0x3e) {
        dosCloseFile();
        return;
    }
    if (*regAH == 0x3d) {
        dosOpenFile();
        return;
    }
    if (*regAH == 0x3f) {
        dosReadFromFile();
        return;
    }
    if (*regAH == 0x00) {
        context.end = 1;
        return;
    }
    if (*regAH == 0x42) {
        doslSeekFile();
        return;
    }
    if (*regAH == 0x35) {
        setMem(SR_ES, 0x024C);
        *regBXu = 0x0240;
        return;
    }
    if (*regAH == 0x48) {
        FillFlags();
        int result = dosAllocateBlockMemory(*regBXu);
        if (result > 0) {
            *regAX = result;
            SET_FLAG(CF, 0);
        } else {
            *regAX = 1;
            *regBXu = -result;
            SET_FLAG(CF, 0);
        }
        return;
    }
    emptyInterruptCallFunction(a);
}
