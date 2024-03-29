#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int *get_3sum(int a, int b, int c)
{
    int *ret = (int *)malloc(sizeof(int) * 3);
    ret[0] = a;
    ret[1] = b;
    ret[2] = c;
    return ret;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int i,start,end,sum;
    int size = 0;
    int count = 500;
    int **arr;

    qsort(nums,numsSize,sizeof(int),cmp);
    arr = (int **)malloc(sizeof(int *) * count);
    for(i = 0; i < numsSize - 2; ++i){
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        start = i + 1;
        end = numsSize - 1;
        while(start < end){
            sum = nums[i] + nums[start] + nums[end];

            if(start > i + 1 && nums[start-1] == nums[start]){
                ++start;

                continue;
            }

            if(sum == 0){
                arr[size++] = get_3sum(nums[i],nums[start],nums[end]);
                if(size == count){
                    count <<= 1;
                    arr = realloc(arr,sizeof(int *) * count);
                }
            }

            if(sum > 0)
                --end;
            else
                ++start;
        }
    }

    *returnSize = size;
    return arr;
}

int main()
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = 6;
    int returnSize;
    int** result;
    int* returnColSize = NULL;
    result = threeSum(nums, numsSize, &returnSize, &returnColSize);
    printf("returnSize:%d \n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
