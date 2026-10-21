# 二分查找

该算法的时间复杂度为 $O(log_2 n)$，每次循环都把搜索区间缩小一半。


## 例题：LeetCode 852

给定一个长度为 `n` 的整数山脉数组 `arr`，其中的值递增到一个峰值元素然后递减。

返回峰值元素的下标。

你必须设计并实现时间复杂度为 $O(log_2 n)$ 的解决方案。

### 解法

比较中间元素和它的下一个元素，判断当前处于上升还是下降段

```c++
int peakIndexInMountainArray(int* arr, int arrSize) {
    int left = 0;
    int right = arrSize - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < arr[mid + 1]) left = mid + 1;
        else right = mid;
    }
    return left;
}
```