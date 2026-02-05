//
//  adjList.c
//  c-data-structures
//
//  Created by 하림 on 1/27/26.
//

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX_VERTEX 30

// 인접 리스트의 노드 구조를 구조체로 정의
typedef struct graphNode {
    int vertex;
    struct graphNode *link;
} graphNode;

// 그래프를 인접 리스트로 표현하기 위한 구조체 정의
typedef struct graphType {
    int n;
    graphNode *adjList_H[MAX_VERTEX];
} graphType;

void createGraph(graphType *g);
void insertVertex(graphType *g, int v);
void insertEdge(graphType *g, int u, int v);
void printAdjList(graphType *g);

int main(void) {
    int i;
    graphType *G1 = (graphType *)malloc(sizeof(graphType));
    graphType *G2 = (graphType *)malloc(sizeof(graphType));
    graphType *G3 = (graphType *)malloc(sizeof(graphType));
    graphType *G4 = (graphType *)malloc(sizeof(graphType));
    
    // G1 구성
    createGraph(G1);
    for (i = 0; i < 4; i++) {
        insertVertex(G1, i);
    }
    insertEdge(G1, 0, 3);
    insertEdge(G1, 0, 1);
    insertEdge(G1, 1, 3);
    insertEdge(G1, 1, 2);
    insertEdge(G1, 1, 0);
    insertEdge(G1, 2, 3);
    insertEdge(G1, 2, 1);
    insertEdge(G1, 3, 2);
    insertEdge(G1, 3, 1);
    insertEdge(G1, 3, 0);
    
    // G2 구성
    createGraph(G2);
    for (i = 0; i < 3; i++) {
        insertVertex(G2, i);
    }
    insertEdge(G2, 0, 2);
    insertEdge(G2, 0, 1);
    insertEdge(G2, 1, 2);
    insertEdge(G2, 1, 0);
    insertEdge(G2, 2, 1);
    insertEdge(G2, 2, 0);
    
    // G3 구성
    createGraph(G3);
    for (i = 0; i < 4; i++) {
        insertVertex(G3, i);
    }
    insertEdge(G3, 0, 3);
    insertEdge(G3, 0, 1);
    insertEdge(G3, 1, 3);
    insertEdge(G3, 1, 2);
    insertEdge(G3, 2, 3);
    
    // G4 구성
    createGraph(G4);
    for (i = 0; i < 3; i++) {
        insertVertex(G4, i);
    }
    insertEdge(G4, 0, 2);
    insertEdge(G4, 0, 1);
    insertEdge(G4, 1, 2);
    insertEdge(G4, 1, 0);
    
    // 인접 리스트 출력
    printf("\nG1의 인접 리스트\n");
    printAdjList(G1);
    
    printf("\nG2의 인접 리스트\n");
    printAdjList(G2);
    
    printf("\nG3의 인접 리스트\n");
    printAdjList(G3);
    
    printf("\nG4의 인접 리스트\n");
    printAdjList(G4);
    
    return 0;
}

// 공백 그래프를 생성하는 연산
void createGraph(graphType *g) {
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTEX; v++) {
        g->adjList_H[v] = NULL;
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
