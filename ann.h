//
// Created by Lasse Kukkula on 16.5.2023.
//
#include "annLayer.h"
#include "generalLayers.h"

#ifndef ANN_IN_C_ANN_H
#define ANN_IN_C_ANN_H

#endif //ANN_IN_C_ANN_H

typedef struct ann {
    ANNlayer* layers;
    int nLayers;
    outLayer layer;
    double error;
} ANN;