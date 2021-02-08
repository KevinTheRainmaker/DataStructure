#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List *plist)
{
    plist->head = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head;
    if (plist->head != NULL)         // 빈 리스트가 아닐 때 == 두 번째 이후의 노드를 추가할 때
        plist->head->prev = newNode; // 기존 노드(첫 번째 노드)의 prev가 새로운 노드를 가리키게 한다

    newNode->prev = NULL;
    plist->head = newNode;

    (plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
    if (plist->head->next == NULL) // 더미 노드가 NULL을 가리킬 경우
        return FALSE;              // 반환할 데이터 X

    plist->cur = plist->head; // cur이 첫 번째 노드를 가리키게 함

    *pdata = plist->cur->data; // 첫 번째 노드의 데이터를 전달
    return TRUE;               // 데이터 반환 성공
}

int LNext(List *plist, Data *pdata)
{
    if (plist->cur->next == NULL) // cur이 NULL을 가리킨다면
        return FALSE;             // 반환할 데이터 X

    plist->cur = plist->cur->next; // cur은 다음 노드를 가리킴
    *pdata = plist->cur->data;     // cur이 가리키는 노드의 데이터 전달
    return TRUE;                   // 데이터 반환 성공
}

int LPrevious(List *plist, Data *pdata)
{
    if (plist->cur->prev == NULL) // cur이 (왼쪽방향으로) NULL을 가리킬 경우
        return FALSE;

    plist->cur = plist->cur->prev; // cur을 왼쪽으로 이동
    *pdata = plist->cur->data;     // cur이 (왼쪽방향으로) 가리키는 노드의 데이터 반환
    return TRUE;                   // 반환 성공
}

int LCount(List *plist)
{
    return plist->numOfData;
}