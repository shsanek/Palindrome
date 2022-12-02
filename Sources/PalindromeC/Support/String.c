//
//  String.c
//  
//
//  Created by Alex Shipin on 11/29/22.
//

#include "String.h"

int8_t* stringCopy(int8_t *source) {
    if (source == NULL) {
        return NULL;
    }
    int len = getLengthString(source) + 1;

    int8_t* target = malloc(len);
    memcpy(target, source, len);
    return target;
}

int checkPrefix(int8_t *source, int8_t *prefix) {
    if (source == NULL || prefix == NULL) {
        return 0;
    }
    int len = 0;
    while (source[len] != 0 && prefix[len] != 0 && prefix[len] == source[len]) { len++; }
    if (prefix[len] == 0) {
        return len;
    }
    return 0;
}

int getLengthString(int8_t *source) {
    if (source == NULL) {
        return 0;
    }
    int len = 0;
    while (source[len] != 0) { len++; }
    return len;
}

int8_t* stringConcatenation(int8_t *first, int8_t *second) {
    int len1 = getLengthString(first);
    int len2 = getLengthString(second);

    int8_t* result = malloc(len1 + len2 + 1);

    if (len1 > 0) { memcpy(result, first, len1); }
    if (len2 > 0) { memcpy(result + len1, second, len2); }
    result[len1 + len2] = 0;

    return result;
}
