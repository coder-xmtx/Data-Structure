// Question 1  线性表的顺序表示和实现
// 已知线性表 LA 和 LB 中的数据元素按值非递减有序排列，
// 现要求使用顺序存储结构编程将 LA 和 LB 归并为一个新的线性表 LC，
// 且 LC 中的数据元素仍按值非递减有序排列。
// 例如，设 LA = (3,5,8,11) LB = (2,6,8,9,11,15,20)
// 则 LC = (2,3,5,6,8,8,9,11,11,15,20)

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

// 顺序表结构体
typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;

// 初始化顺序表
void InitList(SqList *L) {
    L->length = 0;
}

// 添加元素（尾插法）
// 函数参数：顺序表的地址，数组地址，数组元素数量
bool ListInsert(SqList *L, const int *arr, const int nums) {
    if (L->length >= MAXSIZE) return false;
    for (int i = 0; i < nums; i++) {
        L->data[L->length] = arr[i];
        L->length++;
    }
    return true;
}

// 打印顺序表
void PrintList(const SqList *L) {
    if (L->length == 0) return;
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 合并排序
void MergeList(const SqList *LA, const SqList *LB, SqList *LC) {
    // 需要合并的顺序表中，若没有元素，则退出
    if (LA->length == 0 || LB->length == 0) return;

    // a b c 分别负责三个顺序表的元素定位
    int a = 0;
    int b = 0;
    int c = 0;

    // 比较，插入
    while (a < LA->length && b < LB->length) {
        if (LA->data[a] < LB->data[b]) {
            LC->data[c] = LA->data[a];
            a++;
        } else {
            LC->data[c] = LB->data[b];
            b++;
        }
        c++;
    }

    // 对于长的那个顺序表，剩下的元素直接插入目标表尾
    while (a < LA->length) {
        LC->data[c] = LA->data[a];
        a++;
        c++;
    }

    while (b < LB->length) {
        LC->data[c] = LB->data[b];
        b++;
        c++;
    }

    // 更新目标顺序表的长度
    LC->length = c;
}

int main () {
    // 创建顺序表
    SqList LA, LB, LC;

    // 初始化
    InitList(&LA);
    InitList(&LB);
    InitList(&LC);

    // 添加元素
    const int array_LA[] = {3, 5, 8, 11};
    ListInsert(&LA, array_LA, 4);

    const int array_LB[] = {2, 6, 8, 9, 11, 15, 20};
    ListInsert(&LB, array_LB, 7);

    // 进行合并排序
    MergeList(&LA, &LB, &LC);

    PrintList(&LC);
}