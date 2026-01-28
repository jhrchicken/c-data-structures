//
//  floyd.c
//  c-data-structures
//
//  Created by 하림 on 1/28/26.
//

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#define INF 10000
#define MAX_VERTICES 5

int A[MAX_VERTICES][MAX_VERTICES];

// 그래프 G11의 가중치 인접 행렬
int weight[MAX_VERTICES][MAX_VERTICES] = {
    { 0, 10, 5, INF, INF },
    { INF, 0, 2, 1, INF },
    { INF, 3, 0, 9, 2 },
    { INF, INF, INF, 0, 4 },
    { 7, INF, INF, 6, 0 }
};

void printStep(int step);
void Folyd_shortestPath(int n);

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
    
    printf("플로이드 최단 경로 구하기");
    Folyd_shortestPath(MAX_VERTICES);
    
    return 0;
}

// 최단 경로를 구하는 과정을 출력하는 연산
void printStep(int step) {
    int i, j;
    printf("\n[A%d]\n", step);
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            if (A[i][j] == INF) {
                printf("%3c ", '*');
            }
            else {
                printf("%3d ", A[i][j]);
            }
        }
        printf("\n\n");
    }
}

void Folyd_shortestPath(int n) {
    int v, w, k, step = -1;
    
    // 초기화
    for (v = 0; v < n; v++) {
        for (w = 0; w < n; w++) {
            A[v][w] = weight[v][w];
        }
    }
    
    printStep(step);
    
    for (k = 0; k < n; k++) {
        for (v = 0; v < n; v++) {
            for (w = 0; w < n; w++) {
                if (A[v][k] + A[k][w] < A[v][w]) {
                    A[v][w] = A[v][k] + A[k][w];
                }
            }
        }
        printStep(++step);
    }
}
