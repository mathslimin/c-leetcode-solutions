#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
116. 填充每个节点的下一个右侧节点指针

 */

struct Node {
  int val;
  struct Node *left;
  struct Node *right;
  struct Node *next;
};

struct Node* connect(struct Node* root) {
    if (!root || !root->left) {
        return root;
    }
    root->left->next = root->right;
    if (root->next) {
        root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);
    return root;
}

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    return node;
}

void printTree(struct Node* root) {
    if (root) {
        printf("%d -> ", root->val);
        if (root->next) {
            printf("%d", root->next->val);
        } else {
            printf("NULL");
        }
        printTree(root->left);
        printTree(root->right);
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    connect(root);
    printTree(root);

    return 0;
}