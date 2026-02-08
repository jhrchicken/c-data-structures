#include <stdio.h>
#include "bst.h"

// 트리 정렬 연산
void treeSort(int a[], int n) {
    treeNode *root = NULL;
    root = insertBSTNode(root, a[0]);
    
    for (int i = 1; i < n; i++) {
        insertBSTNode(root, a[i]);
    }
    displayInorder(root);
}
