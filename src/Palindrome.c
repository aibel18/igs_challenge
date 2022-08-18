#include "Palindrome.h"
#include <stdbool.h>
#include <stdio.h>

int palindrome_major(char* str) {

	int letter[26] = {0};

	// frequency letter
	for (int i = 0; str[i] != '\0'; i++) {
		letter[str[i] - 'a']++;
	}

	int count = 0;
	bool have_odd = false;

	for (int i = 0; i < 26; i++) {
		if (letter[i] & 1) {  // if odd number: using letter[i] - 1 letters to build palindrome
			count += letter[i] - 1;
			have_odd = true;
		} else {  // if even number: using all letters to build palindrome
			count += letter[i];
		}
	}

	// if exist odd number of letter: using one letter for the center position
	if (have_odd)
		count++;

	return count;
}

int main() {

	char str[] = "asdoromametemamorfdf";

	int rpta = palindrome_major(str);

	printf("str1 is %i\n", rpta);

	return 0;
}