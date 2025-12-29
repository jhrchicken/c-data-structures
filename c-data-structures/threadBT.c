//
//  threadBT.c
//  c-data-structures
//
//  Created by 하림 on 12/29/25.
//

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct treeThNode {
    char data;
    struct treeThNode *left;
    struct treeThNode *right;
    int isTreadRight;
} treeThNode;

treeThNode *makeRootThNode(char data, treeThNode *leftNode, treeThNode *rightNode, int isThreadRight);
treeThNode *findThreadSuccessor(treeThNode *p);
void threadInorder(treeThNode *root);

int main(void) {
    treeThNode *N7 = makeRootThNode('D', NULL, NULL, 0);
    treeThNode *N6 = makeRootThNode('C', NULL, NULL, 1);
    treeThNode *N5 = makeRootThNode('B', NULL, NULL, 1);
    treeThNode *N4 = makeRootThNode('A', NULL, NULL, 1);
    treeThNode *N3 = makeRootThNode('/', N6, N7, 0);
    treeThNode *N2 = makeRootThNode('*', N4, N5, 0);
    treeThNode *N1 = makeRootThNode('-', N2, N3, 0);
    
    N4->right = N2;
    N5->right = N1;
    N6->right = N3;
    
    printf("스레드 이진 트리의 중위 순회 : ");
    threadInorder(N1);
    printf("\n");
    
    return 0;
}

// data를 루트 노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeThNode *makeRootThNode(char data, treeThNode *leftNode, treeThNode *rightNode, int isThreadRight) {
    treeThNode *root = (treeThNode*)malloc(sizeof(treeThNode));
    root->data = data;
    root->left = leftNode;
    root->right = rightNode;
    root->isTreadRight = isThreadRight;
    return root;
}

// 후속자 노드를 반환하는 연산
treeThNode *findThreadSuccessor(treeThNode *p) {
    treeThNode *q = p->right;
    if (q == NULL) {
        return q;
    }
    if (p->isTreadRight == 1) {
        return q;
    }
    while (q->left != NULL) {
        q = q->left;
    }
    return q;
}

// 스레드 이진 트리의 중위 순회
void threadInorder(treeThNode *root) {
    treeThNode *q;
    q = root;
    while (q->left) {
        q = q->left;
    }
    
    do {
        printf("%c", q->data);
        q = findThreadSuccessor(q);
    } while (q);
}
