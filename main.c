// https://buildyourownlisp.com/chapter4_interactive_prompt#read_evaluate_print

#include "imports.h"
#include "runtime.h"


int main(int argc, const char * argv[]) {

    // mpc_parser_t * Adjective = mpc_or(4, mpc_sym("Wow"), mpc_sym("Many"), mpc_sym("so"), mpc_sym("such"));

    // mpc_parser_t* Noun = mpc_or(5, mpc_sym("lisp"), mpc_sym("language"), mpc_sym("book"),mpc_sym("build"), mpc_sym("c"));

    if (argc > 1){
        // parse passed files instead
        parse_code_file(argc, argv);
        return EXIT_SUCCESS;
    }

    while (1) {

        char * input = readline(promptString());

        sampleParse(input, TERMINAL_INTERACTIVE);

        add_history(input);

        // check exit
        check_termination(input);

        free(input);
    }


    return 0;
}
