// https://leetcode.cn/problems/decode-ways/
// 题解：动态规划DP，单字符：dp[i] += dp[i-1]，双字符：dp[i] += dp[i-2]，结果为dp[n]。
class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        int a = 0, b = 1, c = 0; // dp[i-2], dp[i-1], dp[i]

        for(int i = 1; i <= n; i++) {
            c = 0;
            if(s.charAt(i-1) != '0') c += b; // dp[i] = dp[i-1];
            if(i > 1 && s.charAt(i-2) != '0' && 10 * (s.charAt(i-2) - '0') + (s.charAt(i-1) - '0') <= 26) c += a; // dp[i] = dp[i-2];
            a = b; b = c; // update
        }

        return c;
    }
}

/*
"06"
"12"
"226"

0
2
3
*/