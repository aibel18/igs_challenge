#include "Palindrome.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#ifndef DATA_PATH
#define DATA_PATH "/"
#endif

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
	if (count && have_odd)
		count++;

	return count;
}

int main() {

	char file_path[] = DATA_PATH;
	strcat(file_path, "arquivo.txt");

	FILE* file = fopen(file_path, "r+");

	if (file == NULL) {
		printf("file no exits \n");
		return -1;
	}

	int bufferLength = 255;
	char buffer[bufferLength];

	while (fgets(buffer, bufferLength, file)) {
		int rpta = palindrome_major(buffer);
		printf("palidrome major is: %i\n", rpta);
	}

	fclose(file);

	return 0;
}