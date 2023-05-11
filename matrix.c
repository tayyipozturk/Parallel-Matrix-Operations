#include "matrix.h"

Matrix* createMatrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(sizeof(int) * cols);
    }
    return matrix;
}

void destroyMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *readMatrix(){
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    Matrix *matrix = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++){
            scanf("%d", &matrix->data[i][j]);
        }
    }
    return matrix;
}

Matrix** readAllMatrices(){
    Matrix **matrices = malloc(sizeof(Matrix*) * 4);
    for (int i = 0; i < 4; i++){
        matrices[i] = readMatrix();
    }
    return matrices;
}

void* addMatrices0(void* arg){
    args0 *arguments = (args0*) arg;
    Matrix *matrix1 = arguments->matrix1;
    Matrix *matrix2 = arguments->matrix2;
    Matrix *result = arguments->result;
    int row = arguments->row;
    sem_t* sem = &arguments->sem[row];

    for (int i = 0; i < matrix1->cols; i++){
        result->data[row][i] = matrix1->data[row][i] + matrix2->data[row][i];
        hw2_write_output(0, row + 1, i + 1, result->data[row][i]);
    }
    sem_post(sem);
    pthread_exit(NULL);
}

void* addMatrices1(void* arg){
    args1 *arguments = (args1*) arg;
    Matrix *matrix1 = arguments->matrix1;
    Matrix *matrix2 = arguments->matrix2;
    Matrix *result = arguments->result;
    int col = arguments->col;
    sem_t* sem = &arguments->sem[col];

    for (int i = 0; i < matrix1->rows; i++){
        result->data[i][col] = matrix1->data[i][col] + matrix2->data[i][col];
        hw2_write_output(1, i + 1, col + 1, result->data[i][col]);
    }
    sem_post(sem);
    pthread_exit(NULL);
}
