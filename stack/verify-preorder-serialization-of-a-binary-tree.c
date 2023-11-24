#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValidSerialization(char* preorder)
{
    int count = 0;
    char* next = preorder;
    char *left, *right;

    if (*next && *next != '#')
        count++;

    while (count-- > 0) {
        while (*next && *next != ',')
            next++;
        if (*next)
            next++;
        left = next;
        if (!*left)
            return false;

        while (*next && *next != ',')
            next++;
        if (*next)
            next++;
        right = next;
        if (!*right)
            return false;

        if (*left != '#')
            count++;
        if (*right != '#')
            count++;
    }
    while (*next && *next != ',')
        next++;
    if (*next)
        return false;

    return true;
}

int main() {
    char* preorder1 = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    char* preorder2 = "1,#";
    char* preorder3 = "9,#,#,1";
    printf("%d", isValidSerialization(preorder1));  // 输出 1
    printf("%d", isValidSerialization(preorder2));  // 输出 1
    printf("%d", isValidSerialization(preorder3));  // 输出 0
    return 0;
}