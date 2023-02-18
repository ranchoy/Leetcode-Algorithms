// https://leetcode.cn/problems/largest-1-bordered-square/
// 题解：动态规划DP，分别记录横向row[]和纵向col[]连续1的个数。在点(i,j)处不断缩小边长，判断是否构成边界全为1的正方形。
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int ans = 0;
        int n = grid.length, m = grid[0].length;
        int[][] row = new int[n][m]; // 横向连续1个数
        int[][] col = new int[n][m]; // 竖向连续1个数

        // init
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) continue;
                row[i][j] = (j > 0) ? row[i][j - 1] + 1 : 1;
                col[i][j] = (i > 0) ? col[i - 1][j] + 1 : 1;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cur = Math.min(row[i][j], col[i][j]);
                if(cur <= ans) continue; // 减枝

                while(cur > ans) {
                    if(row[i - cur + 1][j] >= cur && col[i][j - cur + 1] >= cur) {
                        ans = cur;
                        break;
                    }
                    cur--;
                }
            }
        }

        return ans * ans;
    }
}

/*
[[0,0],[0,1]]
[[0,1,0,1,1],[1,1,1,1,1],[1,1,0,1,1],[1,1,1,1,0],[0,1,1,1,1],[1,1,1,0,1],[0,1,1,1,1],[1,1,1,0,1]]
[[0,1,1,1,1,0],[1,1,0,1,1,0],[1,1,0,1,0,1],[1,1,0,1,1,1],[1,1,0,1,1,1],[1,1,1,1,1,1],[1,0,1,1,1,1],[0,0,1,1,1,1],[1,1,1,1,1,1]]

1
9
16
*/