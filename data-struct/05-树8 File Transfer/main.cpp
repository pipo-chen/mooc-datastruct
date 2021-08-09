//
//  main.cpp
//  05-树8 File Transfer
//
//  Created by mk on 2021/8/6.
//

#include <iostream>
using namespace::std;
#define MaxSize 10010
typedef int ElementType;
typedef int SetName; /*默认用根结点的下标作为集合名称*/
typedef ElementType SetType[MaxSize];

SetName Find(SetType S, ElementType X) {
    while (S[X] >= 0) {
        X = S[X];
    }
    return X;
}

void Union(SetType S, SetName Root1, SetName Root2) {
    if (S[Root2] < S[Root1]) {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    } else {
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }
}
void Input_connection(SetType S) {
    ElementType u, v;
    SetName Root1, Root2;
    scanf("%d %d\n", &u, &v);
    Root1 = Find(S, u - 1);
    Root2 = Find(S, v - 1);
    if (Root1 != Root2)
        Union(S, Root1, Root2);
}

void Check_connection(SetType S) {
    ElementType u, v;
    SetName Root1, Root2;
    scanf("%d %d\n", &u, &v);
    Root1 = Find(S, u-1);
    Root2 = Find(S, v-1);
    if (Root1 == Root2)
        printf("yes\n");
    else
        printf("no\n");
}

void Check_network( SetType S, int n) {
    int i, counter = 0;
    for (i = 0; i < n; i++) {
        if (S[i] < 0)
            counter++;
    }
    if (counter == 1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n",counter);
}

int main() {
    SetType S;
    int n;
    char in;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
        S[i] = -1;
    do {
        scanf("%c",&in);
        switch (in) {
            case 'I':
                Input_connection( S );
                break;
            case 'C':
                Check_connection( S );
                break;
            case 'S':
                Check_network( S, n );
                break;
                break;
        }
    } while (in != 'S');
    return 0;
}
