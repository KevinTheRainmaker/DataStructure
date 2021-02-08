#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	int data;
	struct _node * next;
} Node;

int main() {
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	//데이터 입력받기 - 이전 코드와 동일
	while (1) {
		printf("Enter integer: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;
	
		//노드의 추가
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}
	printf("\n");
	
	//입력받은 데이터 출력
	printf("Print all input data \n");
	if (head == NULL)
		printf("There is no stored data.\n");
	else {
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n");

	//메모리 해제
	if (head == NULL) 
		return 0;
	else {
		Node * delNode = head;
		Node * delNextNode = head->next;

		printf("Delete %d. \n", head->data);
		free(delNode); // 첫 번째 노드 삭제

		while (delNextNode != NULL) { // 두 번째 이후 노드 삭제
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("Delete %d. \n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}