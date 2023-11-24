#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int lengthOfLongestSubstring(char* s) {
    int index[256] = {0};
    int last_index = -1;
    int len = strlen(s);
    int ret = 0;

    for(int i = 0; i < len; ++i){
        last_index = index[s[i]] > last_index ? index[s[i]] : last_index;
        index[s[i]] = i + 1;
        ret = (i - last_index + 1) > ret ? (i - last_index + 1) : ret;
    }

    return ret;
}

int main() {
    char s[] = "abcabcbb";
    int len = lengthOfLongestSubstring(s);
    printf("%d", len); // 输出3
    return 0;
}