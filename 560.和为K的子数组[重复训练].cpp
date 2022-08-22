// https://leetcode-cn.com/problems/subarray-sum-equals-k/
// 前缀和，dp[i]表示区间[0,i]内的元素和，map存储dp[i]
// 推导，假设区间[i,j]的元素和为k，则：dp[j] = dp[i] + k;
// 出现连续子数组和为k的次数：cnt += mp[dp_sum - k];
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int cnt = 0, dp_sum = 0;
        unordered_map<int,int> mp; // <dp[i],times>
        mp.insert(make_pair(0, 1));
        for(int i = 0; i < nums.size(); i++) {
            dp_sum += nums[i];

            if(mp.find(dp_sum-k) != mp.end()) {
                cnt += mp[dp_sum-k];
            }
            if(mp.find(dp_sum) == mp.end()) {
                mp.insert(make_pair(dp_sum, 1)); // 注意数组有负数，相同前缀和可能多次出现
            } else {
                mp[dp_sum] += 1;
            }
        }
        return cnt;
    }
};

/*
[1,1,1]
2
[1,2,3]
3
[1,-1,0]
0
[1,2,1,2,1]
3

2
2
3
4
*/
