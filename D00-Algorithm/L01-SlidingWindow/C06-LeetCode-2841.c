// 几乎唯一子数组的最大和

// 给你一个整数数组 nums 和两个正整数 m 和 k 。
// 请你返回 nums 中长度为 k 的 几乎唯一 子数组的 最大和 ，如果不存在几乎唯一子数组，请你返回 0 。
// 如果 nums 的一个子数组有至少 m 个互不相同的元素，我们称它是 几乎唯一 子数组。
// 子数组指的是一个数组中一段连续 非空 的元素序列。

#include "../Libaray/uthash.h"
#include <stdlib.h>

typedef struct {
    int key;
    int count;
    UT_hash_handle hh;
} FreqItem;

long long maxSum(int* nums, int numsSize, int m, int k) {
    FreqItem *users = NULL;
    long long sum = 0;
    long long ans = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        sum += x;

        FreqItem *it = NULL;
        HASH_FIND_INT(users, &x, it);

        if (it == NULL) {
            it = (FreqItem*)malloc(sizeof(FreqItem));
            it->key = x;
            it->count = 1;
            HASH_ADD_INT(users, key, it);
        } else {
            it->count++;
        }

        int left = i - k + 1;

        if (left >= 0) {
            // 当前窗口是 [left, i]，长度为 k
            if (HASH_COUNT(users) >= m) {
                if (sum > ans) {
                    ans = sum;
                }
            }

            // 移除左边界元素
            int y = nums[left];
            FreqItem *old = NULL;
            HASH_FIND_INT(users, &y, old);

            if (old != NULL) {
                old->count--;
                if (old->count == 0) {
                    HASH_DEL(users, old);
                    free(old);
                }
            }

            sum -= y;
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