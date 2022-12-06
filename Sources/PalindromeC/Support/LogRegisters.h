//
//  LogRegisters.h
//  
//
//  Created by Alex Shipin on 11/26/22.
//

#ifndef LogRegisters_h
#define LogRegisters_h

#include <stdio.h>
#include <stdlib.h>

#include "Log.h"
#include "../Base/Registers.h"
#include "../Base/Read.h"
#include "../Base/Flags.h"

void printFlags(char *out);

char* print32Registers();

#define FLAGS_PRINT_SIZE (3 * 8 + 2)

#define REG32_PRINT_SIZE (14 * 9 + 9 * 4 + FLAGS_PRINT_SIZE)
#define PRINT32_REGS DEBUG_RUN({ char* out = print32Registers(); printf("%s", out); free(out); })

char* print16Registers();

#define REG16_PRINT_SIZE (9 * 13 + FLAGS_PRINT_SIZE)
#define PRINT16_REGS DEBUG_RUN({ char* out = print16Registers(); printf("%s", out); free(out); })

#define PRINT_REGS DEBUG_RUN({\
if (context.mod) {\
    char* out = print32Registers(); printf("%s", out); free(out);\
} else { \
    char* out = print16Registers(); printf("%s", out); free(out);\
}\
})\

#endif /* LogRegisters_h */
