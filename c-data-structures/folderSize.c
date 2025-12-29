//
//  folderSize.c
//  c-data-structures
//
//  Created by 하림 on 12/29/25.
//

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int folderSize;
typedef struct treeNode {
    int size;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

treeNode *makeRootNode(int size, treeNode *leftNode, treeNode *rightNode);
int postorder_size(treeNode *root);

int main(void) {
    treeNode *F11 = makeRootNode(120, NULL, NULL);
    treeNode *F10 = makeRootNode(55, NULL, NULL);
    treeNode *F9 = makeRootNode(100, NULL, NULL);
    treeNode *F8 = makeRootNode(200, NULL, NULL);
    treeNode *F7 = makeRootNode(68, F10, F11);
    treeNode *F6 = makeRootNode(40, NULL, NULL);
    treeNode *F5 = makeRootNode(15, NULL, NULL);
    treeNode *F4 = makeRootNode(2, F8, F9);
    treeNode *F3 = makeRootNode(10, F6, F7);
    treeNode *F2 = makeRootNode(0, F4, F5);
    treeNode *F1 = makeRootNode(0, F2, F3);
    
    folderSize = 0;
    printf("C:\\의 용량 : %dM\n", postorder_size(F2));
    
    folderSize = 0;
    printf("D:\\의 용량 : %dM\n", postorder_size(F3));
    
    folderSize = 0;
    printf("내 컴퓨터의 전체 용량 : %dM\n", postorder_size(F1));
    
    return 0;
}

// size를 루트 노드의 데이터 필드로 하여 왼쪽과 오른쪽 서브 트리를 연결하는 연산
treeNode *makeRootNode(int size, treeNode *leftNode, treeNode *rightNode) {
    treeNode *root = (treeNode*)malloc(sizeof(treeNode));
    root->size = size;
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

// 각 폴더 크기를 계산하기 위한 후위 순회 연산
int postorder_size(treeNode *root) {
    if (root) {
        postorder_size(root->left);
        postorder_size(root->right);
        folderSize += root->size;
    }
    return folderSize;
}



