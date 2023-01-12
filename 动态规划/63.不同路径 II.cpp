// https://leetcode.cn/problems/unique-paths-ii/
// 题解：动态规划DP，遇到石头就路径数dp[i][j]归零。
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));

        for(int i = 0; i < n && (obstacleGrid[i][0] != 1); i++) {
            dp[i][0] = 1;
        }
        for(int j = 0; j < m && (obstacleGrid[0][j] != 1); j++) {
            dp[0][j] = 1;
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[n-1][m-1];
    }
};

/*
[[0],[0]]
[[0,1],[0,0]]
[[0,0,0],[0,1,0],[0,0,0]]

1
1
2
*/
