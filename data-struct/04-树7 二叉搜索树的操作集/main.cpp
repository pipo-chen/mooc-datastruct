#include <iostream>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;
    
    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
//递归实现
void PreorderTraversal( BinTree BT ) {
    if (BT) {
        printf(" %d ",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

//常规实现 常规要用堆栈进行存储
void InorderTraversal( BinTree BT ) {
    if (BT) {
        InorderTraversal(BT->Left);
        printf(" %d ",BT->Data);
        InorderTraversal(BT->Right);
    }
    
}
//插入 在左侧 还是在右侧插入的问题
BinTree Insert( BinTree BST, ElementType X ) {
    //如果是空树 直接插入
    if (!BST) {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    } else {
        if (BST->Data > X) {
            BST->Left = Insert(BST->Left, X);
        } else if (BST->Data < X)
            BST->Right = Insert(BST->Right, X);
    }
    return BST;
}

BinTree Delete( BinTree BST, ElementType X ) {
    Position Tmp;
    //如果是 2 个节点的情况
    if (!BST) {
        printf("Not Found\n");
    } else {
        if (X < BST->Data)
            BST->Left = Delete(BST->Left, X);
        else if (X > BST->Data)
            BST->Right = Delete(BST->Right, X);
        else {
            //说明 BST 就是要删除的结点
            if (BST->Left && BST->Right) {
                Tmp = FindMin(BST->Right);
                BST->Data = Tmp->Data;
                BST->Right = Delete(BST->Right, BST->Data);
            } else {
                if (BST->Right)
                    //如果只有右边节点
                    BST = BST->Right;
                else
                    BST = BST->Left;
            }
        }
    }
    return BST;
}

Position Find( BinTree BST, ElementType X ) {
    if (!BST)
        return NULL;
    if (BST->Data > X)
        return Find(BST->Left, X);
    else if (BST->Data < X)
        return Find(BST->Right, X);
    return BST;
}

Position FindMin( BinTree BST ) {
    if (BST)
        while (BST->Left)
            BST = BST->Left;
    return BST;
}
Position FindMax( BinTree BST ) {
    if (!BST)
        return NULL;
    else if (!BST->Right)
        return BST;
    return FindMax(BST->Right);
}
