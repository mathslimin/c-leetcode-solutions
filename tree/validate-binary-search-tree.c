#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**
题目描述

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

 */
bool isValidBST(struct TreeNode* root)
{
    if (root == NULL)
        return true;

    struct TreeNode* node = root->left;
    while (node && node->right)
        node = node->right;

    if (node && node->val >= root->val)
        return false;

    node = root->right;
    while (node && node->left)
        node = node->left;

    if (node && node->val <= root->val)
        return false;

    return isValidBST(root->left) && isValidBST(root->right);
}

int main() {
    struct TreeNode* root1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* root2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* root3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* root4 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* root5 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root1->val = 2;
    root1->left = root2;
    root1->right = root3;
    root2->val = 1;
    root2->left = NULL;
    root2->right = NULL;
    root3->val = 3;
    root3->left = NULL;
    root3->right = NULL;
    root4->val = 5;
    root4->left = root2;
    root4->right = root5;
    root5->val = 6;
    root5->left = root3;
    root5->right = NULL;
    bool res1 = isValidBST(root1);
    bool res2 = isValidBST(root4);
    printf("%d %d", res1, res2);
    return 0;
}
