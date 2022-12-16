// https://leetcode.cn/problems/longest-common-subsequence/
// 题解：动态规划DP, 二维dp[i][j]表示text1[0,i-1]和text2[0,j-1]的最长公共子序列长度。
// 二维DP, 当text1[i-1]=text2[j]时, dp[i][j] = dp[i-1][j-1] + 1; 否则, dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
// 一维DP, 当text1[i-1]=text2[j]时, dp[j] = top_left + 1; 否则, dp[j] = max(dp[j-1], dp[j]);
// 维度优化, 注意二维DP的状态与上一轮的dp[i-1][j-1]和dp[i-1][j]，以及当前轮dp[i][j-1]相关。当优化成一维时, 注意保存上一轮的top_left值。
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> dp(m+1, 0);

        for(int i = 1; i <= n; i++) {
            int top_left = 0; // 等价于二维dp[0][0]
            for(int j = 1; j <= m; j++) {
                int next_top_left = dp[j];
                if(text1[i-1] == text2[j-1]) {
                    dp[j] = top_left + 1;
                } else {
                    dp[j] = max(dp[j-1], dp[j]);
                }
                top_left = next_top_left; // 等价于二维dp[i-1][j-1]
            }
        }

        return dp[m];
    }

    int longestCommonSubsequence2(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};
/*
"abcde"
"ace"
"abcba"
"abcbcba"
"bsbininm"
"jmjkbkjkv"

3
5
1
*/
