//
//  DosLoader.c
//  
//
//  Created by Alex Shipin on 11/15/22.
//

#include "DosLoader.h"
#include "VideoServiceInterrupt.h"
#include "../include/Base.h"

typedef struct DOSHeader {
    /// 0000h
    /// Шестнадцатеричное 0x4D5A. Компоновщик устанавливает это значение для идентификации правильного EXE файла.
    uint16_t magic;

    /// 0002h
    /// Число байт в последнем блоке EXE файла (остаток от деления размера EXE файла на размер блока).
    uint16_t lastBlockSize;

    /// 0004h
    /// исло блоков по 512 байт EXE файла, включая заголовок.
    uint16_t numberOfBlock;

    /// 0006h
    /// Число элементов в таблице перемещения.
    uint16_t numberOfShiftElement;

    /// 0008h 1 word   Header size in paragraphs
    uint16_t headerParagraphSize;

    /// 000Ah 1 word   Minimum paragraphs of memory allocated in addition to the code size
    uint16_t minParagraphCount;

    /// 000Ch 1 word   Maximum number of paragraphs allocated in addition to the code size
    uint16_t maxParagraphCount;

    /// Флаг загрузки в младшие или старшие адреса. Значение 0xFFFF означает загрузку в младшие адреса памяти, 0x0000 - в старшие.
    /// uint16_t flag;

    /// 000Eh Относительный адрес сегмента стека в выполняемом модуле. SS
    uint16_t stackAddress;

    /// 0010h Относительный адрес, который загрузчик помещает в регистр SP (адрес дна стека) перед передачей управления загруженной программе.
    uint16_t stackIndexAddress;

    /// 0012h Контрольная сумма - сумма всех слов в файле без учёта переполнений. Может использоваться для проверки корректности данных файла, но обычно не используется и равна 0x0000.
    uint16_t hashSum;

    /// 0014h Относительный адрес, который загрузчик помещает в регистр IP перед передачей управления загруженной программе.
    uint16_t codeAddressIndex;

    /// 0014h  + 2h Относительный адрес кодового сегмента в выполняемом модуле (это значение помещается в регистр CS).
    uint16_t codeAddress;

    /// 0018h Смещение таблица перемещения относительно начала EXE файла.
    uint16_t tableShiftAddress;

    /// 001Ah Номер оверлейного фрагмента. Нуль означает, что заголовок относится к главному модулю.
    uint16_t fragmentNumber;

    /// Таблица перемещения (см. выше).
    uint16_t* offsets;
} DOSHeader;

//"SET_VALUE_IN_SEGMENT(SR_CS, (*((uint16_t*)(target + 2))));",
//"context.index = GET_SEGMENT_POINTER(SR_CS) + (*((uint%dataSize_t*)(target)));"
void loadBaseInterrupt() {
    realModMemorySetSize(0xFFFF);
    uint16_t address = realModMemoryAllocate(0x04FF);
    uint8_t* addressPointer = GET_REAL_MOD_MEMORY_POINTER(address);

    realModMemoryAllocate(0x126F);

    uint16_t implementation = allocateMemoryLoadWithForceBlock(0xF000, 0x04FF);
    uint8_t* implementationPointer = GET_REAL_MOD_MEMORY_POINTER(implementation);

    for (int i = 0; i < 256; i++) {
        int value = i;
        if (i == 190) { value = 189; }
        *((uint16_t*)(addressPointer + i * 4 + 0)) = value * 4;
        *((uint16_t*)(addressPointer + i * 4 + 2)) = implementation;

        *(implementationPointer + i * 4 + 0) = 0xF1;
        *(uint16_t*)(implementationPointer + i * 4 + 1) = (uint16_t)i;
        *(implementationPointer + i * 4 + 3) = 0xCB;
    }
}

void loadRealModForDos() {
    realModMemorySetSize(0xFFFF);
    loadBaseInterrupt();

    uint8_t* downMemory = GET_REAL_MOD_MEMORY_POINTER(0);
    uint8_t* upMemory = GET_REAL_MOD_MEMORY_POINTER(0xFFFF);

    *(GET_REAL_MOD_MEMORY_POINTER(0xF000) + 0xFFFE + 0) = 0xFC;
    *(GET_REAL_MOD_MEMORY_POINTER(0xF000) + 0xFFFE + 1) = 0xC4;

    *(upMemory + 0x30 + 0) = 0x4D;
    *(upMemory + 0x30 + 1) = 0x53;
    *(upMemory + 0x30 + 2) = 0xFF;
    *(upMemory + 0x30 + 3) = 0xFF;
}

void loadProgramInZeroMemory(uint8_t *input, uint size, uint mod) {
    loadRealModForDos();

    uint16_t blocks = 0x1FFF;
    int block = realModMemoryAllocate(blocks);
    uint8_t *program = GET_REAL_MOD_MEMORY_POINTER(block);
    memcpy(program, input, size);

    context.program = program;
    context.index = program;

    (program + 0xFFFF)[-2] = 0xCD;
    (program + 0xFFFF)[-1] = 0x20;

    SET_VALUE_IN_SEGMENT(SR_CS, block);
    SET_VALUE_IN_SEGMENT(SR_DS, block);
    SET_VALUE_IN_SEGMENT(SR_ES, block);
    SET_VALUE_IN_SEGMENT(SR_SS, block + (0x0FFF));
    reg_SP_16u = 0x0FFF;

    context.mod = mod;

    returnToTopStack();
}

void returnToTopStack() {
    uint8_t* stack = GET_REAL_MOD_MEMORY_POINTER(SR_VALUE(SR_SS));
    if (context.mod == 1) {
        reg_SP_32u = reg_SP_16u - 4;
        *(int32_t*)(stack + reg_SP_32u) += 0xFFFF - 2;
    } else {
        reg_SP_16u = reg_SP_16u - 2;
        *(int16_t*)(stack + reg_SP_16u) += 0xFFFF - 2;
    }
}

void allocateMZDosHeader() {
    uint16_t block = realModMemoryAllocate(0x20);
    assert(block == 0x176E);
}

void fillMZDosHeader() {
    uint8_t *memory = GET_REAL_MOD_MEMORY_POINTER(0x179E);


    for (int i = 0; i < 528; i++) {
        // тут заголовок дума надо будет поменять этот моментик
        if (testContext == TestContextDoom) {
            *(memory - 528 + i) = dosExeHeaderDamp[i];
        } else if (testContext == TestContextPrince) {
            *(memory - 528 + i) = dosPrinceExeHeaderDamp[i];
        } else {

            /// все это костыль нужны конфиги для запуска
            *(memory - 528 + i) = dosPrinceExeHeaderDamp[i];
        }
    }
}

void loadMZDosProgram() {
    void *start = context.index;
    DOSHeader header;
    header.magic = read16u();
    header.lastBlockSize = read16u();

    header.numberOfBlock = read16u();
    header.numberOfShiftElement = read16u();
    header.headerParagraphSize = read16u();
    header.minParagraphCount = read16u();
    header.maxParagraphCount = read16u();

    header.stackAddress = read16u();
    header.stackIndexAddress = read16u();
    header.hashSum = read16u();
    header.codeAddressIndex = read16u();
    header.codeAddress = read16u();
    header.tableShiftAddress = read16u();
    header.fragmentNumber = read16u();

    uint16_t* offsets = malloc(2 * header.numberOfShiftElement);
    for (int i = 0; i < header.numberOfShiftElement; i++) {
        offsets[i * 2] = ((uint16_t*)(start + header.tableShiftAddress))[i * 2];
        offsets[i * 2 + 1] = ((uint16_t*)(start + header.tableShiftAddress))[i * 2 + 1];
    }

    allocateMZDosHeader();
    int fullSize = (int)header.numberOfBlock * 512 + (int)header.lastBlockSize;
    uint16_t programSize = (fullSize) / 16 + 2; // в параграфах
    uint16_t programBlock = realModMemoryAllocate(programSize);
    fillMZDosHeader();

    // такие странные константы для тестов
    assert(programBlock == 0x178E);

    programBlock += 0x10;

    uint8_t* programMemory = GET_REAL_MOD_MEMORY_POINTER(programBlock);
    memcpy(programMemory, ((uint8_t*)start) + header.headerParagraphSize * 16, fullSize);

    context.program = programMemory;

    SET_VALUE_IN_SEGMENT(SR_DS, programBlock - 0x10);
    SET_VALUE_IN_SEGMENT(SR_ES, programBlock - 0x10);

    SET_VALUE_IN_SEGMENT(SR_SS, header.stackAddress + programBlock);
    reg_SP_16u = header.stackIndexAddress;

    SET_VALUE_IN_SEGMENT(SR_CS, header.codeAddress + programBlock);
    context.index = GET_SEGMENT_POINTER(SR_CS) + header.codeAddressIndex;

    for (int i = 0; i < header.numberOfShiftElement; i++) {
        uint32_t offset = ((int32_t)offsets[i * 2]) + ((uint32_t)offsets[i * 2 + 1]) * 16;
        *(uint16_t*)(programMemory + offset) = (*(uint16_t*)(programMemory + offset)) + programBlock;
    }
    free(offsets);

    GET_REAL_MOD_MEMORY_POINTER(0xFCB8)[0x2F97] = 0xB0;
    GET_REAL_MOD_MEMORY_POINTER(0xFCB8)[0x2F98] = 0x01;
    GET_REAL_MOD_MEMORY_POINTER(0xFCB8)[0x2F99] = 0xF1;
    GET_REAL_MOD_MEMORY_POINTER(0xFCB8)[0x2F9A] = 0x20;
    GET_REAL_MOD_MEMORY_POINTER(0xFCB8)[0x2F9B] = 0xCB;
}

void loadCOMDosProgram(uint size) {
    realModMemoryAllocate(0x10);
    int fullSize = size;
    uint16_t programSize = (fullSize) / 16 + 1; // в параграфах
    uint16_t programBlock = realModMemoryAllocate(programSize);

    uint8_t* programMemory = GET_REAL_MOD_MEMORY_POINTER(programBlock);
    memcpy(programMemory, context.index, size);

    uint8_t header[16] = {0xCD, 0x20, 0x00, 0xA0, 0x00, 0x9A, 0xF0, 0xFE, 0x1D, 0xF0, 0x4F, 0x03, 0xF2, 0x10, 0x8A, 0x03};
    for (int i = 0; i < 16; i++) {
        *(programMemory - 256 + i) = header[i];
    }

    context.program = programMemory;

    SET_VALUE_IN_SEGMENT(SR_CS, programBlock);
    context.index = GET_SEGMENT_POINTER(SR_CS);
}

void realModCPUSetting() {
    DebugOnlyPrint = 0;

    RegFlagBaseValue = 0x2;
    IOPL = 3;
    IF = 1;
    TF = 1;
    NT = 1;
    VM = 1;

    context.pmode = 0;
    context.mod = 0;

    *regBX = 0x0001;
    *regCX = 0xDFC7;
}


void loadDosProgram(uint8_t *program, uint size) {
    context.index = program;
    uint16_t magic = *(uint16_t*)program;
    if (magic == 23117) {
        // EXE
        loadRealModForDos(); realModCPUSetting(); // для PE програм нужно будет убрать
        loadMZDosProgram();
    } else {
        // COM
        loadRealModForDos(); realModCPUSetting();
        loadCOMDosProgram(size);
    }
}
