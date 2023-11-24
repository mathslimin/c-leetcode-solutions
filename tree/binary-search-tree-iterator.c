#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treenode.h"


typedef struct {
    struct TreeNode** stack;
    int top;
} BSTIterator;

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* iterator = (BSTIterator*)malloc(sizeof(BSTIterator));
    iterator->stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    iterator->top = -1;
    struct TreeNode* p = root;
    while (p != NULL) {
        iterator->stack[++iterator->top] = p;
        p = p->left;
    }
    return iterator;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* p = obj->stack[obj->top--];
    int res = p->val;
    p = p->right;
    while (p != NULL) {
        obj->stack[++obj->top] = p;
        p = p->left;
    }
    return res;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top != -1;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->stack);
    free(obj);
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 7;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 3;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 15;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->val = 9;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->val = 20;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    BSTIterator* iterator = bSTIteratorCreate(root);
    printf("%d\n", bSTIteratorNext(iterator)); // 3
    printf("%d\n", bSTIteratorNext(iterator)); // 7
    printf("%d\n", bSTIteratorHasNext(iterator)); // true
    printf("%d\n", bSTIteratorNext(iterator)); // 9
    printf("%d\n", bSTIteratorHasNext(iterator)); // true
    printf("%d\n", bSTIteratorNext(iterator)); // 15
    printf("%d\n", bSTIteratorHasNext(iterator)); // true
    printf("%d\n", bSTIteratorNext(iterator)); // 20
    printf("%d\n", bSTIteratorHasNext(iterator)); // false
    bSTIteratorFree(iterator);
    return 0;
}