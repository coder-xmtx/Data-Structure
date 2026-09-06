#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 创建链表节点
typedef struct Node {
    ElementType data;
    struct Node *next;
} Node;

Node* initNode() {
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0; // 头节点设为0
    head->next = NULL; // 指向下一个节点的指针也设为空
    return head;
}

// 第 1 题 查找倒数第 k 个位置
int findNodeWithFastLow(Node* head, const int k) {
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

// 第 2 题
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
    const int step = abs(lenA - lenB);
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

// 第 3 题
// 其中 n 是绝对值最大的数，用来创建数组
void removeSameNode(Node* head, const int n) {
    Node* p = head;
    int index;
    int *q = (int*)malloc(sizeof(int) * (n+1));

    // 遍历数组，初始化为0
    for (int i = 0; i < n+1; i++) *(q+i) = 0;

    while (p->next != NULL) {
        index = abs(p->next->data);
        if (*(q+index) == 0) {
            *(q+index) = 1;
            p = p->next;
        }
        else {
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    free(q);
}

// 第 4 题  反转链表
Node* reverseList(Node* head) {
    Node *first = NULL;
    Node *second = head->next;
    Node *third;

    while (second != NULL) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    Node *newHead = initNode();
    newHead->next = first;

    return newHead;
}

// 第 5 题  删除链表中间节点
void deleteMiddleNode(Node* head) {
    Node *fast = head->next;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = temp->next;
    free(temp);
}

// 第 6 题  链表重新排序
void reOrderList(Node* head) {
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node* first = NULL;
    Node* second = slow->next;
    Node* third = NULL;

    while (second != NULL) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    Node *p1 = head->next;
    Node *q1 = first;
    Node *p2, *q2;
    while (p1 != NULL && q1 != NULL) {
        p2 = p1->next;
        q2 = q1->next;

        p1->next = q1;
        q1->next = p2;

        p1 = p2;
        q1 = q2;
    }
}