//
//  LogRegisters.h
//  
//
//  Created by Alex Shipin on 11/26/22.
//

#ifndef LogRegisters_h
#define LogRegisters_h

#include <stdio.h>
#include "Log.h"

char* print32Registers();

#define REG32_PRINT_SIZE (14 * 13)
#define PRINT32_REGS DEBUG_RUN({ char* out = print32Registers(); printf("%s", out); free(out); })

char* print16Registers();

#define REG16_PRINT_SIZE (9 * 13)
#define PRINT16_REGS DEBUG_RUN({ char* out = print16Registers(); printf("%s", out); free(out); })

#endif /* LogRegisters_h */
