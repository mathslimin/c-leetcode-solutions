#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "treenode.h"

/**

 */

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    struct TreeNode* st[1000];
    int top = -1;
    int* arr;
    int idx = 0;
    int count = 32;

    arr = malloc(sizeof(int) * count);
    while (root != NULL || top > -1) {
        while (root) {
            st[++top] = root;
            root = root->left;
        }

        root = st[top--];
        if (idx == count) {
            count <<= 1;
            arr = realloc(arr, sizeof(int) * count);
        }
        arr[idx++] = root->val;
        root = root->right;
    }

    *returnSize = idx;
    return arr;
}

int main() {
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

    int returnSize;
    int* res = inorderTraversal(root, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(root->right->left);
    free(root->right);
    free(root);

    free(res);

    return 0;
}