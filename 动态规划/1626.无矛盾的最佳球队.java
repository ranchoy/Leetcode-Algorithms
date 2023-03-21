// https://leetcode.cn/problems/best-team-with-no-conflicts/
// 题解：动态规划DP，最长递增子序列，dp[i]表示以ages[i]结尾的递增子序列的最大得分，则有转移方程dp[i] = max(dp[j], 0<=j<i)。
class Solution {
    public int bestTeamScore(int[] scores, int[] ages) {
        int ans = 0;
        int n = scores.length;
        int[] dp = new int[n+1];
        var idx_arr = new Integer[n];

        for(int i = 0; i < n; i++) idx_arr[i] = i;
        // 按照socres从小到大，ages从小到大排序。
        Arrays.sort(idx_arr, (j, i) -> (scores[j] != scores[i]) ? (scores[j] - scores[i]) : (ages[j] - ages[i]));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(ages[ idx_arr[j] ] <= ages[ idx_arr[i] ]) {
                    dp[i] = Math.max(dp[i], dp[j]);
                }
            }
            
            dp[i] += scores[ idx_arr[i] ]; // important!!!
            ans = Math.max(ans, dp[i]);
        }

        return ans;
    }
}

/*
[1,2,3,5]
[8,9,10,1]
[1,3,5,10,15]
[1,2,3,4,5]
[1,3,7,3,2,4,10,7,5]
[4,5,2,1,1,2,4,1,4]

6
34
29
*/