#include "header.h"
 
bool mx_isspace(char c) {
	if (c == 32) {
		return true;
	}
	else if (c >= 9 && c <= 13) {
		return true;
	}
	else {
		return false;
	}
}


