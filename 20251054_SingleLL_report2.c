#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[30];
    char num[30];
    struct Node* next;
} Node;

Node* insertContact(Node* head) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return head;

    printf("이름: ");
    scanf("%s", newNode->name);
    printf("전화번호: ");
    scanf("%s", newNode->num);

    newNode->next = head;
    printf("'%s'님의 연락처가 추가되었습니다.\n", newNode->name);
    return newNode;
}

void searchContact(Node* head) {
    if (head == NULL) {
        printf("전화번호부가 비어있습니다.\n");
        return;
    }

    char target[30];
    printf("검색할 이름: ");
    scanf("%s", target);

    Node* current = head;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->name, target) == 0) {
            printf("[결과] %s: %s\n", current->name, current->num);
            found = 1;
        }
        current = current->next;
    }
    if (!found) printf("찾으시는 이름이 없습니다.\n");
}

Node* deleteContact(Node* head) {
    if (head == NULL) {
        printf("전화번호부가 비어 있습니다.\n");
        return NULL;
    }

    char target[30];
    printf("삭제할 이름: ");
    scanf("%s", target);

    Node* current = head;
    Node* prev = NULL;

    if (strcmp(head->name, target) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("'%s'님의 정보를 삭제했습니다.\n", target);
        return head;
    }

    while (current != NULL && strcmp(current->name, target) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("'%s'님을 찾을 수 없습니다.\n", target);
        return head;
    }

    prev->next = current->next;
    free(current);
    printf("'%s'님의 정보를 삭제했습니다.\n", target);

    return head;
}

void totalNum(Node* head) {
    if (head == NULL) {
        printf("전화번호부가 비어있습니다.\n");
        return;
    }

    Node* current = head;
    int i = 1;
    while (current != NULL) {
        printf("[%d] %s: %s\n", i, current->name, current->num);
        i++;
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    char c = ' ';

    while (c != 'q') {
        printf("\n--- 연락처 관리 프로그램 ---\n");
        printf("1: 추가 | 2: 검색 | 3: 삭제 | 4: 보기 | q: 종료\n선택: ");
        scanf(" %c", &c);

        switch (c) {
        case '1':
            head = insertContact(head);
            break;
        case '2':
            searchContact(head);
            break;
        case '3':
            head = deleteContact(head);
            break;
        case '4':
            totalNum(head);
            break;
        case 'q':
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 입력입니다.\n");
        }
    }
    return 0;
}