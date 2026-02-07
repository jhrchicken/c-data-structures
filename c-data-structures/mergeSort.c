//
//  mergeSort.c
//  c-data-structures
//
//  Created by 하림 on 2/7/26.
//

#include <stdio.h>
#pragma warning(disable:4996)
#define MAX 30
int size;
int sorted[MAX];

void merge(int a[], int m, int middle, int n);
void mergeSort(int a[], int m, int n);

int main(void) {
    int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    size = sizeof(list) / sizeof(list[0]);
    
    // 정렬 전의 원소 출력
    printf("정렬할 원소 >> ");
    for (i = 0; i < size; i++) {
        printf("%3d ", list[i]);
    }
    printf("\n\n");
    
    // 병합정렬 함수 호출
    mergeSort(list, 0, size - 1);
    
    return 0;
}

void merge(int a[], int m, int middle, int n) {
    int i, j, k, t;
    i = m;
    j = middle + 1;
    k = m;
    
    // 작은 값을 먼저 넣기
    while (i <= middle && j <= n) {
        if (a[i] <= a[j]) {
            sorted[k++] = a[i++];
        }
        else {
            sorted[k++] = a[j++];
        }
    }
    
    // 왼쪽 배열 다쓴 경우
    if (i > middle) {
        for (t = j; t <= n; t++, k++) {
            sorted[k] = a[t];
        }
    }
    // 오른쪽 배열 다쓴 경우
    else {
        for (t = i; t <= middle; t++, k++) {
            sorted[k] = a[t];
        }
    }
    
    // 임시 배열 sorted를 원본 배열로 복사
    for (t = m; t <= n; t++) {
        a[t] = sorted[t];
    }
    
    // 출력
    for (t = 0; t < size; t++) {
        printf("%4d ", a[t]);
    }
    printf("\n");
}

void mergeSort(int a[], int m, int n) {
    int middle;
    if (m < n) {
        middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}
