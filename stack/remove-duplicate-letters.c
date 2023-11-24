#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
1. 首先遍历字符串s，统计每个字符出现的次数。

2. 然后再次遍历字符串s，对于每个字符，将其出现次数减1。

3. 如果当前字符已经在栈中，则直接跳过。

4. 如果当前字符比栈顶字符小且栈顶字符在后面还会出现，则弹出栈顶字符，重复此过程直到栈顶字符比当前字符小或者不存在于后面的字符中。

5. 将当前字符压入栈中。

6. 最后将栈中的字符依次弹出并组成字符串即可。
*/
char* removeDuplicateLetters(char* s) {
    int len = strlen(s);
    int count[26] = {0}; // 统计每个字符出现的次数
    int visited[26] = {0}; // 标记每个字符是否在栈中
    char stack[len]; // 栈
    int top = -1; // 栈顶指针

    // 统计每个字符出现的次数
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    // 遍历字符串s
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']--; // 将当前字符出现次数减1

        // 如果当前字符已经在栈中，则直接跳过
        if (visited[s[i] - 'a']) {
            continue;
        }

        // 如果当前字符比栈顶字符小且栈顶字符在后面还会出现，则弹出栈顶字符
        while (top >= 0 && s[i] < stack[top] && count[stack[top] - 'a'] > 0) {
            visited[stack[top] - 'a'] = 0;
            top--;
        }

        // 将当前字符压入栈中
        stack[++top] = s[i];
        visited[s[i] - 'a'] = 1;
    }

    // 将栈中的字符依次弹出并组成字符串
    char* res = (char*)malloc(sizeof(char) * (top + 2));
    for (int i = 0; i <= top; i++) {
        res[i] = stack[i];
    }
    res[top + 1] = '\0';

    return res;
}

int main() {
    char s[] = "bcabc";
    char* res = removeDuplicateLetters(s);
    printf("%s", res); // 输出结果为abc
    free(res);

    return 0;
}