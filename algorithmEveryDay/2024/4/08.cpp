
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

// 2009. 使数组连续的最少操作数

// 给你一个整数数组 nums 。每一次操作中，你可以将 nums 中 任意 一个元素替换成 任意 整数。
//  如果 nums 满足以下条件，那么它是 连续的 ：
// nums 中所有元素都是 互不相同 的。
//  nums 中 最大 元素与 最小 元素的差等于 nums.length -
// 1 。 比方说，nums = [ 4, 2, 5, 3 ] 是 连续的 ，但是 nums = [ 1, 2, 3, 5, 6 ] 不是连续的 。
// 请你返回使 nums 连续 的 最少 操作次数。
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> cnt(nums.begin(), nums.end());
        vector<int> sortedUniqueNums(cnt.begin(), cnt.end());
        sort(sortedUniqueNums.begin(), sortedUniqueNums.end());
        int res = n, j = 0;
        for (int i = 0; i < sortedUniqueNums.size(); i++)
        {
            int right = sortedUniqueNums[i] + n - 1;
            while (j < sortedUniqueNums.size() && sortedUniqueNums[j] <= right)
            {
                res = min(res, n - (j - i + 1));
                j++;
            }
        }
        return res;
    }
};

// 方法一：去重 + 排序 + 滑动窗口 思路

// 记数组 nums\textit{nums} nums 的长度为 nnn。经过若干次操作后，若数组变为连续的，那么数组的长度不会改变，仍然为 nnn，且数组最大值与最小值之差为 n−1n -
//  1n−1，所有元素均不相同。可以反向考虑，假设最后连续的数组的最小值为 leftleftleft，则最大值 right = left + n−1right = left + n - 1right = left + n−1。
// 原数组 nums\textit{nums} nums 中，如果有位于[left,
// right][\textit{left}, \textit{right}][left, right] 中的，如果只出现一次，我们可以对其进行保留；
// 多次出现时，我们则需要对其进行操作；不在这个区间的数字，我们也需要对其进行操作，
// 将它们变成其他数字来对这个区间进行补足。因此，我们需要统计原数组 nums\textit{nums} nums 中，位于区间[left, right][\textit{left}, \textit{right}][left, right]
// 内不同的数字个数 kkk，而 n−kn - kn−k 就是我们需要进行的操作数。
// 接下来就是需要确定 left\textit{left} left，我们可以将原数组 nums\textit{nums} nums 所有不同的数字作为 left\textit{left} left 的候选值，分别计算出 n−kn -
//  kn−k，然后求出最小值。这样的话，我们可以先将原数字进行去重后排序，然后利用滑动窗口。滑动窗口左端点的值作为 left\textit{left} left，
// 然后向右扩展右端点，窗口的长度即为 kkk，求出所有可能性下最小的 n−kn - kn−k 即可。
