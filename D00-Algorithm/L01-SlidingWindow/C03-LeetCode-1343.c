// 大小为 K 且平均值大于等于阈值的子数组数目

// 给你一个整数数组 arr 和两个整数 k 和 threshold 。
// 请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。

int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    int sum = 0;
    int counter = 0;

    for (int i = 0; i < arrSize; i++) {

        sum += arr[i];

        int left = i - k + 1;
        if (left < 0) continue;

        if (sum >= threshold * k) counter++;

        sum -= arr[left];
    }

    return counter;
}