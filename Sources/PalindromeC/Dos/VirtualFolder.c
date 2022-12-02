//
//  DosFileSystem.c
//  
//
//  Created by Alex Shipin on 11/29/22.
//

#include "VirtualFolder.h"

typedef struct VirtualFolder {
    int8_t *virtualPath;
    int8_t *realPath;

    char isWriteEnabled;

    struct VirtualFolder *next;
} VirtualFolder;

VirtualFolder* virtualFoldersHead = NULL;

void addVirtualFolder(int8_t *virtualFolder, int8_t *realFolder, int8_t isWriteEnabled) {
    int8_t *v = stringCopy(virtualFolder);
    int8_t *r = stringCopy(realFolder);

    VirtualFolder* folder = malloc(sizeof(VirtualFolder));
    folder->virtualPath = v;
    folder->realPath = r;
    folder->isWriteEnabled = isWriteEnabled;
    folder->next = virtualFoldersHead;
    virtualFoldersHead = folder;

    return folder;
}

char* realPathForPath(int8_t *path) {
    int prefixLen = 0;
    VirtualFolder* forever = NULL;
    for (VirtualFolder* current = virtualFoldersHead; current != NULL; current = current->next) {
        int currentLen = checkPrefix(path, current->virtualPath);
        if (currentLen > prefixLen) {
            prefixLen = currentLen;
            forever = current;
        }
    }
    if (prefixLen == 0) {
        return NULL;
    }
    int8_t *result = stringConcatenation(forever->realPath, path + prefixLen);
    if (result == NULL) {
        return NULL;
    }
    int i = 0;
    while (result[i] != 0) {
        if (result[i] == '\\') {
            result[i] = '/';
        }
        i++;
    }
    return (char*)result;
}

ARRAY_STACK_IMP(debugFileDescription, uint16_t);

FILE* OpeningVirtualFile[512];

void settingVFS(int debugCount) {
    for (int i = 0; i < 512; i ++) {
        OpeningVirtualFile[i] = NULL;
    }
    debugFileDescriptionSetCount(debugCount);
}

int vfsLseekFile(uint16_t descriptor, int32_t offset, int type) {
    FILE* file = OpeningVirtualFile[descriptor];
    if (file == NULL) {
        return -2;
    }
    int value = fseek(file, offset, type);
    if (value != 0) {
        return -1;
    }
    int current = ftell(file);
    return current;
}

int vfsFileSize(uint16_t descriptor, int32_t offset, int type) {
    FILE* file = OpeningVirtualFile[descriptor];
    if (file == NULL) {
        return -2;
    }
    fseek(file, offset, type);
}

int vfsOpenFile(char *path, int mode) {
    int id = -1;
    for (int i = 5; i < 512; i++) {
        if (OpeningVirtualFile[i] == NULL) {
            id = i;
            break;;
        }
    }
    DEBUG_RUN({ if (debugFileDescriptionIndex > 0) { id = debugFileDescriptionPop(); } })

    char *realPath = realPathForPath((int8_t*)path);

    if (id == -1 || realPath == NULL) {
        assert(0);
        return -1;
    }

    FILE* file = NULL;
    if (mode == 0) {
        file = fopen(realPath, "rb");
    } else if (mode == 1) {
        file = fopen(realPath, "wb");
    } else if (mode == 2) {
        file = fopen(realPath, "rb+");
    }
    free(realPath);
    
    if (file == NULL) {
        return -2;
    }
    OpeningVirtualFile[id] = file;
    return id;
}

int vfsReadFile(uint16_t descriptor, void* target, int size, char* isEnd) {
    FILE* file = OpeningVirtualFile[descriptor];
    if (file == NULL) {
        return -2;
    }
    int len = 0;
    for (int i = 0; i < size; i ++) {
        fread(((uint8_t*)target) + i, 1, 1, file);
        len++;
    }
    if (feof(file)) {
        *isEnd = 1;
    } else {
        *isEnd = 0;
    }
    if (ferror(file) && len == 0) {
        return -1;
    }
    return len;
}

int vfsCloseFile(uint16_t descriptor) {
    if (descriptor >= 512) {
        return 6;
    }
    if (NULL == OpeningVirtualFile[descriptor]) {
        return 1;
    }
    fclose(OpeningVirtualFile[descriptor]);
    OpeningVirtualFile[descriptor] = NULL;
    return 0;
}


