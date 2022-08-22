// https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
// 动态规划，dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        if(grid.size() == 0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        if(n == 1 && m == 1) return grid[0][0];

        vector<vector<int>> dp(n, vector<int>(m,0));
        // 初始化边界
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < m; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        // 动态规划
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};

/*
[[1,3,1],[1,5,1],[4,2,1]]
12
*/
