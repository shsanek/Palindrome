//
//  DOSFileSystem.h
//  
//
//  Created by Alex Shipin on 11/29/22.
//

#ifndef DOSFileSystem_h
#define DOSFileSystem_h

#include <stdio.h>

#include "../Base/Read.h"
#include "../Base/Flags.h"
#include "../include/Base.h"
#include "../Function/BaseFunction.h"
#include "../Memory/RealMemoryManager.h"

void dosOpenFile();
void dosReadFromFile();
void dosCloseFile();

void systemDOSFunction(uint8_t a);

#endif /* DOSFileSystem_h */
