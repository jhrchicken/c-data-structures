//
//  insertionSort.c
//  c-data-structures
//
//  Created by 하림 on 2/7/26.
//

#include <stdio.h>
#pragma warning(disable:4996)

void insertSort(int a[], int size);

int main(void) {
    int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    int size = sizeof(list) / sizeof(list[0]);
    
    // 정렬 전의 원소 출력
    printf("정렬할 원소 : ");
    for (i = 0; i < size; i++) {
        printf("%3d ", list[i]);
    }
    printf("\n");
    
    // 삽입정렬 함수 호출
    insertSort(list, size);
    
    return 0;
}

void insertSort(int a[], int size) {
    int i, j, t, temp;
    
    for (i = 0; i < size; i++) {
        temp = a[i];
        j = i;
        while ((j > 0) && (a[j - 1] > temp)) {
            a[j] = a[j - 1];
            j = j - 1;
        }
        a[j] = temp;
        
        printf("\n%d단계 : ", i);
        for (t = 0; t < size; t++) {
            printf("%3d ", a[t]);
        }
    }
}
