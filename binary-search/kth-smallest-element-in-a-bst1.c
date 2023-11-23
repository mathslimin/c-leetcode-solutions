/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "treenode.h"

int getKth(struct TreeNode *root, int k, int *val)
{
    if(root == NULL)
        return 0;

    int left = getKth(root->left,k,val);
    if(left + 1 > k)
        return left;
    if(left + 1 == k){
        *val = root->val;
        return left+1;
    }

    return left + 1 + getKth(root->right,k-left-1,val);
}

int kthSmallest(struct TreeNode* root, int k) {
    int val;
    getKth(root,k, &val);

    return val;
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