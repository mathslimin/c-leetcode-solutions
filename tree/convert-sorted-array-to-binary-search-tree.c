#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"

/**

 */
struct TreeNode* bcreate(int* nums, int start, int end)
{
    if (end < start)
        return NULL;

    int mid = (start + end) / 2;
    struct TreeNode* node = malloc(sizeof(struct TreeNode));

    node->val = nums[mid];
    node->left = bcreate(nums, start, mid - 1);
    node->right = bcreate(nums, mid + 1, end);

    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return bcreate(nums, 0, numsSize - 1);
}

int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    int numsSize = sizeof(nums) / sizeof(int);
    struct TreeNode* root = sortedArrayToBST(nums, numsSize);
    printTree(root);
    return 0;
}