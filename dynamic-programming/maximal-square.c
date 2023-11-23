#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define max_2(x, y) ((x) > (y)) ? (x) : (y)
#define min_2(x, y) ((x) < (y)) ? (x) : (y)

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int **dp;
    int i,j,max_square,min_value;

    dp = (int **)malloc(sizeof(int *) * (matrixRowSize + 1));
    for(i = 0; i <= matrixRowSize; ++i){
        dp[i] = (int *)malloc(sizeof(int) * (matrixColSize + 1));
        memset(dp[i], 0, sizeof(int) * (matrixColSize + 1));
    }

    for(i = 1; i <= matrixRowSize; ++i)
        for(j = 1; j <= matrixColSize; ++j){
            if(matrix[i-1][j-1] == '0')
                continue;

            min_value = min_2(dp[i-1][j], dp[i-1][j-1]);
            min_value = min_2(dp[i][j-1], min_value);
            dp[i][j] = min_value + 1;
        }

    max_square = 0;
    for(i = 1; i <= matrixRowSize; ++i)
        for(j = 1; j <= matrixColSize; ++j)
            max_square = max_2(max_square,dp[i][j] * dp[i][j]);

    for(i = 0; i <= matrixRowSize; ++i)
        free(dp[i]);
    free(dp);

    return max_square;
}

int main() {
    char* matrix[5] = {"10100", "10111", "11111", "10010", "11000"};
    int matrixRowSize = 5;
    int matrixColSize = 5;
    int maxArea = maximalSquare(matrix, matrixRowSize, matrixColSize);
    printf("Maximal Square Area: %d", maxArea);
    return 0;
}