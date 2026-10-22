// 双向链表

#include <stdio.h>

// 双向链表结构体
typedef struct DLNode {
    int data;              // 数据
    struct DLNode *prior;  // 前驱指针
    struct DLNode *next;   // 后继指针
}DLNode;