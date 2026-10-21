// 单链表的查找、插入、删除

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 单链表结构体
typedef struct LNode {
    int data;           // 数据域
    struct LNode *next; // 指针域
} LNode;


// 按值查找
// 在单链表中查找值为 e 的结点
LNode* Find(LNode *L, int e) {
    // 从第一个结点开始
    LNode *p = L->next;
    // 依次和e进行比较，直到找到了e或者走到了末尾NULL
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}


// 按位序查找
// 在单链表中找第 k 个结点
LNode* FindKth(LNode *L, int k) {
    // 查找位序不小于0
    if (k < 0) return NULL;
    // 设头结点为第0个结点
    LNode *p = L;
    // 遍历
    int i = 0;
    while (p != NULL && i < k) {
        p = p->next;
        i++;
    }
    return p;
}


// 插入
// 在单链表的第 i 个位置插入数据 e
bool Insert(LNode *L, int i, int e) {
    // 先找到插入位置的前一个结点p
    LNode *p = FindKth(L, i - 1);
    // 如果插入位置不合法，返回
    if (p == NULL) return false;
    // 创建新结点，将其插入到p结点之后
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}


// 删除
// 删除单链表第 i 个结点
bool Delete(LNode *L, int i) {
    // 先找到删除位置的前一个结点p
    LNode *p = FindKth(L, i - 1);
    // 如果删除位置不合法（不存在前一个结点或者要删除的结点），返回
    if (p == NULL || p->next == NULL) return false;
    // 删除p后面的结点，用一个指针来记录被删除的结点，用于后面销毁
    LNode *record = p->next;
    p->next = record->next;
    free(record);

    return true;
}