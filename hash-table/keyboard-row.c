#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char** findWords(char** words, int wordsSize, int* returnSize) {
    char **res;
    char *word;
    int count = 0;
    int i,j,len;
    char *line[3] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL",
            "zxcvbnmZXCVBNM"};
    int map[256] = {0};
    for(i = 0; i < 3; ++i){
        len = strlen(line[i]);
        for(j = 0; j < len; ++j)
            map[line[i][j]] = i;
    }
    res = malloc(sizeof(char *) * wordsSize);

    for(i = 0; i < wordsSize; ++i){
        word = words[i];
        len = strlen(word);
        int f = map[word[0]];
        for(j = 0; j < len; ++j)
            if(map[word[j]] != f)
                break;

        if(j == len)
            res[count++] = strdup(word);
    }

    *returnSize = count;
    return res;
}

int main() {
    char *words[] = {"Hello", "Alaska", "Dad", "Peace"};
    int returnSize;
    char **result = findWords(words, 4, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", result[i]);
    }
    return 0;
}