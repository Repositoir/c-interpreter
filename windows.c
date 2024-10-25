//
// Created by Aritra on 24/10/2024.
//

#include "windows.h"



#ifdef __WIN32

static char buffer[2048];

char * readline(const char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);

    char * cpy = (char *) malloc(strlen(buffer) + 1);

    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

void terminalOutputClear(void){
    system("cls");
}

#endif
