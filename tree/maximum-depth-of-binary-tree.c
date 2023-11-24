#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */
void depth(struct TreeNode* root, int cur_h, int* max_h)
{
    if (root == NULL)
        return;

    cur_h++;
    if (cur_h > *max_h)
        *max_h = cur_h;

    depth(root->left, cur_h, max_h);
    depth(root->right, cur_h, max_h);
}

int maxDepth(struct TreeNode* root)
{
    int max_h = 0;
    int cur_h = 0;

    depth(root, cur_h, &max_h);

    return max_h;
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