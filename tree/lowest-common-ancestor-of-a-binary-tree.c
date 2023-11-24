#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (root == NULL || root == p || root == q)
        return root;

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right)
        return root;

    return left ? left : right;
}

int main() {
    // 创建二叉树
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 3;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 5;
    root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->val = 6;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 2;
    root->left->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->left->val = 7;
    root->left->right->left->left = NULL;
    root->left->right->left->right = NULL;
    root->left->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->right->val = 4;
    root->left->right->right->left = NULL;
    root->left->right->right->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 1;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->val = 0;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->val = 8;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    // 测试
    struct TreeNode *p = root->left;
    struct TreeNode *q = root->right;
    struct TreeNode *result = lowestCommonAncestor(root, p, q);
    printf("The lowest common ancestor of %d and %d is %d.", p->val, q->val, result->val);

    // 释放内存
    free(root->left->left);
    free(root->left->right->left);
    free(root->left->right->right);
    free(root->left->right);
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}