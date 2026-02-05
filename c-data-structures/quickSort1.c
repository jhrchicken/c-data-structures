//
//  quickSort1.c
//  c-data-structures
//
//  Created by 하림 on 2/5/26.
//

#include <stdio.h>
#pragma warning(disable:4996)

int partition(int a[], int begin, int end, int size);
void quickSort(int a[], int begin, int end, int size);

int i = 0;

int main(void) {
    int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    int size = sizeof(list) / sizeof(list[0]);
    
    // 정렬 전의 원소 출력
    printf("[정렬할 원소]\n\t");
    for (i = 0; i < size; i++) {
        printf("%3d ", list[i]);
    }
    printf("\n");
    
    // 퀵정렬 함수 호출
    quickSort(list, 0, size - 1, size);
    
    return 0;
}

int partition(int a[], int begin, int end, int size) {
    int pivot, L, R, t, temp;
    L = begin;
    R = end;
    pivot = (begin + end) / 2;
    printf("\n[ %d단계 : pivot = %d ]\n", ++i, a[pivot]);
    while (L < R) {
        while ((a[L] < a[pivot]) && (L < R)) L++;
        while ((a[R] >= a[pivot]) && (L < R)) R--;
        if (L < R) {
            temp = a[L];
            a[L] = a[R];
            a[R] = temp;
            if (L == pivot) pivot = R;
        }
    }
    temp = a[pivot];
    a[pivot] = a[R];
    a[R] = temp;
    for (t = 0; t < size; t++) {
        printf("%4d", a[t]);
    }
    printf("\n");
    return R;
}

void quickSort(int a[], int begin, int end, int size) {
    int p;
    if (begin < end) {
        p = partition(a, begin, end, size);
        quickSort(a, begin, p - 1, size);
        quickSort(a, p + 1, end, size);
    }
}
