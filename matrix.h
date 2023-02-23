//
// Created by Lasse Kukkula on 23.2.2023.
//

#ifndef ANN_IN_C_MATRIX_H
#define ANN_IN_C_MATRIX_H

#endif //ANN_IN_C_MATRIX_H

#include "matrix.c"

double** createArray(unsigned const int M, unsigned const int N)
double** matMul(double** a, double** b, unsigned const int Ma, unsigned const int Na, unsigned const int Mb, unsigned const int Nb)

double** matAdd(double** a, double** b, unsigned const int Ma, unsigned const int Na, unsigned const int Mb, unsigned const int Nb)
double** matSub(double** a, double** b, unsigned const int Ma, unsigned const int Na, unsigned const int Mb, unsigned const int Nb)
double** elemMul(double** a, double** b, unsigned const int Ma, unsigned const int Na, unsigned const int Mb, unsigned const int Nb)
double** scalAdd(double** a, double k, unsigned const int M, unsigned const int N)
double** scalSub(double** a, double k, unsigned const int M, unsigned const int N)
double** scalMul(double** a, double k, unsigned const int M, unsigned const int N)
double** scalDiv(double** a, double k, unsigned const int M, unsigned const int N)

double** matAdd(double** a, double** b, unsigned const int Ma, unsigned const int Na, unsigned const int Mb, unsigned const int Nb)
double** matSub(double** a, double** b, unsigned const int Ma, unsigned const int Na, unsigned const int Mb, unsigned const int Nb)
double** elemMul(double** a, double** b, unsigned const int Ma, unsigned const int Na, unsigned const int Mb, unsigned const int Nb)
double** scalAdd(double** a, double k, unsigned const int M, unsigned const int N)
double** scalSub(double** a, double k, unsigned const int M, unsigned const int N)
double** scalMul(double** a, double k, unsigned const int M, unsigned const int N)
double** scalDiv(double** a, double k, unsigned const int M, unsigned const int N)

double** copy(double** a, unsigned const int M, unsigned const int N)

double** freeArray(double** a)
double sum(double** a, unsigned const int M, unsigned const int N)
double** transpose(double** a, unsigned const int M, unsigned const N)
void printArray(double** a, unsigned const int M, unsigned const int N)
