//
//  WindowsHeader.c
//  
//
//  Created by Alex Shipin on 12/12/22.
//

#include "ImageNT32Header.h"
#include "WindowsHeader.h"
#include <stdlib.h>
#include <string.h>

//RVA = VA - ImageBase
//VA = RVA + ImageBase

void loadWindows32NT(uint8_t *peData, uint8_t *allData) {
    uint8_t *pePData = peData;
    WINDOWS_EXE_HEADER exeHeader = CreateWINDOWS_EXE_HEADER(&pePData);
    exeHeader.Header.OptionalHeader.ImageBase = 0x1000;
    exeHeader.Header.OptionalHeader.SizeOfImage += 0x1000;
    uint8_t *image = malloc(exeHeader.Header.OptionalHeader.SizeOfImage);
    for (int i = 0; i < exeHeader.Header.OptionalHeader.SizeOfImage; i++) {
        image[i] = 0;
    }
    uint8_t *imageBase = image + exeHeader.Header.OptionalHeader.ImageBase;
    memcpy(
        imageBase,
        peData,
        exeHeader.Header.OptionalHeader.SizeOfHeaders
    );
    for (int i = 0; i < exeHeader.Header.FileHeader.NumberOfSections; i++) {
        IMAGE_SECTION_HEADER section = exeHeader.Sections[i];
        memcpy(imageBase + section.VirtualAddress, allData + section.PointerToRawData, section.SizeOfRawData);
    }


    if (exeHeader.Header.OptionalHeader.NumberOfRvaAndSizes > 1) {
        // IMAGE_DIRECTORY_ENTRY_EXPORT
        uint8_t *imports = imageBase + exeHeader.Header.OptionalHeader.DataDirectory[1].VirtualAddress;
        uint8_t *startItem = imports;
        while (imports - startItem < exeHeader.Header.OptionalHeader.DataDirectory[1].Size) {
            IMAGE_BASE_IMPORT_DESCRIPTOR import = CreateIMAGE_BASE_IMPORT_DESCRIPTOR(&imports);
            if (import.FirstThunk == 0) {
                break;
            }
            printf("<dll: %s, function: %s>\n", image + import.FirstThunk, image + import.Name);
        }
    }
}

