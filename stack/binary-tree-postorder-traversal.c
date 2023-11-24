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
    struct TreeNode** st;
    struct TreeNode *cur, *pre = NULL;
    int top;
    int* data;
    int idx;
    int st_count = 32;
    int data_count = 32;

    data = malloc(sizeof(int) * data_count);
    st = malloc(sizeof(struct TreeNode*) * st_count);
    top = -1;
    idx = 0;

    if (root)
        st[++top] = root;

    while (top > -1) {
        cur = st[top];
        if ((cur->left == NULL && cur->right == NULL) || (pre != NULL && (pre == cur->left || pre == cur->right))) {
            if (idx == data_count) {
                data_count <<= 1;
                data = realloc(data, sizeof(int) * data_count);
            }
            data[idx++] = cur->val;
            top--;
            pre = cur;
        } else {
            if (top + 2 >= st_count) {
                st_count <<= 1;
                st = realloc(st, sizeof(struct TreeNode*) * st_count);
            }
            if (cur->right != NULL)
                st[++top] = cur->right;
            if (cur->left != NULL)
                st[++top] = cur->left;
        }
    }

    free(st);
    *returnSize = idx;
    return data;
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
    int* res = postorderTraversal(root, &returnSize);

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