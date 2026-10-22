// 顺序表的定义、创建、查找

#include <stdio.h>

#define MAXSIZE 100

// 顺序表结构体
typedef struct {
    int data[MAXSIZE]; // 存放数据
    int length;        // 存放顺序表长度
}SqList;


// 初始化顺序表
void InitList(SqList* L) {
    L->length = 0;
}

// 创建顺序表
// 函数参数：顺序表指针，数据数组，数组长度
void CreateList(SqList* L, int *data, int length) {
    for (int i = 0; i < length; i++) {
        L->data[i] = data[i];
    }
}

// 遍历输出顺序表
void PrintList(SqList *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
}

// 按值查找
// 在顺序表中查找元素e，返回其序号
int Find(SqList *L, int e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) return i + 1;
    }
    return -1;
}

int main () {}