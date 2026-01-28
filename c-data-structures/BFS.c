//
//  BFS.c
//  c-data-structures
//
//  Created by 하림 on 1/28/26.
//

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX_VERTEX 30
#define FALSE 0
#define TRUE 1

typedef int element;

typedef struct QNode {
    element data;
    struct QNode *link;
} QNode;

typedef struct {
    QNode *front, *rear;
} LQueueType;

// 인접 리스트의 노드 구조를 구조체로 정의ㅣ
typedef struct graphNode {
    int vertex;
    struct graphNode *link;
} graphNode;

// 그래프를 인접 리스트로 표현하기 위한 구조체 정의
typedef struct graphType {
    int n;
    graphNode *adjList_H[MAX_VERTEX];
    int visited[MAX_VERTEX];
} graphType;

LQueueType *createLinkedQueue(void);
int isLQEmpty(LQueueType *LQ);
void enLQueue(LQueueType *LQ, element item);
element deLQueue(LQueueType *LQ);
void createGraph(graphType *g);
void insertVertex(graphType *g, int v);
void insertEdge(graphType *g, int u, int v);
void printAdjList(graphType *g);
void BFS_adjList(graphType *g, int v);

int main(void) {
    int i;
    graphType *G9;
    G9 = (graphType *)malloc(sizeof(graphType));
    createGraph(G9);
    
    for (i = 0; i < 7; i++) {
        insertVertex(G9, i);
    }
    insertEdge(G9, 0, 2);
    insertEdge(G9, 0, 1);
    insertEdge(G9, 1, 4);
    insertEdge(G9, 1, 3);
    insertEdge(G9, 1, 0);
    insertEdge(G9, 2, 4);
    insertEdge(G9, 2, 0);
    insertEdge(G9, 3, 6);
    insertEdge(G9, 3, 1);
    insertEdge(G9, 4, 6);
    insertEdge(G9, 4, 2);
    insertEdge(G9, 4, 1);
    insertEdge(G9, 5, 6);
    insertEdge(G9, 6, 5);
    insertEdge(G9, 6, 4);
    insertEdge(G9, 6, 3);
    
    printf("G9의 인접 리스트\n");
    printAdjList(G9);
    printf("\n");
    
    printf("깊이 우선 탐색 >> ");
    BFS_adjList(G9, 0);
    printf("\n");
    
    return 0;
}

// 공백 연결 큐를 생성하는 연산
LQueueType *createLinkedQueue(void) {
    LQueueType *LQ;
    LQ = (LQueueType*)malloc(sizeof(LQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

// 연결 큐가 공백 상태인지 검사하는 연산
int isLQEmpty(LQueueType *LQ) {
    if (LQ->front == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void enLQueue(LQueueType *LQ, element item) {
    QNode *newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;
    // 현재 큐가 공백 상태인 경우
    if (LQ->front == NULL) {
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    // 현재 큐가 공백 상태가 아닌 경우
    else {
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}

// 연결 큐에서 원소를 삭제하고 반환하는 연산
element deLQueue(LQueueType *LQ) {
    QNode *old = LQ->front;
    element item;
    if (isLQEmpty(LQ)) {
        return 0;
    }
    else {
        item = old->data;
        LQ->front = LQ->front->link;
        if (LQ->front == NULL) {
            LQ->rear = NULL;
        }
        free(old);
        return item;
    }
}

// 공백 그래프를 생성하는 연산
void createGraph(graphType *g) {
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTEX; v++) {
        g->adjList_H[v] = NULL;
        g->visited[v] = FALSE;
    }
}

// 그래프 g에 정점 v를 삽입하는 연산
void insertVertex(graphType *g, int v) {
    if (((g->n) + 1) > MAX_VERTEX) {
        printf("그래프 정점의 개수를 초과하였습니다!");
        return;
    }
    
    g->n++;
}

// 그래프 g에 간선 (u, v)를 삽입하는 연산
void insertEdge(graphType *g, int u, int v) {
    graphNode *node;
    
    // 간선을 삽입하기 위해 정점 u와 정점 v가 현재 그래프에 있는지 확인
    if (u >= g->n || v >= g->n) {
        printf("그래프에 없는 정점입니다!");
        return;
    }
    
    node = (graphNode *)malloc(sizeof(graphNode));
    node->vertex = v;
    node->link = g->adjList_H[u];
    g->adjList_H[u] = node;
}

// 그래프 g의 각 정점에 대한 인접 리스트를 출력하는 연산
void printAdjList(graphType *g) {
    int i;
    graphNode *p;
    for (i = 0; i < g->n; i++) {
        printf("정점 %c의 인접 리스트", i + 65);
        p = g->adjList_H[i];
        while(p) {
            printf(" -> %c", p->vertex - 0 + 'A');
            p = p->link;
        }
        printf("\n");
    }
}

// 그래프 g에서 정점 v에 대한 너비 우선 탐색 연산
void BFS_adjList(graphType *g, int v) {
    graphNode *w;
    LQueueType *Q;
    Q = createLinkedQueue();
    g->visited[v] = TRUE;
    printf(" %c", v + 65);
    enLQueue(Q, v);
    
    // 큐가 공백인 아닌 동안 너비 우선 탐색 수행
    while (!isLQEmpty(Q)) {
        v = deLQueue(Q);
        // 현재 정점 w를 방문하지 않은 경우
        for (w = g->adjList_H[v]; w; w = w->link) {
            if (!g->visited[w->vertex]) {
                g->visited[w->vertex] = TRUE;
                printf(" %c", w->vertex + 65);
                enLQueue(Q, w->vertex);
            }
        }
    }
}
