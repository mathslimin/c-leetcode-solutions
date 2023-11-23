#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int** generate(int numRows, int** columnSizes, int* returnSize) {
    int **ret;
    int i,j;
    int *col;

    col = (int *)malloc(sizeof(int) * numRows);
    ret = (int **)malloc(sizeof(int *) * numRows);
    for(i = 0; i < numRows; ++i){
        col[i] = i + 1;
        ret[i] = (int *)malloc(sizeof(int) * col[i]);

        ret[i][0] = 1;
        for(j = 1; j < col[i] - 1; ++j)
            ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        ret[i][col[i]-1] = 1;
    }

    *returnSize = numRows;
    *columnSizes = col;
    return ret;
}

int main(){
    int numRows = 5;
    int returnSize;
    int* returnColumnSizes;
    int** result = generate(numRows, &returnSize, &returnColumnSizes);

    for(int i = 0; i < returnSize; i++){
        for(int j = 0; j < returnColumnSizes[i]; j++){
            printf("%d ", result[i][j]);
        }
        printf(" ");
    }

    return 0;
}
