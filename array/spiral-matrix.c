#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize == 0 || *matrixColSize == 0){
        *returnSize = 0;
        return NULL;
    }
    int left = 0, right = *matrixColSize - 1, top = 0, bottom = matrixSize - 1;
    int* res = (int*)malloc(sizeof(int) * matrixSize * (*matrixColSize));
    *returnSize = 0;
    while(left <= right && top <= bottom){
        for(int i = left; i <= right; i++){
            res[(*returnSize)++] = matrix[top][i];
        }
        for(int i = top + 1; i <= bottom; i++){
            res[(*returnSize)++] = matrix[i][right];
        }
        if(left < right && top < bottom){
            for(int i = right - 1; i >= left; i--){
                res[(*returnSize)++] = matrix[bottom][i];
            }
            for(int i = bottom - 1; i > top; i--){
                res[(*returnSize)++] = matrix[i][left];
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return res;
}

int main(){
    int matrixSize = 3;
    int matrixColSize[] = {3, 4, 5};
    int** matrix = (int**)malloc(sizeof(int*) * matrixSize);
    for(int i = 0; i < matrixSize; i++){
        matrix[i] = (int*)malloc(sizeof(int) * matrixColSize[i]);
        for(int j = 0; j < matrixColSize[i]; j++){
            matrix[i][j] = i * matrixColSize[i] + j + 1;
        }
    }
    int returnSize;
    int* res = spiralOrder(matrix, matrixSize, matrixColSize, &returnSize);
    printf("[");
    for(int i = 0; i < returnSize; i++){
        printf("%d", res[i]);
        if(i != returnSize - 1){
            printf(", ");
        }
    }
    printf("]");
    for(int i = 0; i < matrixSize; i++){
        free(matrix[i]);
    }
    free(matrix);
    free(res);
    return 0;
}