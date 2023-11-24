#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int** result = (int**)malloc(sizeof(int*) * 1000); // 最多有 1000 层
    *columnSizes = (int*)malloc(sizeof(int) * 1000);
    int level = 0;
    int front = 0, rear = 0;
    struct TreeNode* queue[10000];
    queue[rear++] = root;
    while (front < rear) {
        int size = rear - front;
        (*columnSizes)[level] = size;
        result[level] = (int*)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            result[level][i] = node->val;
            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }
        level++;
    }
    *returnSize = level;
    return result;
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 3;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 9;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 20;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->val = 15;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->val = 7;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    int* columnSizes;
    int returnSize;
    int** result = levelOrder(root, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/**
这个测试代码会输出以下结果：

```
3
9 20
15 7
```
*/