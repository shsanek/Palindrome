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

void dosOpenFile() {
    FillFlags();
    char* name = (char*)(mem(SR_DS) + *regDX);
    int file = vfsOpenFile(name, *regAL);
    if (file == -1) {
        *regAX = 1;
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

void systemDOSFunction(uint8_t a) {
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
    emptyInterruptCallFunction(a);
}
