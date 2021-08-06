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
bool cmp(int a, int b) {
    return a < b;
}

int getLeftLength(int n) {
    double h, x, L, t;
    h = (double)(int)(log((double)n + 1) / log(2.0));
    x = n - pow(2.0, h) + 1;
    t = pow(2.0, h - 1.0);
    x = x < t ? x : t;
    L = t - 1 + x;
    return (int)L;
}

//计算左边子树的高度

void build(int left, int right, int root, int data[], int result[]) {
    int length = right - left + 1;
    if (length <= 0)
        return;
    length = getLeftLength(length);
    result[root] = data[length];
    int left_root = root * 2 + 1;
    int right_root = left_root + 1;
    build(left, left + length - 1, left_root, data, result);
    build(left + length + 1, right, right_root, data, result);

}
int main() {
    int n;
    scanf("%d", &n);
    int data[n], result[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    sort(data, data + n, cmp);
    //开始构成树
    build(0, n - 1, 0, data, result);
    for (int i = 0; i < n; i++) {
        printf(" %d ", result[i]);
    }
}
