//
//  main.cpp
//  10-排序5 PAT Judge
//
//  Created by mk on 2021/8/13.
//

#include <iostream>
#include <algorithm>
#define MAX_SIZE 6
#define MAX_STU 10010
#define ORIGINAL_SCORE -1
using namespace::std;

struct Student {
    int id;
    int score[MAX_SIZE] = {ORIGINAL_SCORE,ORIGINAL_SCORE,ORIGINAL_SCORE,ORIGINAL_SCORE,ORIGINAL_SCORE,ORIGINAL_SCORE};
    int perfect_count[MAX_SIZE] = {0,0,0,0,0,0};
    int total_score = 0;
    int count = 0;
    int commit = 0;
    int rank;
}students[MAX_STU];


bool cmp(struct Student a, struct Student b) {
    if (a.total_score != b.total_score)
        return a.total_score > b.total_score;
    if (a.count != b.count)
        return a.count > b.count;
    return a.id < b.id;
}

int main() {
    int N, K, M;
    int full[MAX_SIZE];
    scanf("%d %d %d\n", &N, &K, &M);
    for (int i = 0; i < K; i++) {
        scanf("%d",&full[i+1]);
    }
    
    for(int i = 0; i < M; i++) {
        int id, q_id, score;
        scanf("%d %d %d\n",&id, &q_id, &score);
        students[id].id = id;
        
        //总成绩统计
        if (score > students[id].score[q_id]) {
            if (students[id].score[q_id] == ORIGINAL_SCORE) {
                students[id].total_score += score;
            } else {
                students[id].total_score = students[id].total_score  - students[id].score[q_id] + score;
            }
            students[id].score[q_id] = score;
        } else if (score == ORIGINAL_SCORE)
            students[id].score[q_id] = 0;
        //perfect 统计
        if (score == full[q_id]) {
            students[id].perfect_count[q_id] = 1;
        }
    }
    //统计 perfect total = 0 有两种情况 1. 全部提交上来是 0 2 全部为 -1 或 0
    for (int i = 0; i < MAX_STU; i++) {
        if (students[i].total_score != 0) {
            int count = 0;
            for (int j = 1; j <= K; j++) {
                if (students[i].perfect_count[j] == 1)
                    count++;
            }
            students[i].count = count;
        }
    }
    
    //开始排序
    sort(students, students + MAX_STU, cmp);

    int last = 0;
    int index = 1;
    for (int i = 0; i < MAX_STU; i++) {
        if (students[i].total_score > 0) {
            if(students[i].total_score == students[last].total_score && i != 0) {
                students[i].rank = students[last].rank;
            } else {
                students[i].rank = index;
            }
            index++;
            
            printf("%d %05d %d ",students[i].rank, students[i].id, students[i].total_score);
            for (int j = 1; j <= K; j++) {
                if (students[i].score[j] == ORIGINAL_SCORE)
                    printf("-");
                else
                    printf("%d",students[i].score[j]);
                if (j != K) {
                    printf(" ");
                }
            }
            printf("\n");
            last = i;
        }
    }
    
    return 0;
    
}
