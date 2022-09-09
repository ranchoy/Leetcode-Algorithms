// https://leetcode.cn/problems/wildcard-matching/
// 题解：使用棋盘模拟，当p[j-1]='*'匹配(tab[i-1][j] || tab[i][j-1])是否连续，当p[j-1]='?'|s[i-1]匹配tab[i-1][j-1]是否连续。
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true;
        for(int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j-1] && (p[j-1] == '*'); // p starts with '*'.
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } else if(p[j-1] == s[i-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }

        return dp[n][m];
    }
};

/*
""
"******"
"aa"
"a"
"abcab"
"a*b"

true
true
true
*/
