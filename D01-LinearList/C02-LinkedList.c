#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node {
    ElementType data;
    struct Node *next;
} Node;


// 单链表初始化
Node* initNode() {
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0; // 头节点设为0
    head->next = NULL; // 指向下一个节点的指针也设为空
    return head;
}

// 单链表 - 头插法，每次插入数据都插在头节点的后面
// 头插法的顺序和排列是相反的
void insertHead(Node *head, ElementType x) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = head->next;
    head->next = newNode;
}

// 遍历
void printList(Node *head) {
    Node *p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 单链表 - 尾插法 - 利用遍历先获取尾节点
Node* getTail(Node *head) {
    Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    return p;
}

// 单链表 - 尾插法
Node* insertTail(Node *tail, ElementType x) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    tail->next = newNode;
    return newNode;
}

// 单链表 - 在指定位置插入
void insertPosition(Node *head, ElementType x, const int pos) {
    Node *p = head;
    int i = 0;

    // 找到插入位置的前驱节点
    while (i <= pos - 1) {
        p = p->next;
        i++;
        if (p == NULL) return;
    }

    // 要插入的新节点
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
}

// 单链表 - 删除节点
void deleteNode(Node *head, ElementType x, const int pos) {
    Node *p = head;
    int i = 0;

    // 找到插入位置的前驱节点
    while (i <= pos - 1) {
        p = p->next;
        i++;
        if (p == NULL) return;
    }

    if (p->next == NULL) {
        printf("Deleted element not found in list\n");
        return;
    }

    // delNode 指向要删除的节点
    Node *delNode = p->next;
    // 让要删除节点的前驱指向要删除节点的后继
    p->next = delNode->next;
    // 释放被删除节点的内存空间
    free(delNode);

}

// 单链表 - 获取链表长度（包括头节点）
int lengthNode(Node *head) {
    Node *p = head;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// 单链表 - 释放整个链表（包括头节点）
void freeList(Node *head) {
    Node *p = head;
    while (p != NULL) {
        Node *tmp = p;
        p = p->next;
        free(tmp);
    }
}

int main() {
    // 头插法
    Node *list_1 = initNode();

    insertHead(list_1, 3);
    insertHead(list_1, 4);
    insertHead(list_1, 5);

    printList(list_1);
    freeList(list_1);

    // 尾插法
    Node *list_2 = initNode();
    Node *tail = getTail(list_2);
    tail = insertTail(tail, 10);
    tail = insertTail(tail, 20);
    tail = insertTail(tail, 30);
    printList(list_2);
    freeList(list_2);

    return 0;
}