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

int main() {
    printf("중고나라에 오신걸 환영합니다!\n");
    TreeNode* root;

    while(1){
        printf("|-----------MENU------------|\n");
        printf("1. 올라온 중고차 매물 확인하기\n");
        printf("2. 중고차 매물 올리기\n");
        printf("3. 내가 원하는 중고차 검색\n");
        printf("4. 중고차 매물 삭제하기\n");
        printf("|---------------------------|\n");
        
    }
}

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

















TreeNode* deleteBST(TreeNode* root, int cost) {
    //트리가 비어있으면 종료
    if (root == NULL) return root;
    //삭제할 노드 찾기
    if (cost < root->cost)
        root->left = deleteBST(root->left, cost);
    else if (cost > root->cost)
        root->right = deleteBST(root->right, cost);
    else {
      
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
      
        TreeNode* temp = findMinNode(root->right);
        root->cost = temp->cost;
        strcpy(root->carName, temp->carName);
        root->right = deleteBST(root->right, temp->cost);
    }
    return root;
}









