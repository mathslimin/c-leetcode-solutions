#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int maxArea(int* height, int heightSize) {
    int ret = 0;
    int start,end;
    int mul;

    start = 0;
    end = heightSize-1;
    while(start < end){
        if(height[start] < height[end]){
            mul = height[start] * (end - start);
            ++start;
        }else{
            mul = height[end] * (end - start);
            --end;
        }

        ret = mul > ret ? mul : ret;
    }

    return ret;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);
    int result = maxArea(height, heightSize);
    printf("The maximum area is: %d", result);
    return 0;
}
