#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**
 */
void dfs(struct TreeNode* root, int level, int** res, int* colSizes) {
    if (root == NULL) {
        return;
    }
    if (level % 2 == 0) {
        res[level][colSizes[level]++] = root->val;
    } else {
        res[level][--colSizes[level]] = root->val;
    }
    dfs(root->left, level + 1, res, colSizes);
    dfs(root->right, level + 1, res, colSizes);
}

int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int depth = 0;
    int* colSizes = (int*)malloc(sizeof(int) * 1000);
    int** res = (int**)malloc(sizeof(int*) * 1000);
    for (int i = 0; i < 1000; i++) {
        colSizes[i] = 0;
        res[i] = (int*)malloc(sizeof(int) * 1000);
    }
    dfs(root, 0, res, colSizes);
    for (int i = 0; i < 1000; i++) {
        if (colSizes[i] > 0) {
            depth++;
        }
    }
    *columnSizes = colSizes;
    *returnSize = depth;
    return res;
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

    int* colSizes;
    int returnSize;
    int** res = zigzagLevelOrder(root, &colSizes, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}