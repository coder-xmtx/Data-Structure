// 单链表的定义与创建

#include <stdio.h>
#include <stdlib.h>

// 单链表结构体
typedef struct LNode {
    int data;           // 数据域
    struct LNode *next; // 指针域
} LNode;

// 初始化
LNode* InitNode() {
    // 分配内存空间，持久化节点
    LNode *L = (LNode *) malloc(sizeof(LNode));
    // 头结点
    L->data = 0;
    L->next = NULL;

    // 返回头结点的地址
    return L;
}

// 尾插法创建 - 带头结点
// 函数参数：头结点指针，待插入数据的数组，数组长度
void CreatTail(LNode *L, const int *data, const int length) {
    // 尾指针从头结点开始
    LNode *tail = L;

    for (int i = 0; i < length; i++) {
        LNode *node = (LNode *) malloc(sizeof(LNode));
        node->data = data[i];
        node->next = NULL;

        // 尾插
        tail->next = node;    // 挂到尾部
        tail = node;          // 尾指针后移
    }
}

// 头插法创建 - 带头结点
void CreateHead(LNode *L, const int *data, const int length) {
    for (int i = 0; i < length; i++) {
        LNode *node = (LNode *) malloc(sizeof(LNode));
        node->data = data[i];
        node->next = NULL;

        // 头插
        node->next = L->next;
        L->next = node;
    }
}

// 打印输出
void PrintList(const LNode *L) {
    // 跳过头结点
    const LNode *p = L->next;

    // 遍历
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void) {
    // 初始化
    LNode *L = InitNode();
    // 给定数组
    int a[] = {1, 2, 3, 4, 5};
    // 尾插
    CreatTail(L, a, 5);
    // 遍历打印
    PrintList(L);

    // 释放内存
    free(L);

    return 0;
}