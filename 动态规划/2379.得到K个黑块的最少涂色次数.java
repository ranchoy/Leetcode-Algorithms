// https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
// 题解：动态规划DP，记录长度为k窗口内的白色块个数k - (dp[i] - dp[i-k])的最小值，滑动窗口也可实现。
class Solution {
    public int minimumRecolors(String blocks, int k) {
        int ans = Integer.MAX_VALUE;
        int n = blocks.length();
        int[] dp = new int[n + 1];

        for(int i = 1; i <= n; i++) {
            int cur = (blocks.charAt(i-1) == 'B') ? 1 : 0;
            dp[i] = dp[i-1] + cur;
            
            if(i >= k) ans = Math.min(ans, k - (dp[i] - dp[i-k])); // compare
        }

        return ans;
    }
}

/*
"WBWBBBW"
2
"WBBWWBBWBW"
7
"BWWWBB"
6

0
3
3
*/