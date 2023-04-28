#include "matrix.h"

int main() {
    Matrix* matrix1 = readMatrix();
    Matrix* matrix2 = readMatrix();
    Matrix* matrix3 = readMatrix();
    Matrix* matrix4 = readMatrix();

    printMatrix(matrix1);
    printf("\n");
    printMatrix(matrix2);
    printf("\n");
    printMatrix(matrix3);
    printf("\n");
    printMatrix(matrix4);
    printf("\n");

    return 0;
}