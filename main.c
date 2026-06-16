#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "algorithms/sort.h"

// ANSI-коды для раскраски терминала
#define ANSI_RESET          "\x1b[0m"
#define ANSI_BOLD_CYAN      "\x1b[1;36m"
#define ANSI_BOLD_YELLOW    "\x1b[1;33m"
#define ANSI_GREEN          "\x1b[32m"
#define ANSI_MAGENTA        "\x1b[35m"

void measureStart(int *temp, int *arr,clock_t *startTime, int size){
    for (int q = 0; q < size; q++) temp[q] = arr[q];
    *startTime = clock();
}

void measureEnd(clock_t startTime, const char *sortName){
    clock_t endTime = clock();
    double seconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("  " ANSI_GREEN "%-12s" ANSI_RESET " : " ANSI_MAGENTA "%.6f" ANSI_RESET " sec\n", sortName, seconds);
}

int main(){
    srand(time(NULL));

    int sizes[] = {100, 1000, 5000, 10000, 50000};
    void (*GenerateFunc[])(int*, int) = {
        generateRandomArray, generateSortedArray, 
        generateSortedReverseArray, generateLargeRepetArray};
    const char *generateNames[] = {"Random", "Sorted", "Sorted Reverse", "Large Repeat"};
    
    for (int i = 0; i < 5; i++){
        int size = sizes[i];

        int *arr = malloc(sizeof(int) * size);
        int *temp = malloc(sizeof(int) * size);

        if (arr == NULL || temp == NULL){
            fprintf(stderr, "error: memory allocation\n");
            return 1;
        }

        printf(ANSI_BOLD_CYAN "=========================================\n");
        printf(" ARRAY SIZE: %d\n", size);
        printf("=========================================\n" ANSI_RESET);

        for (int j = 0; j < 4; j++){
            // генерируем массив 
            GenerateFunc[j](arr, size);
            printf("\n " ANSI_BOLD_YELLOW "-> Type: %s" ANSI_RESET "\n", generateNames[j]);

            clock_t startTime;

            measureStart(temp, arr, &startTime, size);
            bubbleSort(temp, size);
            measureEnd(startTime, "bubble");

            measureStart(temp, arr, &startTime, size);
            selectSort(temp, size);
            measureEnd(startTime, "select");

            measureStart(temp, arr, &startTime, size);
            quickSort(temp, 0, size-1);
            measureEnd(startTime, "quick");

            measureStart(temp, arr, &startTime, size);
            mergeSort(temp, 0, size-1);
            measureEnd(startTime, "merge");

            measureStart(temp, arr, &startTime, size);
            heapSort(temp, size);
            measureEnd(startTime, "heap");
        }

        printf("\n");

        free(arr);
        free(temp);
    }

    return 0;
}