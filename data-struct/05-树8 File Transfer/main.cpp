//
//  main.cpp
//  05-树8 File Transfer
//
//  Created by mk on 2021/8/6.
//

#include <iostream>
using namespace::std;
#define MAXSIZE 10010
typedef struct node SetType;
struct node {
    int data;
    int parent;
};
int find_root(SetType datas[], SetType node) {
    if (node.parent <= -1)
        return node.data;
    return find_root(datas, datas[node.parent]);
}

bool check_two_nodes(SetType datas[], int n1, int n2) {
    if (datas[n1].parent <= -1) {
        return false;
    }
    if (datas[n1].parent == n2) {
        return true;
    }
    return check_two_nodes(datas, datas[n1].parent, n2);
}

void input_conntection(SetType datas[], int n1, int n2) {
    //寻找根的过程中 有没有遇到n2
    int root1 = find_root(datas, datas[n1]);
    int root2 = find_root(datas, datas[n2]);

    if (root1 != root2) {
        //union 方式直接让第一个节点指向第二个节点 按秩归并
        //比较一下 谁贴到谁上面去 根据高度来判断
        datas[root1].parent = n2;
    }
    
}

void check_connection(SetType datas[], int n1, int n2) {
    //在搜索的过程中 能找到 n2
    if (check_two_nodes(datas, n1, n2)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}

void check_network(SetType datas[], int N) {
    //判断这里面有几组
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (datas[i].parent == -1)
            count++;
    }
    if (count <= 1) {
        printf("The network is connected\n");
    } else {
        printf("There are %d components.\n",count);
    }
}

int main(int argc, const char * argv[]) {
    int N;
    char in;
    scanf("%d\n",&N);
    SetType datas[N + 1];
    
    for (int i = 1; i <= N; i++) {
        datas[i].parent = -1;
        datas[i].data = i ;
    }
    
    do {
        scanf("%c",&in);
        int n1, n2;
        scanf("%d %d",&n1, &n2);
        switch (in) {
            case 'C':
                check_connection(datas, n1, n2);
                break;
            case 'I':
                input_conntection(datas, n1, n2);
                break;
            case 'S':
                check_network(datas, N);
                break;
        }
    } while (in != 'S');
    
 
    return 0;
}
