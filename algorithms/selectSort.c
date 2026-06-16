#include "sort.h"

void selectSort(int *arr, int n){
    int l = 0;

    while (l < n){
        int minElInd = l;

        for (int i = l + 1; i < n; i++){
            if (arr[i] < arr[minElInd]) {
                minElInd = i;
            }
        }

        if (arr[minElInd] != arr[l]){
            int temp = arr[l];
            arr[l] =  arr[minElInd];
            arr[minElInd] = temp;
        }

        l++;
    } 
}