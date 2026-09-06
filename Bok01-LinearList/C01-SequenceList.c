// 顺序表

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
#define initSize 100

// 顺序表结构体
typedef struct {
    ElemType *elem; // 存储空间的基地址
    int length; // 当前长度
}SeqList;

// 初始化
void initList(SeqList *L) {
    L->elem = (ElemType *) malloc(sizeof(ElemType) * initSize); // 分配大小为 initSize 的数组空间
    if (!L->elem) { exit(-1); } // 存储失败退出
    L->length = 0; // 空表长度为 0
}

// 取值
void GetElem(const SeqList *L, const int index, ElemType *e) {
    if (index < 1 || index > L->length) { exit(-1); } // 判断 index 是否合理，不合理退出
    *e = L->elem[index - 1]; // Elem[index -1] 存储 第 index 个元素
}

// 按值查找位序
int LocateElem(const SeqList *L, const ElemType e) {
    if (L->length == 0) { return -1; }
    for (int i = 0; i < L->length; i++) {
        if (L->elem[i] == e) { return i + 1; }
    }
    return -1;
}

// 插入
void ListInsert(SeqList *L, const int index, ElemType e) {
    if (index < 1 || index > L->length) { exit(-1); } // 判断 index 是否合理，不合理退出
    if (L->length == initSize) { exit(-1); } // 存储空间已满，则退出

    for (int i = L->length - 1; i >= index - 1; i--) { // 插入位置之后的元素后移
        L->elem[i + 1] = L->elem[i];
    }

    L->elem[index - 1] = e; // 新元素放进第 index 个位置
    L->length++;
}

// 删除
void ListDelete(SeqList *L, const int index) {
    if (index < 1 || index > L->length) { exit(-1); }
    for (int i = index; i < L->length - 1; i++) {
        L->elem[i - 1] = L->elem[i]; // 被删除元素之后的元素前移
    }
    L->length--;
}

int main() {
    SeqList L;
    initList(&L);

    return 0;
}