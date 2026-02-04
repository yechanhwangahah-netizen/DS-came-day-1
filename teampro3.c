#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char carName[20];
    int cost;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data);
TreeNode* findMinNode(TreeNode* node);
TreeNode* deleteBST(TreeNode* root, int key);
TreeNode* insertBST(TreeNode* root, int key);
TreeNode* searchBST(TreeNode* root, int key);
