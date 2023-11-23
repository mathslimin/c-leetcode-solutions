#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int size = matrixRowSize * matrixColSize;
    int i,count;
    int *ret;
    int left,right,up,down;

    ret = (int *)malloc(sizeof(int) * size);
    count = 0;

    left = 0;
    up = 0;
    right = matrixColSize - 1;
    down = matrixRowSize - 1;

    while(left <= right && up <= down){
        for(i = left; i <= right; ++i)
            ret[count++] = matrix[up][i];
        if(count == size)
            break;
        for(i = up + 1; i <= down; ++i)
            ret[count++] = matrix[i][right];
        if(count == size)
            break;
        for(i = right - 1; i >= left; --i)
            ret[count++] = matrix[down][i];
        if(count == size)
            break;
        for(i = down - 1; i > up; --i)
            ret[count++] = matrix[i][left];
        if(count == size)
            break;
        left++;
        up++;
        right--;
        down--;
    }

    return ret;
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
