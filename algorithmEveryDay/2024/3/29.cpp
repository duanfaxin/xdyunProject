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