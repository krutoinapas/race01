#include "header.h"

char *mx_strncpy(char *dst, const char *src, int len) {
	char *original_dst = dst;
	const char *original_src = src;
	while (len > 0 && *src != '\0') {
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	while (len > 0) {
	*dst = '\0';
	dst++;
	len--;
	}
	dst = original_dst;
	src = original_src;
	return original_dst;
}



