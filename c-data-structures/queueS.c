//
//  queueS.c
//  c-data-structures
//
//  Created by 하림 on 12/15/25.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define Q_SIZE 4

typedef char element;

typedef struct {
    element queue[Q_SIZE];
    int front;
    int rear;
} QueueType;

QueueType *createQueue(void);
int isQueueEmpty(QueueType* Q);
int isQueueFull(QueueType *Q);
void enQueue(QueueType *Q, element item);
element deQueue(QueueType *Q);
element peekQ(QueueType *Q);
void printQ(QueueType *Q);

int main(void) {
    char command[7];
    QueueType *Q = createQueue();
    element item;
    
    while(1) {
        printf("명령 : ");
        scanf("%s", command);
        
        if (strcmp(command, "ENQUEUE") == 0) {
            printf("문자 : ");
            getchar();
            scanf("%c", &item);
            enQueue(Q, item);
        }
        else if (strcmp(command, "DEQUEUE") == 0) {
            printf("DEQUEUE : %c\n", deQueue(Q));
        }
        else if (strcmp(command, "PEEK") == 0) {
            printf("PEEK : %c\n", peekQ(Q));
        }
        else if (strcmp(command, "EXIT") == 0) {
            return 0;
        }
        
        printQ(Q);
    }
    
    return 0;
}

// 공백 순차 큐를 생성하는 연산
QueueType *createQueue(void) {
    QueueType *Q = (QueueType*)malloc(sizeof(QueueType));
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

// 순차 큐가 공백 상태인지 검사하는 연산
int isQueueEmpty(QueueType* Q) {
    if (Q->front == Q->rear) {
        printf("QUEUE IS EMPTY!\n");
        return 1;
    }
    else {
        return 0;
    }
}

// 순차 큐가 포화 상태인지 검사하는 연산
int isQueueFull(QueueType *Q) {
    if (Q->rear == Q_SIZE - 1) {
        printf("QUEUE IS FULL\n");
        return 1;
    }
    else {
        return 0;
    }
}

// 순차 큐의 rear에 원소를 삽입하는 연산
void enQueue(QueueType *Q, element item) {
    if (isQueueFull(Q)) {
        return;
    }
    else {
        Q->rear++;
        Q->queue[Q->rear] = item;
    }
}

// 순차 큐의 front에서 원소를 삭제하는 연산
element deQueue(QueueType *Q) {
    if (isQueueEmpty(Q)) {
        return 0;
    }
    else {
        Q->front++;
        return Q->queue[Q->front];
    }
}

// 순차 큐의 가장 앞에 있는 원소를 검색하는 연산
element peekQ(QueueType *Q) {
    if (isQueueEmpty(Q)) {
        return 0;
    }
    else {
        return Q->queue[Q->front + 1];
    }
}

// 순차 큐의 원소를 출력하는 연산
void printQ(QueueType *Q) {
    int i;
    printf("Queue : [ ");
    for (i = Q->front + 1; i <= Q->rear; i++) {
        printf("%c ", Q->queue[i]);
    }
    printf("]\n\n");
}
