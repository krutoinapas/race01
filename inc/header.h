#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int mx_strlen(const char *s);
void mx_printchar(char c);
bool mx_isspace(char c);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_printerr(const char *s);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
void mx_strdel(char **str);
void mx_printerror(char *s, char *arg);
bool mx_isdigit(int c);
int mx_atoi(const char *str);
char* mx_itoa(int number);
void mx_str_reverse(char *s);
char *mx_strcpy(char *dst, const char *src);
void mx_printstr(const char *s);
bool mx_check(char *operand1, char *operand2, char *operation, char *result);
bool mx_compare(char *operand1, char *operation, char *operand2, char *result);
void mx_print_equation(char *a, char *b, char *op, char *c);
void decode(char *operand1, char *operation, char *operand2, char *result);
void mx_printint(int n);


