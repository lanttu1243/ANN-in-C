//
// Created by Lasse Kukkula on 16.5.2023.
//
#include "matrix.h"
#ifndef ANN_IN_C_ANNLAYER_H
#define ANN_IN_C_ANNLAYER_H

#endif //ANN_IN_C_ANNLAYER_H

typedef struct annLayer {
    double (*activationFunction)(array, array);
    array weight;
    array bias;
    array dW;
    array dB;
    array dO;
}ANNlayer;

