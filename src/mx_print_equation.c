#include "header.h"

void mx_print_equation(char* a, char* op, char* b, char* c) {
    int operand1 = mx_atoi(a);
    int operand2 = mx_atoi(b);
    int result = mx_atoi(c);

    mx_printint(operand1);
    mx_printchar(' ');
    mx_printchar(op[0]);
    mx_printchar(' ');
    mx_printint(operand2);
    mx_printchar(' ');
    mx_printchar('=');
    mx_printchar(' ');
    mx_printint(result);
    mx_printchar('\n');
}


