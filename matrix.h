#ifndef HW2_MATRIX_H
#define HW2_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix* createMatrix(int rows, int cols);

void destroyMatrix(Matrix *matrix);

void printMatrix(Matrix *matrix);

Matrix* readMatrix();

//Matrix* addMatrices(Matrix *matrix1, Matrix *matrix2);

//Matrix* multiplyMatrices(Matrix *matrix1, Matrix *matrix2);


#endif //HW2_MATRIX_H
