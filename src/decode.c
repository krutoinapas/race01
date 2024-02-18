#include "header.h"

 void decode(char* operand1, char* operation, char* operand2, char* result) {
    if (operation[0] == '?') {
        char* oper = mx_strnew(mx_strlen(operation));
        mx_strcpy(oper, "+");
        decode(operand1, oper, operand2, result);
        mx_strcpy(oper, "-");
        decode(operand1, oper, operand2, result);
        mx_strcpy(oper, "*");
        decode(operand1, oper, operand2, result);
        mx_strcpy(oper, "/");
        decode(operand1, oper, operand2, result);
        free(oper);
        return;
    }


    int operand1_size = mx_strlen(operand1);
    int operand2_size = mx_strlen(operand2);
    int result_size = mx_strlen(result);

    bool is_unknown1 = 0, is_unknown2 = 0, is_unknown3 = 0;

    // check unknown 1
    for (int i = 0; i < operand1_size; i++) {
        if (operand1[i] == '?') {
            is_unknown1 = true;
            break;
        }

    }
    int quest_count1 = 0;
    if (is_unknown1) {
        for (int i = 0; i < operand1_size; i++) {
            if (operand1[i] == '?') {
                quest_count1++;
            }
        }
    }

    // check unknown 2
    for (int i = 0; i < operand2_size; i++) {
        if (operand2[i] == '?') {
            is_unknown2 = true;
            break;
        }
    }
    int quest_count2 = 0;
    if (is_unknown2) {
        for (int i = 0; i < operand2_size; i++) {
            if (operand2[i] == '?') {
                quest_count2++;
            }
        }
    }

    // check unknown 3
    for (int i = 0; i < result_size; i++) {
        if (result[i] == '?') {
            is_unknown3 = true;
            break;
        }
    }
    int quest_count3 = 0;
    if (is_unknown3) {
        for (int i = 0; i < result_size; i++) {
            if (result[i] == '?') {
                quest_count3++;
            }
        }
    }

    // unknown 1 2
    if (is_unknown1 && is_unknown2) {
        int quest_index;
        for (int i = 0; i < operand1_size; i++) {
            if (operand1[i] == '?') {
                quest_index = i;
                break;
            }
        }
        for (int k = 0; k <= 9; k++) {
            char* copy = mx_strnew(operand1_size + 1);
            mx_strcpy(copy, operand1);
            char* n = mx_itoa(k);
            copy[quest_index] = n[0];
            free(n);
            decode(copy, operation, operand2, result);
            free(copy);
        }
    }

    // unknown 1 3
    else if (is_unknown1 && is_unknown3) {
        int quest_index;
        for (int i = 0; i < operand1_size; i++) {
            if (operand1[i] == '?') {
                quest_index = i;
                break;
            }
        }
        for (int k = 0; k <= 9; k++) {
            char* copy = mx_strnew(operand1_size + 1);
            mx_strcpy(copy, operand1);
            char* n = mx_itoa(k);
            copy[quest_index] = n[0];
            free(n);
            decode(copy, operation, operand2, result);
            free(copy);
        }

    }

    // unknown 2 3
    else if (is_unknown2 && is_unknown3) {
        int quest_index;
        for (int i = 0; i < operand2_size; i++) {
            if (operand2[i] == '?') {
                quest_index = i;
                break;
            }
        }
        for (int k = 0; k <= 9; k++) {
            char* copy = mx_strnew(operand1_size + 1);
            mx_strcpy(copy, operand2);
            char* n = mx_itoa(k);
            copy[quest_index] = n[0];
            free(n);
            decode(operand1, operation, copy, result);
            free(copy);
        }
    }

    // count ? 1
    else if (quest_count1 > 1) {
        int quest_index;
        for (int i = 0; i < operand1_size; i++) {
            if (operand1[i] == '?') {
                quest_index = i;
                break;
            }
        }
        for (int k = 0; k <= 9; k++) {
            char* copy = mx_strnew(operand1_size + 1);
            mx_strcpy(copy, operand1);
            char* n = mx_itoa(k);
            copy[quest_index] = n[0];
            free(n);
            decode(copy, operation, operand2, result);
            free(copy);
        }

    }

    // count ? 2        
    else if (quest_count2 > 1) {
        int quest_index;
        for (int i = 0; i < operand2_size; i++) {
            if (operand2[i] == '?') {
                quest_index = i;
                break;
            }
        }
        for (int k = 0; k <= 9; k++) {
            char* copy = mx_strnew(operand2_size + 1);
            mx_strcpy(copy, operand2);
            char* n = mx_itoa(k);
            copy[quest_index] = n[0];
            free(n);
            decode(operand1, operation, copy, result);
            free(copy);
        }
    }

    // count ? 3
    else if (quest_count3 > 1) {
        int quest_index;
        for (int i = 0; i < result_size; i++) {
            if (result[i] == '?') {
                quest_index = i;
                break;
            }
        }
        for (int k = 0; k <= 9; k++) {
            char* copy = mx_strnew(result_size + 1);
            mx_strcpy(copy, result);
            char* n = mx_itoa(k);
            copy[quest_index] = n[0];
            free(n);
            decode(operand1, operation, operand2, copy);
            free(copy);
        }
    }


    if (quest_count1 == 1) {
        int index;
        for (int i = 0; i < operand1_size; i++) {
            if (operand1[i] == '?') {
                index = i;
                break;
            }
        }
        char* copy = mx_strnew(operand1_size + 1);
        mx_strcpy(copy, operand1);
        for (int i = 0; i <= 9; i++) {
            char* n = mx_itoa(i);
            copy[index] = n[0];
            free(n);
            if (mx_compare(copy, operation, operand2, result)) {
                mx_print_equation(copy, operation, operand2, result);
            }
        }
        free(copy);
    }


    if (quest_count2 == 1) {
        int index;
        for (int i = 0; i < operand2_size; i++) {
            if (operand2[i] == '?') {
                index = i;
                break;
            }
        }
        char* copy = mx_strnew(operand2_size + 1);
        mx_strcpy(copy, operand2);
        for (int i = 0; i <= 9; i++) {
            char* n = mx_itoa(i);
            copy[index] = n[0];
            free(n);
            if (mx_compare(operand1, operation, copy, result)) {
                mx_print_equation(operand1, operation, copy, result);
            }
        }
        free(copy);
    }

    if (quest_count3 == 1) {
        int index;
        for (int i = 0; i < result_size; i++) {
            if (result[i] == '?') {
                index = i;
                break;
            }
        }
        char* copy = mx_strnew(result_size + 1);
        mx_strcpy(copy, result);
        for (int i = 0; i <= 9; i++) {
            char* n = mx_itoa(i);
            copy[index] = n[0];
            free(n);
            if (mx_compare(operand1, operation, operand2, copy)) {
                mx_print_equation(operand1, operation, operand2, copy);
            }
        }
        free(copy);
    }
    if (quest_count1 == 0 && quest_count2 == 0 && quest_count3 == 0) {
        if (mx_compare(operand1, operation, operand2, result)) {
            mx_print_equation(operand1, operation, operand2, result);
        }
    }
}

