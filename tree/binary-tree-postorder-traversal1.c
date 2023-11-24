#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* arr;
    int arr_count = 32;
    struct TreeNode** st;
    struct TreeNode* pre = NULL;
    int st_count = 32;
    int idx = 0;
    int top = -1;

    arr = malloc(sizeof(int) * arr_count);
    st = malloc(sizeof(struct TreeNode*) * st_count);
    if (root)
        st[++top] = root;

    while (top > -1) {
        struct TreeNode* cur = st[top];
        if ((cur->left == NULL && cur->right == NULL) || (pre && (pre == cur->left || pre == cur->right))) {
            --top;
            if (idx == arr_count) {
                arr_count <<= 1;
                arr = realloc(arr, sizeof(int) * arr_count);
            }
            arr[idx++] = cur->val;
            pre = cur;
        } else {
            if (top + 2 >= st_count) {
                st_count <<= 1;
                st = realloc(st, sizeof(struct TreeNode*) * st_count);
            }
            if (cur->right)
                st[++top] = cur->right;
            if (cur->left)
                st[++top] = cur->left;
        }
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

    // 测试postorderTraversal函数
    int size;
    int* result = postorderTraversal(root, &size);
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}