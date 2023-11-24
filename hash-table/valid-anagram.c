#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool isAnagram(char* s, char* t)
{
    int hash[26] = {0};
    int s_len = strlen(s);
    int t_len = strlen(t);
    int i;
    if (s_len != t_len)
        return false;

    for (i = 0; i < s_len; ++i) {
        hash[s[i] - 'a']++;
        hash[t[i] - 'a']--;
    }

    for (i = 0; i < 26; ++i)
        if (hash[i])
            return false;

    return true;
}

int main() {
    char s[] = "anagram";
    char t[] = "nagaram";
    if (isAnagram(s, t)) {
        printf("s and t are anagrams");
    } else {
        printf("s and t are not anagrams");
    }
    return 0;
}