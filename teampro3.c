#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char carName[20];
    int cost;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
