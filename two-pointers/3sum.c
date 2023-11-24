#include <stdio.h>
#include <stdlib.h>

/**
由于题目中要求返回一个二维数组，因此需要先定义一个二维数组指针来存储结果。同时，题目中要求返回的三元组必须满足三个数的和为0，因此可以采用双指针的方法来解决。
*/
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    // 先将数组升序排序
    qsort(nums, numsSize, sizeof(int), cmp);

    // 定义一个二维数组指针，用来存储结果
    int **result = (int **)malloc(sizeof(int *) * numsSize * numsSize);
    int count = 0;  // 记录符合条件的三元组个数

    // 双指针法
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // 跳过重复元素
        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result[count] = (int *)malloc(sizeof(int) * 3);
                result[count][0] = nums[i];
                result[count][1] = nums[left];
                result[count][2] = nums[right];
                count++;
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) left++;  // 跳过重复元素
                while (left < right && nums[right] == nums[right + 1]) right--;  // 跳过重复元素
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    *returnSize = count;
    return result;
}


int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize;
    int **result = threeSum(nums, numsSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]", result[i][0], result[i][1], result[i][2]);
    }
    return 0;
}