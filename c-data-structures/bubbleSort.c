//
//  bubbleSort.c
//  c-data-structures
//
//  Created by 하림 on 2/5/26.
//

#include <stdio.h>

void bubbleSort(int a[], int size);

int main(void) {
    int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    int size = sizeof(list) / sizeof(list[0]);
    
    // 정렬 전의 원소 출력
    printf("\n정렬할 원소 : ");
    for (i = 0; i < size; i++) {
        printf("%3d ", list[i]);
    }
    
    // 선택 정렬 함수 호출
    bubbleSort(list, size);
    
    return 0;
}

void bubbleSort(int a[], int size) {
    int i, j, t, temp;
    
    for (i = size - 1; i > 0; i++) {
        printf("\n%d단계 >> ", size - i);
        for (j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            
            for (t = 0; t < size; t++) {
                printf("%3d ", a[t]);
            }
        }
    }
}
