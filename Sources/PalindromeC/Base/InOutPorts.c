//
//  InOutPorts.c
//  
//
//  Created by Alex Shipin on 12/5/22.
//

#include "InOutPorts.h"
#include "Models.h"
#include "Registers.h"

void emptyIOPortOutputFunction(uint16_t port, uint8_t* value, uint8_t size) {
    printf("[OUT]found p: %d, s: %d", port, size);
}

void emptyIOPortInputFunction(uint16_t port, uint8_t* value, uint8_t size) {
    printf("[IN]found p: %d, s: %d", port, size);
}


void IOPortInstall() {
    for (int i = 0; i < 0xFFFF; i++) {
        context.ports[i].input = emptyIOPortInputFunction;
        context.ports[i].output = emptyIOPortOutputFunction;
    }
}
