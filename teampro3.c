#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char carName[20];
    int cost;
    struct TreeNode* left;    
    struct TreeNode* right;
} TreeNode;

void Menu();
TreeNode* createNode(int data);
TreeNode* findMinNode(TreeNode* node);
TreeNode* deleteBST(TreeNode* root, int key);
TreeNode* insertBST(TreeNode* root, int key);
TreeNode* searchBST(TreeNode* root, int key);

int main() {
    printf("중고나라에 오신걸 환영합니다!\n");
    TreeNode* root;

    while(1){
        int menu;
        Menu(root);
        printf("메뉴를 선택해주세요. >>");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
            
            case 2:
            case 3:
            case 4:
    }
}

void Menu(){
    printf("|-----------MENU------------|\n");
    printf("1. 올라온 중고차 매물 확인하기\n");
    printf("2. 중고차 매물 올리기\n");
    printf("3. 내가 원하는 중고차 검색\n");
    printf("4. 중고차 매물 삭제하기\n");
    printf("0. 종료\n");
    printf("|---------------------------|\n");

}
TreeNode* createNode(char* name, int cost) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->carName, name);
    newNode->cost = cost;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


