#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
示例 1：
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。
*/
#define max(a,b) ((a)>(b)?(a):(b))

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL || *matrixColSize == 0) {
        return 0;
    }
    int m = matrixSize, n = *matrixColSize;
    int* heights = (int*)malloc(n * sizeof(int));
    int maxArea = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        int* stack = (int*)malloc((n + 1) * sizeof(int));
        int top = -1;
        stack[++top] = -1;
        for (int j = 0; j < n; j++) {
            while (top > 0 && heights[j] < heights[stack[top]]) {
                int height = heights[stack[top--]];
                int width = j - stack[top] - 1;
                maxArea = max(maxArea, height * width);
            }
            stack[++top] = j;
        }
        free(stack);
    }
    free(heights);
    return maxArea;
}

int main() {
    char* matrix[4] = {"10100", "10111", "11111", "10010"};
    int matrixSize = 4;
    int matrixColSize[4] = {5, 5, 5, 5};
    int maxArea = maximalRectangle(matrix, matrixSize, matrixColSize);
    printf("%d", maxArea);
    return 0;
}