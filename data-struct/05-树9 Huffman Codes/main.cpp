//
//  main.cpp
//  05-树9 Huffman Codes
//
//  Created by mk on 2021/8/9.
//
/**
 哈夫曼树：
 1. 总长度 WPL 最小
 2. 无歧义编码 - 前缀数据仅存在于叶子结点
 3. 没有度为 1 的结点
 
 哈夫曼 构成 - 最大最小堆？
 */

#include <iostream>
#include <algorithm>
using namespace::std;
//先建立一个最小堆， 哈夫曼里面的元素都从堆里面开始存取

#define MINDATA -1
#define NULL_LETTER -1
#define SIZE 100

typedef struct Item *DataItem;
typedef struct HNode *MinHeap;
typedef struct HuffmanNode *HuffmanTree;

struct HuffmanNode {
    int height;
    DataItem item;
    HuffmanTree Left;
    HuffmanTree Right;
};
//然后再把新生成的 插入最小堆 重新排

struct Item {
    char letter;
    int frequent;
};

struct HNode {
    //堆也用数组进行存储
    HuffmanTree trees[64];
    int size;
    int capacity;
};

bool IsEmpty(MinHeap H) {
    return H->size == 0;
}

bool IsFull(MinHeap H) {
    return H->size == H->capacity;
}

MinHeap initializer(int size) {
    //不设置哨兵
    MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
    H->size = 0;
    H->capacity = size ;
    return H;
}

void Insert(MinHeap H, HuffmanTree tree) {
    if (IsFull(H))
        return;
    //怎么在最后插入
    int index = H->size++;
    H->trees[index] = tree;
    int parent = index / 2;
    //在 index 这个位置做插入 然后不断的向上比较 看看有没有比 parent 小，有的话继续向上
    //如果等于 0 ？
    while (index > 0 && tree->item->frequent < H->trees[parent]->item->frequent) {
        HuffmanTree temp = H->trees[index];
        H->trees[index] = H->trees[parent];
        H->trees[parent] = temp;
        index = parent;
        parent /= 2;
    }
}

HuffmanTree Delete(MinHeap H) {
    //把最顶上的删除掉
    //替补之后后面不停的从儿子中选出小的上位
    if (IsEmpty(H))
        return NULL;
    //最顶上的应该是0位置..
    HuffmanTree item = H->trees[0];
    int Parent = 0;
    int Child = Parent * 2 + 1;
    H->trees[0] = H->trees[--H->size];
    while (Child < H->size) {
        //从左右儿子中选择
        if (H->trees[Child]->item->frequent > H->trees[Child + 1]->item->frequent)
            Child ++;
        //然后父节点中 儿子上位 父亲下去
        if (H->trees[Parent]->item->frequent > H->trees[Child]->item->frequent) {
            //交换
            HuffmanTree temp = H->trees[Parent];
            H->trees[Parent] = H->trees[Child];
            H->trees[Child] = temp;

        } else {
            break;
        }
        
        Parent = Child;
        Child = Parent * 2 + 1;
    }
    return item;
}

//输出
void Print(MinHeap H) {
    for (int i = 0; i < H->size; i++) {
        printf("-->(%c,%d)",H->trees[i]->item->letter, H->trees[i]->item->frequent);
    }
}

//开始构建哈夫曼树
HuffmanTree Build(MinHeap H) {
    while (H->size != 1) {
        HuffmanTree temp = (HuffmanTree)malloc(sizeof(struct HuffmanNode));
        //直接赋值好像没有赋过来
        temp->Left = Delete(H);
        //如果这个时候已经空了？
        temp->Right = Delete(H);
        temp->item = (DataItem)malloc(sizeof(struct Item));
        temp->item->frequent = temp->Left->item->frequent + temp->Right->item->frequent;
        temp->item->letter = NULL_LETTER;
        Insert(H, temp);
    }
    
    return Delete(H);
}

//输出 哈夫曼树
void Print_Tree(HuffmanTree Root) {
    if (Root != NULL) {
        printf("-->(%c,%d)", Root->item->letter, Root->item->frequent);
        Print_Tree(Root->Left);
        Print_Tree(Root->Right);
    }
}

int Calculate_WPL(HuffmanTree T) {
    int count = 0;
    if (T != NULL) {
        count = T->item->frequent + Calculate_WPL(T->Left) + Calculate_WPL(T->Right);
    }
    return count;
   
}

int main() {
    int N, Check;
    scanf("%d\n", &N);
    MinHeap H = initializer(N);
    int total = 0;
    for (int i = 0; i < N; i++) {
        HuffmanTree tree = (HuffmanTree)malloc(sizeof(struct HuffmanNode));
        tree->height = 0;
        tree->item = (DataItem)malloc(sizeof(struct Item));
        tree->Left = NULL;
        tree->Right = NULL;
        scanf("%c %d ", &tree->item->letter, &tree->item->frequent);
        total += tree->item->frequent;
        Insert(H, tree);
    }
    Print(H);
    HuffmanTree Root = Build(H);
    //计算 WPL
    int wpl = 0;
    wpl = Calculate_WPL(Root) - total;
    
    
}
