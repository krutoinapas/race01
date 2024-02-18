#include "header.h"

char* mx_itoa(int number) {
    char* result;
    int size = 0;
    int temp = number;

    if (number < 0) {
            size++;
            temp *= -1;
    }
    if (number == 0) {
        result = mx_strnew(1);
        result[0] = '0';
        return result;
    }
    while (temp != 0) {
        temp /= 10;
        size++;
    }

    result = mx_strnew(size);
    if (number < 0) {
        result[0] = '-';
        number *= -1;
    }

    result[size] = '\0';
    size--;

    for (int i = size; number != 0; i++) {
        result[size] = (number % 10) + '0';
        number /= 10;
        size--;
    }
    return result;
}


