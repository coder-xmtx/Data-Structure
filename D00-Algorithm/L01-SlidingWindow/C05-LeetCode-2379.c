// 得到 K 个黑块的最少涂色次数

// 给你一个长度为 n 下标从 0 开始的字符串 blocks ，blocks[i] 要么是 'W' 要么是 'B' ，表示第 i 块的颜色。字符 'W' 和 'B' 分别表示白色和黑色。
// 给你一个整数 k ，表示想要 连续 黑色块的数目。
// 每一次操作中，你可以选择一个白色块将它 涂成 黑色块。
// 请你返回至少出现 一次 连续 k 个黑色块的 最少 操作次数。

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int minimumRecolors(char* blocks, int k) {
    int min = 0;
    int black = 0;
    int change = 0;

    for (int i = 0; blocks[i]; i++) {

        if (blocks[i] == 'B') black++;
        else change++;

        int left = i - k + 1;

        if (left < 0) continue;

        char out = blocks[left];



        if (black == k) {
            min = 0;
            break;
        }
        else {
            min = i >= k ? MIN(min,change) : change;
        }

        if (out == 'B') black--;
        else change--;
    }

    return min;
}