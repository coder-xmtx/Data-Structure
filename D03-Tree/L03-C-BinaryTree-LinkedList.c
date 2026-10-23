// 二叉树 - 链式存储
// n个结点的二叉树，空指针数为 n+1

// 二叉链表结构体
typedef struct BTNode {
    char data;
    struct BTNode *lchird, *rchild;
} BTNode;


// 三叉链表结构体
// 为了方便找父结点，可以再加个指针域 *parent
typedef struct BTNodeP {
    char data;
    struct BTNodeP *lchird, *parent, *rchild;
} BTNodeP;
