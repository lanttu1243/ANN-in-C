#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int main() {
    // Initialise input and output matrices
    double** input = createArray(4, 3);
    double** output = createArray(4, 1);
    input[0][2] = 1.0;
    input[1][1] = 1.0;
    input[2][0] = 1.0;
    input[2][2] = 1.0;
    input[3][0] = 1.0;
    input[3][1] = 1.0;
    output[0][0] = 1.0;
    output[2][0] = 1.0;

    double** weight = createArray(3, 1);
    randoms(weight, 3, 1);

    double** bias = createArray(1, 1);
    randoms(bias, 1, 1);

    double error = 100;
    double learningRate = 1e-3;

    int n = 0;

    while (error > 0.1) {
        // Forward pass
        double** y = matAdd(matMul(input, weight, 4, 3, 3, 1), bias, 4, 1, 4, 1);
        double** elemEr = matSub(output, y, 4, 1, 4, 1);
        double** rms = copy(elemEr, 4, 1);
        scalMulV(rms, 0.5, 4, 1);
        elemMulV(rms, rms, 4, 1, 4, 1);
        // Calculate the error
        error = sum(rms, 4, 1);
        // Backpropagation dE/dB
        double** dy = copy(elemEr, 4, 1);
        scalMulV(dy, -1.0, 4, 1);
        scalSubV(bias, learningRate * sum(dy, 4, 1), 1, 1);
        // Backpropagation dE/dW
        double** xt = transpose(input, 4, 3);
        double** dw = matMul(xt, dy, 3, 4, 4, 1);
        matSubV(weight, dw, 3, 1, 3, 1);

        if (n % 1000 == 0) {
            printf("%d, %f\n", n, error);
            printArray(y, 4, 1);
        }
        freeArray(y);
        freeArray(elemEr);
        freeArray(rms);
        freeArray(dy);
        freeArray(xt);
        freeArray(dw);
        n++;
    }

}