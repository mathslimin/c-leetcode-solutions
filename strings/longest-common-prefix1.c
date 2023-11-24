#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    int i, j;
    int len;

    if (strsSize == 0)
        return "";

    len = strlen(strs[0]);
    for (i = 0; i < len; ++i) {
        for (j = 1; j < strsSize; ++j)
            if (strs[j][i] != strs[0][i])
                return strndup(strs[0], i);
    }

    return strndup(strs[0], i);
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