//
//  DosFileSystem.h
//  
//
//  Created by Alex Shipin on 11/29/22.
//

#ifndef DosFileSystem_h
#define DosFileSystem_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../Function/BaseFunction.h"
#include "../Support/String.h"
#include "../Support/Log.h"

void addVirtualFolder(int8_t *virtualFolder, int8_t *realFolder, int8_t isWriteEnabled);
char* realPathForPath(int8_t *path);

int vfsLseekFile(uint16_t descriptor, int32_t offset, int type);
int vfsCloseFile(uint16_t descriptor);
int vfsReadFile(uint16_t descriptor, void* target, int size, char* isEnd);
int vfsOpenFile(char *path, int mode);
void settingVFS(int debugCount);

ARRAY_STACK(debugFileDescription, uint16_t);

#endif /* DosFileSystem_h */
