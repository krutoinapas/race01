#include "header.h"

bool mx_isspace(char c);
bool mx_isdigit(int c);

int mx_atoi(const char *str) {
	int number = 0;
	int negative = 1;
	int i = 0;
	while (mx_isspace(str[i])) {
		i++;
	}
	if (!mx_isdigit(str[i]) && str[i] != '-' && str[i] != '+') {
		return 0;
	}
	if (str[i] == '-') {
		negative = -1;
		i++;
	}
	else if (str[i] == '+') {
			negative = 1;
			i++;
	}
	while (mx_isdigit(str[i])) {
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return number * negative;
}



