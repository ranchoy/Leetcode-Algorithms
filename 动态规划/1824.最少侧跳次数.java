// https://leetcode.cn/problems/minimum-sideway-jumps/
// 题解：动态规划DP，dp[i][j]表示点i和赛道j处的最小侧跳次数，dp[i][j]与dp[i-1][j]相关，故可以压缩成一维状态空间。
// if obstacles[i]==j+1 : dp[i][j]=INF; else: dp[i][j]=min(dp[i-1][j], min dp[i][k,0<=k<=2 && k!=j]);
class Solution {
    public int minSideJumps(int[] obstacles) {
        int n = obstacles.length;
        int[] dp = new int[3];

        dp[1] = 0; dp[0] = dp[2] = 1;
        for(int i = 1; i < n; i++) {
            int min_cnt = Integer.MAX_VALUE;
            for(int j = 0; j < 3; j++) {
                if(obstacles[i] == j + 1) {
                    dp[j] = Integer.MAX_VALUE;
                } else {
                    min_cnt = Math.min(min_cnt, dp[j]);
                }
            }

            for(int j = 0; j < 3; j++) {
                if(obstacles[i] == j + 1) continue;
                dp[j] = Math.min(dp[j], min_cnt + 1); // 若dp[i][j]就是最小的，其值不变。
            }
        }

        return Math.min(dp[0], Math.min(dp[1], dp[2]));
    }
}