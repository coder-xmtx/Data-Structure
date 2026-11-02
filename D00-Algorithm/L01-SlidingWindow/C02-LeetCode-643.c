// 子数组最大平均数 I

// 给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。
// 请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。
// 任何误差小于 10-5 的答案都将被视为正确答案。

#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

double findMaxAverage(int* nums, int numsSize, int k) {
    int sum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];

        int left = i - k + 1;
        if (left < 0) continue;

        maxSum = MAX(maxSum, sum);

        sum -= nums[left];
    }

    return (double)maxSum / k;
}