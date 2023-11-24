#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */
int getKth(struct TreeNode* root, int k, int* val)
{
    if (root == NULL)
        return 0;

    int left = getKth(root->left, k, val);
    if (left + 1 > k)
        return left;
    else if (left + 1 == k) {
        *val = root->val;
        return left + 1;
    }

    return left + 1 + getKth(root->right, k - left - 1, val);
}

int kthSmallest(struct TreeNode* root, int k)
{
    int val;
    getKth(root, k, &val);

    return val;
}

int main() {
    struct TreeNode node1 = {1, NULL, NULL};
    struct TreeNode node3 = {3, NULL, NULL};
    struct TreeNode node2 = {2, &node1, &node3};
    struct TreeNode node6 = {6, NULL, NULL};
    struct TreeNode node4 = {4, &node2, &node6};
    struct TreeNode* root = &node4;
    int k = 3;
    int result = kthSmallest(root, k);
    printf("result: %d", result);
    return 0;
}
