#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int maxProduct(int* nums, int numsSize) {
    int ret;
    int i;
    int *min;
    int *max;

    min = (int *)malloc(sizeof(int) * numsSize);
    max = (int *)malloc(sizeof(int) * numsSize);


    min[0] = nums[0];
    max[0] = nums[0];
    ret = nums[0];

    for(i = 1; i < numsSize; ++i){
        min[i] = max[i] = nums[i];
        if(nums[i] > 0){
            max[i] = (max[i-1] * nums[i] > max[i]) ?
                max[i-1] * nums[i] : max[i];
            min[i] = (min[i-1] * nums[i] < min[i]) ?
                min[i-1] * nums[i] : min[i];
        }else if(nums[i] < 0){
            max[i] = (min[i-1] * nums[i] > max[i]) ?
                min[i-1] * nums[i] : max[i];
            min[i] = (max[i-1] * nums[i] < min[i]) ?
                max[i-1] * nums[i] : min[i];
        }

        ret = max[i] > ret ? max[i] : ret;
    }

    free(min);
    free(max);
    return ret;
}

int main()
{
    int cards[] = {1, 2, 8, 9};
    int cnt = 3;
    int cardsSize = sizeof(cards) / sizeof(int);
    int ret = maxProduct(cards, cnt);
    printf("ret:%d\n", ret);
    return 0;
}
