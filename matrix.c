#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include "math.h"
#include <time.h>
typedef struct array{
    double** array;
    int M;
    int N;
}array;
array createArray(unsigned int M, unsigned int N) {
    double** arr = (double**) calloc(M, sizeof(double*));
    array matrix = {arr, M, N};
    for (unsigned int i = 0; i < matrix.M; i++) {
        matrix.array[i] = (double*) calloc(matrix.N, sizeof(double));
    }
    return matrix;
}
void freeArray(array arr) {
    for (int i = 0; i < arr.M; i++) {
        free(arr.array[i]);
    }
    free(arr.array);
}
void printArray(array arr) {
    for (unsigned int i = 0; i < arr.M; i++) {
        printf("[");
        for (unsigned int j = 0; j < arr.N; j++) {
            (arr.N-1)==j ? printf("%0.3f", arr.array[i][j]) : printf("%0.3f,", arr.array[i][j]);
        }
        (arr.M-1)==i ? printf("]\n") : printf("\n");
    }
}
void copy(array target, array source) {
    int an, am, bn, bm;
    am = target.M;
    an = target.N;
    bm = source.M;
    bn = source.N;
#if am != bm && an != bn
#error shape mismatch
#endif
    for (int i = 0; i < source.M; i++) {
        for (int j = 0; j < source.N; j++) {
            target.array[i][j] = source.array[i][j];
        }
    }
}
array matMul(array a, array b) {
    int an = a.N;
    int bm = b.M;
#if an != bm
#error shape mismatch
#endif
    array c = createArray(a.M, b.N);
    for (int i = 0; i < a.M; i++) {
        for (int j = 0; j < b.N; j++) {
            c.array[i][j] = 0;
            for (int k = 0; k < a.N; k++) {
                c.array[i][j] += a.array[i][k] * b.array[k][j];
            }
        }
    }
    return c;
}
void arrayAdd(array a, array b) {
    int an = a.N;
    int am = a.M;
    int bn = b.N;
    int bM = b.M;
#if an != bn && am != bm
#error shape mismatch
#endif
    for (int i = 0; i < a.M; i++){
        for (int j = 0; j < a.N; j++) {
            a.array[i][j] += b.array[i][j];
        }
    }
}
void arraySub(array a, array b) {
    int an = a.N;
    int am = a.M;
    int bn = b.N;
    int bM = b.M;
#if an != bn && am != bm
#error shape mismatch
#endif
    for (int i = 0; i < a.M; i++){
        for (int j = 0; j < a.N; j++) {
            a.array[i][j] -= b.array[i][j];
        }
    }
}
void scalAdd(array a, double b) {
    for (int i = 0; i < a.M; i++){
        for (int j = 0; j < a.N; j++) {
            a.array[i][j] += b;
        }
    }
}
void scalMul(array a, double b) {
    for (int i = 0; i < a.M; i++){
        for (int j = 0; j < a.N; j++) {
            a.array[i][j] *= b;
        }
    }
}
void arrayMul(array a, array b) {
    int an = a.N;
    int am = a.M;
    int bn = b.N;
    int bM = b.M;
#if an != bn && am != bm
#error shape mismatch
#endif
    for (int i = 0; i < a.M; i++){
        for (int j = 0; j < a.N; j++) {
            a.array[i][j] *= b.array[i][j];
        }
    }
}
void randoms(array arr) {
    for (unsigned int i = 0; i < arr.M; i++){
        for (unsigned int j = 0; j < arr.N; j++) {
            arr.array[i][j] = rand() * 2.0 / RAND_MAX - 1.0;
        }
    }
}
double sigmoidDouble(double x) {
    return 1 / (1 + exp(- x));
}
void sigmoid(array target, array source) {
    for (unsigned int i = 0; i < target.M; i++){
        for (unsigned int j = 0; j < target.N; j++) {
            target.array[i][j] = sigmoidDouble(source.array[i][j]);
        }
    }
}
void sigmoidDerivative(array target, array source) {
    for (unsigned int i = 0; i < target.M; i++){
        for (unsigned int j = 0; j < target.N; j++) {
            target.array[i][j] = sigmoidDouble(source.array[i][j]) * (1.0 - sigmoidDouble(source.array[i][j]));
        }
    }
}
double sum(array a) {
    double out = 0;
    for (unsigned int i = 0; i < a.M; i++){
        for (unsigned int j = 0; j < a.N; j++) {
            out += a.array[i][j];
        }
    }
    return out;
}
void T(array target, array source) {
    int an, am, bn, bm;
    am = target.M;
    an = target.N;
    bm = source.M;
    bn = source.N;
#if am != bn && an != bm
#error shape mismatch
#endif
    for (int i = 0; i < source.M; i++) {
        for (int j = 0; j < source.N; j++) {
            target.array[j][i] = source.array[i][j];
        }
    }
}
void random01(array a) {
    for (unsigned int i = 0; i < a.M; i++){
        for (unsigned int j = 0; j < a.N; j++) {
            a.array[i][j] = (rand() % 2);
        }
    }
}