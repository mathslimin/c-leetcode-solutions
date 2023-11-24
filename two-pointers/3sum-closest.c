#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(const int*)a - *(const int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    int start, end;
    int sum;
    int i;
    int ret = nums[0] + nums[1] + nums[2];

    qsort(nums, numsSize, sizeof(int), cmp);
    for (i = 0; i < numsSize - 2; ++i) {
        start = i + 1;
        end = numsSize - 1;
        while (start < end) {
            sum = nums[i] + nums[start] + nums[end];
            if (abs(sum - target) < abs(ret - target))
                ret = sum;
            if (sum > target)
                --end;
            else
                ++start;
        }
    }

    return ret;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 1;
    int closest = threeSumClosest(nums, numsSize, target);
    printf("%d", closest);
    return 0;
}