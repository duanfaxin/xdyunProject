#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        unordered_map<int,int> mp;
        int count  = 0,index = 0,sum = -1; //count记录访问了
        while(count < nextVisit.size())
        {
            
            if(!mp.count(index))
            {
                //cout<<count<<"  "<<endl;
                count++;
            }
            mp[index]++;
            if(mp[index]%2 == 1)
            {
                 //cout<<index<<"  1"<<endl;
                index = nextVisit[index];
            }else{
                    //cout<<index<<"  2"<<endl;
                    index = (index + 1) % nextVisit.size();
                }
        
            
            sum++;
        }
        return  sum % 100000007;
    }
};

//题解  //动态规划
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int mod = 1e9 + 7;
        int len = nextVisit.size();
        vector<int> dp(len);

        dp[0] = 2; //初始化原地待一天 + 访问下一个房间一天
        for (int i = 1; i < len; i++) {
            int to = nextVisit[i];
            dp[i] = 2 + dp[i - 1];
            
            if (to != 0) {
                dp[i] = (dp[i] - dp[to - 1] + mod) % mod; //避免负数
            }
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        }
        return dp[len - 2]; //题目保证n >= 2
    }
};
