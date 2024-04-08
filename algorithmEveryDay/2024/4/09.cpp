
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     int maximumCount(vector<int>& nums) {
//         //二分查找
//         int _right = nums.size() - 1;
//         int _left = 0;
//         int mid = 0;
//         while(_right > _left)
//         {
//             mid = (_left + _right)/2; //不会溢出
//             if(nums[mid] > 0)
//             {
//                  _right = mid;
//             }else if(nums[mid] < 0)
//             {
//                  _left = mid + 1;
//             }else {
//                 break;
//             }
//         }
//         if(_left < _right) //找到0了
//         {
//             _left = mid;
//             while(nums[_left]==0)
//             {
//                 _left--;
//             }
//             while(nums[_right]==0)
//             {
//                 _right++;
//             }
//              cout<<_left<<"  --  "<<_right;
//             if((nums.size()-_right)>(_left + 1))
//             {
//                 return nums.size()-_right;
//             }else {
//                 return _left + 1;
//             }
//         }else {
//             cout<<_left<<"    "<<_right;
//             return nums.size() - _right > _left + 1 ? nums.size() - _right :  _left ;
//         }
//     }
// };

class Solution
{
public:
    int lowerBound(vector<int> &nums, int val)
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums[m] >= val)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }

    int maximumCount(vector<int> &nums)
    {
        int pos1 = lowerBound(nums, 0);
        int pos2 = lowerBound(nums, 1);
        return max(pos1, (int)nums.size() - pos2);
    }
};