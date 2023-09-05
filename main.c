#include <stdio.h>
#include "matrix.h"

void formatOutput(array in, array out) {
    for (int i = 0; i < in.M; i++) {
        out.array[i][0] = in.array[i][0] && in.array[i][1];
        out.array[i][1] = in.array[i][1] && in.array[i][2];
        out.array[i][2] = in.array[i][2] && in.array[i][3];
        out.array[i][3] = in.array[i][3] && in.array[i][4];
        out.array[i][4] = in.array[i][4] && in.array[i][5];
    }
}
void printResults(array input, array output, array o, double error, int n) {
    printf("Round: %d, Error: %f\n", n, error);
    for (int i = 0; i < input.M; i++){
        printf("%d: [", i);
        for (int j = 0; j < input.N; j++) {
            printf("%0.1f, ", input.array[i][j]);
        }
        printf("]: Calculated: [");
        for (int j = 0; j < output.N; j++) {
            printf("%0.3f, ", o.array[j][i]);
        }
        printf("]: Actual: [");
        for (int j = 0; j < output.N; j++) {
            printf("%0.3f, ", output.array[j][i]);
        }
        printf("]\n");
    }
}

int main() {
    int dataSize = 100; // number of entries
    int inputSize = 6; // size of input
    int outputSize = 5; // size of output
    printf("Input matrix is of size %dX%d", dataSize, inputSize);
    printf("Output matrix is of size %dX%d", dataSize, outputSize);
    // Initialise input and output matrices
    array input = createArray(dataSize, inputSize);
    array output = createArray(dataSize, outputSize);
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

    while (error > 0.00000001 && n < 10000000) {
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
        if (n == 1) {
            printResults(input, output, o, error, n);
        }
    }
    printResults(input, output, o, error, n);
    return 0;
}