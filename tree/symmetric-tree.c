#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */

bool isSame(struct TreeNode* left, struct TreeNode* right)
{
    if (left && right) {
        if (left->val != right->val)
            return false;

        return isSame(left->left, right->right) && isSame(left->right, right->left);
    }

    return left == NULL && right == NULL;
}

bool isSymmetric(struct TreeNode* root)
{
    if (root)
        return isSame(root->left, root->right);

    return true;
}

// 测试代码
int main() {
    struct TreeNode node1 = {1, NULL, NULL};
    struct TreeNode node2 = {2, NULL, NULL};
    struct TreeNode node3 = {3, NULL, NULL};
    node1.left = &node2;
    node1.right = &node3;
    printf("%d", isSymmetric(&node1)); // 25


    return 0;
}