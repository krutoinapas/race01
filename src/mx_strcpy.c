#include "header.h"

char *mx_strcpy(char *dst, const char *src) {
	char *original_dst = dst;
    const char *original_src = src;
	while (*src != '\0') {
		*dst = *src;
		dst++;
		src++;	
	}	
	*dst = '\0';
    src = original_src;
	return original_dst;
}

