// https://leetcode.cn/problems/largest-sum-of-averages/
// 题解：dp动态规划，dp[i][j]表示[0,i-1]区间分成j个连续子数组的结果；
// j=1时，dp[i][1] = sum{0,i-1}/i;
// j>1时，dp[i][j] = max(dp[i][j], dp[x][j-1] + sum{x,i-1}/(i-x));
class Solution {
public:
    double largestSumOfAverages(vector<int> &nums, int k) {
        int n = nums.size();
        vector<double> p_sum(n+1,0);
        vector<vector<double>> dp(n+1, vector<double>(k+1, 0));

        for(int i = 0; i < n; i++) {
            p_sum[i+1] = p_sum[i] + nums[i];
        }
        for(int i = 1; i <= n; i++) {
            dp[i][1] = p_sum[i] / i; // dp[i][1] = sum{0,i-1}/i;
        }

        for(int j = 2; j <= k; j++) {
            for(int i = j; i <= n; i++) {
                for(int x = j-1; x <= i-1; x++) {
                    dp[i][j] = max(dp[i][j], dp[x][j-1] + (p_sum[i] - p_sum[x]) / (i - x));
                }
            }
        }

        return dp[n][k];
    }
};
