#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */
int rob(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    int m1 = rob(root->left) + rob(root->right);
    int m2 = root->val;
    if (root->left)
        m2 += rob(root->left->left) + rob(root->left->right);
    if (root->right)
        m2 += rob(root->right->left) + rob(root->right->right);

    return m2 > m1 ? m2 : m1;
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 3;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 3;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->right->left = NULL;
    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->val = 1;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    printf("%d", rob(root));
    return 0;
}