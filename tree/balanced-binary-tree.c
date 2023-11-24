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

struct TreeNode* createNode(int val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
/**

 */
#define max_2(x, y)        \
    ({                     \
        int _x = (x);      \
        int _y = (y);      \
        _x > _y ? _x : _y; \
    })

int depth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    int left = depth(root->left);
    int right = depth(root->right);

    if (left == -1 || right == -1 || abs(left - right) > 1)
        return -1;

    return max_2(left, right) + 1;
}

bool isBalanced(struct TreeNode* root)
{
    return depth(root) != -1;
}

int main(){
    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);
    if(isBalanced(root)){
        printf("The binary tree is balanced.");
    }else{
        printf("The binary tree is not balanced.");
    }
    return 0;
}