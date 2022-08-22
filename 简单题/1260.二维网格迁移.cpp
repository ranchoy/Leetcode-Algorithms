// https://leetcode.cn/problems/shift-2d-grid/
// 题意：二维数组元素迁移，注意k的大小可能会超过数组元素本身。
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int elem_size = n * m;
        vector<int> temp_arr;
        vector<vector<int>> res(n, vector<int>(m,0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                temp_arr.push_back(grid[i][j]);
            }
        }

        int t = 0;
        k = k % elem_size; // important
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[i][j] = temp_arr[(elem_size-k+t)%elem_size];
                ++t;
            }
        }

        return res;
    }
};

/*
[[1,2,3],[4,5,6],[7,8,9]]
9
[[1],[2],[3],[4],[7],[6],[5]]
23

[[1,2,3],[4,5,6],[7,8,9]]
[[6],[5],[1],[2],[3],[4],[7]]
*/
