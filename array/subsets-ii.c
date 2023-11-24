#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
// 90. 子集 II
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    // 计算子集个数
    int subsetCount = 1 << numsSize;
    // 分配内存
    int **result = (int **)malloc(subsetCount * sizeof(int *));
    *returnColumnSizes = (int *)malloc(subsetCount * sizeof(int));
    // 对数组进行排序
    qsort(nums, numsSize, sizeof(int), cmp);
    // 遍历所有子集
    for (int i = 0; i < subsetCount; i++) {
        // 分配内存
        result[i] = (int *)malloc(numsSize * sizeof(int));
        (*returnColumnSizes)[i] = 0;
        // 遍历每一位
        for (int j = 0; j < numsSize; j++) {
            // 判断该位是否为1
            if (i & (1 << j)) {
                // 如果是1，则将该数加入子集中
                result[i][(*returnColumnSizes)[i]++] = nums[j];
            }
        }
    }
    // 去重
    int **temp = (int **)malloc(subsetCount * sizeof(int *));
    int tempCount = 0;
    for (int i = 0; i < subsetCount; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < tempCount; j++) {
            if ((*returnColumnSizes)[i] == (*returnColumnSizes)[j]) {
                int k = 0;
                for (; k < (*returnColumnSizes)[i]; k++) {
                    if (result[i][k] != temp[j][k]) {
                        break;
                    }
                }
                if (k == (*returnColumnSizes)[i]) {
                    isDuplicate = 1;
                    break;
                }
            }
        }
        if (!isDuplicate) {
            temp[tempCount] = result[i];
            tempCount++;
        }
    }
    // 释放内存
    for (int i = 0; i < subsetCount; i++) {
        if (result[i] != temp[i]) {
            free(result[i]);
        }
    }
    free(result);
    // 返回结果
    *returnSize = tempCount;
    return temp;
}

int main() {
    int nums[] = {1, 2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *returnColumnSizes;
    int **result = subsetsWithDup(nums, numsSize, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j != returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]");
    }
    return 0;
}