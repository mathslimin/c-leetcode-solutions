#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */
int sum(struct TreeNode* root, int cur_val)
{
    if (root == NULL)
        return 0;

    int val = cur_val * 10 + root->val;
    if (root->left == NULL && root->right == NULL)
        return val;

    return sum(root->left, val) + sum(root->right, val);
}

int sumNumbers(struct TreeNode* root)
{
    return sum(root, 0);
}

// 测试代码
int main() {
    struct TreeNode node1 = {1, NULL, NULL};
    struct TreeNode node2 = {2, NULL, NULL};
    struct TreeNode node3 = {3, NULL, NULL};
    node1.left = &node2;
    node1.right = &node3;
    printf("%d", sumNumbers(&node1)); // 25

    struct TreeNode node4 = {4, NULL, NULL};
    struct TreeNode node5 = {9, NULL, NULL};
    struct TreeNode node6 = {0, NULL, NULL};
    struct TreeNode node7 = {5, NULL, NULL};
    struct TreeNode node8 = {1, NULL, NULL};
    node4.left = &node5;
    node4.right = &node6;
    node5.left = &node7;
    node5.right = &node8;
    printf("%d", sumNumbers(&node4)); // 1026

    return 0;
}