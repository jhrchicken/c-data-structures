//
//  DFS.c
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

// 인접 리스트의 노드 구조를 구조체로 정의
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

typedef int element;

typedef struct stackNode {
    element data;
    struct stackNode *link;
} stackNode;

stackNode *top;

int isStackEmpty(void);
void push(element item);
element pop(void);
void createGraph(graphType *g);
void insertVertex(graphType *g, int v);
void insertEdge(graphType *g, int u, int v);
void printAdjList(graphType *g);
void DFS_adjList(graphType *g, int v);

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
    DFS_adjList(G9, 0);
    printf("\n");
    
    return 0;
}

// 스택이 공백 상태인지 확인하는 연산
int isStackEmpty(void) {
    if (top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// 스택의 top에 원소를 삽입하는 언산
void push(element item) {
    stackNode *tmp = (stackNode*)malloc(sizeof(stackNode));
    
    tmp->data = item;
    tmp->link = top;
    top = tmp;
}

// 스택의 top에서 원소를 삭제하는 연산
element pop(void) {
    element item;
    stackNode *tmp = top;
    
    if (isStackEmpty()) {
        printf("STACK IS EMPTY!\n");
        return 0;
    }
    else {
        item = tmp->data;
        top = tmp->link;
        free(tmp);
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

// 그래프 g에서 정점 v에 대한 깊이 우선 탐색 연산
void DFS_adjList(graphType *g, int v) {
    graphNode *w;
    top = NULL;
    push(v);
    g->visited[v] = TRUE;
    printf(" %c", v + 65);
    
    // 스택이 공백이 아닌 동안 깊이 우선 탐색
    while (!isStackEmpty()) {
        w = g->adjList_H[v];
        // 인접 정점이 있는 동안 수행
        while(w) {
            // 현재 정점 w를 방문하지 않은 경우
            if (!g->visited[w->vertex]) {
                push(w->vertex);
                g->visited[w->vertex] = TRUE;
                printf(" %c", w->vertex + 65);
                v = w->vertex;
                w = g->adjList_H[v];
            }
            // 현재 정점 w가 이미 방문된 경우
            else {
                w = w->link;
            }
        }
        // 현재 정점에서 순회를 진행할 인접 정점이 더 없는 경우에 스택 pop
        v = pop();
    }
}
