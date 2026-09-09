// 链表

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// 单链表结构体
typedef struct LNode {
    ElemType data; // 节点的数据域
    struct LNode *next; // 节点的指针域（指向下一个节点）
} LNode, *LinkList;

// 初始化
LinkList initList() {
    const LinkList L = (LNode *) malloc(sizeof(LNode)); // 创建头指针
    L->next = NULL;

    return L;
}

// 单链表按位取值
void GetElem(const LinkList L, const int i, ElemType *e) {
    // 初始化，p 指向首元节点，计数器 j 初赋值为 1
    const LNode *p = L->next;
    int j = 1;

    // 循环
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }

    // 循环结束，有两种可能：
    // 情况A：找到了第 i 个节点（p 指向它） -> 取值成功
    // 情况B：链表太短，或者 i 非法（比如 i<1 或 i>链表长度） -> p 变成了 NULL
    if (p == NULL || i < 1) {
        printf("查找位置非法\n");
        return;
    }

    *e = p->data;
}

// 单链表按值查找
LNode* LocateElem(const LinkList L, const ElemType e) {
    LNode *p = L->next; // 指向首元节点
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

// 单链表的插入
void listInsert(const LinkList L, const int i, const ElemType e) {
    // 找前驱
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i-1) {
        p = p->next;
        j++;
    }

    if (p == NULL || i < 1) {
        return;
    }

    // 插入
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
}

void listDelete(LinkList L, int i) {
    // 找前驱
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i-1) {
        p = p->next;
        j++;
    }

    if (p == NULL || i < 1) {
        return;
    }

    // 删除
    LNode *q = p->next;

    if (q == NULL) {
        printf("删除位置超出链表长度！\n");
        return;
    }

    p->next = q->next;
    free(q);
}

// 前插法创建单链表

int main() {}
