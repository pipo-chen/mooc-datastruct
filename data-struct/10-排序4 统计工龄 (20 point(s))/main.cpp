//
//  main.cpp
//  10-排序4 统计工龄 (20 point(s))
//
//  Created by mk on 2021/8/13.
//

#include <iostream>
#include <algorithm>
#define MAXAGE 51
using namespace::std;
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int count[MAXAGE];//0-50
    for (int i = 0; i < MAXAGE; i++)
        count[i] = -1;
    for (int j = 0; j < n; j++) {
        int age;
        scanf("%d",&age);
        count[age]++;
    }
    for (int k = 0; k < MAXAGE; k++) {
        if (count[k] != -1) {
            printf("%d:%d\n",k, count[k] + 1);
        }
    }
    
    return 0;
}
