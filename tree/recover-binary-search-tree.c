#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**
由于题目中要求恢复二叉搜索树，我们可以利用中序遍历得到一个递增的序列，如果有两个节点位置错误，则必然有两个相邻的数位置颠倒了。我们只需要找到这两个位置颠倒的节点，交换它们的值即可。
 */
struct TreeNode *prev, *t2, *t1;

void inorder(struct TreeNode* root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    if (prev && prev->val > root->val) {
        t2 = root;
        if (t1 == NULL)
            t1 = prev;
    }

    prev = root;
    inorder(root->right);
}

void recoverTree(struct TreeNode* root)
{
    prev = NULL;
    t1 = NULL;
    t2 = NULL;
    inorder(root);

    if (t1 && t2) {
        int tmp = t1->val;
        t1->val = t2->val;
        t2->val = tmp;
    }
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

    recoverTree(root);

    printf("%d %d %d", root->val, root->left->val, root->left->right->val);

    return 0;
}