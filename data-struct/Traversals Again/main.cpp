//
//  main.cpp
//  Traversals Again
//
//  Created by mk on 2021/7/29.
//

#include <iostream>
#include <string.h>
using namespace :: std;
#define MaxSize 40
#define Null -1

typedef struct Node *Stack;
typedef struct TreeNode *Tree;

struct TreeNode {
    int Elem;
    Tree Left;
    Tree Right;
};


struct Node {
    int Data[MaxSize];
    int top;
};

void push(int x, Stack s) {
    if (s->top + 1 != MaxSize) {
        s->Data[++(s->top)] = x;
    }
}

int pop(Stack s) {
    if (s->top == -1)
        return Null;
    return s->Data[s->top--];
}

//根据先序和中序构建后序
Tree BulidTree(int *inOrder, int *preOrder, int p1, int p2, int i1, int i2) {
    Tree t = (Tree)malloc(sizeof(struct TreeNode));
    t->Elem = preOrder[p1];
    t->Left = NULL;
    t->Right = NULL;
    int pos = i1;
    while (inOrder[pos] != preOrder[p1]) {
        pos++;
    }
    int children = pos - i1;
    if (pos > i1)
        t->Left = BulidTree(inOrder, preOrder, p1+1, p1 + children, i1, pos-1);
    if (pos < i2)
        t->Right = BulidTree(inOrder, preOrder,  p1 + children + 1, p2, pos+1, i2);
    return t;
}

void LastOrder(Tree t, int last) {
    if (t) {
        LastOrder(t->Left, last);
        LastOrder(t->Right, last);
        printf("%d",t->Elem);
        if (t->Elem != last)
            printf(" ");
            
    }
}

int main(int argc, const char * argv[]) {
    Stack s = (Stack)malloc(sizeof(struct Node));
    s->top = -1;
    int N, data, pre_index = 0, in_index = 0;
    cin >> N;
    int inOrder[N], preOrder[N];
    string str;
  
    for (int i = 0; i < 2 * N; i++) {
        cin>>str;
        if (str == "Push") {
            cin >> data;
            push(data, s);
            //入栈 先序
            preOrder[pre_index++] = data;
        } else {
            //出栈 中序
            inOrder[in_index++] = pop(s);
        }
    }
    
    Tree t = BulidTree(inOrder, preOrder, 0, N - 1, 0, N - 1);
    LastOrder(t, preOrder[0]);
    
    return 0;
}
