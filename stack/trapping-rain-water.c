#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trap(int* height, int heightSize)
{
    int max_height = 0;
    int max_index = 0;
    int i;
    int ret = 0;

    for (i = 0; i < heightSize; ++i) {
        if (height[i] > max_height) {
            max_height = height[i];
            max_index = i;
        }
    }

    max_height = 0;
    for (i = 0; i < max_index; ++i) {
        if (max_height > height[i])
            ret += (max_height - height[i]);
        else
            max_height = height[i];
    }

    max_height = 0;
    for (i = heightSize - 1; i > max_index; --i) {
        if (max_height > height[i])
            ret += (max_height - height[i]);
        else
            max_height = height[i];
    }

    return ret;
}

//双指针解法
int trapTwoPointer(int* height, int heightSize) {
    if (heightSize <= 2) return 0;
    int left = 0, right = heightSize - 1;
    int left_max = height[left], right_max = height[right];
    int water = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            left_max = height[left] > left_max ? height[left] : left_max;
            water += left_max - height[left];
            left++;
        } else {
            right_max = height[right] > right_max ? height[right] : right_max;
            water += right_max - height[right];
            right--;
        }
    }
    return water;
}

int main() {
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int heightSize = sizeof(height) / sizeof(height[0]);
    int water = trap(height, heightSize);
    printf("The trapped water is %d", water);
    return 0;
}