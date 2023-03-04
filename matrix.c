#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double** createArray(unsigned int M, unsigned int N) {
    double** arr = (double**) malloc(M*sizeof(double*));
    for (unsigned int i = 0; i < M; i++) {
        arr[i] = (double*) malloc(N*sizeof(double));
    }
    return arr;
}
void freeArray(double** arr, unsigned int M) {
    for (int i = 0; i < M; i++) {
        free(arr[i]);
    }
    free(arr);
}
void printArray(double** arr, unsigned int M, unsigned int N) {
    for (unsigned int i = 0; i < M; i++) {
        printf("[");
        for (unsigned int j = 0; j < N; j++) {
            (N-1)==j ? printf("%0.3f", arr[i][j]) : printf("%0.3f,", arr[i][j]);
        }
        (N-1)==i ? printf("]\n") : printf("\n");
    }
}