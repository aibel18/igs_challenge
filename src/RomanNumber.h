#ifndef ROMAN_NUMBER_H
#define ROMAN_NUMBER_H

#include <stdbool.h>

char INPUT_MESSAGE[] = "Enter a valid roman number [I, V, X, L, C, D, M]\n";
char TO_QUIT_MESSAGE[] = "Press 'q' key to out\n";

int RomanLetter[26] = {0, 0, 100, 500, 0, 0, 0, 0, 1, 0, 0, 50, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10, 0, 0};

bool inputRomanNumber(char* str);

bool validateRomanNumber(char* str);

int toDecimal(char c);

int romanToDecimal(char* str);

#endif
