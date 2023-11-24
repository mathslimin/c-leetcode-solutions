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
    struct TreeNode** st;
    struct TreeNode* cur;
    int* data;
    int idx = 0;
    int top = -1;
    int data_count = 32;
    int st_count = 32;

    st = malloc(sizeof(struct TreeNode*) * st_count);
    data = malloc(sizeof(int) * data_count);

    if (root)
        st[++top] = cur;

    while (top > -1) {
        cur = st[top--];

        data[idx++] = cur->val;
        if (idx == data_count) {
            data_count <<= 1;
            data = realloc(data, sizeof(int) * data_count);
        }

        if (cur->right)
            st[++top] = cur->right;

        if (cur->left)
            st[++top] = cur->left;

        if (top + 1 == st_count) {
            st_count <<= 1;
            st = realloc(st, sizeof(struct TreeNode*) * st_count);
        }
    }

    *returnSize = idx;

    free(st);
    return data;
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));  // 创建一个二叉树
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
    int* res = preorderTraversal(root, &returnSize);  // 调用函数进行遍历
    printf("[");  // 输出遍历结果
    for (int i = 0; i < returnSize; i++) {
        printf("%d", res[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]");
    free(res);  // 释放数组的内存
    free(root->right->left);  // 释放二叉树的内存
    free(root->right);
    free(root);
    return 0;
}