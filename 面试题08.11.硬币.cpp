// https://leetcode-cn.com/problems/coin-lcci/
// DP动态规划，dp[i][v] = dp[i-1][v] + dp[i][v-ci]，注意转移公式。
class Solution {
public:
    int mod = 1000000007;
    vector<int> coins = {1, 5, 10, 25};

    int waysToChange(int n) {
        vector<int> dp(n+1,0); dp[0] = 1;
        for(int k = 0; k < coins.size(); k++) {
            for(int i = coins[k]; i <= n; i++) {
                dp[i] = (dp[i] + dp[i - coins[k]]) % mod;
            }
        }
        return dp[n];
    }

};

/*
5
10

2
4
*/
