//
//  main.cpp
//  09-排序1 排序 (25 point(s))
//
//  Created by mk on 2021/8/13.
//

#include <iostream>
#include <algorithm>

using namespace::std;
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d\n",&n);
    int data[n];
    for (int i = 0; i < n; i++) {
        scanf("%d",&data[i]);
    }
    sort(data, data+n);
    for (int i = 0; i < n; i++) {
        printf("%d",data[i]);
        if (i != n-1)
            printf(" ");
    }
    return 0;
}
