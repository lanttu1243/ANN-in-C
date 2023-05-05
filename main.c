#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void formatOutput(array in, array out) {
    for (int i = 0; i < in.M; i++) {
        out.array[i][0] = in.array[i][2];
    }
}

int main() {
    int inputSize = 10;
    // Initialise input and output matrices
    array input = createArray(inputSize, 3);
    array output = createArray(inputSize, 1);
    randomInt(input, 0, 2);
    formatOutput(input, output);

    array weight = createArray(3, 1);
    randomFloat(weight);

    array bias = createArray(1, 1);
    randomFloat(bias);

    array xT = createArray(3, inputSize);
    T(xT, input);

    printArray(matMul(input, weight));

    double error = 100;
    double learningRate = 1e-7;
    array y = createArray(inputSize, 1);
    int n = 0;

    while (error > 0.3) {
        // Initialise forward pass
        array z = matMul(input, weight);
        array eZ = createArray(inputSize, 1);
        array eO = createArray(inputSize, 1);
        array E = createArray(inputSize, 1);
        // forward pass
        scalAdd(z, bias.array[0][0]);
        sigmoid(y, z);
        arrayAdd(eZ, output);
        arraySub(eZ, y);
        arrayAdd(eO, eZ);
        arrayMul(eO, eO);
        arrayAdd(E, eO);
        scalMul(E, 0.5);
        error = sum(E);

        array dedy = createArray(inputSize, 1);
        array dydz = createArray(inputSize, 1);
        array dzdW;
        array dzdB = createArray(1, 1);

        copy(dedy, eZ);

        sigmoidDerivative(dydz, dedy);
        dzdW = matMul(xT, dydz);
        dzdB.array[0][0] = sum(dydz);
        scalMul(dzdB, learningRate);
        scalMul(dzdW, learningRate);
        arrayAdd(weight, dzdW);
        arrayAdd(bias, dzdB);

        freeArray(z);
        freeArray(eZ);
        freeArray(eO);
        freeArray(E);
        freeArray(dedy);
        freeArray(dydz);
        freeArray(dzdW);
        freeArray(dzdB);


        if (n % 1000 == 0) {
            printf("%d, %f\n", n, error);
        }
        n++;
    }
    printArray(y);
    printArray(output);
    return 0;
}