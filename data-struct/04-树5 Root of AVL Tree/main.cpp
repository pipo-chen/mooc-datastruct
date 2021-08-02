//
//  main.cpp
//  04-树5 Root of AVL Tree
//
//  Created by mk on 2021/8/2.
//

#include <iostream>
using namespace :: std;
typedef struct AVLNode * AVLTree;
struct AVLNode {
    int Data;
    AVLTree Left;
    AVLTree Right;
};

int GetHeight(AVLTree T) {
    int HL, HR, MaxH;
    if (T) {
        HL = GetHeight(T->Left);
        HR = GetHeight(T->Right);
        MaxH = HL > HR ? HL : HR;
        return MaxH + 1;
    }
    else
        return 0;
}

AVLTree singleRightRotation(AVLTree A) {
    AVLTree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    return B;
}

AVLTree singleLeftRotation(AVLTree A) {
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    return B;
}

AVLTree DoubleRightLeftRotation(AVLTree A) {
    A->Right = singleLeftRotation(A->Right);
    return singleRightRotation(A);
}

AVLTree DoubleLeftRightRotation(AVLTree A) {
    A->Left = singleRightRotation(A->Left);
    return singleLeftRotation(A);
}

AVLTree insert(AVLTree T, int X) {
    //如果空的话 创建
    if (!T) {
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Left = NULL;
        T->Right = NULL;
    }
    else if (T->Data < X) {
        T->Right = insert(T->Right, X);
        //说明不平衡了
        if (GetHeight(T->Right) - GetHeight(T->Left) == 2) {
            //开始判断旋转
            if ( X > T->Right->Data) {
                T = singleRightRotation(T);
            } else {
                T = DoubleRightLeftRotation(T);
            }
        }
        
    } else if (T->Data > X) {
        T->Left = insert(T->Left, X);
        if (GetHeight(T->Left) - GetHeight(T->Right) == 2) {
            if (X < T->Left->Data) {
                T = singleLeftRotation(T);
            } else {
                T = DoubleLeftRightRotation(T);
            }
        }
    }

    return T;
}

void printTree(AVLTree T) {
    if (T) {
        printTree(T->Left);
        printf("->%d",T->Data);
        printTree(T->Right);
    }
}

int main(int argc, const char * argv[]) {
    int N;
    AVLTree Root = NULL;
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        int data;
        scanf("%d", &data);
        Root = insert(Root, data);
        
    }
    printf("%d\n", Root->Data);
    return 0;
}
