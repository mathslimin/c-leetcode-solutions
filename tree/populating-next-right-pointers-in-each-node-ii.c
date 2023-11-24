#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/**
117. 填充每个节点的下一个右侧节点指针 II
 */
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};

struct Node *connect(struct Node *root) {
    if (!root) {
        return NULL;
    }
    struct Node *q[10001];
    int left = 0, right = 0;
    q[right++] = root;
    while (left < right) {
        int n = right - left;
        struct Node *last = NULL;
        for (int i = 1; i <= n; ++i) {
            struct Node *f = q[left++];
            if (f->left) {
                q[right++] = f->left;
            }
            if (f->right) {
                q[right++] = f->right;
            }
            if (i != 1) {
                last->next = f;
            }
            last = f;
        }
    }
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