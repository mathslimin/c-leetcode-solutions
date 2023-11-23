//120. 三角形最小路径和

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int minimumTotal(int **triangle, int numRows) {
    int *dp;
    int *tmp;
    int i,j,ret;

    dp = (int *)malloc(sizeof(int) * numRows);
    tmp = (int *)malloc(sizeof(int) * numRows);
    dp[0] = triangle[0][0];
    for(i = 1; i < numRows; ++i){
        memcpy(tmp,dp,sizeof(int) * i);
        memcpy(dp,triangle[i],sizeof(int) * (i + 1));
        dp[0] += tmp[0];
        for(j = 1; j < i; ++j){
            dp[j] += tmp[j] < tmp[j-1] ? tmp[j] : tmp[j-1];
        }
        dp[i] += tmp[i-1];
    }

    ret = dp[0];
    for(i = 1; i < numRows; ++i)
        ret = dp[i] < ret ? dp[i] : ret;

    free(tmp);
    free(dp);
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
    int res = minimumTotal(triangle, triangleSize, triangleColSize);
    printf("%d", res);
    for(int i=0;i<triangleSize;i++){
        free(triangle[i]);
    }
    free(triangle);
    return 0;
}