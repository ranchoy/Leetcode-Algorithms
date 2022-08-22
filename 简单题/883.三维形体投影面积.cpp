// https://leetcode-cn.com/problems/projection-area-of-3d-shapes/
// 模拟题目，注意grid[i][j]为0的情况。
class Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int h_i, h_j;
        int s1, s2, s3;
        int n = grid.size();

        s1 = s2 = s3 = 0;
        for(int i = 0; i < n; i++) {
            h_i = h_j = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) s1++;
                h_i = max(h_i, grid[i][j]);
                h_j = max(h_j, grid[j][i]);
            }
            s2 += h_i; s3 += h_j;
        }
        return s1 + s2 + s3;
    }
};

/*
[[1,2],[3,4]]

17
*/
