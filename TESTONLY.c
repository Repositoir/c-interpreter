#include "mpc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long eval_op(long x, char* op, long y) {
    if (strcmp(op, "+") == 0) { return x + y; }
    if (strcmp(op, "-") == 0) { return x - y; }
    if (strcmp(op, "*") == 0) { return x * y; }
    if (strcmp(op, "/") == 0) { return x / y; }
    return 0;
}

long eval(mpc_ast_t* t) {
    /* If tagged as number, return it directly. */
    if (strstr(t->tag, "number")) {
        return atoi(t->contents);
    }

    /* Skip extraneous nodes to get the operator. */
    char* op = t->children[1]->contents;

    /* Store the third child (first operand) in `x`. */
    long x = eval(t->children[2]);

    /* Iterate the remaining children, combining results. */
    int i = 3;
    while (i < t->children_num && strstr(t->children[i]->tag, "expr")) {
        x = eval_op(x, op, eval(t->children[i]));
        i++;
    }

    return x;
}

int main(void) {
    /* Initialize parsers for individual grammar components */
    mpc_parser_t *Number = mpc_new("number");
    mpc_parser_t *Operator = mpc_new("operator");
    mpc_parser_t *Expr = mpc_new("expr");
    mpc_parser_t *Lispy = mpc_new("lispy");

    /* Define the grammar with parentheses support */
    mpca_lang(MPCA_LANG_DEFAULT,
              "                                              \
        number   : /-?[0-9]+/ ;                               \
        operator : '+' | '-' | '*' | '/' ;                    \
        expr     : <number> | '(' <operator> <expr>+ ')' ;    \
        lispy    : /^/ <expr> /$/ ;                           \
        ",
              Number, Operator, Expr, Lispy);

    /* Parse input */
    mpc_result_t r;
    if (mpc_parse("<stdin>", "(+ 6 5)", Lispy, &r)) {
        mpc_ast_print(r.output);
        long result = eval(r.output);
        printf("%li\n", result); // Print the evaluated result
        mpc_ast_delete(r.output); // Cleanup parsed output
    } else {
        mpc_err_print(r.error); // Print error if parsing fails
        mpc_err_delete(r.error); // Cleanup error
    }

    /* Cleanup parsers */
    mpc_cleanup(4, Number, Operator, Expr, Lispy);

    return 0;
}
