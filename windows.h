//
// Created by Aritra on 24/10/2024.
//

#ifndef CINTERPRETER_WINDOWS_H
#define CINTERPRETER_WINDOWS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __WIN32

char * readline(const char * prompt);
void terminalOutputClear(void);

#endif

#endif //CINTERPRETER_WINDOWS_H
