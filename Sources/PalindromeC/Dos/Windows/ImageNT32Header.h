#ifndef WindowsNTHeader_h
#define WindowsNTHeader_h

#include <stdio.h>
#include "WindowsHeader.h"
/// 
typedef struct IMAGE_FILE_HEADER {
	/// Архитектура процессора
	uint16_t Machine;
	/// Кол-во секций
	uint16_t NumberOfSections;
	/// Дата и время создания программы
	uint32_t TimeDateStamp;
	/// Указатель на таблицу символов
	uint32_t PointerToSymbolTable;
	/// Число символов в таблицу
	uint32_t NumberOfSymbols;
	/// Размер дополнительного заголовка
	uint16_t SizeOfOptionalHeader;
	/// Характеристика
	uint16_t Characteristics;
} IMAGE_FILE_HEADER;
IMAGE_FILE_HEADER CreateIMAGE_FILE_HEADER(uint8_t **data);
void FreeIMAGE_FILE_HEADER(IMAGE_FILE_HEADER obj);

/// 
typedef struct IMAGE_DATA_DIRECTORY {
	/// 
	uint32_t VirtualAddress;
	/// 
	uint32_t Size;
} IMAGE_DATA_DIRECTORY;
IMAGE_DATA_DIRECTORY CreateIMAGE_DATA_DIRECTORY(uint8_t **data);
void FreeIMAGE_DATA_DIRECTORY(IMAGE_DATA_DIRECTORY obj);

/// 
typedef struct IMAGE_OPTIONAL_HEADER32 {
	/// 
	uint16_t Magic;
	/// 
	uint8_t MajorLinkerVersion;
	/// 
	uint8_t MinorLinkerVersion;
	/// 
	uint32_t SizeOfCode;
	/// 
	uint32_t SizeOfInitializedData;
	/// 
	uint32_t SizeOfUninitializedData;
	/// 
	uint32_t AddressOfEntryPoint;
	/// 
	uint32_t BaseOfCode;
	/// 
	uint32_t BaseOfData;
	/// 
	uint32_t ImageBase;
	/// 
	uint32_t SectionAlignment;
	/// 
	uint32_t FileAlignment;
	/// 
	uint16_t MajorOperatingSystemVersion;
	/// 
	uint16_t MinorOperatingSystemVersion;
	/// 
	uint16_t MajorImageVersion;
	/// 
	uint16_t MinorImageVersion;
	/// 
	uint16_t MajorSubsystemVersion;
	/// 
	uint16_t MinorSubsystemVersion;
	/// 
	uint32_t Win32VersionValue;
	/// 
	uint32_t SizeOfImage;
	/// 
	uint32_t SizeOfHeaders;
	/// 
	uint32_t CheckSum;
	/// 
	uint16_t Subsystem;
	/// 
	uint16_t DllCharacteristics;
	/// 
	uint32_t SizeOfStackReserve;
	/// 
	uint32_t SizeOfStackCommit;
	/// 
	uint32_t SizeOfHeapReserve;
	/// 
	uint32_t SizeOfHeapCommit;
	/// 
	uint32_t LoaderFlags;
	/// 
	uint32_t NumberOfRvaAndSizes;
	/// 
	IMAGE_DATA_DIRECTORY* DataDirectory;
} IMAGE_OPTIONAL_HEADER32;
IMAGE_OPTIONAL_HEADER32 CreateIMAGE_OPTIONAL_HEADER32(uint8_t **data);
void FreeIMAGE_OPTIONAL_HEADER32(IMAGE_OPTIONAL_HEADER32 obj);

/// 
typedef struct IMAGE_NT_HEADERS32 {
	/// Сигнатура
	uint32_t Signature;
	/// Файловый заголовка
	IMAGE_FILE_HEADER FileHeader;
	/// Дополнительный
	IMAGE_OPTIONAL_HEADER32 OptionalHeader;
} IMAGE_NT_HEADERS32;
IMAGE_NT_HEADERS32 CreateIMAGE_NT_HEADERS32(uint8_t **data);
void FreeIMAGE_NT_HEADERS32(IMAGE_NT_HEADERS32 obj);

/// 
typedef struct IMAGE_SECTION_HEADER {
	/// 
	uint8_t* Name;
	/// 
	uint32_t VirtualSize;
	/// 
	uint32_t VirtualAddress;
	/// 
	uint32_t SizeOfRawData;
	/// 
	uint32_t PointerToRawData;
	/// 
	uint32_t PointerToRelocations;
	/// 
	uint32_t PointerToLinenumbers;
	/// 
	uint16_t NumberOfRelocations;
	/// 
	uint16_t NumberOfLinenumbers;
	/// 
	uint32_t Characteristics;
} IMAGE_SECTION_HEADER;
IMAGE_SECTION_HEADER CreateIMAGE_SECTION_HEADER(uint8_t **data);
void FreeIMAGE_SECTION_HEADER(IMAGE_SECTION_HEADER obj);

/// 
typedef struct WINDOWS_EXE_HEADER {
	/// 
	IMAGE_NT_HEADERS32 Header;
	/// 
	IMAGE_SECTION_HEADER* Sections;
} WINDOWS_EXE_HEADER;
WINDOWS_EXE_HEADER CreateWINDOWS_EXE_HEADER(uint8_t **data);
void FreeWINDOWS_EXE_HEADER(WINDOWS_EXE_HEADER obj);

/// 
typedef struct IMAGE_BASE_IMPORT_DESCRIPTOR {
	/// 
	uint32_t OriginalFirstThunk;
	/// 
	uint32_t TimeDateStamp;
	/// 
	uint32_t ForwarderChain;
	/// 
	uint32_t Name;
	/// 
	uint32_t FirstThunk;
} IMAGE_BASE_IMPORT_DESCRIPTOR;
IMAGE_BASE_IMPORT_DESCRIPTOR CreateIMAGE_BASE_IMPORT_DESCRIPTOR(uint8_t **data);
void FreeIMAGE_BASE_IMPORT_DESCRIPTOR(IMAGE_BASE_IMPORT_DESCRIPTOR obj);

/// 
typedef struct IMAGE_DELAY_IMPORT_DESCRIPTOR {
	/// 
	uint32_t grAttrs;
	/// 
	uint32_t szName;
	/// 
	uint32_t phmod;
	/// 
	uint32_t pIAT;
	/// 
	uint32_t pINT;
	/// 
	uint32_t pBoundIAT;
	/// 
	uint32_t pUnloadIAT;
	/// 
	uint32_t dwTimeStamp;
} IMAGE_DELAY_IMPORT_DESCRIPTOR;
IMAGE_DELAY_IMPORT_DESCRIPTOR CreateIMAGE_DELAY_IMPORT_DESCRIPTOR(uint8_t **data);
void FreeIMAGE_DELAY_IMPORT_DESCRIPTOR(IMAGE_DELAY_IMPORT_DESCRIPTOR obj);

/// 
typedef struct IMAGE_BOUND_IMPORT_DESCRIPTOR {
	/// 
	uint32_t TimeDataStamp;
	/// 
	uint16_t OffsetModuleName;
	/// 
	uint16_t NumberOfModuleForwarderRefs;
} IMAGE_BOUND_IMPORT_DESCRIPTOR;
IMAGE_BOUND_IMPORT_DESCRIPTOR CreateIMAGE_BOUND_IMPORT_DESCRIPTOR(uint8_t **data);
void FreeIMAGE_BOUND_IMPORT_DESCRIPTOR(IMAGE_BOUND_IMPORT_DESCRIPTOR obj);

#endif