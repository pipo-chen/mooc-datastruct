//
//  main.cpp
//  05-树7 堆中的路径
//
//  Created by mk on 2021/8/6.
//

#include <iostream>
using namespace :: std;

#define MIN_NUM -10001

typedef struct HeapStruct *MinHeap;

struct HeapStruct {
    int *data;
    int size;
    int capcity;
};

MinHeap createHeap(int MaxSize) {
    MinHeap min = (MinHeap)malloc(sizeof(struct HeapStruct));
    min->data = (int *)malloc(sizeof(int) * (MaxSize + 1));
    min->size = 1;
    min->capcity = MaxSize + 1;
    min->data[0] = MIN_NUM;
    return min;
}

bool isFull(MinHeap heap) {
    return heap->size == heap->capcity;
}

void build(MinHeap heap, int X) {
    if (isFull(heap))
        return;
    int child = heap->size++;
    //开始不停的跟父亲节点比较然后交换
    heap->data[child] = X;
    for (; heap->data[child / 2] > heap->data[child]; child /= 2) {
        //交换
        int temp = heap->data[child];
        heap->data[child] = heap->data[child / 2];
        heap->data[child / 2]  = temp;
    }
}

//输出从节点 到 根经过的路径

int main(int argc, const char * argv[]) {
    int N, M;
    scanf("%d %d",&N, &M);
    MinHeap heap = createHeap(N);
    for (int i = 0; i < N; i++) {
        int item;
        scanf("%d",&item);
        build(heap, item);
    }
    for (int j = 0; j < M; j++) {
        int child;
        scanf("%d", &child);
        //开始输出
        while (child != 0) {
            printf("%d",heap->data[child]);
            child /= 2;
            if (child != 0)
                printf(" ");
                
        }
        printf("\n");
    }

    return 0;
}
