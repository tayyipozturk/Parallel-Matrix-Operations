#include "matrix.h"
#include "hw2_output.h"

int main() {
    hw2_init_output();

    Matrix** matrices = readAllMatrices();
    Matrix* result0 = createMatrix(matrices[0]->rows, matrices[0]->cols);
    Matrix* result1 = createMatrix(matrices[2]->rows, matrices[2]->cols);
    Matrix* result2 = createMatrix(matrices[0]->rows, matrices[2]->cols);
    int* count1 = malloc(sizeof(int) * matrices[2]->cols);
    for (int i = 0; i < matrices[2]->cols; i++){
        count1[i] = 0;
    }

    sem_t* sem0 = malloc(sizeof(sem_t) * matrices[0]->rows);
    sem_t* sem1 = malloc(sizeof(sem_t) * matrices[2]->cols);

    pthread_mutex_t* mutex1 = malloc(sizeof(pthread_mutex_t)*matrices[2]->cols);

    pthread_t* threads0 = malloc(sizeof(pthread_t) * matrices[0]->rows);
    pthread_t* threads1 = malloc(sizeof(pthread_t) * matrices[2]->cols);
    pthread_t* threads2 = malloc(sizeof(pthread_t) * matrices[0]->rows);

    for (int i = 0; i < matrices[0]->rows; i++){
        sem_init(&sem0[i], 0, 0);
        args0 *arguments = malloc(sizeof(args0));
        arguments->matrix1 = matrices[0];
        arguments->matrix2 = matrices[1];
        arguments->result = result0;
        arguments->row = i;
        arguments->sem = sem0;
        pthread_create(&threads0[i], NULL, addMatrices0, arguments);
    }

    for (int i = 0; i < matrices[2]->rows; i++){
        sem_init(&sem1[i], 0, 0);
        args1 *arguments = malloc(sizeof(args1));
        arguments->matrix1 = matrices[2];
        arguments->matrix2 = matrices[3];
        arguments->result = result1;
        arguments->row = i;
        arguments->sem = sem1;
        arguments->count = count1;
        arguments->semCount = matrices[0]->rows;
        arguments->mutex = mutex1;
        pthread_create(&threads1[i], NULL, addMatrices1, arguments);
    }

    for (int i = 0; i < matrices[0]->rows; i++){
        args2 *arguments = malloc(sizeof(args2));
        arguments->matrix1 = result0;
        arguments->matrix2 = result1;
        arguments->result = result2;
        arguments->row = i;
        arguments->sem0 = sem0;
        arguments->sem1 = sem1;
        pthread_create(&threads2[i], NULL, multiplyMatrices, arguments);
    }

    for (int i = 0; i < matrices[0]->rows; i++){
        pthread_join(threads0[i], NULL);
    }

    for (int i = 0; i < matrices[2]->rows; i++){
        pthread_join(threads1[i], NULL);
    }

    for (int i = 0; i < matrices[0]->rows; i++){
        pthread_join(threads2[i], NULL);
    }

//    printMatrix(result0);
//    printMatrix(result1);
    printMatrix(result2);

    return 0;
}