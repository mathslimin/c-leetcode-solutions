#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* arr;
    struct TreeNode** st;
    struct TreeNode* cur;
    int top = -1;
    int arr_count = 32;
    int st_count = 32;
    int idx = 0;

    st = malloc(sizeof(struct TreeNode*) * st_count);
    arr = malloc(sizeof(int) * arr_count);

    cur = root;
    while (cur || top > -1) {
        while (cur) {
            if (top + 1 == st_count) {
                st_count <<= 1;
                st = realloc(st, sizeof(struct TreeNode*) * st_count);
            }
            st[++top] = cur;
            cur = cur->left;
        }

        struct TreeNode* tmp = st[top--];
        cur = tmp->right;
        if (idx == arr_count) {
            arr_count <<= 1;
            arr = realloc(arr, sizeof(int) * arr_count);
        }
        arr[idx++] = tmp->val;
    }

    *returnSize = idx;
    free(st);
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

    free(root->right->left);
    free(root->right);
    free(root);

    free(res);

    return 0;
}