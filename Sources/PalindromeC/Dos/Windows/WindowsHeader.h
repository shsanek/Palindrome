//
//  WindowsHeader.h
//  
//
//  Created by Alex Shipin on 12/12/22.
//

#ifndef WindowsHeader_h
#define WindowsHeader_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//VA (Virtual Address) - адрес ячейки в виртуальной памяти
//RVA (Relative Virtual Address) - относительный виртуальный адрес
//
//RVA = VA - ImageBase
//VA = RVA + ImageBase

#define IMAGE_DIRECTORY_ENTRY_EXPORT              0
#define IMAGE_DIRECTORY_ENTRY_IMPORT              1
#define IMAGE_DIRECTORY_ENTRY_RESOURCE            2
#define IMAGE_DIRECTORY_ENTRY_EXCEPTION           3
#define IMAGE_DIRECTORY_ENTRY_SECURITY            4
#define IMAGE_DIRECTORY_ENTRY_BASERELOC           5
#define IMAGE_DIRECTORY_ENTRY_DEBUG               6
#define IMAGE_DIRECTORY_ENTRY_ARCHITECTURE        7
#define IMAGE_DIRECTORY_ENTRY_GLOBALPTR           8
#define IMAGE_DIRECTORY_ENTRY_TLS                 9
#define IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG         10
#define IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT        11
#define IMAGE_DIRECTORY_ENTRY_IAT                 12
#define IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT        13
#define IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR      14

void loadWindows32NT(uint8_t *peData, uint8_t *allData);

#endif /* WindowsHeader_h */
