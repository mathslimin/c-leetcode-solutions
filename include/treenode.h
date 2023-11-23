#include <limits.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#define LEN(x, y) (sizeof(x) / sizeof(y))
#define COUNT 10
#define MAX_SIZE 100

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 二叉树初始化

/**
 * 输入一维数组 [1 2 3 4 5 6]
 *
 * 规律： 1
 *     2   3
 *    4 5 6 7
 */

/**
 * 递归创建节点
 */
struct TreeNode* createNode(int* a, int arraySize, int index)
{
    // printf("%d,%d\n", arraySize, index);
    if (index > arraySize) {
        return NULL;
    }

    int val = a[index - 1];
    if (val <= INT16_MIN) {
        // printf("%d\n", val);
        return NULL;
    }

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = createNode(a, arraySize, 2 * index);
    root->right = createNode(a, arraySize, 2 * index + 1);

    return root;
}

struct TreeNode* createNodeByInt(int val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* init(int* a, int arraySize)
{
    return createNode(a, arraySize, 1);
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

void handleVal(int val)
{
    printf("Node is %d\n", val);
}

void r(struct TreeNode* root, void (*handle)(int))
{
    if (root == NULL) {
        printf("Null Node;\n");
        return;
    }
    handle(root->val);
    r(root->left, handle);
    r(root->right, handle);
}

void visiable(struct TreeNode* root)
{
    // todo 打印成 一种更加优美的方式
    //    比如:
    //     1
    //    /  \
    //   2    2
    //  / \  / \
    // 33  1 2  3
    // 自己给自己的难题 一种排版算法！
    r(root, handleVal);
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct TreeNode* root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->val);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void printTree(struct TreeNode* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

void inorderTraversalTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversalTree(root->left);
    printf("%d ", root->val);
    inorderTraversalTree(root->right);
}
