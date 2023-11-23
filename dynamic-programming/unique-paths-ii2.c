#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int *dp;
    int i,j,ret;

    dp = malloc(sizeof(int) * obstacleGridColSize);

    dp[0] = ((obstacleGrid[0][0] == 1) ? 0 : 1);
    for(j = 1;j < obstacleGridColSize; ++j){
        if(obstacleGrid[0][j] == 1)
            dp[j] = 0;
        else
            dp[j] = dp[j-1];
    }

    for(i = 1; i < obstacleGridRowSize; ++i){
        if(obstacleGrid[i][0] == 1)
            dp[0] = 0;
        for(j = 1; j < obstacleGridColSize; ++j){
            if(obstacleGrid[i][j] == 1)
                dp[j] = 0;
            else
                dp[j] = dp[j-1]+dp[j];
        }
    }

    ret = dp[obstacleGridColSize-1];
    free(dp);
    return ret;
}

int main() {
    int obstacleGrid[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int* ptr[3] = {obstacleGrid[0], obstacleGrid[1], obstacleGrid[2]};
    int result = uniquePathsWithObstacles(ptr, 3, 3);
    printf("The result is %d", result);
    return 0;
}