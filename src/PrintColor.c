#include "PrintColor.h"

#include <stdio.h>
#include <string.h>

void printIntAsHex(ui32 num) {
	char hex_val[32];
	sprintf(hex_val, "%X", num);

	printf("%s\n", hex_val);
}

int getRedCanal(ui32 num) {
	return (num & MASK_RED) >> 16;
}

ui32 toRedCanal(int num) {
	return num << 16;
}

void printGradientInRedCanal(ui32 rgb1, ui32 rgb2, int step) {

	if (step <= 0 || rgb2 < rgb1) {
		printf("invalid inputs");
		return;
	}

	int red1 = getRedCanal(rgb1);
	int red2 = getRedCanal(rgb2);

	int gradient_step = (red2 - red1) / step;

	ui32 gradient = 0;

	for (int i = 0; i < step; i++) {
		red1 += gradient_step;

		gradient = toRedCanal(red1) | rgb1;

		printIntAsHex(gradient);
	}
}

int main() {

	ui32 a = 0x00001A;
	ui32 b = 0xFF001A;
	int step = 3;

	printGradientInRedCanal(a, b, step);

	return 0;
}