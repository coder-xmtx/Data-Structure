// 快慢指针

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node {
    ElementType data;
    struct Node *next;
} Node;

// Q01 第 1 题 查找倒数第 k 个位置
int findNodeWithFastLow(Node* head, int k) {
    // 快慢指针都从第一个位置开始（头节点后的那个位置）
    Node* fast = head->next;
    Node* slow = head->next;

    // 快指针先走 k 步
    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }

    // 然后快慢指针一起走
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    printf("倒数第%d个节点值为：%d\n", k, slow->data);

    return 1;
}

// Q01 第 2 题
Node* findIntersectionNodeWithFastLow(Node* headA, Node* headB) {

    if (headA == NULL || headB == NULL) return NULL;

    int lenA = 0;
    int lenB = 0;

    // 遍历链表A，获取其长度
    Node *p = headA;
    while (p != NULL) {
        lenA++;
        p = p->next;
    }

    // 遍历链表B，获取其长度
    p = headB;
    while (p != NULL) {
        lenB++;
        p = p->next;
    }

    Node* fast; // 快指针
    Node* slow; // 慢指针
    int step = abs(lenA - lenB);
    if (lenA > lenB) {
        fast = headA;
        slow = headB;
    }
    else {
        fast = headB;
        slow = headA;
    }

    // 让快指针先走 step 步
    for (int i = 0; i < step; i++) fast = fast->next;

    // 快慢指针同步走，直到指向同一个节点退出循环
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}
