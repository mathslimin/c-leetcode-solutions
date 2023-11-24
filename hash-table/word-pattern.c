#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool wordPattern(char* pattern, char* str) {
    char *words[1000]; // 存放单词的数组
    int n = 0; // 单词个数
    // 将字符串按照空格分隔成单词，存放在数组 words 中
    char *p = strtok(str, " ");
    while (p != NULL) {
        words[n++] = p;
        p = strtok(NULL, " ");
    }
    // 如果 pattern 和 words 的长度不同，说明不匹配，返回 false
    if (strlen(pattern) != n) {
        return false;
    }
    // 使用两个哈希表分别记录 pattern 中每个字符和单词 words 中每个单词的对应关系
    char map1[26] = {0}; // 字符到单词的映射
    char *map2[1000] = {NULL}; // 单词到字符的映射
    // 遍历 pattern 和 words，对于每个字符和单词，分别在哈希表中查找对应关系
    for (int i = 0; i < n; i++) {
        char c = pattern[i];
        char *word = words[i];
        // 如果当前字符或单词不在哈希表中，将其加入哈希表
        if (map1[c - 'a'] == 0 && map2[i] == NULL) {
            map1[c - 'a'] = word[0];
            map2[i] = &c;
        }
        // 如果当前字符或单词在哈希表中，但对应的值不同，说明不匹配，返回 false
        else if (map1[c - 'a'] != word[0] || *map2[i] != c) {
            return false;
        }
    }
    // 如果遍历结束，说明匹配成功，返回 true
    return true;
}

int main() {
    char pattern[] = "abba";
    char str[] = "dog cat cat dog";
    bool result = wordPattern(pattern, str);
    printf("%d", result);
    return 0;
}
