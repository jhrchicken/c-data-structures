//
//  shellSort.c
//  c-data-structures
//
//  Created by 하림 on 2/7/26.
//

#include <stdio.h>
#pragma  warning(disable:4996)

void intervalSort(int a[], int begin, int end, int interval);
void shellSort(int a[], int size);

int main(void) {
    int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    int size = sizeof(list) / sizeof(list[0]);
    
    // 정렬 전의 원소 출력
    printf("정렬할 원소 : ");
    for (i = 0; i < size; i++) {
        printf("%3d ", list[i]);
    }
    printf("\n");
    
    // 셀정렬 함수 호출
    shellSort(list, size);
    
    return 0;
}

void intervalSort(int a[], int begin, int end, int interval) {
    int i, j, item;
    for (i = begin + interval; i <= end; i = i + interval) {
        item = a[i];
        for (j = i - interval; j >= begin && item < a[j]; j = j - interval) {
            a[j + interval] = a[j];
        }
        a[j + interval] = item;
    }
}

void shellSort(int a[], int size) {
    int i, interval;
    interval = size / 2;
    while(interval >= 1) {
        for (i = 0; i < interval; i++) {
            intervalSort(a, i, size - 1, interval);
        }
        printf("\ninterval=%d >> ", interval);
        
        for (i = 0; i < size; i++) {
            printf("%d ", a[i]);
        }
        
        interval = interval / 2;
    }
}
