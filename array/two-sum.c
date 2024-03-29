#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct node{
    int val;
    int index;
};

int search(struct node *arr, int numsSize, int target)
{
    int start,end,mid;
    start = 0;
    end = numsSize - 1;
    while(start <= end){
        mid = (start + end) / 2;
        if(arr[mid].val == target)
            return arr[mid].index;
        else if(arr[mid].val > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int cmp(const void *a, const void *b)
{
    return ((struct node *)a)->val - ((struct node *)b)->val;
}

int* twoSum(int* nums, int numsSize, int target) {
    int *ret;
    struct node *arr;
    int i,index;
    ret = (int *)malloc(sizeof(int) * 2);
    arr = (struct node *)malloc(sizeof(struct node) * numsSize);
    for(i = 0; i < numsSize; ++i){
        arr[i].val = nums[i];
        arr[i].index = i + 1;
    }

    qsort(arr,numsSize,sizeof(struct node),cmp);

    for(i = 0; i < numsSize; ++i)
    {
        index = search(arr,numsSize,target - nums[i]);
        if(index != -1 && index != i+1){
            ret[0] = i+1 < index ? i + 1 : index;
            ret[1] = i+1 > index ? i + 1 : index;
        }
    }

    free(arr);
    return ret;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize;
    int* result = twoSum(nums, numsSize, target);
    printf("[%d, %d]", result[0], result[1]);
    free(result);
    return 0;
}