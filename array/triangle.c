//120. 三角形最小路径和

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    //初始化dp数组
    int* dp = (int*)malloc(triangleSize*sizeof(int));
    for(int i=0;i<triangleSize;i++){
        dp[i] = triangle[triangleSize-1][i];
    }
    //从倒数第二层开始递推
    for(int i=triangleSize-2;i>=0;i--){
        for(int j=0;j<triangleColSize[i];j++){
            dp[j] = triangle[i][j] + (dp[j]<dp[j+1]?dp[j]:dp[j+1]);
        }
    }
    int res = dp[0];
    free(dp);
    return res;
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