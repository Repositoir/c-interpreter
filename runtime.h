//
// Created by Aritra on 24/10/2024.
//

#ifndef CINTERPRETER_RUNTIME_H
#define CINTERPRETER_RUNTIME_H

void parse_code_file(int argc, const char * argv[]);

void terminalOutputClear(void);

const char * promptString(void);

void sampleParse(const char * inputPrompt, runtype_t runType);

void check_termination(char * input);


#endif //CINTERPRETER_RUNTIME_H
