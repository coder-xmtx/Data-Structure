// 可获得的最大点数

// 几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。
// 每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。
// 你的点数就是你拿到手中的所有卡牌的点数之和。
// 给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。

int maxScore(int* cardPoints, int cardPointsSize, int k) {
    int n = cardPointsSize;
    long long total = 0;
    for (int i = 0; i < n; i++) total += cardPoints[i];

    int w = n - k;
    if (w == 0) return (int)total;   // 全部拿走

    // 第一个长度为 w 的窗口
    long long sum = 0;
    for (int i = 0; i < w; i++) sum += cardPoints[i];
    long long min = sum;

    // 滑动窗口
    for (int i = w; i < n; i++) {
        sum += cardPoints[i] - cardPoints[i - w];
        if (sum < min) min = sum;
    }

    return (int)(total - min);
}