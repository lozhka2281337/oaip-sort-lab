#include "generateArray.h"

void generateRandomArray(int *arr, int n){
    for (int i = 0; i < n; i++){
        arr[i] = rand();
    }
}

void generateSortedArray(int *arr, int n){
    for (int i = 0; i < n; i++) arr[i] = i+1;
}

void generateSortedReverseArray(int *arr, int n){
    for (int i = 0; i < n; i++) arr[i] = n - i;
}

void generateLargeRepetArray(int *arr, int n){
    int limit = n / ARRAY_FRACTION_DIVISOR;

    for (int i = 0; i < n; i++) arr[i] = 1 + rand() % limit;
}