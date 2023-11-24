#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//117. 填充每个节点的下一个右侧节点指针 II

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};

struct Node *connect(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }
    struct Node *cur = root;
    while (cur != NULL) {
        // 定义虚拟头节点和当前节点
        struct Node *dummy = (struct Node *)malloc(sizeof(struct Node));
        dummy->next = NULL;
        struct Node *tail = dummy;
        // 遍历当前层的节点
        while (cur != NULL) {
            if (cur->left != NULL) {
                tail->next = cur->left;
                tail = tail->next;
            }
            if (cur->right != NULL) {
                tail->next = cur->right;
                tail = tail->next;
            }
            cur = cur->next;
        }
        // 更新当前层的节点
        cur = dummy->next;
        free(dummy);
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