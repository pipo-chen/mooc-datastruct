//
//  main.cpp
//  04-树6 Complete Binary Search Tree
//
//  Created by mk on 2021/8/2.
//

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace::std;
#define MAXSIZE 3010

int rearr[1005];

bool cmp(int a, int b) {
    return a < b;
}

int getLeftLength(int n) {
    double h, x, L, t;
    h = (double)(int)( log((double) n + 1) / log(2.0));
    x = n - pow(2.0, h) + 1;
    t = pow(2.0, h - 1.0);
    x = x < t ? x : t;
    L = t - 1 + x;
    return (int)L;
                  
}
//计算是根 轮到哪个位置
void solve(int left, int right, int root, int arr[]) {
    int n, L, leftRoot, rightRoot;
    n = right - left + 1;
    if (n == 0)
        return;
    L = getLeftLength(n);
    rearr[root] = arr[left + L]; //将新结点放入新的数组
    leftRoot = root * 2 + 1; //左孩子
    rightRoot = leftRoot + 1; //右孩子
    solve(left, left + L - 1, leftRoot, arr);
    solve(left + L + 1, right, rightRoot, arr);
}

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d",&N);
    int data[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &data[i]);
    }

    sort(data, data + N, cmp);
    
    solve(0, N - 1, 0, data);
    for (int i = 0; i < N; i++) {
        if (i != 0)
            printf(" ");
        printf("%d",rearr[i]);
    }
    
    return 0;
}
