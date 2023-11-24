#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**

 */
void flatten(struct TreeNode* root)
{
    if (!root)
        return;

    while (root) {
        if (root->left) {
            struct TreeNode* node = root->left;
            while (node->right)
                node = node->right;

            node->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        root = root->right;
    }
}

struct TreeNode* createNode(int val) {
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->right = createNode(6);

    printf("Original tree: ");
    printTree(root);

    flatten(root);

    printf("Flattened tree: ");
    printTree(root);

    return 0;
}