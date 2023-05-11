#ifndef HW2_MATRIX_H
#define HW2_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "hw2_output.h"

typedef struct Matrix {
    int rows;
    int cols;
    int **data;
} Matrix;

typedef struct args0 {
    Matrix *matrix1;
    Matrix *matrix2;
    Matrix *result;
    int row;
    sem_t* sem;
} args0;

typedef struct args1 {
    Matrix *matrix1;
    Matrix *matrix2;
    Matrix *result;
    int col;
    sem_t* sem;
} args1;

typedef struct args2 {
    Matrix *matrix1;
    Matrix *matrix2;
    Matrix *result;
    int row;
    sem_t* sem0;
    sem_t* sem1;
} args2;


Matrix* createMatrix(int rows, int cols);

void destroyMatrix(Matrix *matrix);

void printMatrix(Matrix *matrix);

Matrix* readMatrix();

Matrix** readAllMatrices();

void* addMatrices0(void* arg);

void* addMatrices1(void* arg);

void* multiplyMatrices(void* arg);


#endif //HW2_MATRIX_H
