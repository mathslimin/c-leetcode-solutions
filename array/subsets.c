#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    // 计算子集个数
    int count = 1 << numsSize;
    // 分配二维数组空间
    int** res = (int**)malloc(sizeof(int*) * count);
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    // 遍历每个子集
    for (int i = 0; i < count; i++) {
        // 计算当前子集的元素个数
        int size = 0;
        for (int j = 0; j < numsSize; j++) {
            if (i & (1 << j)) {
                size++;
            }
        }
        // 分配当前子集空间
        res[i] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[i] = size;
        // 将当前子集的元素加入到数组中
        int index = 0;
        for (int j = 0; j < numsSize; j++) {
            if (i & (1 << j)) {
                res[i][index++] = nums[j];
            }
        }
    }
    // 设置返回值
    *returnSize = count;
    return res;
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int** res = subsets(nums, numsSize, &returnSize, &returnColumnSizes);
    // 打印结果
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", res[i][j]);
            if (j != returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]");
    }
    // 释放空间
    for (int i = 0; i < returnSize; i++) {
        free(res[i]);
    }
    free(res);
    free(returnColumnSizes);
    return 0;
}
