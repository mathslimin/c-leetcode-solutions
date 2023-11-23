#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
// 90. 子集 II

int **ret;
int *col;
int size;
int alloc_size;
int idx;

void helper(int *arr, int len, int *nums, int pos)
{
    int i;

    ret[idx] = (int *)malloc(sizeof(int) * len);
    for(i = 0; i < len; ++i){
        ret[idx][i] = arr[i];
    }
    col[idx] = len;
    idx++;

    for(i = pos; i < size; ++i){
        if(i > pos && nums[i-1] == nums[i])
            continue;
        arr[len] = nums[i];
        helper(arr,len+1,nums,i+1);
    }
}

int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int *arr;
    size = numsSize;
    alloc_size = 1 << numsSize;
    idx = 0;

    ret = (int **)malloc(sizeof(int *) * alloc_size);
    col = (int *)malloc(sizeof(int) * alloc_size);
    arr = (int *)malloc(sizeof(int) * numsSize);

    qsort(nums,numsSize,sizeof(int), cmp);

    helper(arr,0,nums,0);

    free(arr);
    *columnSizes = col;
    *returnSize = idx;
    return ret;
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
