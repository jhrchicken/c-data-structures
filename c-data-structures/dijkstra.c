//
//  dijkstra.c
//  c-data-structures
//
//  Created by 하림 on 1/28/26.
//

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#define TRUE 1
#define FALSE 0
#define INF 10000
#define MAX_VERTICES 5

int distance[MAX_VERTICES];
int S[MAX_VERTICES];

// 그래프 G11의 가중치 인접 행렬
int weight[MAX_VERTICES][MAX_VERTICES] = {
    { 0, 10, 5, INF, INF },
    { INF, 0, 2, 1, INF },
    { INF, 3, 0, 9, 2 },
    { INF, INF, INF, 0, 4 },
    { 7, INF, INF, 6, 0 }
};

int nextVertex(int n);
int printStep(int step);
void Dijkstra_shortestPath(int start, int n);

int main(void) {
    int i, j;
    extern int weight[MAX_VERTICES][MAX_VERTICES];
    
    printf("가중치 인접 행렬\n");
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            if (weight[i][j] == INF) {
                printf("%3c", '*');
            }
            else {
                printf("%3d", weight[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
    
    printf("다익스트라 최단 경로 구하기");
    Dijkstra_shortestPath(0, MAX_VERTICES);
    
    return 0;
}

// 최소 거리를 갖는 다음 정점을 찾는 연산
int nextVertex(int n) {
    int i, min, minPos;
    min = INF;
    minPos = -1;
    for (i = 0; i < n; i++) {
        if ((distance[i] < min) && !S[i]) {
            min = distance[i];
            minPos = i;
        }
    }
    return minPos;
}

// 최단 경로를 구하는 과정을 출력하는 연산
int printStep(int step) {
    int i;
    printf("\n[%d단계]\nS={", step);
    for (i = 0; i < MAX_VERTICES; i++) {
        if (S[i] == TRUE) {
            printf("%c", i + 65);
        }
    }
    printf("}\n");
    
    printf("distance : [ ");
    for (i = 0; i < MAX_VERTICES; i++) {
        if (distance[i] == INF) {
            printf("%c ", '*');
        }
        else {
            printf("%d ", distance[i]);
        }
    }
    printf("%c\n", ']');
    return ++step;
}

void Dijkstra_shortestPath(int start, int n) {
    int i, u, w, step = 0;
    
    // 초기화
    for (i = 0; i < n; i++) {
        distance[i] = weight[start][i];
        S[i] = FALSE;
    }
    
    // 시작 정점
    S[start] = TRUE;
    distance[start] = 0;
    
    step = printStep(0);
    
    for (i = 0; i < n - 1; i++) {
        u = nextVertex(n);
        S[u] = TRUE;
        for (w = 0; w < n; w++) {
            if (!S[w]) {
                if (distance[u] + weight[u][w] < distance[w]) {
                    distance[w] = distance[u] + weight[u][w];
                }
            }
        }
        step = printStep(step);
    }
}
