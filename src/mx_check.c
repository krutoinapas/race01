#include "header.h"

bool mx_check(char* operand1, char* operand2, char* operation, char* result) {
    int len_op1 = mx_strlen(operand1);
    int len_op2 = mx_strlen(operand2);
    int len_op = mx_strlen(operation);
    int len_res = mx_strlen(result);

    if (len_op != 1) {
        mx_printerror("Invalid operation: ", operation);
        return false;
    }
    if (operation[0] != '+' && operation[0] != '-' && operation[0] != '*' && operation[0] != '/' && operation[0] != '?') {
        mx_printerror("Invalid operation: ", operation);
        return false;
    }
    if (len_op1 <= 0) {
        mx_printerror("Invalid operand: ", operand1);
        return false;
    }
    int i = 0;
    if (operand1[0] == '-') {
        i++;
    }
    for (; i < len_op1; i++) {
        if (!mx_isdigit(operand1[i]) && operand1[i] != '?') {
            mx_printerror("Invalid operand: ", operand1);
            return false;
        }
    }
    if (len_op2 <= 0) {
        mx_printerror("Invalid operand: ", operand2);
        return false;
    }
    i = 0;
    if (operand2[0] == '-') {
        i++;
    }
    for (; i < len_op2; i++) {
        if (!mx_isdigit(operand2[i]) && operand2[i] != '?') {
            mx_printerror("Invalid operand: ", operand2);
            return false;
        }
    }
    if (len_res <= 0) {
        mx_printerror("Inalid result: ", result);
        return false;
    }
    i = 0;
    if (result[0] == '-') {
        i++;
    }
    for (; i < len_res; i++) {
        if (!mx_isdigit(result[i]) && result[i] != '?') {
            mx_printerror("Inalid result: ", result);
            return false;
        }
    }
    return true;
}


