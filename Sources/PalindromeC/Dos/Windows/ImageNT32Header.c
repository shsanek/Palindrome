#include "ImageNT32Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/// 
IMAGE_FILE_HEADER CreateIMAGE_FILE_HEADER(uint8_t **data) {
	uint8_t *rawData = *data;
	IMAGE_FILE_HEADER obj;
	obj.Machine = *(uint16_t*)rawData; rawData += 2;
	obj.NumberOfSections = *(uint16_t*)rawData; rawData += 2;
	obj.TimeDateStamp = *(uint32_t*)rawData; rawData += 4;
	obj.PointerToSymbolTable = *(uint32_t*)rawData; rawData += 4;
	obj.NumberOfSymbols = *(uint32_t*)rawData; rawData += 4;
	obj.SizeOfOptionalHeader = *(uint16_t*)rawData; rawData += 2;
	obj.Characteristics = *(uint16_t*)rawData; rawData += 2;
	*data = rawData;
	return obj;
};
void FreeIMAGE_FILE_HEADER(IMAGE_FILE_HEADER obj) {
};

/// 
IMAGE_DATA_DIRECTORY CreateIMAGE_DATA_DIRECTORY(uint8_t **data) {
	uint8_t *rawData = *data;
	IMAGE_DATA_DIRECTORY obj;
	obj.VirtualAddress = *(uint32_t*)rawData; rawData += 4;
	obj.Size = *(uint32_t*)rawData; rawData += 4;
	*data = rawData;
	return obj;
};
void FreeIMAGE_DATA_DIRECTORY(IMAGE_DATA_DIRECTORY obj) {
};

/// 
IMAGE_OPTIONAL_HEADER32 CreateIMAGE_OPTIONAL_HEADER32(uint8_t **data) {
	uint8_t *rawData = *data;
	IMAGE_OPTIONAL_HEADER32 obj;
	obj.Magic = *(uint16_t*)rawData; rawData += 2;
	obj.MajorLinkerVersion = *(uint8_t*)rawData; rawData += 1;
	obj.MinorLinkerVersion = *(uint8_t*)rawData; rawData += 1;
	obj.SizeOfCode = *(uint32_t*)rawData; rawData += 4;
	obj.SizeOfInitializedData = *(uint32_t*)rawData; rawData += 4;
	obj.SizeOfUninitializedData = *(uint32_t*)rawData; rawData += 4;
	obj.AddressOfEntryPoint = *(uint32_t*)rawData; rawData += 4;
	obj.BaseOfCode = *(uint32_t*)rawData; rawData += 4;
	obj.BaseOfData = *(uint32_t*)rawData; rawData += 4;
	obj.ImageBase = *(uint32_t*)rawData; rawData += 4;
	obj.SectionAlignment = *(uint32_t*)rawData; rawData += 4;
	obj.FileAlignment = *(uint32_t*)rawData; rawData += 4;
	obj.MajorOperatingSystemVersion = *(uint16_t*)rawData; rawData += 2;
	obj.MinorOperatingSystemVersion = *(uint16_t*)rawData; rawData += 2;
	obj.MajorImageVersion = *(uint16_t*)rawData; rawData += 2;
	obj.MinorImageVersion = *(uint16_t*)rawData; rawData += 2;
	obj.MajorSubsystemVersion = *(uint16_t*)rawData; rawData += 2;
	obj.MinorSubsystemVersion = *(uint16_t*)rawData; rawData += 2;
	obj.Win32VersionValue = *(uint32_t*)rawData; rawData += 4;
	obj.SizeOfImage = *(uint32_t*)rawData; rawData += 4;
	obj.SizeOfHeaders = *(uint32_t*)rawData; rawData += 4;
	obj.CheckSum = *(uint32_t*)rawData; rawData += 4;
	obj.Subsystem = *(uint16_t*)rawData; rawData += 2;
	obj.DllCharacteristics = *(uint16_t*)rawData; rawData += 2;
	obj.SizeOfStackReserve = *(uint32_t*)rawData; rawData += 4;
	obj.SizeOfStackCommit = *(uint32_t*)rawData; rawData += 4;
	obj.SizeOfHeapReserve = *(uint32_t*)rawData; rawData += 4;
	obj.SizeOfHeapCommit = *(uint32_t*)rawData; rawData += 4;
	obj.LoaderFlags = *(uint32_t*)rawData; rawData += 4;
	obj.NumberOfRvaAndSizes = *(uint32_t*)rawData; rawData += 4;
	obj.DataDirectory = malloc(obj.NumberOfRvaAndSizes * sizeof(IMAGE_DATA_DIRECTORY));
	for (int i = 0; i < obj.NumberOfRvaAndSizes; i++) {
		obj.DataDirectory[i] = CreateIMAGE_DATA_DIRECTORY(&rawData);
	}
	*data = rawData;
	return obj;
};
void FreeIMAGE_OPTIONAL_HEADER32(IMAGE_OPTIONAL_HEADER32 obj) {
	for (int i = 0; i < obj.NumberOfRvaAndSizes; i++) {
		FreeIMAGE_DATA_DIRECTORY(obj.DataDirectory[i]);
	}
	free(obj.DataDirectory);
};

/// 
IMAGE_NT_HEADERS32 CreateIMAGE_NT_HEADERS32(uint8_t **data) {
	uint8_t *rawData = *data;
	IMAGE_NT_HEADERS32 obj;
	obj.Signature = *(uint32_t*)rawData; rawData += 4;
	obj.FileHeader = CreateIMAGE_FILE_HEADER(&rawData);
	obj.OptionalHeader = CreateIMAGE_OPTIONAL_HEADER32(&rawData);
	*data = rawData;
	return obj;
};
void FreeIMAGE_NT_HEADERS32(IMAGE_NT_HEADERS32 obj) {
	FreeIMAGE_FILE_HEADER(obj.FileHeader);
	FreeIMAGE_OPTIONAL_HEADER32(obj.OptionalHeader);
};

/// 
IMAGE_SECTION_HEADER CreateIMAGE_SECTION_HEADER(uint8_t **data) {
	uint8_t *rawData = *data;
	IMAGE_SECTION_HEADER obj;
	obj.Name = malloc(8);
	for (int i = 0; i < 8; i++) {
		obj.Name = rawData[i];
	}
	rawData += 8;
	obj.VirtualSize = *(uint32_t*)rawData; rawData += 4;
	obj.VirtualAddress = *(uint32_t*)rawData; rawData += 4;
	obj.SizeOfRawData = *(uint32_t*)rawData; rawData += 4;
	obj.PointerToRawData = *(uint32_t*)rawData; rawData += 4;
	obj.PointerToRelocations = *(uint32_t*)rawData; rawData += 4;
	obj.PointerToLinenumbers = *(uint32_t*)rawData; rawData += 4;
	obj.NumberOfRelocations = *(uint16_t*)rawData; rawData += 2;
	obj.NumberOfLinenumbers = *(uint16_t*)rawData; rawData += 2;
	obj.Characteristics = *(uint32_t*)rawData; rawData += 4;
	*data = rawData;
	return obj;
};
void FreeIMAGE_SECTION_HEADER(IMAGE_SECTION_HEADER obj) {
	free(obj.Name);
};

/// 
WINDOWS_EXE_HEADER CreateWINDOWS_EXE_HEADER(uint8_t **data) {
	uint8_t *rawData = *data;
	WINDOWS_EXE_HEADER obj;
	obj.Header = CreateIMAGE_NT_HEADERS32(&rawData);
	obj.Sections = malloc(obj.Header.FileHeader.NumberOfSections * sizeof(IMAGE_SECTION_HEADER));
	for (int i = 0; i < obj.Header.FileHeader.NumberOfSections; i++) {
		obj.Sections[i] = CreateIMAGE_SECTION_HEADER(&rawData);
	}
	*data = rawData;
	return obj;
};
void FreeWINDOWS_EXE_HEADER(WINDOWS_EXE_HEADER obj) {
	FreeIMAGE_NT_HEADERS32(obj.Header);
	for (int i = 0; i < obj.Header.FileHeader.NumberOfSections; i++) {
		FreeIMAGE_SECTION_HEADER(obj.Sections[i]);
	}
	free(obj.Sections);
};

/// 
IMAGE_BASE_IMPORT_DESCRIPTOR CreateIMAGE_BASE_IMPORT_DESCRIPTOR(uint8_t **data) {
	uint8_t *rawData = *data;
	IMAGE_BASE_IMPORT_DESCRIPTOR obj;
	obj.OriginalFirstThunk = *(uint32_t*)rawData; rawData += 4;
	obj.TimeDateStamp = *(uint32_t*)rawData; rawData += 4;
	obj.ForwarderChain = *(uint32_t*)rawData; rawData += 4;
	obj.Name = *(uint32_t*)rawData; rawData += 4;
	obj.FirstThunk = *(uint32_t*)rawData; rawData += 4;
	*data = rawData;
	return obj;
};
void FreeIMAGE_BASE_IMPORT_DESCRIPTOR(IMAGE_BASE_IMPORT_DESCRIPTOR obj) {
};

/// 
IMAGE_DELAY_IMPORT_DESCRIPTOR CreateIMAGE_DELAY_IMPORT_DESCRIPTOR(uint8_t **data) {
	uint8_t *rawData = *data;
	IMAGE_DELAY_IMPORT_DESCRIPTOR obj;
	obj.grAttrs = *(uint32_t*)rawData; rawData += 4;
	obj.szName = *(uint32_t*)rawData; rawData += 4;
	obj.phmod = *(uint32_t*)rawData; rawData += 4;
	obj.pIAT = *(uint32_t*)rawData; rawData += 4;
	obj.pINT = *(uint32_t*)rawData; rawData += 4;
	obj.pBoundIAT = *(uint32_t*)rawData; rawData += 4;
	obj.pUnloadIAT = *(uint32_t*)rawData; rawData += 4;
	obj.dwTimeStamp = *(uint32_t*)rawData; rawData += 4;
	*data = rawData;
	return obj;
};
void FreeIMAGE_DELAY_IMPORT_DESCRIPTOR(IMAGE_DELAY_IMPORT_DESCRIPTOR obj) {
};

/// 
IMAGE_BOUND_IMPORT_DESCRIPTOR CreateIMAGE_BOUND_IMPORT_DESCRIPTOR(uint8_t **data) {
	uint8_t *rawData = *data;
	IMAGE_BOUND_IMPORT_DESCRIPTOR obj;
	obj.TimeDataStamp = *(uint32_t*)rawData; rawData += 4;
	obj.OffsetModuleName = *(uint16_t*)rawData; rawData += 2;
	obj.NumberOfModuleForwarderRefs = *(uint16_t*)rawData; rawData += 2;
	*data = rawData;
	return obj;
};
void FreeIMAGE_BOUND_IMPORT_DESCRIPTOR(IMAGE_BOUND_IMPORT_DESCRIPTOR obj) {
};

