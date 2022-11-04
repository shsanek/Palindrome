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

typedef void (*CommandFunction)(
    Context* context
);

CommandFunction commandFunctions16[512];
CommandFunction commandFunctions32[512];

#endif /* GenerateFunctions_h */
