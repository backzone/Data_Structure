#pragma warning(disable:6011)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* insertFirst(Node* head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		return newNode;
	}
	newNode->next = head;
	return newNode;
	return head;
}

Node* insertLast(Node* head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		return newNode;
	}

	Node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;

	return head;
}

void insertAfterValue(Node* head, int targetValue, int newData) {
	Node* current = head;

	while (current != NULL) {
		if (current->data == targetValue) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = newData;
			newNode->next = current->next;
			current->next = newNode;
			return;
		}
		current = current->next;
	}

	printf("값 %d를 가진 노드를 찾을 수 없습니다. 삽입하지 않습니다.\n", targetValue);
}

Node* deleteHead(Node* head) {
	if (head == NULL) {
		printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
		return NULL;
	}

	Node* temp = head;
	head = head->next;
	free(temp);

	return head;
}

Node* deleteLast(Node* head) {
	if (head == NULL) {
		printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
		return NULL;
	}

	if (head->next == NULL) {
		free(head);
		return NULL;
	}

	Node* current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	free(current->next);
	current->next = NULL;

	return head;
}

Node* deleteNode(Node* head, int targetValue) {
	if (head == NULL) {
		printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
		return NULL;
	}

	if (head->data == targetValue) {
		Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}

	Node* current = head;
	while (current->next != NULL && current->next->data != targetValue) {
		current = current->next;
	}

	if (current->next == NULL) {
		printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", targetValue);
		return head;
	}

	Node* temp = current->next;
	current->next = current->next->next;
	free(temp);

	return head;
}

Node* printList(Node* head) {
	head = insertFirst(head, 30); // 첫 번째 노드 삽입
	head = insertFirst(head, 20); // 두 번째 노드 삽입
	head = insertFirst(head, 10); // 세 번째 노드 삽입
	head = insertLast(head, 70); // 세 번째 노드 삽입
	head = insertLast(head, 80); // 세 번째 노드 삽입
	head = insertLast(head, 90); // 세 번째 노드 삽입
	insertAfterValue(head, 30, 40); // 세 번째 노드 삽입
	insertAfterValue(head, 40, 50); // 세 번째 노드 삽입
	insertAfterValue(head, 50, 60); // 세 번째 노드 삽입

	head = deleteHead(head);
	head = deleteLast(head);
	head = deleteNode(head, 40);
	head = deleteNode(head, 70);
	head = deleteNode(head, 80);


	// 리스트 출력
	Node* current = head;
	if (head == NULL) {
		printf("리스트가 비어있습니다.\n");
	}
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
	return head;
}

int searchValue1(Node* head, int targetValue) {
	Node* current = head;
	int i = 1;
	if (current == NULL) {
		printf("리스트가 비어 있습니다. 찾을 노드가 없습니다.\n");
		return NULL;
	}
	while (current != NULL) {
		if (current->data == targetValue) {
			return i;
		}
		current = current->next;
		i++;
	}
	return -1;
}

Node* searchValue2(Node* head, int targetValue) {
	Node* current = head;
	if (current == NULL) {
		printf("리스트가 비어 있습니다. 찾을 노드가 없습니다.\n");
		return NULL;
	}
	while (current != NULL && current->next != NULL && current->next->next != NULL) {
		if (current->next->data == targetValue) {
			printf("%d 사이에 %d, %d 값이 앞뒤로 존재하였습니다.\n", current->next->data,current->data, current->next->next->data);
		}
		current = current->next;
	}
}

void freeList(Node* head) {
	Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	printf("모든 노드가 제거되었습니다.\n");
}

int main() {
	Node* head = NULL;
	int pos = -1;
	int val = 50;
	head = printList(head);
	pos = searchValue1(head, val);
	if (pos != -1) {
		printf("%d의 위치는 %d번째\n", val, pos);
	}
	else {
		printf("%d를 찾을 수 없습니다.\n", val);
	}
	searchValue2(head, val);
	freeList(head);
	return 0;
}