#include "header.h"

char *mx_strtrim(const char *str) {
	if (str == NULL) {
		return NULL;
	}
	int first = 0;
	while (mx_isspace(str[first]) && str[first] != '\0') {
		first++;
	}
	int last = mx_strlen(str) - 1;
	while (mx_isspace(str[last]) && last > first) {
		last--;
	}
	char *new_str = mx_strnew(last - first + 1);
	if (new_str == NULL) {
		return NULL;
	}
	mx_strncpy(new_str, str + first, last - first + 1);
	return new_str;
}



