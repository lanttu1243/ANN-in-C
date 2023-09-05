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
    array input = createArray(inputSize, 10);
    array output = createArray(inputSize, 1);
    randomInt(input, 0, 2);
    formatOutput(input, output);

    array weight = createArray(10, 1);
    randomFloat(weight);

    array bias = createArray(1, 1);
    randomFloat(bias);

    array xT = createArray(10, inputSize);
    T(xT, input);

    double error = 100;
    double learningRate = 1e-1;
    array o = createArray(inputSize, 1);
    int n = 0;

    while (error > 0.000001) {
        // Initialise forward pass
        array z = matMul(input, weight);
        array eZ = createArray(inputSize, 1);
        array eO = createArray(inputSize, 1);
        array E = createArray(inputSize, 1);
        // forward pass
        scalAdd(z, bias.array[0][0]);
        tanhArray(o, z);
        arrayAdd(eZ, output);
        arraySub(eZ, o);
        arrayAdd(eO, eZ);
        arrayMul(eO, eO);
        arrayAdd(E, eO);
        scalMul(E, 0.5);
        error = sum(E);

        array dy = createArray(inputSize, 1);
        array dz = createArray(inputSize, 1);
        array ds = createArray(inputSize, 1);
        array dw;
        array db = createArray(1, 1);

        copy(dy, eZ);
        tanhDerivative(ds, dy);
        arrayMul(ds, dy);
        arrayAdd(dz, ds);

        dw = matMul(xT, dz);
        db.array[0][0] = sum(dz);
        scalMul(db, learningRate);
        scalMul(dw, learningRate);
        arrayAdd(weight, dw);
        arrayAdd(bias, db);

        freeArray(z);
        freeArray(eZ);
        freeArray(eO);
        freeArray(E);
        freeArray(dy);
        freeArray(dz);
        freeArray(dw);
        freeArray(db);
        freeArray(ds);
        n++;
    }
    printf("%d, %f\n", n, error);
    for (int i = 0; i < (o.M < o.N ? o.N : o.M); i++){
        printf("Calculated: %0.3f, Actual: %0.3f, Difference: %0.3f\n", o.array[0][i], output.array[0][i], output.array[0][i] - o.array[0][i]);
    }
    return 0;
}