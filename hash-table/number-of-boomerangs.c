#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int numberOfBoomerangs(int** points, int pointsRowSize, int pointsColSize) {
    int res = 0;
    for (int i = 0; i < pointsRowSize; i++) {
        // 用哈希表存储距离相等的点的数量
        int hash[10001] = {0};
        for (int j = 0; j < pointsRowSize; j++) {
            if (j != i) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int dis = dx * dx + dy * dy;
                hash[dis]++;
            }
        }
        for (int k = 0; k < 10001; k++) {
            if (hash[k] > 1) {
                res += hash[k] * (hash[k] - 1);
            }
        }
    }
    return res;
}


int main() {
    int nums[3][2] = {{0, 0}, {1, 0}, {2, 0}};
    int *points[3] ={nums[0], nums[1], nums[2]};
    int res = numberOfBoomerangs(points, 3, 2);
    printf("%d", res); // 输出2
    return 0;
}