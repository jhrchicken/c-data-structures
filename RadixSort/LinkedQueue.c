#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// 공백 연결 큐를 생성하는 연산
LQueueType *createLinkedQueue(void) {
    LQueueType *LQ;
    LQ = (LQueueType*)malloc(sizeof(LQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

// 연결 큐가 공백 상태인지 확인하는 연산
int isLQEmpty(LQueueType *LQ) {
    if (LQ->front == NULL) {
        return 0;
    }
    else return 1;
}

// 연결 큐의 rear에 원소를 삽입하는 연산
void enLQueue(LQueueType *LQ, element item) {
    QNode *newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;
    
    // 현재 연결 큐가 공백 상태인 경우
    if (LQ->front == NULL) {
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    // 현재 연결 큐가 공백 상태가 아닌 경우
    else {
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}

// 연결 큐에서 원소를 삭제하고 반환하는 연산
element deLQueue(LQueueType *LQ) {
    QNode *oldNode = LQ->front;
    element item;
    
    if (isLQEmpty(LQ) == 0) {
        return 0;
    }
    else {
        item = oldNode->data;
        LQ->front = LQ->front->link;
        if (LQ->front == NULL) {
            LQ->rear = NULL;
        }
        free(oldNode);
        return item;
    }
}

// 연결 큐에서 원소를 검색하는 연산
element peekLQ(LQueueType *LQ) {
    element item;
    
    if (isLQEmpty(LQ) == 0) {
        return 0;
    }
    else {
        item = LQ->front->data;
        return item;
    }
}

// 연결 큐의 원소를 출력하는 연산
void printLQ(LQueueType *LQ) {
    QNode *temp = LQ->front;
    printf("Linked Queue : [");
    while (temp) {
        printf("%3d", temp->data);
        temp = temp->link;
    }
    printf("]");
}
