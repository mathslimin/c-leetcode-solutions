#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int top;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->top = -1;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->data[++obj->top] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    return obj->data[obj->top--];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->data[obj->top];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->top == -1;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

int main() {
    MyStack* stack = myStackCreate();
    myStackPush(stack, 1);
    myStackPush(stack, 2);
    printf("%d\n", myStackTop(stack));
    printf("%d\n", myStackPop(stack));
    printf("%d\n", myStackEmpty(stack));
    myStackFree(stack);
    return 0;
}