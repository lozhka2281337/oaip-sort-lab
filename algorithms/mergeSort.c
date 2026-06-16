#include "sort.h"

void merge(int *arr, int l, int mid, int r){
    int n1 = mid-l+1;
    int n2 = r - mid;
    
    int arr1[n1];
    int arr2[n2];
    
    for (int i = 0; i < n1; i++) arr1[i] = arr[l+i];
    for (int i = 0; i < n2; i++) arr2[i] = arr[mid + i + 1];
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2){
        if (arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k++] = arr1[i++];
    }

    while (j < n2){
        arr[k++] = arr2[j++];
    }
}


void mergeSort(int *arr, int l, int r){
    if (l >= r) return;

    int mid = (l + r) / 2;
    
    mergeSort(arr, l, mid - 1);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}
