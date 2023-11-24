#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */


int* arr;
int arr_size;
int idx;

void dfs(struct TreeNode* root, int depth)
{
    if (!root)
        return;

    if (depth >= idx)
        idx = depth;
    if (depth >= arr_size) {
        arr_size <<= 1;
        arr = realloc(arr, sizeof(int) * arr_size);
    }
    arr[depth] = root->val;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}

int* rightSideView(struct TreeNode* root, int* returnSize)
{
    arr_size = 32;
    idx = -1;
    arr = malloc(sizeof(int) * arr_size);
    dfs(root, 0);

    *returnSize = idx + 1;

    return arr;
}

int main() {
    // 构造二叉树
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 5;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->right->left = NULL;
    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->val = 4;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    // 调用函数
    int returnSize = 0;
    int* res = rightSideView(root, &returnSize);
    // 输出结果
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}