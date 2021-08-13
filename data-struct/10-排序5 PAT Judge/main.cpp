//
//  main.cpp
//  10-排序5 PAT Judge
//
//  Created by mk on 2021/8/13.
//

#include <iostream>
#include <algorithm>
using namespace::std;
#define TOTAL_QUESTION 6
#define MAX_STU 10010
struct student {
    //还是要存id？
    int id;
    int perfect[TOTAL_QUESTION] = {0,0,0,0,0,0};
    int total = 0;
    int score[TOTAL_QUESTION] = {-1,-1,-1,-1,-1,-1};
    int submit = 0;
    int rank;
    int p = 0;
}student[MAX_STU];

bool cmp(struct student a, struct student b) {
    if (a.total != b.total)
        return a.total > b.total;
    if (a.perfect != b.perfect)
        return a.p > b.p;
    return a.id < b.id;
}

int main(int argc, const char * argv[]) {
    int n,kth, lines;
    int sum_scores[TOTAL_QUESTION];
    scanf("%d %d %d",&n, &kth, &lines);
    //总成绩
    for (int i = 0; i < kth; i++) {
        scanf("%d",&sum_scores[i+1]);
    }
    //录入成绩
    for (int i = 0; i < lines; i++) {
        int id, k, score;
        scanf("%d %d %d\n", &id, &k, &score);
        //如果原先是-1呢 如果 输入的是 -1 呢
        if (score == -1)
            score = 0;
        if (student[id].score[k] < score) {
            student[id].total = (student[id].score[k] == -1 ? student[id].total + score : student[id].total - student[id].score[k] + score);
            student[id].score[k] = score;
            
        }
        //记录学生提交
        student[id].submit++;
        //id
        student[id].id = id;
        //判断是否perfect
        if (sum_scores[k] == score)
            student[id].perfect[k] = 1;
    }
    //统计perfect
    for (int i = 0; i < MAX_STU; i++) {
        if (student[i].total != 0) {
            //开始统计
            int count = 0;
            for (int k = 0; k <= kth; k++) {
                if (student[i].perfect[k] == 1)
                    count++;
            }
            student[i].p = count;
        }
    }
    //查看成绩
    //开始排序
    sort(student, student + MAX_STU, cmp);
    
    int index = 1;
    int last = 0;
    for (int i = 0; i < MAX_STU; i++) {
        if (student[i].total != 0) {
            if (last == i)
                student[i].rank = index;
            else if(student[i].total == student[last].total)
                student[i].rank = student[last].rank;
            else
                student[i].rank = index;
            last = i;
            index++;
 
            printf("%d %05d %d ",student[i].rank,student[i].id, student[i].total);
            
            for (int k = 1; k <= kth; k++) {
                if (student[i].score[k] != -1) {
                    printf("%d",student[i].score[k]);
                } else {
                    printf("-");
                }
                if (k != kth)
                    printf(" ");
            }
            printf("\n");
        }
    
    }
    return 0;
}
