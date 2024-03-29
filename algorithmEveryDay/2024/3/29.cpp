#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int count = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] < nums[j] && nums[j] > nums[k]) {
                        //cout << i << "  " << j << "  " << k << endl;
                        if (count < 0) {
                            count = nums[i] + nums[j] + nums[k];
                        } else {
                            count = min(nums[i] + nums[j] + nums[k], count);
                        }
                    }
                }
            }
        }
        return count;
    }
};
//////


class Solution1 {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size(), res = 1000, mn = 1000; 
        vector<int> left(n);
        for (int i = 1; i < n; i++) {
            left[i] = mn = min(nums[i - 1], mn); //找到左边最小
        }

        int right = nums[n - 1];
        for (int i = n - 2; i > 0; i--) {
            if (left[i] < nums[i] && nums[i] > right) {
                res = min(res, left[i] + nums[i] + right); //找出总和最小
            }
            right = min(right, nums[i]); //更新右边最小
        }

        return res < 1000 ? res : -1;
    }
};
