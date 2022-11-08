//
//  GenerateFunctions.h
//  
//
//  Created by Alex Shipin on 10/17/22.
//

#ifndef GenerateFunctions_h
#define GenerateFunctions_h

#include <stdio.h>
#include "BaseFunction.h"

typedef void (*CommandFunction)();

CommandFunction commandFunctions16[256 * 8];
CommandFunction commandFunctions32[256 * 8];

#endif /* GenerateFunctions_h */