//
//  main.cpp
//  04-树4 是否同一棵二叉搜索树
//
//  Created by mk on 2021/7/30.
//

#include <iostream>

using namespace::std;

typedef struct Node *Tree;
struct Node {
    int Elem;
    Tree Left;
    Tree Right;
};

Tree insert(Tree root, int x) {
    if (root == NULL) {
        //直接插入
        root = (Tree)malloc(sizeof(struct Node));
        root->Elem = x;
        root->Left = NULL;
        root->Right = NULL;
    } else {
        //查询插入
        if (root->Elem > x) {
            root->Left = insert(root->Left, x);
        }
        else if (root->Elem < x) {
            root->Right = insert(root->Right, x);
        }
    }
    return root;
}

bool checkSimilarTree(Tree T1, Tree T2) {
    //开始从根到根
    //两颗树都为空
    if (T1 == NULL && T2 == NULL)
        return true;
    
    //一空 一不空
    if ((T1 == NULL && T2 != NULL) || (T2 == NULL && T1 != NULL))
        return false;
    
    //两个都不空
    if (T1 && T2) {
        if (T1->Elem != T2->Elem)
            return false;
        if (T1->Elem == T2->Elem && checkSimilarTree(T1->Left, T2->Left) &&  checkSimilarTree(T1->Right, T2->Right)) {
            return true;
        } else {
            return false;
        }
    }
    
    return true;
}

void printTree(Tree root) {
    if (root) {
        //前序
        printf(" %d ",root->Elem);
        printTree(root->Left);
        printTree(root->Right);
    }
}

int main(int argc, const char * argv[]) {
    int N, L;
    while (scanf("%d",&N) && N != 0) {
        scanf("%d",&L);
       
        //原始树
        Tree origin_root = NULL;
        for (int i = 0; i < N; i++) {
            int data;
            scanf("%d", &data);
            origin_root = insert(origin_root, data);
        }
       
        //然后开始输入待检测的树
        for (int j = 0; j < L; j++) {

            Tree compare_root = NULL;
            for (int i = 0; i < N; i++) {
                int data;
                scanf("%d", &data);
                compare_root = insert(compare_root, data);
            }
  
            //开始比较
            if (checkSimilarTree(origin_root, compare_root)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    
    return 0;
}
