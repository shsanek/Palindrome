//
//  String.h
//  
//
//  Created by Alex Shipin on 11/29/22.
//

#ifndef String_h
#define String_h

#include <stdio.h>

int8_t* stringCopy(int8_t *source);
int checkPrefix(int8_t *source, int8_t *prefix);
int getLengthString(int8_t *source);
int8_t* stringConcatenation(int8_t *first, int8_t *second);

#endif /* String_h */
