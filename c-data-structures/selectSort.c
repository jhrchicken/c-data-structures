//
//  selectSort.c
//  c-data-structures
//
//  Created by 하림 on 2/5/26.
//

#include <stdio.h>

void selectionSort(int a[], int size);

int main(void) {
    int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    int size = sizeof(list) / sizeof(list[0]);
    
    // 정렬 전의 원소 출력
    printf("\n정렬할 원소 : ");
    for (i = 0; i < size; i++) {
        printf("%3d ", list[i]);
    }
    
    // 선택 정렬 함수 호출
    selectionSort(list, size);
    
    return 0;
}

void selectionSort(int a[], int size) {
    int i, j, t, min, temp;
    
    for (i = 0;  i < size; i++) {
        min = i;
        for (j = 0; j < size; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        
        printf("\n%d단계 : ", i + 1);
        for (t = 0; t < size; t++) {
            printf("%3d ", a[t]);
        }
    }
}
