#include <stdio.h>
#include <stdlib.h>

/**
由于题目中要求返回一个二维数组，因此我们需要使用动态内存分配来创建二维数组。具体实现如下：
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, k, l, sum, count = 0;
    int** res = (int**)malloc(sizeof(int*) * numsSize * numsSize); // 动态分配二维数组空间

    for (i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // 避免重复解

        for (j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // 避免重复解

            k = j + 1;
            l = numsSize - 1;

            while (k < l) {
                sum = nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target) {
                    res[count] = (int*)malloc(sizeof(int) * 4); // 动态分配一维数组空间
                    res[count][0] = nums[i];
                    res[count][1] = nums[j];
                    res[count][2] = nums[k];
                    res[count][3] = nums[l];
                    count++;
                    while (k < l && nums[k] == nums[k + 1]) k++; // 避免重复解
                    while (k < l && nums[l] == nums[l - 1]) l--; // 避免重复解
                    k++;
                    l--;
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }

    *returnSize = count;
    return res;
}

int main() {
    int nums[] = {1, 0, -1, 0, -2, 2};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 0;
    int returnSize;
    int i, j;

    int** res = fourSum(nums, numsSize, target, &returnSize);

    for (i = 0; i < returnSize; i++) {
        printf("[");
        for (j = 0; j < 4; j++) {
            printf("%d", res[i][j]);
            if (j < 3) printf(", ");
        }
        printf("]");
    }

    return 0;
}