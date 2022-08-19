#include "RomanNumber.h"

#include <stdio.h>
#include <string.h>

bool inputRomanNumber(char* buffer) {

	printf("%s", INPUT_MESSAGE);
	printf("%s", TO_QUIT_MESSAGE);

	scanf("%s", buffer);

	if (strcmp(buffer, "q") == 0)
		return false;
}

bool validateRomanNumber(char* str) {

	for (int i = 0; str[i] != '\0'; i++) {

		if (str[i] == 'I' || str[i] == 'V' || str[i] == 'X' || str[i] == 'L' || str[i] == 'C' || str[i] == 'D' ||
		    str[i] == 'M')
			continue;
		else
			return false;
	}
	return true;
}

int toDecimal(char c) { return RomanLetter[c - 'A']; }

int romanToDecimal(char* str) {
	int rpta = 0;

	int prev = toDecimal('M');

	for (int i = 0; str[i] != '\0'; i++) {

		int value = toDecimal(str[i]);

		if (value <= prev) {
			rpta += value;
		} else {
			rpta += value - 2 * prev;
		}
		prev = value;
	}

	return rpta;
}

int main() {

	const int bufferSize = 64;

	char buffer[bufferSize];

	while (inputRomanNumber(buffer)) {
		if (validateRomanNumber(buffer)) {
			int rpta = romanToDecimal(buffer);
			printf("%s => %i\n", buffer, rpta);
		}
	}

	return 0;
}