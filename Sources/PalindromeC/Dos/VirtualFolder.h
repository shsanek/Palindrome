//
//  DosFileSystem.h
//  
//
//  Created by Alex Shipin on 11/29/22.
//

#ifndef DosFileSystem_h
#define DosFileSystem_h

#include <stdio.h>
#include "../include/Base.h"

#define ARRAY_STACK(NAME, TYPE) \
void NAME##SetCount(uint16_t count);\
void NAME##Push(TYPE value);\
TYPE NAME##Pop();\

void addVirtualFolder(int8_t *virtualFolder, int8_t *realFolder, int8_t isWriteEnabled);
char* realPathForPath(int8_t *path);

int vfsCloseFile(uint16_t descriptor);
int vfsReadFile(uint16_t descriptor, void* target, int size, char* isEnd);
int vfsOpenFile(char *path, int mode);
void settingVFS(int debugCount);

ARRAY_STACK(debugFileDescription, uint16_t);

#endif /* DosFileSystem_h */
