//
//  InOutPorts.h
//  
//
//  Created by Alex Shipin on 12/5/22.
//

#ifndef InOutPorts_h
#define InOutPorts_h

#include <stdio.h>

typedef void (*IOPortFunction)(uint16_t port, uint8_t* value, uint8_t size);

typedef struct IOPort {
    IOPortFunction input;
    IOPortFunction output;
} IOPort;

void IOPortInstall();

#endif /* InOutPorts_h */
