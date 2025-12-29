//
//  stackL.c
//  c-data-structures
//
//  Created by 하림 on 12/11/25.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef int element;

typedef struct stackNode {
    element data;
    struct stackNode *link;
} stackNode;

stackNode *top;

// 함수의 원형 선언
int isStackEmpty(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);

int main(void) {
    char command[5];
    element item;
    
    while(1) {
        printf("명령 : ");
        scanf("%s", command);
        
        if (strcmp(command, "PUSH") == 0) {
            printf("정수 : ");
            scanf("%d", &item);
            push(item);
        }
        else if (strcmp(command, "POP") == 0) {
            printf("POP : %d\n", pop());
        }
        else if (strcmp(command, "PEEK") == 0) {
            printf("PEEK : %d\n", peek());
        }
        else if (strcmp(command, "EXIT") == 0) {
            return 0;
        }
        
        printStack();
    }
    
    return 0;
}

// 스택이 공백 상태인지 확인하는 연산
int isStackEmpty(void) {
    if (top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// 스택의 top에 원소를 삽입하는 언산
void push(element item) {
    stackNode *tmp = (stackNode*)malloc(sizeof(stackNode));
    
    tmp->data = item;
    tmp->link = top;
    top = tmp;
}

// 스택의 top에서 원소를 삭제하는 연산
element pop(void) {
    element item;
    stackNode *tmp = top;
    
    if (isStackEmpty()) {
        printf("STACK IS EMPTY!\n");
        return 0;
    }
    else {
        item = tmp->data;
        top = tmp->link;
        free(tmp);
        return item;
    }
}

// 스택의 top 원소를 검색하는 연산
element peek(void) {
    if (isStackEmpty()) {
        printf("STACK IS EMPTY!\n");
        return 0;
    }
    else {
        return (top->data);
    }
}

// 스택의 원소를 top에서 bottom 순서로 출력하는 연산
void printStack(void) {
    stackNode *p = top;
    printf("STACK : [ ");
    while(p) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("]\n\n");
}
