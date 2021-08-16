//
//  main.cpp
//  树基础
//
//  Created by mk on 2021/8/16.
//

#include <iostream>
using namespace::std;
typedef int ElementType;
typedef struct Node *BTNode;
typedef struct SNode *Stack;
#define MAXSIZE 20
struct Node {
    ElementType val;
    BTNode left;
    BTNode right;
};
struct SNode {
    ElementType data[MAXSIZE];
    int top;
    int size;
};

Stack initializer_stack() {
    Stack s = (Stack)malloc(sizeof(struct SNode));
    s->size = 0;
    s->top = -1;
    return s;
}

void push(Stack s, ElementType x) {
    if (s->top == MAXSIZE - 1)
        return;
    s->data[++s->top] = x;
    s->size++;
}

void pop(Stack s) {
    if (s->top == -1)
        return;
    s->top--;
    s->size--;
}

ElementType top(Stack s) {
    return s->data[s->top];
}

int size(Stack s) {
    return s->size;
}

Stack copy(Stack s) {
    Stack mirror = (Stack)malloc(sizeof(struct SNode));
    mirror->top = -1;
    mirror->size = 0;
    for (int i = 0; i <= s->top ; i++) {
        push(mirror, s->data[i]);
    }
    mirror->top = s->top;
    mirror->size = s->size;
    return mirror;
}

BTNode create() {
    BTNode T = (BTNode)malloc(sizeof(struct Node));
    T->val = 1;
    T->left = (BTNode)malloc(sizeof(struct Node));
    T->left->val = 2;
    T->right = (BTNode)malloc(sizeof(struct Node));
    T->right->val = 5;
    T->right->left = NULL;
    T->right->right = NULL;
    T->left->left = (BTNode)malloc(sizeof(struct Node));
    T->left->left->val = 3;
    T->left->left->left = NULL;
    T->left->left->right = NULL;
    T->left->right = (BTNode)malloc(sizeof(struct Node));
    T->left->right->val = 4;
    T->left->right->left = NULL;
    T->left->right->right = NULL;
    return T;
}

void PrintAllPath(BTNode p, Stack s) {
    if (p != NULL) {
        push(s, p->val);
        if (p->left == NULL && p->right == NULL) {
            Stack mirror = copy(s);
            for (int i = 0; i < size(mirror); i++) {
                printf("-->%d",top(mirror));
                pop(mirror);
            }
            printf("\n");
            pop(s);
        }
        PrintAllPath(p->left, s);
        PrintAllPath(p->right, s);
    }
    
}

int main(int argc, const char * argv[]) {
    BTNode T = create();
    Stack s, mirror;
    s = initializer_stack();
    mirror = initializer_stack();
    
    PrintAllPath(T, s);
    return 0;
}
