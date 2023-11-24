#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize)
{
    int start, end;
    int ret = 0;
    int mul;

    start = 0;
    end = heightSize - 1;
    while (start < end) {
        mul = min(height[start], height[end]) * (end - start);
        if (mul > ret)
            ret = mul;
        if (height[start] > height[end])
            --end;
        else
            ++start;
    }

    return ret;
}


int main() {
    int height[] = {1,8,6,2,5,4,8,3,7};
    int heightSize = sizeof(height) / sizeof(int);
    int max = maxArea(height, heightSize);
    printf("The maximum area is %d", max);
    return 0;
}