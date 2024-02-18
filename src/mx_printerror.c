#include "header.h"

void mx_printerror(char *s, char *arg) {
    mx_printerr(s);
    mx_printerr(arg);
    mx_printerr("\n");
}

