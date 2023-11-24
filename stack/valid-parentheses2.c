#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**

题目描述

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。

示例1：

输入：s = "()"
输出：true

*/
bool isValid(char* s) {
    int len = strlen(s);
    if (len % 2 == 1) return false;  // 如果字符串长度为奇数，直接返回false
    char stack[len + 1];  // 初始化栈
    int top = 0;  // 栈顶指针
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[top++] = s[i];  // 左括号入栈
        } else {
            if (top == 0) return false;  // 栈为空，返回false
            char c = stack[--top];  // 右括号出栈
            if ((s[i] == ')' && c != '(') || (s[i] == ']' && c != '[') || (s[i] == '}' && c != '{')) {
                return false;  // 不匹配，返回false
            }
        }
    }
    return top == 0;  // 栈为空，返回true，否则返回false
}

int main()
{
    char s[] = "[]";
    printf("%d\n", isValid(s));
    return 0;
}