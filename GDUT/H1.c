// 作业 1
// 设顺序表 L 中的数据元素递增有序。
// 试写一算法，将 x 插入到顺序表的适当位置，以保持该表的有序性。

#include<stdio.h>
#include<stdbool.h>

#define MAXSIZE 100

// 顺序表结构体
typedef struct SqList {
    int data[MAXSIZE];
    int length;
} SqList;

// 初始化 + 创建顺序表
// 函数参数：顺序表指针，待插入数组，数组长度
bool CreateList(SqList *L, const int *arr, const int size) {
    // 初始化
    L->length = 0;

    // 给顺序表添加元素
    for (int i = 0; i < size; i++) {
        if (L->length >= MAXSIZE) return false;
        L->data[i] = arr[i];
        L->length++;
    }

    return true;
}

// 插入元素
// 函数参数：顺序表指针，插入数值，插入位置（位置从 0 开始）
bool InsertList(SqList *L, const int e, const int index) {
    // 顺序表已满，返回false
    if (L->length >= MAXSIZE) return false;
    // 插入位置不合法，返回false
    if (index > L->length || index < 0) return false;
    // 插入
    for (int i = L->length - 1; i >= index; i--) {
        L->data[i + 1] = L->data[i];
    }
    L->data[index] = e;
    L->length++;

    return true;
}

// 二分查找算法
// 函数参数：顺序表指针，插入数值
bool BinaryInsert(SqList *L, const int e) {
    // 顺序表已满，返回false
    if (L->length >= MAXSIZE) return false;
    // 使用二分查找算法
    int start = 0;
    int end = L->length - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (L->data[mid] > e) end = mid - 1;
        else start = mid + 1;
    }
    InsertList(L, e, start);

    return true;
}

// 打印顺序表
void PrintList(const SqList *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 测试
int main(void) {
    // 创建顺序表
    SqList L;

    // 待插入数组
    const int arr[] = {1, 4, 7, 8, 12, 20};

    // 插入元素
    CreateList(&L, arr, 6);
    printf("Original List: ");
    PrintList(&L); // 打印

    // 测试：将 10 插入
    BinaryInsert(&L, 10);
    printf("After Insertion: ");
    PrintList(&L); // 打印

    return 0;
}