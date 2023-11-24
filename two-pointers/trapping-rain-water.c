#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//双指针解法
int trap(int* height, int heightSize) {
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