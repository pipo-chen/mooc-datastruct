//
//  main.cpp
//  PK
//
//  Created by mk on 2021/7/20.
//

#include <iostream>
/**
 5 局 3 胜 每一局都有两队伍的变化
 */

int main(int argc, const char * argv[]) {
    int a = 100, b = 100, a_win = 0, b_win = 0;
    for (int i = 0; i < 5; i++) {
        //a 循环一百次 b 循环 100 ci
        for (int a_score = 0; a_score < 101; a_score++) {
            for (int b_score = 0; b_score < 101; b++) {
                if (b_score < a_score) {
                    a_win
                }
            }
        }
        //每 5 次 记录一下胜利
    }
    //记录max 最大的时候 a b 的情况
    return 0;
}
