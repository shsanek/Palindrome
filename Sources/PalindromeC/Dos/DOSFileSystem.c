//
//  DOSFileSystem.c
//  
//
//  Created by Alex Shipin on 11/29/22.
//

#include "DOSFileSystem.h"

void dosOpenFile() {
    char* name = (char*)(GET_SEGMENT_POINTER(SR_DS) + *regDX);
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
    uint16_t description = *regBXu;
    char isEnd = 0;
    int state = vfsReadFile(description, GET_SEGMENT_POINTER(SR_DS) + *regDX, *regCXu, &isEnd);
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
    uint16_t description = *regBXu;
    *regAX = vfsCloseFile(description);
    SET_FLAG(CF, *regAX != 0);
}

void doslSeekFile() {
    uint16_t description = *regBXu;
    if (*regAL == 2 && *regCX == 0 && *regAX == 0) {
        ExternalCallFunctionEmpty(0x21);
        return;
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
    SET_FLAG(CF, 0);
}

void dosAllocateMemory() {
    int result = realModMemoryAllocate(*regBXu);
    if (result > 0) {
        *regAX = result;
        SET_FLAG(CF, 0);
    } else {
        *regAX = 1;
        *regBXu = -result;
        SET_FLAG(CF, 0);
    }
}

void dosFreeMemory() {
    int result = realModMemoryFree(SR_VALUE(SR_ES));
    if (result > 0) {
        SET_FLAG(CF, 0);
    } else {
        *regAX = 1;
        SET_FLAG(CF, 1);
    }
}

void dosResizeMemory() {
    int result = realModMemoryRelocate(SR_VALUE(SR_ES), *regBXu);
    if (result > 0) {
        SET_FLAG(CF, 0);
        *regAXu = SR_VALUE(SR_ES);
    } else {
        SET_FLAG(CF, 1);
        *regAX = 1;
        *regBXu = -result;
    }
}

void dosLinePrint() {
    int i = 0;
    char *text = (char*)(GET_SEGMENT_POINTER(SR_DS) + *regDX);
    while (text[i] != '$' && text[i] != '\0') {
        i++;
    }
    char symbol = text[i];
    text[i] = 0;
    printf("\n[DOS] %s\n", text);
    text[i] = symbol;
}

void systemDOSFunction(uint16_t a) {
    if (*regAH == 0x33) {
        controlBreakFunction();
        return;
    }
    if (*regAH == 0x38) { // инфо о стране
        *regAXu = 0001;
        *regBXu = 0001;
        return;
    }
    if (*regAH == 0x30) { // инфо о версии дос
        *regBX = 0;
        *regCX = 0;
        *regAL = 7;
        *regAH = 10;
        *regBX = 0xFF00;
        return;
    }

    /// затычки для файловых дескрипторов
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
        SET_FLAG(CF, 0);
        return;
    }
    if (*regAH == 0x42) {
        doslSeekFile();
        return;
    }
    if (*regAH == 0x48) {
        dosAllocateMemory();
        return;
    }
    if (*regAH == 0x4A) {
        dosResizeMemory();
        return;
    }
    if (*regAH == 0x49) {
        dosFreeMemory();
        return;
    }
    if (*regAH == 0x09) {
        dosLinePrint();
        return;
    }
    if (*regAH == 0x35) {
        *regBX = *(uint16_t*)(GET_REAL_MOD_MEMORY_POINTER(0) + *regAL * 4 );
        SET_VALUE_IN_SEGMENT(SR_ES, (*(uint16_t*)(GET_REAL_MOD_MEMORY_POINTER(0) + *regAL * 4 + 2)))
        return;
    }
    if (*regAH == 0x25) {
        *(uint16_t*)(GET_REAL_MOD_MEMORY_POINTER(0) + *regAL * 4 ) = *regDX;
        (*(uint16_t*)(GET_REAL_MOD_MEMORY_POINTER(0) + *regAL * 4 + 2)) = SR_VALUE(SR_DS);
        return;
    }
    ExternalCallFunctionEmpty(a);
}


void SystemDOSInstall() {
    context.functions[0x21] = systemDOSFunction;
}
