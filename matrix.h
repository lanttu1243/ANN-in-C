//
// Created by Lasse Kukkula on 23.2.2023.
//

#ifndef ANN_IN_C_MATRIX_H
#define ANN_IN_C_MATRIX_H

#endif //ANN_IN_C_MATRIX_H
typedef struct array array;

array createArray(unsigned int M, unsigned int N);
void freeArray(array arr);
void printArray(array arr);
void copy(array target, array source);

array matMul(array a, array b);

void arrayAdd(array a, array b);
void arraySub(array a, array b);
void arrayMul(array a, array b);

void scalAdd(array a, double b);
void scalMul(array a, double b);

void sigmoid(array target, array source);
void sigmoidDerivative(array target, array source);

double sum(array a);
void T(array target, array source);

void randoms(array arr);
void random01(array a);
