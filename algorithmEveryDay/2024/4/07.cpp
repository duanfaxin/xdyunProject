#include <iostream>
#include <unordered_map>
#include <vector>
// 输入一个 32位整数，输出该数二进制表示中 1 的个数
class Solution
{
public:
    int NumberOf1(int n)
    {
        int res = 0;
        unsigned int un = n;
        while (un)
        {
            res += un & 1;
            un >>= 1;
        }
        return res;
    }
};

// (位运算) O(logn)()
// 迭代进行如下两步，直到 n
// 变成0为止：

// 如果 n在二进制表示下末尾是1，则在答案中加1；
// 将 n 右移一位，也就是将 n在二进制表示下的最后一位删掉；
// 这里有个难点是如何处理负数。
// 在C++ 中如果我们右移一个负整数，系统会自动在最高位补1，这样会导致 n
// 永远不为0，就死循环了。
// 解决办法是把 n
// 强制转化成无符号整型，这样 n
// 的二进制表示不会发生改变，但在右移时系统会自动在最高位补0。时间复杂度每次会将 n除以2，最多会除 logn次，所以时间复杂度是 O(logn)
