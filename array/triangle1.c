#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int minimumTotal(int **triangle, int numRows) {
    int *dp;
    int tmp,prev;
    int i,j,ret;

    dp = (int *)malloc(sizeof(int) * numRows);
    dp[0] = triangle[0][0];
    for(i = 1; i < numRows; ++i){
        prev = dp[0];
        dp[0] += triangle[i][0];
        for(j = 1; j < i; ++j){
            tmp = dp[j];
            dp[j] = prev < tmp ? prev : tmp;
            dp[j] += triangle[i][j];
            prev = tmp;
        }
        dp[i] = triangle[i][i] + prev;
    }

    ret = dp[0];
    for(i = 1; i < numRows; ++i)
        ret = dp[i] < ret ? dp[i] : ret;

    return ret;
}

int main(){
    int triangleSize = 4;
    int triangleColSize[4] = {1,2,3,4};
    int** triangle = (int**)malloc(triangleSize*sizeof(int*));
    for(int i=0;i<triangleSize;i++){
        triangle[i] = (int*)malloc(triangleColSize[i]*sizeof(int));
    }
    triangle[0][0] = 2;
    triangle[1][0] = 3;
    triangle[1][1] = 4;
    triangle[2][0] = 6;
    triangle[2][1] = 5;
    triangle[2][2] = 7;
    triangle[3][0] = 4;
    triangle[3][1] = 1;
    triangle[3][2] = 8;
    triangle[3][3] = 3;
    int res = minimumTotal(triangle, triangleSize);
    printf("%d", res);
    return 0;
}