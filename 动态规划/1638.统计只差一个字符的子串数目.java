// https://leetcode.cn/problems/count-substrings-that-differ-by-one-character/
// 题解：动态规划DP，dp_left[i+1][j+1]表示以s[i]/t[j]结尾的左侧连续相同子串长度，dp_right[i][j]表示以s[i+1]/t[j+1]结尾的右侧连续相同子串长度，结果为\sum((dp_left[i][j] + 1) * (dp[i+1][j+1] + 1))。
class Solution {
    public int countSubstrings(String s, String t) {
        int ans = 0;
        int n = s.length(), m = t.length();
        int[][] dp_left = new int[n + 1][m + 1];
        int[][] dp_right = new int[n + 1][m + 1];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp_left[i + 1][j + 1] = (s.charAt(i) == t.charAt(j)) ? (dp_left[i][j] + 1) : 0;
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                dp_right[i][j] = (s.charAt(i) == t.charAt(j)) ? (dp_right[i + 1][j + 1] + 1) : 0;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s.charAt(i) != t.charAt(j)) ans += (dp_left[i][j] + 1) * (dp_right[i + 1][j + 1] + 1);
            }
        }

        return ans;
    }
}

/*
"aba"
"baba"

6
*/