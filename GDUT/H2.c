// 作业 2
// 试写一算法，将带头结点的单链表的偶号结点子序列逆置并接到表尾。例如：
// 设链表 L = (a_1,a_2,...,a_n-1,a_n)，则改造为
// 若 n 是偶数：L = (a_1,a_3,...,a_n-3,a_n-1,a_n,a_n-2,...,a_4,a_2)
// 若 n 是奇数：L = (a_1,a_3,...,a_n-2,a_n,a_n-1,a_n-3,...,a_4,a_2)

#include <stdio.h>
#include <stdlib.h>

// 链表结构体
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

// 初始化 + 创建链表
// 函数参数：待插入数组，数组长度
LNode* CreateList(const int *arr, const int length) {
    // 初始化
    LNode *L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    L->data = -1;

    // 尾指针
    LNode *tail = L;

    // 创建
    for (int i = 0; i < length; i++) {
        LNode *newNode = (LNode *)malloc(sizeof(LNode));
        newNode->data = arr[i];
        newNode->next = NULL;
        // 尾指针
        tail->next = newNode;
        tail = newNode;
    }

    return L;
}

// 打印链表
void PrintList(LNode *L) {
    LNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 释放链表
void DestroyList(LNode* L) {
    while (L != NULL) {
        LNode* temp = L;
        L = L->next;
        free(temp);
    }
}

// 偶号结点逆置
// 使用双指针
void HandleList(LNode *L) {
    // 链表为空或只有1、2个结点时无需操作
    if (L == NULL || L->next == NULL || L->next->next == NULL) return;

    // 遍历原链表
    LNode *p = L->next;
    // 奇数号结点尾指针
    LNode *oddTail = L;
    // 偶数号结点头指针
    LNode *evenHead = NULL;
    // 预存下一个结点
    LNode *next_p = NULL;

    while (p != NULL) {
        // 处理奇数号结点
        oddTail->next = p; // 将奇数结点接到奇数链尾部
        oddTail = p;       // 更新奇数链尾指针
        p = p->next;       // 链表指针后移，处理偶数号结点

        // 处理偶数号结点
        if (p != NULL) {
            next_p = p->next;   // 暂存下一个结点，防止断链
            p->next = evenHead; // 头插：当前偶数结点指向之前的偶数链头
            evenHead = p;       // 更新偶数链头指针
            p = next_p;         // p后移，继续下一轮循环
        }
    }

    // 将逆置后的偶数链表接到奇数链表尾部
    oddTail->next = evenHead;
}

// 测试
int main(void) {
    // 待插入数组
    const int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 创建链表
    LNode *L = CreateList(arr, 10);
    // 打印链表
    printf("Origin: ");
    PrintList(L);

    // 逆置
    HandleList(L);
    printf("Handle: ");
    PrintList(L);

    // 释放内存
    DestroyList(L);

    return 0;
}