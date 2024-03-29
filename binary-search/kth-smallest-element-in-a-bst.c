// 230. 二叉搜索树中第K小的元素
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "treenode.h"

/**

 */
int helper(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return helper(root->left) + helper(root->right) + 1;
}

int kthSmallest(struct TreeNode* root, int k)
{
    int left;
    left = helper(root->left);
    if (left + 1 > k)
        return kthSmallest(root->left, k);
    else if (left + 1 == k)
        return root->val;
    return kthSmallest(root->right, k - left - 1);
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 3;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 1;
    root->left->left = NULL;
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 2;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 4;
    root->right->left = NULL;
    root->right->right = NULL;
    int k = 1;
    int result = kthSmallest(root, k);
    printf("%d", result);
    return 0;
}