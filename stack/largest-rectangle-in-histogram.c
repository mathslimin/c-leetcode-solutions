#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
给定n个非负整数表示柱状图中每个柱子的高度，每个柱子的宽度为1。找到柱状图中最大的矩形面积。

示例：

输入：heights = [2,1,5,6,2,3]
输出：10

输入：heights = [2,4]
输出：4

*/

int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc(sizeof(int) * (heightsSize + 1));  // 定义栈
    int top = -1;  // 栈顶指针初始化为-1
    int maxArea = 0;  // 最大面积初始化为0
    int i = 0;
    while (i <= heightsSize) {
        int h = (i == heightsSize ? 0 : heights[i]);  // 如果i已经到了heightsSize，说明所有柱子都已经处理完了，此时h为0，否则h为当前柱子的高度
        if (top == -1 || h >= heights[stack[top]]) {  // 如果栈为空或者当前柱子的高度大于等于栈顶柱子的高度，就把当前柱子的下标压入栈中
            stack[++top] = i++;
        } else {  // 如果当前柱子的高度小于栈顶柱子的高度，就弹出栈顶柱子，计算以该柱子为高的矩形面积
            int height = heights[stack[top--]];  // 栈顶元素出栈，并记录其高度
            int width = (top == -1 ? i : i - stack[top] - 1);  // 如果栈为空，说明弹出的柱子是柱状图中最左侧的柱子，此时矩形的宽度为i；否则矩形的宽度为i减去栈顶元素的下标再减1
            int area = height * width;  // 计算矩形面积
            if (area > maxArea) {  // 更新最大面积
                maxArea = area;
            }
        }
    }
    free(stack);  // 释放栈空间
    return maxArea;
}

int main() {
    int heights[] = {2, 1, 5, 6, 2, 3};
    int heightsSize = sizeof(heights) / sizeof(int);
    int maxArea = largestRectangleArea(heights, heightsSize);
    printf("%d", maxArea);  // 输出最大面积
    return 0;
}