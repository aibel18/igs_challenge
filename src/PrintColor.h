#ifndef PRINT_COLOR_H
#define PRINT_COLOR_H

#define MASK_RED 0x00FF0000

typedef unsigned int ui32;

void printIntAsHex(ui32 num);

int getRedCanal(ui32 num);

ui32 toRedCanal(int num);

void printGradientInRedCanal(ui32 rgb1, ui32 rgb2, int step);

#endif
