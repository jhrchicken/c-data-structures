//
//  main.c
//  c-data-structures
//
//  Created by 하림 on 12/11/25.
//

#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

#define STACK_SIZE 5

typedef int element;
element stack[STACK_SIZE];

// 함수의 원형선언
int isStackEmpty(void);
int isStackFull(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);

int top = -1;

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
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

// 스택이 포화 상태인지 확인하는 연산
int isStackFull(void) {
    if (top == STACK_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
    if (isStackFull()) {
        printf("STACK IS FULL!\n");
        return;
    }
    else {
        stack[++top] = item;
    }
}

// 스택의 top에서 원소를 삭제하는 연산
element pop(void) {
    if (isStackEmpty()) {
        printf("STACK IS EMPTY!\n");
        return 0;
    }
    else {
        return stack[top--];
    }
}

// 스택의 top 원소를 검색하는 연산
element peek(void) {
    if (isStackEmpty()) {
        printf("STACK IS EMPTY!\n");
        return 0;
    }
    else {
        return stack[top];
    }
}

// 스택의 원소를 출력하는 연산
void printStack(void) {
    int i;
    printf("STACK : [ ");
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("]\n\n");
}
