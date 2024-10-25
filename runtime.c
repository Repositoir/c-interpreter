//
// Created by Aritra on 24/10/2024.
//

#include "imports.h"
#include "runtime.h"

void parse_code_file(int argc, const char * argv[]){
    if (argc < 2) return;

    print_file_contents(argv[1]);
}

void terminalOutputClear(void){
    system(CLEAR);
}

const char * promptString(void){
    char * cwd = (char *) malloc(sizeof (char) * PATH_MAX);

    char buffer[PATH_MAX];

    if (getcwd(cwd, PATH_MAX) != NULL){
        sprintf(cwd, "%s%s%s", "user => ", getcwd(buffer, PATH_MAX), " % ");
        // printf("user %s$ ", cwd);
    } else {
        printf("/root"); // *evil laugh*
    }

    return cwd;
}

void sampleParse(const char * inputStr, runtype_t runType){

    if (runType != SCRIPT && runType != TERMINAL_INTERACTIVE) return;

    if (strstr(inputStr, CONSOUT) != NULL){

        if (runType == TERMINAL_INTERACTIVE) {
            printf("%s\n", strstr(inputStr, " ") + 1);
        } else {
            printf("%s", strstr(inputStr, " ") + 1);
        }

        return;
    } else if (strstr(inputStr, CLEAR) != NULL){
        terminalOutputClear();
    }
}

void check_termination(char * input){
    if (strcmp(input, TERMINATE) == 0){
        free(input);
        exit(0);
    }
}

