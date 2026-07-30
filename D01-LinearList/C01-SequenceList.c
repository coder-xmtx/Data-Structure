#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElementType;

typedef struct {
    ElementType *data;
    int length;
} SeqList;

// 初始化顺序表
// void initList(SeqList *L) {
//     L->length = 0;
// }

// 初始化顺序表 - 使用动态内存
SeqList *initList() {
    SeqList *list = (SeqList *) malloc(sizeof(SeqList));
    list->data = (ElementType *) malloc(sizeof(ElementType) * MAXSIZE);
    list->length = 0;
    return list;
}

// 在顺序表尾部添加元素
int appendList(SeqList *L, const ElementType x) {
    if (L->length >= MAXSIZE) {
        printf("Error. The List is Overflow.\n");
        return 0;
    }

    L->data[L->length] = x;
    L->length++;

    return 1;
}

// 遍历顺序表
void printList(const SeqList *L) {
    if (L->length == 0) return;
    for (int i = 0; i < L->length; i++) printf("%d ", L->data[i]);
    printf("\n");
}

// 在顺序表中插入元素（比如，在第 2 个位置插入元素，实际是在下标为 1 的位置插入）
int insertList(SeqList *L, const ElementType x, const int position) {
    if (L->length >= MAXSIZE) {
        printf("Error. The List is Overflow.\n");
        return 0;
    }
    if (position >= L->length || position < 1) {
        printf("Error. Position out of range.\n");
        return 0;
    }

    for (int i = L->length - 1; i >= position - 1; i--) {
        L->data[i + 1] = L->data[i];
    }

    L->data[position - 1] = x;
    L->length++;

    return 1;
}

// 删除元素（position依旧是实际位置不是下标，*x 用来查看被删除元素）
int deleteList(SeqList *L, const int position, ElementType *x) {
    if (L->length == 0) {
        printf("Error. The List is Empty.\n");
        return 0;
    }

    if (L->length < 1 || position > L->length) {
        printf("Error. Position out of range.\n");
        return 0;
    }

    *x = L->data[position - 1];

    for (int i = position; i < L->length; i++) {
        L->data[i - 1] = L->data[i];
    }

    L->length--;

    return 1;
}

// 查找元素（用元素找第一次出现的位置）
int searchList(SeqList *L, const ElementType x) {
    if (L->length == 0) {
        printf("Error. The List is Empty.\n");
    }
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == x) {
            return i + 1;
        }
    }
    return -1;
}

int main(void) {
    // 声明一个顺序表并初始化
    SeqList *List = initList();
    printf("Finish. The Length of List = %d\n", List->length);
    printf("Finish. The Byte of List = %zu\n", sizeof(List->data));

    // 顺序表添加元素
    appendList(List, 10);
    appendList(List, 20);
    appendList(List, 30);
    printList(List); // 遍历顺序表

    // 插入中间元素
    insertList(List, 15, 2);
    printList(List); // 遍历顺序表

    // 删除元素
    ElementType delete_element;
    deleteList(List, 2, &delete_element);
    printList(List);
    printf("Delete: %d\n", delete_element);

    // 查找元素
    printf("The Position of element 30: %d\n", searchList(List, 30));

    free(List);

    return 0;
}
