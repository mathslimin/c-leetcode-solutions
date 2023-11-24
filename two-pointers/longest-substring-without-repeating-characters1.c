#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int index[256];
    int last_pos = -1;
    int i;
    int ret = 0;
    int len;

    memset(index, 0, sizeof(int) * 256);
    len = strlen(s);
    for (i = 0; i < len; ++i) {
        last_pos = index[s[i]] > last_pos ? index[s[i]] : last_pos;
        index[s[i]] = i + 1;
        ret = (i - last_pos + 1) > ret ? (i - last_pos + 1) : ret;
    }

    return ret;
}

int main() {
    char s[] = "abcabcbb";
    int len = lengthOfLongestSubstring(s);
    printf("%d", len); // 输出3
    return 0;
}