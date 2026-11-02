// 长度为 K 子数组中的最大和

// 给你一个整数数组 nums 和一个整数 k 。请你从 nums 中满足下述条件的全部子数组中找出最大子数组和：
// - 子数组的长度是 k，且
// - 子数组中的所有元素 各不相同 。
// 返回满足题面要求的最大子数组和。如果不存在子数组满足这些条件，返回 0 。
// 子数组 是数组中一段连续非空的元素序列。

#include "../Libaray/uthash.h"
#include <stdlib.h>

// 使用哈希表
typedef struct {
    int key;
    int count;
    UT_hash_handle hh;
} FreqItem;

long long maximumSubarraySum(int* nums, int numsSize, int k) {

    FreqItem *users = NULL; // 初始化哈希表
    long long ans = 0;
    long long sum = 0;

    for (int i = 0; i < numsSize; i++) {

        sum += nums[i];

        FreqItem *it = NULL;
        HASH_FIND_INT(users, &nums[i], it);

        if (it == NULL) {
            it = (FreqItem*)malloc(sizeof(FreqItem));
            it->key = nums[i];
            it->count = 1;
            HASH_ADD_INT(users, key, it);
        }
        else {
            it->count++;
        }

        int left = i - k + 1;

        if (left >= 0) {
            if (HASH_COUNT(users) == k) {
                if (sum > ans) ans = sum;
            }

            FreqItem *old = NULL;
            HASH_FIND_INT(users, &nums[left], old);

            if (old != NULL) {
                old->count--;
                if (old->count == 0) {
                    HASH_DEL(users, old);
                    free(old);
                }
            }

            sum -= nums[left];
        }
    }

    // 清理哈希表
    FreqItem *cur, *tmp;
    HASH_ITER(hh, users, cur, tmp) {
        HASH_DEL(users, cur);
        free(cur);
    }

    return ans;
}