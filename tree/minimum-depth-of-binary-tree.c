#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"
#include <limits.h>
/**

 */
int minDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if (left == 0)
        left = INT_MAX;
    if (right == 0)
        right = INT_MAX;

    return left < right ? left + 1 : right + 1;
}

int main() {
    struct TreeNode node1 = {3, NULL, NULL};
    struct TreeNode node2 = {9, NULL, NULL};
    struct TreeNode node3 = {20, NULL, NULL};
    struct TreeNode node4 = {15, NULL, NULL};
    struct TreeNode node5 = {7, NULL, NULL};
    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;
    printf("%d", minDepth(&node1)); // 输出3
    return 0;
}