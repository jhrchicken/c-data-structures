#pragma once
typedef int element;

typedef struct treeNode {
    element key;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

void displayInorder(treeNode *root);
