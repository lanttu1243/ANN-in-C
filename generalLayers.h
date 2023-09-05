//
// Created by Lasse Kukkula on 16.5.2023.
//
#include "matrix.h"
#ifndef ANN_IN_C_GENERALLAYERS_H
#define ANN_IN_C_GENERALLAYERS_H

#endif //ANN_IN_C_GENERALLAYERS_H
typedef struct outputLayer{
    double(*errorFunction)(array*);
    double error;
    array weight;
    array bias;
    array dW;
    array dB;
    array dO;
}outLayer;