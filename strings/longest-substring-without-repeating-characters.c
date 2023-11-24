#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int index[256];
    int last_index;
    int len, i, ret;

    memset(index, 0, sizeof(int) * 256);
    last_index = -1;
    len = strlen(s);

    ret = 0;
    for (i = 0; i < len; ++i) {
        last_index = index[s[i]] > last_index ? index[s[i]] : last_index;
        index[s[i]] = i + 1;
        ret = (i - last_index + 1 > ret) ? i - last_index + 1 : ret;
    }

    return ret;
}

int main() {
    char s[] = "abcabcbb";
    int ans = lengthOfLongestSubstring(s);
    printf("%d", ans); // output: 3
    return 0;
}