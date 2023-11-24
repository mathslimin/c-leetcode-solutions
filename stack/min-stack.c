#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//155. 最小栈
#define MAX_SIZE 10000

typedef struct {
    int* data; // 数据栈
    int* min; // 最小值栈
    int top; // 栈顶指针
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack)); // 分配空间
    obj->data = (int*)malloc(sizeof(int) * MAX_SIZE); // 分配数据栈空间
    obj->min = (int*)malloc(sizeof(int) * MAX_SIZE); // 分配最小值栈空间
    obj->top = -1; // 初始化栈顶指针
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++; // 栈顶指针加1
    obj->data[obj->top] = val; // 将数据入栈
    if (obj->top == 0 || val <= obj->min[obj->top - 1]) { // 如果最小值栈为空或者当前值小于等于最小值栈的栈顶元素
        obj->min[obj->top] = val; // 将当前值入栈
    } else { // 否则将最小值栈的栈顶元素再次入栈
        obj->min[obj->top] = obj->min[obj->top - 1];
    }
}

void minStackPop(MinStack* obj) {
    obj->top--; // 栈顶指针减1
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top]; // 返回数据栈的栈顶元素
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->top]; // 返回最小值栈的栈顶元素
}

void minStackFree(MinStack* obj) {
    free(obj->data); // 释放数据栈空间
    free(obj->min); // 释放最小值栈空间
    free(obj); // 释放栈空间
}

int main() {
    MinStack* obj = minStackCreate(); // 初始化栈

    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);
    printf("%d", minStackGetMin(obj)); // 返回 -3
    minStackPop(obj);
    printf("%d", minStackTop(obj)); // 返回 0
    printf("%d", minStackGetMin(obj)); // 返回 -2

    minStackFree(obj); // 释放栈空间

    return 0;
}