// 并查集
// 利用数组来存储对应下标值的父结点的值


#define MAXN 100

int p[MAXN];

// 初始化
// 让元素值 = 下标
void Initial(int n) {
    for (int i = 0; i < n; i++) p[i] = i;
}


// 查询元素x属于哪个集合（找根结点）
int Find(int x) {
    // 找到了返回，根结点的元素值等于下标值
    if (p[x] == x) return x;

    // 没找到继续递归
    // return Find(p[x]);

    // 【优化】使用路径压缩，将查找元素上的元素直接指向根，那么下次查找就是O(1)复杂度
    return p[x] = Find(p[x]);
}


// 合并两个元素所属的集合（合并根结点）
void Union(int x, int y) {
    // 先用Find找到两个元素的根结点
    int rootx = Find(x);
    int rooty = Find(y);
    // 如果根不一样，证明就是两个不同的集合，合并
    if (rootx != rooty) p[rootx] = rooty;
}

// 合并优化 方法1
// 按高度合并：多使用一个高度h数组记录集合的高度，让矮树合并到高树上，合并后高度不变
// 注意，如果Find函数有路径压缩，树的高度在Find操作后可能会变矮，但是h数组并没有更新，不过不用管
int h[MAXN]; // 初始化的时候要 h[i] = 1
void UnionOptimizeHigh(int x, int y) {
    // 先用Find找到两个元素的根结点
    int rootx = Find(x);
    int rooty = Find(y);
    // 矮树合并到高树上
    if (rootx != rooty) {
        if (h[rootx] < h[rooty]) p[rootx] = rooty;
        else if (h[rootx] > h[rooty]) p[rooty] = rootx;
        else {
            p[rootx] = rooty;
            h[rooty]++;
        }
    }
}

// 合并优化 方法2
// 按大小合并：多使用一个大小s数组记录集合结点的个数，让小树合并到大树上
int s[MAXN]; // 初始化的时候要 s[i] = 1
void UnionOptimizeSize(int x, int y) {
    // 先用Find找到两个元素的根结点
    int rootx = Find(x);
    int rooty = Find(y);
    // 小树合并到大树上
    if (rootx != rooty) {
        if (s[rootx] <= s[rooty]) {
            p[rootx] = rooty;
            s[rooty] += s[rootx];
        }
        else {
            p[rooty] = rootx;
            s[rootx] += s[rooty];
        }
    }
}

