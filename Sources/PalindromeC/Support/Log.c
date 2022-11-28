//
//  Log.c
//  
//
//  Created by Alex Shipin on 11/26/22.
//

#include "Log.h"

char debugLine[512];
uint16_t debugLineIndex = 0;

void sprintHex(uint8_t* value, char* out) {
    if (*value == 0) {
        sprintf(out, "00");
    } else if (*value < 16) {
        sprintf(out, "0%X", *value);
    } else {
        sprintf(out, "%X", *value);
    }
}

void printHex(uint8_t* value) {
    if (*value == 0) {
        printf("00");
    } else if (*value < 16) {
        printf("0%X", *value);
    } else {
        printf("%X", *value);
    }
}

void appendInDebugLineHex(uint8_t* value) {
    char out[2];
    sprintHex(value, out);
    debugLine[debugLineIndex] = out[0];
    debugLine[debugLineIndex + 1] = out[1];
    debugLineIndex += 2;
}

void appendString(char* value) {
    int index = 0;
    while (value[index] != 0) {
        debugLine[debugLineIndex] = value[index];
        debugLineIndex += 1;
    }
}

void clearDebugLine() {
    debugLineIndex = 0;
}

void printDebugLine() {
    debugLine[debugLineIndex] = 0;
    printf("%s", debugLine);
    debugLineIndex = 0;
}
