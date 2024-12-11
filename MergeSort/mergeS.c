#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char* array[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    char* leftArray[n1], * rightArray[n2];

    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left = i];
    }

    for (int j = 0; j < n2; j++) {
        rightArray[j] = array[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(leftArray[i], rightArray[j]) <= 0) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
}

void mergeSort(char* array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}



