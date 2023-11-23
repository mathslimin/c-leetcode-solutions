#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int largestRectangleArea(int* height, int heightSize) {
    int *stack;
    int top = -1;
    int max = 0;
    int i,curh;

    stack = (int *)malloc(sizeof(int) * heightSize);

    for(i = 0; i <= heightSize; ++i){
        curh = (i == heightSize) ? -1 : height[i];

        while(top != -1 && curh <= height[stack[top]]){
            int h = height[stack[top--]];
            int w = (top == -1) ? i : i - stack[top] - 1;

            if(h * w > max)
                max = h * w;
        }
        stack[++top] = i;
    }

    free(stack);
    return max;
}

int main() {
    int height[] = {2,1,5,6,2,3};
    int heightSize = 6;
    int maxArea = largestRectangleArea(height, heightSize);
    printf("largest rectangle area is %d", maxArea);
    return 0;
}
