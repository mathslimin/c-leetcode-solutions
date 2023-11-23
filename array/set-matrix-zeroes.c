#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int *row;
    int *col;
    int i,j;

    row = (int *)malloc(sizeof(int) * matrixRowSize);
    col = (int *)malloc(sizeof(int) * matrixColSize);
    memset(row, 0, sizeof(int) * matrixRowSize);
    memset(col, 0, sizeof(int) * matrixColSize);

    for(i = 0; i < matrixRowSize; ++i){
        for(j = 0; j < matrixColSize; ++j){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(i = 0; i < matrixRowSize; ++i){
        for(j = 0; j < matrixColSize; ++j){
            if(row[i] || col[j])
                matrix[i][j] = 0;
        }
    }

    free(row);
    free(col);
}

int main() {
    int matrixSize = 3;
    int matrixColSize[3] = {4, 4, 4};
    int matrix[3][4] = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 1, 1}};
    int *nums[3] = {matrix[0], matrix[1], matrix[2]};

    setZeroes(nums, matrixSize, matrixColSize);

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
