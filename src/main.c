#include "header.h"

int main(int argc, char *argv[]) {
	if (argc != 5) {
		mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [reult]\n");
		exit(-1);
	}

	char *operand1 = mx_strtrim(argv[1]);
	char *operand2 = mx_strtrim(argv[3]);
	char *operation = mx_strtrim(argv[2]);
	char *result = mx_strtrim(argv[4]);

	bool check = mx_check(operand1, operand2, operation, result);
	
	if (!check) {
	free(operand1);
	free(operand2);
	free(operation);
	free(result);
	exit(-1);
	}

	if (mx_compare(operand1, operation, operand2, result)) {
		mx_print_equation(operand1, operation, operand2, result);
	}

	decode(operand1, operation, operand2, result);
	free(operand1);
	free(operand2);
	free(operation);
	free(result);
	return 0;
}


