#include "functions.h"

bool if_number(char input[], int buffor_index) {
	int i = 0;
	if (buffor_index > 1) {
		i = 1;
		//1, poniewa¿ input[0] moze rownac sie '-' przy negative numbers
	}
	if (input[i] > 47 && input[i] < 58) {
		return true;
	}
	return false;
}
bool znak_bialy(char input) {
	{
		if (input < 33) {
			return true;
		}
		else {
			return false;
		}
	}
}

int priority(char operand) {
	if (operand == '(') {
		return 0;
	}
	if (operand == '+' || operand == '-' ) {
		return 1;
	}
	if (operand == '*' || operand == '/') {
		return 2;
	}
	if (operand == 'I' || operand == 'N' || operand == ')' || operand == 'm' || operand == 'M') {
		return 3;
	}
	else {
		return -1;
	}
}


