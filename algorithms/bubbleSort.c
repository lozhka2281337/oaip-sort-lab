#include "sort.h"

void bubbleSort(int *arr, int n){
    int swapped = 1;
    
    while (swapped) {
        swapped = 0;

        for (int i = 1; i < n; i++){
            if (arr[i] < arr[i-1]) {
                int temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;

                swapped = 1;
            }
        }
    }
}