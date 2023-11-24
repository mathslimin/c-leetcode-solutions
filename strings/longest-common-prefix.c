#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    int n = 0;
    int i, loop_flag;

    if (strsSize == 0)
        return "";
    loop_flag = 1;
    while (loop_flag) {
        char value = strs[0][n];
        for (i = 0; i < strsSize; ++i) {
            if (strs[i][n] == 0 || strs[i][n] != value) {
                loop_flag = 0;
                break;
            }
        }
        if (loop_flag)
            n++;
    }

    return strndup(strs[0], n);
}

int main()
{
    char* strs[20] = {"abcde", "abceawsdffd", "abcsdas", "abcefwfdf", "abcd", "abc"};

    char* s = longestCommonPrefix(strs, 6);
    printf("%s\n", s);

    s = longestCommonPrefix(NULL, 0);
    printf("%s\n", s);

    return 0;
}