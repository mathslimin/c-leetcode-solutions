#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* arr;
    struct TreeNode** st;
    int idx = 0;
    int arr_size = 32;
    int st_size = 32;
    int top = -1;

    arr = malloc(sizeof(int) * arr_size);
    st = malloc(sizeof(struct TreeNode*) * st_size);
    if (root)
        st[++top] = root;

    while (top > -1) {
        struct TreeNode* cur = st[top--];
        if (idx == arr_size) {
            arr_size <<= 1;
            arr = realloc(arr, sizeof(int) * arr_size);
        }

        arr[idx++] = cur->val;
        if (top + 2 >= st_size) {
            st_size <<= 1;
            st = realloc(st, sizeof(struct TreeNode*) * st_size);
        }

        if (cur->right)
            st[++top] = cur->right;
        if (cur->left)
            st[++top] = cur->left;
    }

    *returnSize = idx;
    free(st);
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