#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "treenode.h"
/**
这是一道二叉树的题目，需要对二叉树进行遍历，并记录每个节点的值和左右子树的值之和，最后返回最大值。

 */
int get_max(struct TreeNode* root, int* node)
{
    if (root == NULL)
        return 0;

    int left = get_max(root->left, node);
    int right = get_max(root->right, node);
    int ret;
    int tmp;

    ret = root->val;
    ret += left > right ? left : right;

    tmp = root->val + left + right;
    *node = tmp > *node ? tmp : *node;

    return ret < 0 ? 0 : ret;
}

int maxPathSum(struct TreeNode* root)
{
    int node = INT_MIN;

    get_max(root, &node);

    return node;
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->left = NULL;
    root->right->right = NULL;
    int maxSum = maxPathSum(root);
    printf("%d", maxSum);
    return 0;
}