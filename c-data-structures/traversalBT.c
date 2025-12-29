//
//  traversalBT.c
//  c-data-structures
//
//  Created by 하림 on 12/29/25.
//
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// 구조체 정의
typedef char element;
typedef struct treeNode {
    element data;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

// 함수의 원형 선언
treeNode* makeRootNode(element data, treeNode *leftNode, treeNode *rightNode);
void preorder(treeNode *root);
void inorder(treeNode *root);
void postorder(treeNode *root);

int main(void) {
    // (A*B-C/D) 수식 이진 트리 만들기
    treeNode *N7 = makeRootNode('D', NULL, NULL);
    treeNode *N6 = makeRootNode('C', NULL, NULL);
    treeNode *N5 = makeRootNode('B', NULL, NULL);
    treeNode *N4 = makeRootNode('A', NULL, NULL);
    treeNode *N3 = makeRootNode('/', N6, N7);
    treeNode *N2 = makeRootNode('*', N4, N5);
    treeNode *N1 = makeRootNode('-', N2, N3);
    
    printf("preorder : ");
    preorder(N1);
    printf("\n");
    
    printf("inorder : ");
    inorder(N1);
    printf("\n");
    
    printf("postorder : ");
    postorder(N1);
    printf("\n");

    return 0;
}

// data를 루트 노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeNode* makeRootNode(element data, treeNode *leftNode, treeNode *rightNode) {
    treeNode *root = (treeNode*)malloc(sizeof(treeNode));
    root->data = data;
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

// 이진 트리에 대한 전위 순회 연산 (D-L-R)
void preorder(treeNode *root) {
    if (root) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 이진 트리에 대한 중위 순환 연산 (L-D-R)
void inorder(treeNode *root) {
    if (root) {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

// 이진 트리에 대한 후위 순환 연산 (L-R-D)
void postorder(treeNode *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}
