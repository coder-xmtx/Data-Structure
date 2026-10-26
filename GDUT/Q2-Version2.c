// Question 2  线性表的链式表示和实现
// ----------------------------------
// 已知线性表 LA 和 LB 中的数据元素按值非递减有序排列，
// 现要求使用链式存储结构编程将 LA 和 LB 归并为一个新的线性表 LC，
// 且 LC 中的数据元素仍按值非递减有序排列。
// 例如，设 LA = (3,5,8,11) 和 LB = (2,6,8,9,11,15,20)
// 则 LC = (2,3,5,6,8,8,9,11,11,15,20)

#include <stdio.h>
#include <stdlib.h>

// 链表结构体
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

// 初始化 + 尾插法创建
// 函数参数：待插入元素的数组，数组长度
LNode* CreateList(const int* data, const int length) {
    // 创建头结点
    LNode* L = (LNode*)malloc(sizeof(LNode));
    L->data = 0;
    L->next = NULL;

    // 创建链表元素
    LNode* tail = L; // 尾指针
    for (int i = 0; i < length; i++) {
        LNode* node = (LNode*)malloc(sizeof(LNode));
        node->data = data[i];
        node->next = NULL;
        // 尾指针操作
        tail->next = node; // 将node链接到表尾
        tail = node; // 尾指针后移
    }

    return L;
}

// 打印链表
void PrintList(const LNode* L) {
    // 空链表返回
    if (L == NULL) return;
    // 从首元结点开始
    const LNode* temp = L->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 合并
// 为 LC 新申请结点并复制 data
LNode* MergeList(const LNode* LA, const LNode* LB) {
    LNode* pA = LA->next;
    LNode* pB = LB->next;

    // 创建目标链表LC
    LNode* LC = (LNode*)malloc(sizeof(LNode));
    LC->data = 0;
    LC->next = NULL;
    LNode* pC = LC; // LC尾指针

    while (pA != NULL && pB != NULL) {
        // 新申请结点
        LNode* node = (LNode*)malloc(sizeof(LNode));
        node->next = NULL;

        if (pA->data <= pB->data) {
            node->data = pA->data;
            pA = pA->next;
        } else {
            node->data = pB->data;
            pB = pB->next;
        }

        pC->next = node;
        pC = node;
    }

    // 把 LA 或 LB 剩下的元素逐个复制过来
    LNode* rest = (pA != NULL) ? pA : pB;
    while (rest != NULL) {
        LNode* node = (LNode*)malloc(sizeof(LNode));
        node->data = rest->data;
        node->next = NULL;

        pC->next = node;
        pC = node;

        rest = rest->next;
    }

    return LC;
}

// 释放整个链表，包括头结点
void DestroyList(LNode* L) {
    while (L != NULL) {
        LNode* temp = L;
        L = L->next;
        free(temp);
    }
}

int main() {
    // 待插入元素的数组
    int arr_A[] = {3, 5, 8, 11};
    int arr_B[] = {2, 6, 8, 9, 11, 15, 20};

    // 创建链表
    LNode* LA = CreateList(arr_A, 4);
    LNode* LB = CreateList(arr_B, 7);

    // 合并链表
    LNode* LC = MergeList(LA, LB);
    PrintList(LC);

    // 释放内存，三条链表独立
    DestroyList(LA);
    DestroyList(LB);
    DestroyList(LC);

    return 0;
}