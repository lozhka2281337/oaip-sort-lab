#ifndef GENERATE_ARRAY_H
#define GENERATE_ARRAY_H

#include <stdlib.h>

#define ARRAY_FRACTION_DIVISOR 5

void generateRandomArray(int *arr, int n);
void generateSortedArray(int *arr, int n);
void generateSortedReverseArray(int *arr, int n);
void generateLargeRepetArray(int *arr, int n);

#endif