#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char carName[20];
    int cost;
    struct TreeNode* left;    
    struct TreeNode* right;
} TreeNode;

void Menu();
void displayAll(TreeNode* root);
TreeNode* findMinNode(TreeNode* node);
TreeNode* deleteBST(TreeNode* root, int cost);
TreeNode* createNode(char* name, int cost);
TreeNode* insertBST(TreeNode* root, char* name, int cost);
TreeNode* searchRange(TreeNode* root, int min, int max);

int main() {
    printf("중고나라에 오신걸 환영합니다!\n");
    TreeNode* root = NULL;
    char name[20];
    int cost;
    int min_price, max_price;

    while(1){
        int menu;
        Menu();
        printf("메뉴를 선택해주세요. >> ");
        scanf("%d", &menu);

        if(menu == 0) break;
        
        switch(menu){
            case 1:
                printf("\n[ 매물 목록 ]\n");
                displayAll(root);
                break;
            case 2:
                printf("등록할 차종 이름 입력: >> ");
                scanf("%s", name);
                printf("가격 입력(만원): >> ");
                scanf("%d", &cost);
                
                root = insertBST(root, name, cost);
                printf("성공적으로 등록되었습니다.\n");
                break;
            case 3:
                printf("검색할 최소 가격 입력(만원): >> ");
                scanf("%d", &min_price);
                printf("검색할 최대 가격 입력(만원): >> ");
                scanf("%d", &max_price);
                
                printf("\n[ %d만원 ~ %d만원 사이의 매물 ]\n", min_price, max_price);
                searchRange(root, min_price, max_price);
                break;
            case 4:
                printf("삭제할 매물의 '가격' 입력: "); 
                scanf("%d", &cost);
                root = deleteBST(root, cost);
                printf("처리가 완료되었습니다.\n");
                break;
            case 0:
                printf("프로그램을 종료합니다.\n");
                break;
            default: printf("잘못된 선택입니다.\n");
        }
    }
    return 0;
}

void Menu(){
    printf("|------------MENU-------------|\n");
    printf(" 1. 올라온 중고차 매물 확인하기\n");
    printf(" 2. 중고차 매물 올리기\n");
    printf(" 3. 내가 원하는 중고차 검색\n");
    printf(" 4. 중고차 매물 삭제하기\n");
    printf(" 0. 종료\n");
    printf("|-----------------------------|\n");
}

void displayAll(TreeNode* root){
    if(root != NULL){   
        displayAll(root->left);
        printf("차종: %-10s | 가격: %d만원\n", root->carName, root->cost);
        displayAll(root->right);
    }
}

TreeNode* findMinNode(TreeNode* node){
    TreeNode* current = node;
    while(current && current->left != NULL)
        current = current->left;
    return current;
}

TreeNode* createNode(char* name, int cost) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->carName, name);
    newNode->cost = cost;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

TreeNode* insertBST(TreeNode* root, char* name, int cost) {
    if (root == NULL) return createNode(name, cost);

    if (cost < root->cost) {
        root->left = insertBST(root->left, name, cost);
    } else if (cost > root->cost) {
        root->right = insertBST(root->right, name, cost);
    }
    return root;
}
 
TreeNode* deleteBST(TreeNode* root, int cost) {
    if (root == NULL) return root;
    
    if (cost < root->cost)
        root->left = deleteBST(root->left, cost);
    else if (cost > root->cost)
        root->right = deleteBST(root->right, cost);

    else {
        if (root->left== NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right== NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = findMinNode(root->right);
        root->cost = temp->cost;
        strcpy(root->carName, temp->carName);
        root->right = deleteBST(root->right,temp->cost);
    }
    return root;
}

void * searchRange(TreeNode* root, int min, int max){
    if(root == NULL) return;

    if(root->cost > min) searchRange(root->left, min, max);
    if(root->cost >= min && root->cost <= max){
        printf("차종: %-10s | 가격: %d만원\n", root->carName, root->cost);
    }
    if(root->cost < max) searchRange(root->right, min, max);
}

