//
//  bst.c
//  c-data-structures
//
//  Created by 하림 on 12/29/25.
//

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

// 구조체 정의
typedef char element;
typedef struct treeNode {
    element key;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

// 함수의 원형 선언
void displayInorder(treeNode *root);
treeNode *searchBST(treeNode *root, element x);
treeNode *insertBSTNode(treeNode *p, element x);
void deleteBSTNode(treeNode *root, element key);
void menu(void);

int main(void) {
    treeNode *root = NULL;
    treeNode *foundedNode = NULL;
    char choice, key;
    
    root = insertBSTNode(root, 'G');
    insertBSTNode(root, 'H');
    insertBSTNode(root, 'D');
    insertBSTNode(root, 'B');
    insertBSTNode(root, 'M');
    insertBSTNode(root, 'N');
    insertBSTNode(root, 'A');
    insertBSTNode(root, 'J');
    insertBSTNode(root, 'E');
    insertBSTNode(root, 'Q');
    
    while (1) {
        menu();
        scanf(" %c", &choice);
        
        switch (choice - '0') {
            case 1:
                printf("[이진트리 출력] " );
                displayInorder(root);
                printf("\n\n");
                break;
            case 2:
                printf("삽입할 문자를 입력하세요 : ");
                scanf(" %c", &key);
                insertBSTNode(root, key);
                printf("\n");
                break;
            case 3:
                printf("삭제할 문자를 입력하세요 : ");
                scanf(" %c", &key);
                deleteBSTNode(root, key);
                printf("\n");
                break;
            case 4:
                printf("찾을 문자를 입력하세요 : ");
                scanf(" %c", &key);
                foundedNode = searchBST(root, key);
                if (foundedNode != NULL)
                    printf("%c 문자를 찾았습니다!", foundedNode->key);
                else {
                    printf("문자를 찾지 못했습니다!");
                }
                printf("\n\n");
                break;
            case 5:
                return 0;
            default:
                printf("없는 메뉴입니다. 메뉴를 다시 선택하세요!\n\n");
                break;
        }
    }

    return 0;
}

void menu(void) {
    printf("1. 트리 출력\n");
    printf("2. 문자 삽입\n");
    printf("3. 문자 삭제\n");
    printf("4. 문자 검색\n");
    printf("5. 종료\n");
    printf("메뉴 입력 >> ");
}

// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder(treeNode *root) {
    if (root) {
        displayInorder(root->left);
        printf("%c_", root->key);
        displayInorder(root->right);
    }
}

// 이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
treeNode *searchBST(treeNode *root, element x) {
    treeNode *p;
    p = root;
    while (p != NULL) {
        if (x < p->key) p = p->left;
        else if (x == p->key) return p;
        else p = p->right;
    }
    printf("찾는 키가 없습니다!\n");
    return p;
}

// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode *insertBSTNode(treeNode *p, element x) {
    treeNode *newNode;
    if (p == NULL) {
        newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode->key = x;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if (x < p->key) {
        p->left = insertBSTNode(p->left, x);
    }
    else if (x > p->key) {
        p->right = insertBSTNode(p->right, x);
    }
    else {
        printf("이미 같은 키가 있습니다!\n");
    }
    
    return p;
}

// 루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
void deleteBSTNode(treeNode *root, element key) {
    treeNode *parent, *p, *succ, *succ_parent;
    treeNode *child;
    
    // 삭제할 노드의 위치 탐색
    parent = NULL;
    p = root;
    while ((p != NULL) && (p->key != key)) {
        parent = p;
        if (key < p->key) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
    
    // 삭제할 노드가 없는 경우
    if (p == NULL) {
        printf("찾는 키가 이진 트리에 없습니다!\n");
        return;
    }
    
    // 삭제할 노드가 단말 노드인 경우
    if ((p->left == NULL) && (p->right == NULL)) {
        if (parent != NULL) {
            if (parent -> left == p) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
        }
        else root = NULL;
    }
    
    // 삭제할 노드가 자식 노드를 한 개 가진 경우
    else if ((p->left == NULL) || (p->right == NULL)) {
        if (p->left != NULL) {
            child = p->left;
        }
        else {
            child = p->right;
        }
        
        if (parent != NULL) {
            if (parent->left == p) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
        else root = child;
    }
    
    // 삭제할 노드가 자식 노드 두 개 가진 경우
    else {
        succ_parent = p;
        succ = p->left;
        while (succ->right != NULL) {
            succ_parent = succ;
            succ = succ->right;
        }
        if (succ_parent->left == succ) {
            succ_parent->left = succ->left;
        }
        else {
            succ_parent->right = succ->left;
        }
        p->key = succ->key;
        p = succ;
    }
    free(p);
}
