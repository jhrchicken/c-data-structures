#include <stdio.h>
#include "LinkedQueue.h"
#define RADIX 10
#define DIGIT 2

// 배열 a에 있는 n개의 원소에 대해 기수 정렬을 수행하는 연산
void radixSort(int a[], int n) {
    int i, bucket, d, factor = 1;
    
    // 정렬할 자료의 기수, 즉 RADIX에 따라 10개의 버킷을 큐로 생성
    LQueueType *Q[RADIX];
    for (bucket = 0; bucket < RADIX; bucket++) {
        Q[bucket] = createLinkedQueue();
    }
    
    // 키값의 자리수만큼, 즉 두 번 기수 정렬을 반복 수행
    for (d = 0; d < DIGIT; d++) {
        for (i = 0; i < n; i++) {
            enLQueue(Q[(a[i] / factor) % RADIX], a[i]);
        }
        for (bucket = 0, i = 0; bucket < RADIX; bucket++) {
            while(isLQEmpty(Q[bucket]) == 1) {
                a[i++] = deLQueue(Q[bucket]);
            }
        }
        
        printf("%d단계 : ", d + 1);
        for (i = 0; i < n; i++) {
            printf(" %3d", a[i]);
        }
        printf("\n");
        
        factor = factor * RADIX;
    }
}
