// https://leetcode.cn/problems/climbing-stairs/
// 题解：动态规划DP，递推公式：dp[i] = dp[i-1] + dp[i-2]。
class Solution {
    public int climbStairs(int n) {
        if(n <= 2) return n;
        int ans = 0, pre1 = 1, pre2 = 2;

        for(int i = 3; i <= n; i++) {
            ans = pre1 + pre2;
            pre1 = pre2; pre2 = ans;
        }

        return ans;
    }
}

/*
1
2
4

1
2
5
*/
