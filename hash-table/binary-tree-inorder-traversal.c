// 94. 二叉树的中序遍历
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "treenode.h"

void inorderTraversalHelper(struct TreeNode* root, int* res, int* returnSize) {
    if (root == NULL) {
        return;
    }
    inorderTraversalHelper(root->left, res, returnSize);
    res[(*returnSize)++] = root->val;
    inorderTraversalHelper(root->right, res, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    inorderTraversalHelper(root, res, returnSize);
    return res;
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