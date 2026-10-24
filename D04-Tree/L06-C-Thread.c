// 线索二叉树

typedef struct BTNode {
    char data;
    struct BTNode *lchird, *rchild;
    int ltag, rtag; // 为0，指向孩子结点；为1，指向前驱/后继
} BTNode;

