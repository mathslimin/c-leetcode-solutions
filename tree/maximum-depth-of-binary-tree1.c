#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */
int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return (left > right ? left : right) + 1;
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
    printf("%d", maxDepth(&node1)); // 输出3
    return 0;
}