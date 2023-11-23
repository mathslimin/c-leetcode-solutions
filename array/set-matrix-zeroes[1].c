#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int row0 = 0;
    int col0 = 0;
    int i,j;

    for(i = 0; i < matrixRowSize; ++i){
        if(matrix[i][0] == 0){
            col0 = 1;
            break;
        }
    }

    for(j = 0; j < matrixColSize; ++j){
        if(matrix[0][j] == 0){
            row0 = 1;
            break;
        }
    }

    for(i = 1; i < matrixRowSize; ++i){
        for(j = 1; j < matrixColSize; ++j){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for(i = 1; i < matrixRowSize; ++i){
        for(j = 1; j < matrixColSize; ++j){
            if(matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }

    if(row0){
        for(j = 0; j < matrixColSize; ++j)
            matrix[0][j] = 0;
    }

    if(col0){
        for(i = 0; i < matrixRowSize; ++i){
            matrix[i][0] = 0;
        }
    }
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
