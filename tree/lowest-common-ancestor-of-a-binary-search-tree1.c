#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */
#define min_2(x, y)        \
    ({                     \
        int _x = (x);      \
        int _y = (y);      \
        _x < _y ? _x : _y; \
    })

#define max_2(x, y)        \
    ({                     \
        int _x = (x);      \
        int _y = (y);      \
        _x > _y ? _x : _y; \
    })

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (min_2(p->val, q->val) > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else if (max_2(p->val, q->val) < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else
        return root;
}

int main() {
    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->val = 3;
    root->left = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->left->val = 5;
    root->left->left = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->left->left->val = 6;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->left->right->val = 2;
    root->left->right->left = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->left->right->left->val = 7;
    root->left->right->left->left = NULL;
    root->left->right->left->right = NULL;
    root->left->right->right = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->left->right->right->val = 4;
    root->left->right->right->left = NULL;
    root->left->right->right->right = NULL;
    root->right = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->right->val = 1;
    root->right->left = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->right->left->val = 0;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->right->right->val = 8;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    struct TreeNode* p = root->left;
    struct TreeNode* q = root->right;
    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    printf("The lowest common ancestor of %d and %d is %d.", p->val, q->val, lca->val);
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