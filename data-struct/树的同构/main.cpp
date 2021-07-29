//
//  main.cpp
//  树的同构
//
//  Created by mk on 2021/7/28.
//

#include <iostream>
using namespace :: std;
//1 构造树
//2 判断
#define MaxTree 1000
#define ElemType char
#define Tree int
#define Null -1

struct TreeNode {
    ElemType Element;
    Tree Left;
    Tree Right;
    bool Checked;
    int childNum;
    int total_size;
}T1[MaxTree], T2[MaxTree];

//返回根节点的位置
int Build(struct TreeNode *T) {
    int N;
    scanf("%d ",&N);
    //初始化
    int root = Null;
    T[0].total_size = N;
    for (int i = 0; i < N; i++) {
        T[i].Checked = false;
        T[i].childNum = 2;
    }
    
    for (int i = 0; i < N; i++) {
        char left, right;
        scanf("%c %c %c ", &T[i].Element, &left, &right);
        T[i].Left = left == '-' ? Null : (left - '0');
        T[i].Right = right == '-' ? Null : (right - '0');
        //说明该点 有父节点 left 和 right 位置
        if (T[i].Left != Null) {
            T[(T[i].Left)].Checked = true;
        } else {
            T[i].childNum --;
        }
        if (T[i].Right != Null) {
            T[(T[i].Right)].Checked = true;
        } else {
            T[i].childNum --;
        }
    }
    //存储完之后 遍历 找根节点
    for (int i = 0; i < N; i++) {
        if (!T[i].Checked) {
            root = i;
            break;
        }
    }
    return root;
}
//创建完树之后，进行挨个比较
bool compare(struct TreeNode *T1, int root_1, struct TreeNode *T2, int root_2) {
    
    //两个都是空
    if (root_1 == Null && root_2 == Null)
        return true;
    
    //一个空一个不空
    if ((root_1 == Null && root_2 != Null) || (root_1 != Null && root_2 == Null))
        return false;
    
    //树根的值不一样
    if (T1[root_1].Element != T2[root_2].Element)
        return false;
    
    //总数量不一样
    if (T1[0].total_size != T2[0].total_size)
        return false;
    
    //孩子数不一样
    if (T1[root_1].childNum != T2[root_2].childNum)
        return false;
    
    //都是没有孩子
    if (T1[root_1].childNum == 0 && T2[root_2].childNum == 0)
        return true;
    
    //都只有一个孩子
    if(T1[root_1].childNum == 1 && T2[root_2].childNum == 1) {
        return compare(T1, T1[root_1].Left == Null ? T1[root_1].Right : T1[root_1].Left, T2, T2[root_2].Left == Null ? T2[root_2].Right : T2[root_2].Left);
    }
    
    //都有两个孩子
    if (T1[root_1].childNum == 2 && T2[root_2].childNum == 2) {
        return (compare(T1, T1[root_1].Left, T2, T2[root_2].Left) && compare(T1, T1[root_1].Right, T2, T2[root_2].Right)) || (compare(T1, T1[root_1].Right, T2, T2[root_2].Left) && compare(T1, T1[root_1].Left, T2, T2[root_2].Right));
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    int root_1, root_2;
    root_1 = Build(T1);
    root_2 = Build(T2);
    if (compare(T1, root_1, T2, root_2))
        printf("Yes");
    else
        printf("No");
    
    return 0;
}
