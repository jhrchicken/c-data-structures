#include <stdio.h>

void radixSort(int a[], int n);

int main(void) {
    int i, list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    int size = sizeof(list) / sizeof(list[0]);
    
    // 정렬 전의 원소 출력
    printf("\n정렬할 원소 : ");
    for (i = 0; i < size; i++) {
        printf("%3d", list[i]);
    }
    printf("\n\n");
    
    // 기수 정렬 수행
    radixSort(list, size);
    
    return 0;
}
