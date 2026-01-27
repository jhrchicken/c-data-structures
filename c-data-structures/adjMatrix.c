//
//  adjMatrix.c
//  c-data-structures
//
//  Created by 하림 on 1/27/26.
//

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX_VERTEX 30

// 그래프를 인접 행렬로 표현하기 위한 구조체 정의
typedef struct graphType {
    int n;
    int adxMatrix[MAX_VERTEX][MAX_VERTEX];
} graphType;

void createGraph(graphType *g);
void insertVertex(graphType *g, int v);
void insertEdge(graphType *g, int u, int v);
void printAdjMatrix(graphType *g);

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
    
    // 인접 행렬 출력
    printf("\nG1의 인접 행렬\n");
    printAdjMatrix(G1);
    
    printf("\nG2의 인접 행렬\n");
    printAdjMatrix(G2);
    
    printf("\nG3의 인접 행렬\n");
    printAdjMatrix(G3);
    
    printf("\nG4의 인접 행렬\n");
    printAdjMatrix(G4);
    
    return 0;
}

// 공백 그래프를 생성하는 연산
void createGraph(graphType *g) {
    int i, j;
    g->n = 0;
    for (i = 0; i < MAX_VERTEX; i++) {
        for (j = 0; j < MAX_VERTEX; j++) {
            g->adxMatrix[i][j] = 0;
        }
    }
}

// 그래프 g에 정점 v를 삽입하는 연산
void insertVertex(graphType *g, int v) {
    
    // 그래프 정점 개수 초과
    if (((g->n) + 1) > MAX_VERTEX) {
        printf("그래프 정점의 개수를 초과했습니다!");
        return;
    }
    
    // 이미 존재하는 정점
    if (v < (g->n)) {
        return;
    }

    g->n++;
}


// 그래프 g에 간선 (u, v)를 삽입하는 연산
void insertEdge(graphType *g, int u, int v) {
    
    // 정점 u와 v가 그래프에 존재하는지 확인
    if (u >= g->n || v >= g->n) {
        printf("그래프에 없는 정점입니다!");
        return;
    }
    
    g->adxMatrix[u][v] = 1;
}

// 그래프 g의 2차원 배열값을 순서대로 출력하는 연산
void printAdjMatrix(graphType *g) {
    int i, j;
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            printf("%d ", g->adxMatrix[i][j]);
        }
        printf("\n");
    }
}
