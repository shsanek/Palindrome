//
//  Log.c
//  
//
//  Created by Alex Shipin on 11/26/22.
//

#include "Log.h"

void printHex(uint8_t* value, char* out) {
    if (*value == 0) {
        sprintf(out, "00");
    } else if (*value < 16) {
        sprintf(out, "0%X", *value);
    } else {
        sprintf(out, "%X", *value);
    }
}
