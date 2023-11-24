#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "treenode.h"

/**

 */
struct TreeNode* helper(int* preorder, int pre_start, int pre_end, int* inorder, int in_start, int in_end)
{
    if (in_end < in_start)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[pre_start];

    int mid;
    for (mid = in_start; mid <= in_end; ++mid)
        if (inorder[mid] == preorder[pre_start])
            break;

    root->left = helper(preorder, pre_start + 1, pre_start + mid - in_start, inorder, in_start, mid - 1);
    root->right = helper(preorder, pre_start + mid - in_start + 1, pre_end, inorder, mid + 1, in_end);

    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if (inorderSize == 0)
        return NULL;

    return helper(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}

int main()
{
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int inorderSize = sizeof(inorder) / sizeof(int);
    int preorderSize = sizeof(preorder) / sizeof(int);
    struct TreeNode* tree = buildTree(preorder, preorderSize, inorder, inorderSize);
    printTree(tree);
    return 0;
}