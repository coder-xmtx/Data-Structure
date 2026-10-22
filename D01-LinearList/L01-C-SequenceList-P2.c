// 顺序表的插入、删除

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

// 顺序表结构体
typedef struct {
    int data[MAXSIZE]; // 存放数据
    int length;        // 存放顺序表长度
}SqList;


// 插入
// 在顺序表 L 的第 i 个位置（下标为 i-1）插入新元素 e
bool Insert(SqList *L, int i, int e) {
    // 如果顺序表已满，返回
    if (L->length == MAXSIZE) return false;
    // 如果插入位置不合法，返回
    if (i < 1 || i > L->length + 1) return false;
    // 从最后一个位置到要插入的位置依次后移一位
    for (int j = L->length - 1; j >= i - 1; j--) {
        L->data[j + 1] = L->data[j];
    }
    // 将 e 插入指定位置，表长 +1
    L->data[i - 1] = e;
    L->length++;

    return true;
}


// 删除
// 删除顺序表 L 的第 i 个位置（下标为 i-1）的元素
bool Delete(SqList *L, int i) {
    // 如果插入位置不合法，返回
    if (i < 1 || i > L->length) return false;
    // 被删除元素之后的每一个元素往前移动一位
    for (int j = i; j <= L->length - 1; j++) {
        L->data[j - 1] = L->data[j];
    }
    // 表长 -1
    L->length--;

    return true;
}