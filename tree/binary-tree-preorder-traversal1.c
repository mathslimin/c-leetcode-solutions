#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */

void recursive(struct TreeNode* root, int** array, int* idx, int* arr_size)
{
    if (!root)
        return;

    if (*idx >= *arr_size) {
        *arr_size <<= 1;
        *array = realloc(*array, sizeof(int) * (*arr_size));
    }

    int* arr = *array;
    arr[(*idx)++] = root->val;
    recursive(root->left, &arr, idx, arr_size);
    recursive(root->right, &arr, idx, arr_size);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* arr = NULL;
    int arr_size = 32;
    *returnSize = 0;

    arr = malloc(sizeof(int) * arr_size);
    recursive(root, &arr, returnSize, &arr_size);

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

    int size;
    int* result = preorderTraversal(root, &size);
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}