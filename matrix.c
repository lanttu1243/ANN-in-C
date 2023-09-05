#include "matrix.h"

// Initialises a matrix
array createArray(unsigned int M, unsigned int N) {
    // initialise rows of matrix
    double** arr = (double**) calloc(M, sizeof(double*));
    array matrix = {arr, M, N, printArray};
    // Initialise columns
    for (unsigned int i = 0; i < matrix.M; i++) {
        matrix.array[i] = (double*) calloc(matrix.N, sizeof(double));
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix.array[i][j] = 0;
        }
    }
    return matrix;
}

// frees a matrix
int freeArray(array arr) {
    for (int i = 0; i < arr.M; i++) {
        free(arr.array[i]);
    }
    free(arr.array);
    return 0;
}
void printArray(array arr) {
    printf("[");
    for (unsigned int i = 0; i < arr.M; i++) {
        printf("[");
        for (unsigned int j = 0; j < arr.N; j++) {
            (arr.N-1)==j ? printf("%0.3f]", arr.array[i][j]) : printf("%0.3f,", arr.array[i][j]);
        }
        (arr.M-1)==i ? printf("]\n") : printf("\n");
    }
}
int copy(array target, array source) {
    int an, am, bn, bm;
    am = target.M;
    an = target.N;
    bm = source.M;
    bn = source.N;
    if (am != bm && an != bn) {
        printf("There is a shape mismatch between the two arrays!");
        return -1;
    }
    for (int i = 0; i < source.M; i++) {
        for (int j = 0; j < source.N; j++) {
            target.array[i][j] = source.array[i][j];
        }
    }
    return 0;
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
void randomFloat(array arr) {
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
void tanhArray(array target, array source) {
    for (unsigned int i = 0; i < target.M; i++) {
        for (unsigned int j = 0; j < target.N; j++) {
            target.array[i][j] = tanh(source.array[i][j]);
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
void tanhDerivative(array target, array source){
    for (unsigned int i = 0; i < target.M; i++){
        for (unsigned int j = 0; j < target.N; j++) {
            target.array[i][j] = 1.0 - tanh(source.array[i][j]) * tanh(source.array[i][j]);
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
void randomInt(array a, int min, int max) {
    for (unsigned int i = 0; i < a.M; i++){
        for (unsigned int j = 0; j < a.N; j++) {
            a.array[i][j] = (rand() % (max - min)) + min;
        }
    }
}