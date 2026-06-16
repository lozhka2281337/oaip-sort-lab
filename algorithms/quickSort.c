#include "sort.h"

void quickSort(int *arr, int l, int r){
    if (l >= r) return;

    int pivot = arr[(l + r) / 2];
    int i = l, j = r;

    while (i <= j){
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--; 
        }
    }    

    if (l < j) quickSort(arr, l, j);
    if (i < r) quickSort(arr, i, r);
}
