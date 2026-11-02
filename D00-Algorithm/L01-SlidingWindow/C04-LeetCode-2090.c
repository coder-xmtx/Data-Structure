// 半径为 k 的子数组平均值

// 给你一个下标从 0 开始的数组 nums ，数组中有 n 个整数，另给你一个整数 k 。
// 半径为 k 的子数组平均值 是指：nums 中一个以下标 i 为 中心 且 半径 为 k 的子数组中所有元素的平均值，即下标在 i - k 和 i + k 范围（含 i - k 和 i + k）内所有元素的平均值。
// 如果在下标 i 前或后不足 k 个元素，那么 半径为 k 的子数组平均值 是 -1 。
// 构建并返回一个长度为 n 的数组 avgs ，其中 avgs[i] 是以下标 i 为中心的子数组的 半径为 k 的子数组平均值 。
// x 个元素的 平均值 是 x 个元素相加之和除以 x ，此时使用截断式 整数除法 ，即需要去掉结果的小数部分。
// 例如，四个元素 2、3、1 和 5 的平均值是 (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75，截断后得到 2 。

int* getAverages(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize;
    int* avgs = (int*)malloc(sizeof(int) * numsSize);
    if (numsSize == 0) return avgs;

    int windowSize = 2 * k + 1;
    long long sum = 0;

    // 先计算第一个有效窗口的和（即 i = k 时的窗口 [0, 2k]）
    // 如果 k 太大，窗口不存在，则全部为 -1
    if (windowSize > numsSize) {
        for (int i = 0; i < numsSize; i++) {
            avgs[i] = -1;
        }
        return avgs;
    }

    // 初始化第一个窗口的和
    for (int i = 0; i < windowSize; i++) {
        sum += nums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        if (i < k || i + k >= numsSize) {
            avgs[i] = -1;
        }
        else {
            // 当 i == k 时，窗口和已经在上面的循环中计算好了
            // 对于 i > k，滑动窗口：加上右边新元素，减去左边旧元素
            if (i > k) {
                sum += nums[i + k] - nums[i - k - 1];
            }
            avgs[i] = sum / windowSize;
        }
    }

    return avgs;
}