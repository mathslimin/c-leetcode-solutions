#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */

int count = 32;
void post_order(struct TreeNode* root, int** arr, int* idx)
{
    if (root == NULL)
        return;
    post_order(root->left, arr, idx);
    post_order(root->right, arr, idx);
    if (*idx == count) {
        count <<= 1;
        *arr = realloc(*arr, sizeof(int) * count);
    }
    (*arr)[(*idx)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* arr;
    int idx = 0;
    arr = malloc(sizeof(int) * count);
    post_order(root, &arr, &idx);

    *returnSize = idx;
    return arr;
}

int main() {
    // 构造一棵二叉树
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 2;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->val = 3;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = NULL;

    // 测试postorderTraversal函数
    int size;
    int* result = postorderTraversal(root, &size);
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}