//
// Created by Aritra on 25/10/2024.
//

#include "imports.h"
#include "file_psr.h"
#include "runtime.h"


int starts_with(const char * mainStr, const char * subStr){

    size_t subStrLen = strlen(subStr);

    for (size_t i = 0; i < subStrLen; ++i){
        if (mainStr[i] != subStr[i]){
            return 0;
        }
    }

    return 1;
}

int print_file_contents(const char * fileName){
    FILE * filePtr = fopen(fileName, "r");

    if (filePtr == NULL) {
        printf("NULL FILE * ptr - file '%s' does not exist\n", fileName);
        return 1;
    }

    char buffer[LINE_MAX];

    while (fgets(buffer, LINE_MAX, filePtr)){
        if (starts_with(buffer, CONSOUT)){
            sampleParse(buffer, SCRIPT);
        }
    }

    fclose(filePtr);
    return 0;
}
