// https://leetcode.cn/problems/minimum-path-sum/
// 题解：动态规划DP，非边界dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j])，边界dp[i][0]和dp[0][j]同上与左元素相关。
class Solution {
    public int minPathSum(int[][] grid) {
        int n = grid.length, m = grid[0].length;

        for(int i = 1; i < n; i++) grid[i][0] += grid[i-1][0];
        for(int j = 1; j < m; j++) grid[0][j] += grid[0][j-1];
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                grid[i][j] += Math.min(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid[n-1][m-1];
    }
}

/*
[[1,3,1],[1,5,1],[4,2,1]]
[[1,2,3],[4,5,6]]

7
12
*/
