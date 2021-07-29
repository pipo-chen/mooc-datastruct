//
//  main.cpp
//  02-线性结构4 Pop Sequence
//
//  Created by mk on 2021/7/23.
//

#include <iostream>
using namespace::std;

typedef int ElemType;
typedef int Position;
const ElemType ERROR = -1;

struct SNode {
    ElemType *Data;
    Position top;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack create(int MaxSize) {
    Stack s = (Stack)malloc(sizeof(struct SNode));
    s->Data = (ElemType *)malloc(MaxSize * sizeof(ElemType));
    s->top = -1;
    s->MaxSize = MaxSize;
    return s;
}

bool isFull(Stack s) {
    return (s->MaxSize - 1 == s->top);
}

bool isEmpty(Stack s) {
    return (-1 == s->top);
}

bool push(Stack s, ElemType e) {
    if (isFull(s)) {
        s->Data[++(s->top)] = e;
    }
    return true;
}

ElemType pop(Stack s) {
    if (isEmpty(s)) {
        return ERROR;
    }
    return s->Data[(s->top)--];
}

int main() {
    int M, N, K;
    scanf("%d %d %d",&M, &N, &K);
    while (K) {
        Stack s = create(M);
        int ptr;
        scanf("%d",&ptr);
        int check = N;
        int start = 1;
        s->Data[s->top] = -1;
        while (check) {
            //栈顶元素和当前输入的元素相等
            if (s->Data[s->top] == ptr) {
                ElemType temp = pop(s);
                start = (ptr >= start ? ptr + 1 : start);
                check--;
                if (check)
                    scanf("%d",&ptr);
            }
            //栈顶元素和当前元素不等
            else if (s->Data[s->top] != ptr) {
                for (int i = start; i <= ptr; i++) {
                    push(s, i);
                }
            }
            //一种情况是栈满了，但是当前值不等于栈顶元素，即再也放不进去了
            if (isFull(s) && ptr != s->Data[s->top])
                break;
            //第二种情况就是栈顶元素比当前值还要大
            if (ptr < s->Data[s->top])
                break;
        }
        for (int i = 1; i < check; i++)
            scanf("%d",&start);
        if (check)
            printf("NO\n");
        else
            printf("YES\n");
        K--;
    }
    return 0;
}
