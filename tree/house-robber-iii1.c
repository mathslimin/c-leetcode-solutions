#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */
#define max2(x, y)         \
    ({                     \
        int _x = (x);      \
        int _y = (y);      \
        _x > _y ? _x : _y; \
    })

void dfs(struct TreeNode* root, int* rob, int* not_rob)
{
    if (root == NULL) {
        *rob = 0;
        *not_rob = 0;
        return;
    }

    int left, not_left;
    int right, not_right;
    dfs(root->left, &left, &not_left);
    dfs(root->right, &right, &not_right);

    *rob = root->val + not_left + not_right;
    *not_rob = max2(left, not_left) + max2(right, not_right);
}

int rob(struct TreeNode* root)
{
    int rob, not_rob;

    dfs(root, &rob, &not_rob);

    return max2(rob, not_rob);
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