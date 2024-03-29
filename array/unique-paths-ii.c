#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int **dp;
    int i,j;
    int ret;

    dp = (int **)malloc(sizeof(int *) * obstacleGridRowSize);
    for(i = 0; i < obstacleGridRowSize; ++i){
        dp[i] = (int *)malloc(sizeof(int) * obstacleGridColSize);
        memset(dp[i],0,sizeof(int) * obstacleGridColSize);
    }

    for(i = 0; i < obstacleGridRowSize; ++i){
        if(obstacleGrid[i][0])
            break;
        dp[i][0] = 1;
    }

    for(j = 0; j < obstacleGridColSize; ++j){
        if(obstacleGrid[0][j])
            break;
        dp[0][j] = 1;
    }

    for(i = 1; i < obstacleGridRowSize; ++i)
        for(j = 1; j < obstacleGridColSize; ++j)
            if(obstacleGrid[i][j] == 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];

    ret = dp[obstacleGridRowSize-1][obstacleGridColSize-1];

    for(i = 0; i < obstacleGridRowSize; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}

int main()
{
    int obstacleGrid[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int obstacleGridSize = 3;
    int obstacleGridColSize[3] = {3, 3, 3};
    int* p[3];
    for (int i = 0; i < 3; i++) {
        p[i] = obstacleGrid[i];
    }
    int result = uniquePathsWithObstacles(p, obstacleGridSize, obstacleGridColSize);
    printf("%d", result);
    return 0;
}