#include "header.h"

bool mx_compare(char* operand1, char* operation, char* operand2, char* result) {
    int len_a = mx_strlen(operand1);
    int len_op = mx_strlen(operation);
    int len_b = mx_strlen(operand2);
    int len_c = mx_strlen(result);

    for (int i = 0; i < len_a; i++) {
        if (operand1[i] == '?') {
            return false;
        }
    }
    for (int i = 0; i < len_op; i++) {
        if (operation[i] == '?') {
            return false;
        }
    }
    for (int i = 0; i < len_b; i++) {
        if (operand2[i] == '?') {
            return false;
        }
    }
    for (int i = 0; i < len_c; i++) {
        if (result[i] == '?') {
            return false;
        }
    }

    int a = atoi(operand1);
    int b = atoi(operand2);
    int c = atoi(result);

    if (operation[0] == '/' && b == 0) {
        return false;
    }

    if (a != 0 && operation[0] == '/' && c == 0) {
        return false;
    }

    if (operation[0] == '+') {
        if (a + b == c)
            return true;
    }

    if (operation[0] == '-') {
        if (a - b == c)
            return true;
    }

    if (operation[0] == '*') {
        if (a * b == c)
            return true;
    }

    if (operation[0] == '/') {
        if (a / b == c)
            return true;
    }

    return false;
}


