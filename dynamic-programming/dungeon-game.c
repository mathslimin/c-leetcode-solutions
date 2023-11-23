#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int calculateMinimumHP(int** dungeon, int dungeonRowSize, int dungeonColSize) {
    // 创建动态规划数组
    int dp[dungeonRowSize][dungeonColSize];
    // 初始化右下角格子的最小生命值
    dp[dungeonRowSize-1][dungeonColSize-1] = dungeon[dungeonRowSize-1][dungeonColSize-1] > 0 ? 1 : 1-dungeon[dungeonRowSize-1][dungeonColSize-1];
    // 初始化最后一列的最小生命值
    for (int i = dungeonRowSize-2; i >= 0; i--) {
        dp[i][dungeonColSize-1] = dp[i+1][dungeonColSize-1] - dungeon[i][dungeonColSize-1];
        dp[i][dungeonColSize-1] = dp[i][dungeonColSize-1] <= 0 ? 1 : dp[i][dungeonColSize-1];
    }
    // 初始化最后一行的最小生命值
    for (int j = dungeonColSize-2; j >= 0; j--) {
        dp[dungeonRowSize-1][j] = dp[dungeonRowSize-1][j+1] - dungeon[dungeonRowSize-1][j];
        dp[dungeonRowSize-1][j] = dp[dungeonRowSize-1][j] <= 0 ? 1 : dp[dungeonRowSize-1][j];
    }
    // 从右下角开始往左上角遍历
    for (int i = dungeonRowSize-2; i >= 0; i--) {
        for (int j = dungeonColSize-2; j >= 0; j--) {
            int right = dp[i][j+1] - dungeon[i][j];
            int down = dp[i+1][j] - dungeon[i][j];
            dp[i][j] = right < down ? right : down;
            dp[i][j] = dp[i][j] <= 0 ? 1 : dp[i][j];
        }
    }
    // 返回起点的最小生命值
    return dp[0][0];
}

int main() {
    int dungeon[3][3] = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    int *nums[3] = {dungeon[0], dungeon[1], dungeon[2]};
    int result = calculateMinimumHP(nums, 3, 3);
    printf("%d", result);
    return 0;
}