// https://leetcode.cn/problems/check-if-matrix-is-x-matrix/solution/pan-duan-ju-zhen-shi-fou-shi-yi-ge-x-ju-aloq7/
class Solution {
    public boolean checkXMatrix(int[][] grid) {
        int n = grid.length;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j || i + j == n - 1) {
                    if(grid[i][j] == 0) return false;
                } else {
                    if(grid[i][j] != 0) return false;
                }
            }
        }

        return true;
    }
}

/*
[[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]

true
*/