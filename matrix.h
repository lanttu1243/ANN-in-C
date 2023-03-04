//
// Created by Lasse Kukkula on 23.2.2023.
//

#ifndef ANN_IN_C_MATRIX_H
#define ANN_IN_C_MATRIX_H

#endif //ANN_IN_C_MATRIX_H

double** createArray(unsigned int M, unsigned int N);
double** matMul(double** a, double** b, unsigned int Ma, unsigned int Na, unsigned int Mb, unsigned int Nb);

double** matAdd(double** a, double** b, unsigned int Ma, unsigned int Na, unsigned int Mb, unsigned int Nb);
double** matSub(double** a, double** b, unsigned int Ma, unsigned int Na, unsigned int Mb, unsigned int Nb);
double** elemMul(double** a, double** b, unsigned int Ma, unsigned int Na, unsigned int Mb, unsigned int Nb);
double** scalAdd(double** a, double k, unsigned int M, unsigned int N);
double** scalSub(double** a, double k, unsigned int M, unsigned int N);
double** scalMul(double** a, double k, unsigned int M, unsigned int N);
double** scalDiv(double** a, double k, unsigned int M, unsigned int N);

void matAddV(double** a, double** b, unsigned int Ma, unsigned int Na, unsigned int Mb, unsigned int Nb);
void matSubV(double** a, double** b, unsigned int Ma, unsigned int Na, unsigned int Mb, unsigned int Nb);
void elemMulV(double** a, double** b, unsigned int Ma, unsigned int Na, unsigned int Mb, unsigned int Nb);
void scalAddV(double** a, double k, unsigned int M, unsigned int N);
void scalSubV(double** a, double k, unsigned int M, unsigned int N);
void scalMulV(double** a, double k, unsigned int M, unsigned int N);
void scalDivV(double** a, double k, unsigned int M, unsigned int N);

double** copy(double** a, unsigned int M, unsigned int N);

void randoms(double** a, unsigned int M, unsigned int N);
void freeArray(double** a, unsigned int M);
double sum(double** a, unsigned int M, unsigned int N);
double** transpose(double** a, unsigned int M, unsigned N);
void printArray(double** a, unsigned int M, unsigned int N);
