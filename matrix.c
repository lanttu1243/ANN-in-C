#ifndef ANN_IN_C_MATRIX_H
#define ANN_IN_C_MATRIX_H

#endif //ANN_IN_C_MATRIX_H
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double** createArray(unsigned const int M, unsigned const int N) {
    double** columns = calloc(M, sizeof(double*));
    double* rows = calloc(M*N, sizeof(double));
    for (int i = 0; i < M; i++) {
        columns[i] = rows + N * i;
    }
    return columns;
}
void randoms(double** a, unsigned const int M, unsigned const int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            srand(time(NULL));
            a[i][j] = rand();
        }
    }
}
void ones(double** a, unsigned const int M, unsigned const int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            srand(time(NULL));
            a[i][j] = 1.000;
        }
    }
}
double** matMul(double** a, double** b, unsigned const int Ma, unsigned const int Na, unsigned const int Mb, unsigned const int Nb) {
#if Na != Mb
#error Shape mismatch
#endif
    double** c = createArray(Ma, Nb);
    for (int i = 0; i < Ma; i++) {
        for (int j = 0; j < Nb; j++){
            c[i][j] = 0;
            for (int k = 0; k < Mb; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}
double** matAdd(double** a, double** b, unsigned const int Ma, unsigned const int Na, unsigned const int Mb, unsigned const int Nb) {
#if Na != Nb && Ma != Mb
#error Shape mismatch
#endif
    double** c = createArray(Ma, Nb);
    for (int i = 0; i < Ma; i++) {
        for (int j = 0; j < Nb; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}
double** matSub(double** a, double** b, unsigned const int Ma, unsigned const int Na, unsigned const int Mb, unsigned const int Nb){
#if Na != Nb && Ma != Mb
#error Shape mismatch
#endif
    double** c = createArray(Ma, Nb);
    for (int i = 0; i < Ma; i++) {
        for (int j = 0; j < Nb; j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    return c;
}
double** scalAdd(double** a, double k, unsigned const int M, unsigned const int N) {
    double** c = createArray(Ma, Nb);
    for (int i = 0; i < Ma; i++) {
        for (int j = 0; j < Nb; j++){
            c[i][j] = a[i][j] + k;
        }
    }
    return c;
}
double** scalSub(double** a, double k, unsigned const int M, unsigned const int N) {
    double** c = createArray(Ma, Nb);
    for (int i = 0; i < Ma; i++) {
        for (int j = 0; j < Nb; j++){
            c[i][j] = a[i][j] - k;
        }
    }
    return c;
}
double** scalMul(double** a, double k, unsigned const int M, unsigned const int N) {
    double** c = createArray(Ma, Nb);
    for (int i = 0; i < Ma; i++) {
        for (int j = 0; j < Nb; j++){
            c[i][j] = a[i][j] * k;
        }
    }
    return c;
}
double** scalDiv(double** a, double k, unsigned const int M, unsigned const int N) {
#if k == 0
#error Div by zero
#endif
    double** c = createArray(Ma, Nb);
    for (int i = 0; i < Ma; i++) {
        for (int j = 0; j < Nb; j++){
            c[i][j] = a[i][j] / k;
        }
    }
    return c;
}
void freeArray(double** a) {
    free(a[0]);
    free(a);
}
void printArray(double** a, unsigned const int M, unsigned const int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            j == N-1 ? printf("%0.2f\n", a[i][j]) : printf("%0.2f ", a[i][j]);
        }
    }
}