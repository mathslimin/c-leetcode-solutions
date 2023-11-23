#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int calculateMinimumHP(int** dungeon, int row, int col) {
    int **dp;
    int i,j;
    int ret;

    dp = (int **)malloc(sizeof(int *) * row);
    for(i = 0; i < row; ++i)
        dp[i] = (int *)malloc(sizeof(int *) * col);

    dp[row-1][col-1] = dungeon[row-1][col-1] < 0 ? -dungeon[row-1][col-1] : 0;

    for(i = row - 2; i >= 0; --i)
        dp[i][col-1] = max(dp[i+1][col-1] - dungeon[i][col-1], 0);

    for(j = col - 2; j >= 0; --j)
        dp[row-1][j] = max(dp[row-1][j+1] - dungeon[row-1][j], 0);

    for(i = row - 2; i >= 0; --i)
        for(j = col - 2; j >= 0; --j)
            dp[i][j] = max(min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j], 0);

    ret = dp[0][0] + 1;

    for(i = 0; i < row; ++i)
        free(dp[i]);
    free(dp);

    return ret;
}

int main() {
    int dungeon[3][3] = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    int* pdungeon[3] = {dungeon[0], dungeon[1], dungeon[2]};
    int dungeonSize = 3, dungeonColSize = 3;
    int result = calculateMinimumHP(pdungeon, dungeonSize, &dungeonColSize);
    printf("%d\n", result);
    return 0;
}
