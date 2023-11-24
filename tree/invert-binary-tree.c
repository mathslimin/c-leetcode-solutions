#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**

题目描述

翻转一棵二叉树。

 */
#define MAX_SIZE 100

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root)
{
    if (!root)
        return NULL;

    struct TreeNode* node = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = node;

    return root;
}

struct TreeNode* createBinaryTree(int *array, int size) {
    if (size == 0) {
        return NULL;
    }
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = array[0];
    root->left = NULL;
    root->right = NULL;
    struct TreeNode **queue = malloc(sizeof(struct TreeNode *) * MAX_SIZE);
    int front = 0, rear = 0;
    queue[rear++] = root;
    for (int i = 1; i < size; i += 2) {
        struct TreeNode *node = queue[front++];
        if (array[i] != -1) {
            node->left = malloc(sizeof(struct TreeNode));
            node->left->val = array[i];
            node->left->left = NULL;
            node->left->right = NULL;
            queue[rear++] = node->left;
        }
        if (i + 1 < size && array[i + 1] != -1) {
            node->right = malloc(sizeof(struct TreeNode));
            node->right->val = array[i + 1];
            node->right->left = NULL;
            node->right->right = NULL;
            queue[rear++] = node->right;
        }
    }
    free(queue);
    return root;
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

void test1(){
    int array1[] = {4, 2, 7, 1, 3, 6, 9};
    struct TreeNode *root1 = createBinaryTree(array1, sizeof(array1) / sizeof(int));
    printf("Original Binary Tree:\n");
    inorderTraversal(root1);
    printf("\n");
    root1 = invertTree(root1);
    printf("Inverted Binary Tree:\n");
    inorderTraversal(root1);
    printf("\n");

}

void test2(){
    int array2[] = {1, 2, 3, 4, 5, 6, 7};
    struct TreeNode *root2 = createBinaryTree(array2, sizeof(array2) / sizeof(int));
    printf("Original Binary Tree:\n");
    inorderTraversal(root2);
    printf("\n");
    
    root2 = invertTree(root2);
    printf("Inverted Binary Tree:\n");
    inorderTraversal(root2);
    printf("\n");
}

int main() {
    test1();
    return 0;
}