#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    void reOrderArray(vector<int> &array) {
         int l = 0, r = array.size()-1;
         while(l<r)
         {
             while(l<r&&array[l]%2)
             {
                 l++;
             }
             while(l<r&&!(array[r]%2))
             {
                 r--;
             }
             swap(array[l],array[r]);
             l++;
             r--;
         }
         return;
    }
};


//2952. 需要添加的硬币的最小数量 每日一

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        int x = 1;
        int length = coins.size(), index = 0;
        while (x <= target) {
            if (index < length && coins[index] <= x) {
                x += coins[index];
                index++;
            } else {
                x <<= 1;
                ans++;
            }
        }
        return ans;
    }
};

//思路：排序 + 贪心