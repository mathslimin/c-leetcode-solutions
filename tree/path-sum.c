#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */
bool hasPathSum(struct TreeNode* root, int sum)
{
    if (root == NULL)
        return false;

    if (root->left == NULL && root->right == NULL)
        return root->val == sum;

    bool bleft = hasPathSum(root->left, sum - root->val);
    if (bleft)
        return true;

    bool bright = hasPathSum(root->right, sum - root->val);

    return bright;
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 5;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 4;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 8;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->val = 13;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->val = 4;
    root->right->right->left = NULL;
    root->right->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->right->val = 1;
    root->right->right->right->left = NULL;
    root->right->right->right->right = NULL;
    bool result = hasPathSum(root, 22);
    printf("%d", result);
    return 0;
}