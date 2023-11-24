#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    return leftCount + rightCount + 1;
}

int main() {
    struct TreeNode node1 = {1, NULL, NULL};
    struct TreeNode node2 = {2, NULL, NULL};
    struct TreeNode node3 = {3, NULL, NULL};
    struct TreeNode node4 = {4, NULL, NULL};
    struct TreeNode node5 = {5, NULL, NULL};
    struct TreeNode node6 = {6, NULL, NULL};
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    int count = countNodes(&node1);
    printf("The number of nodes in the binary tree is %d", count);
    return 0;
}