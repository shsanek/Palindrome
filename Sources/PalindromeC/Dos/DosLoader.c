//
//  DosLoader.c
//  
//
//  Created by Alex Shipin on 11/15/22.
//

#include "DosLoader.h"
#include "../include/Base.h"
#include "../Base/Read.h"
#include <stdlib.h>

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

void loadDosHeader() {
    void *start = context.index;
    DOSHeader header;
    header.magic = read16u();
    header.lastBlockSize = read16u();

    header.numberOfBlock = read16u();
    header.numberOfShiftElement = read16u();
    header.headerParagraphSize = read16u();
    header.minParagraphCount = read16u();
    header.maxParagraphCount = read16u();

    // header.flag = read16u();

    header.stackAddress = read16u();
    header.stackIndexAddress = read16u();
    header.hashSum = read16u();
    header.codeAddressIndex = read16u();
    header.codeAddress = read16u();
    header.tableShiftAddress = read16u();
    header.fragmentNumber = read16u();
    uint16_t* offsets = malloc(2 * header.numberOfShiftElement);

    setMem(SR_SS, header.stackAddress);
    reg_SP_16u = header.stackIndexAddress;

    setMem(SR_CS, header.codeAddress);
    context.program = context.memory + header.headerParagraphSize * 16;
    context.index = mem(SR_CS) + header.codeAddressIndex;

    for (int i = 0; i < header.numberOfShiftElement; i++) {
        offsets[i * 2] = read16u();
        offsets[i * 2 + 1] = read16u();
    }

    printf("\n");
    for (int i = 0; i < 1000; i++) {
        char a[3] = {0, 0, 0};
        sprintf(&a, "%X", context.index[i]);
        if (a[1] == 0) {
            printf("0%c", a[0]);
        } else {
            printf("%c%c", a[0], a[1]);
        }
    }
    printf("\n");

    printf("start\n");
    run16ToEnd();
    printf("end\n");
}
