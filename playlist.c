#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node* next;
};

/* 함수 프로토타입 */
struct Node* addSong(struct Node* head, char* songName);
void showPlaylist(struct Node* head);
struct Node* removeSong(struct Node* head, char* songName);

int main() {
    struct Node* head = NULL;
    char songName[50];

    printf("어서오세용");

    head = addSong(head,"Ditto");
    head = addSong(head, "Hype boy");
    head = addSong(head,"OMG");
    
    showPlaylist(head);

    printf("삭제를 원하는곡 입력:");
    scanf("%s", songName);
    head = removeSong(head, songName);

    showPlaylist(head);


    return 0;
}


/* 곡 추가: 리스트 맨 뒤에 삽입 */
struct Node* addSong(struct Node* head, char* songName) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, songName);
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

/* 플레이리스트 출력 */
void showPlaylist(struct Node* head) {
    int index = 1;
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d. %s -> ", index++, temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* 특정 제목의 곡 삭제 */
struct Node* removeSong(struct Node* head, char* songName) {
    if (head == NULL) return NULL;

    if (strcmp(head->name, songName) == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    while (current->next != NULL &&
           strcmp(current->next->name, songName) != 0) {
        current = current->next;
    }

    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    return head;
}
