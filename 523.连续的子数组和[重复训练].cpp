// https://leetcode-cn.com/problems/continuous-subarray-sum/
// 前缀和，dp[i]表示区间[0,i]的元素和，假设结果是区间[i,j]，则有：(dp[j]-dp[i])%k=0；
// 因此，dp[i]%k==dp[j]%k，余数相同，即一旦出现两个相同的余数且(j-i>=2)，则返回ture，否则返回false。
class Solution {
public:
    map<pair<int,int>, int> mp; // 剪枝
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        if(n == 1) return false;

        int dp_sum = 0, r = 0;
        unordered_map<int,int> hash_mp; // <余数,idx>
        hash_mp.insert(make_pair(0,-1)); // 重要，[1,2],3 -> r=3%3=0,idx:2-0=2
        for(int i = 0; i < n; i++) {
            dp_sum = (dp_sum + nums[i])%k;
            r = dp_sum%k;
            if(hash_mp.find(r) != hash_mp.end() && (i - hash_mp[r] >= 2)) {
                return true;
            } else {
                hash_mp.insert(make_pair(r,i));
            }
        }
        return false;
    }
};

/*
[1,0]
2
[23,2,4,6,6]
7
[23,2,6,4,7]

false
true
true
*/
