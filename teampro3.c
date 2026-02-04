#include <stdio.h>
#include <stdlib.h>

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
TreeNode* insertBST(TreeNode* root, int key);
TreeNode* searchBST(TreeNode* root, int key);

int main() {
    printf("중고나라에 오신걸 환영합니다!\n");
    TreeNode* root = NULL;

    while(1){
        int menu;
        Menu();
        printf("메뉴를 선택해주세요. >>");
        scanf("%d", &menu);

        if(menu == 0) break;
        
        switch(menu){
            case 1:
                pritnf("\n[ 매물 목록 ]\n");
                displayAll(root);
                break;
            case 2:
                printf("등록할 차종 이름 입력: ");
                scanf("%s", name);
                printf("가격 입력(만원): ");
                scanf("%d", &cost);
                
                root = insertBST(root,name, cost);
                printf("성공적으로 등록되었습니다.\n");
                break;
            case 3:

                break;
            case 4:
                printf("삭제할 차종 이름 입력: ");
                scanf("%s", name);
                printf("가격 입력(만원): ");
                scanf("%d", &cost);
                
                deleteBST(root, cost);
                printf("성공적으로 삭제되었습니다.\n");
                break;
            case 0:
                printf("앱을 종료합니다.\n");
                break;
            default: printf("잘못된 선택입니다.\n");
    }
    return 0;
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

//삭제
TreeNode* deleteBST(TreeNode* root, int cost) {
    if (root == NULL) return root;
    //2.삭제할 노드 찾기
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
        
        root->right = deleteBST(root->right,temp->cost);
    }
    return root;
}


