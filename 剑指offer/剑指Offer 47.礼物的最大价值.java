// https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/
// 题解：动态规划DP，dp[i][j]表示初始点到<i,j>的最大价值，递推公式如下。注意使用DFS时，需要从位置<n-1,m-1>到<0,0>且存中间值。
// 二维[n][m]递推公式：dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
// 二维[2][m+1]递推公式（只存两行值）：dp[(i+1)%2][j+1] = max(dp[i%2][j+1], dp[(i+1)%2][j]) + grid[i][j];
class Solution {
    public int maxValue(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] dp = new int[2][m + 1];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[(i+1)%2][j+1] = Math.max(dp[i%2][j+1], dp[(i+1)%2][j]) + grid[i][j];
            }
        }

        return dp[n%2][m];
    }
}

/*
[[1,2],[1,1]]
[[1,3,1],[1,5,1],[4,2,1]]

4
12
*/

/*
// 题解：二维动态规划DP。
class Solution {
    public int maxValue(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] dp = new int[n][m];

        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j = 1; j < m; j++) dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[n-1][m-1];
    }
}

// 题解：记忆化的深度优先搜索DFS，等同于二维动态规划DP。
class Solution {
    private int[][] grid, memo;

    public int maxValue(int[][] grid) {
        this.grid = grid;
        int m = grid.length, n = grid[0].length;
        memo = new int[m][n];
        return dfs(grid.length - 1, grid[0].length - 1);
    }

    private int dfs(int i, int j) {
        if (i < 0 || j < 0)
            return 0;
        if (memo[i][j] > 0) // grid[i][j] 都是正数，记忆化的 memo[i][j] 必然为正数
            return memo[i][j];
        return memo[i][j] = Math.max(dfs(i, j - 1), dfs(i - 1, j)) + grid[i][j];
    }
}
*/