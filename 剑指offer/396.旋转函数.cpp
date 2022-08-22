// https://leetcode-cn.com/problems/rotate-function/
// DP动态规划，注意推导公式，dp[k] - dp[k-1] = (sum - arr[n-k]) - (n-1)*arr[n-k];
class Solution {
public:
    int maxRotateFunction(vector<int> &nums) {
        int dp_sum = 0;
        int n = nums.size();
        int mx = INT_MIN, dp_val = 0;

        for(int i = 0; i < n; i++) {
            dp_sum += nums[i];
            dp_val += i * nums[i]; // dp[0]
        }
        mx = dp_val;
        for(int k = 1; k < n; k++) {
            dp_val = dp_val + dp_sum - n * nums[n-k]; // dp[k]
            mx = max(mx, dp_val);
        }
        return mx;
    }
};

/*
[4,3,2,6]
26
*/
