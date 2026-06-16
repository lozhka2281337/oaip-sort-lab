#ifndef SORT_H
#define SORT_H

#include "../generators/generateArray.h"

void bubbleSort(int *arr, int n);
void selectSort(int *arr, int n);
void quickSort(int *arr, int l, int r);
void mergeSort(int *arr, int l, int r);
void heapSort(int *arr, int n);

#endif