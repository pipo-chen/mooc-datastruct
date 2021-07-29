//
//  main.cpp
//  List Leaves
//
//  Created by mk on 2021/7/29.
//

#include <iostream>
#define MaxSize 11
#define Null -1
using namespace std;
typedef struct QueueNode *Queue;
struct TreeNode {
    int Elem;
    int Left;
    int Right;
    bool Checked;
}T[MaxSize];

//顺序存储
struct QueueNode {
    int data[MaxSize];
    int front;
    int rear;
};

Queue Create() {
    Queue q = (Queue)malloc(sizeof(struct QueueNode));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(int x, Queue q) {
    //判断是否合法
    if (q->rear == MaxSize - 1)
        return;
    q->data[++(q->rear)] = x;
}

bool isEmpty(Queue q) {

    return q->front == q->rear;
}

int dequeue(Queue q) {
    if (isEmpty(q))
        return Null;
    return q->data[++(q->front)];
}

int Bulid(struct TreeNode *T) {
    int N, root = Null;
    scanf("%d ",&N);
    for (int i = 0; i < N; i++) {
        T[i].Checked = false;
    }
    for (int i = 0; i < N; i++) {
        char left, right;
        scanf("%c %c ", &left, &right);
        T[i].Elem = i;
        T[i].Left = left == '-' ? Null : left - '0';
        T[i].Right = right == '-' ? Null : right - '0';
        if (T[i].Left != Null)
            T[T[i].Left].Checked = true;
        if (T[i].Right != Null)
            T[T[i].Right].Checked = true;
    }
    //寻找根节点并返回
    for (int i = 0; i < N; i++) {
        if (!T[i].Checked) {
            root = i;
            break;
        }
    }
    return root;
}


//层序遍历 要用队列来实现
void LeavesLevelOrder(int root, struct TreeNode *T, Queue q) {
    if (root != Null) {
        enqueue(T[root].Elem, q);
    }
    while (!isEmpty(q)) {
        int data = dequeue(q);
        if (T[data].Left == Null && T[data].Right == Null) {
            printf("%d",data);
        }
        if (T[data].Left != Null)
            enqueue(T[T[data].Left].Elem, q);
        if (T[data].Right != Null)
            enqueue(T[T[data].Right].Elem, q);
        if (T[data].Left == Null && T[data].Right == Null && !isEmpty(q))
            printf(" ");
    }
    
}

int main(int argc, const char * argv[]) {
    int root = Bulid(T);
    Queue q = Create();
    LeavesLevelOrder(root, T, q);
    return 0;
}



