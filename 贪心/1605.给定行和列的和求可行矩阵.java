// https://leetcode.cn/problems/find-valid-matrix-given-row-and-column-sums/
// 题解：贪心，每次ans[i][j]填充(rowSum[i],colSum[j])的最小值。
class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int n = rowSum.length, m = colSum.length;
        int[][] ans = new int[n][m];
        int i = 0, j = 0;

        while(i < n && j < m) {
            int v = Math.min(rowSum[i], colSum[j]);
            ans[i][j] = v; rowSum[i] -= v; colSum[j] -= v;

            if(rowSum[i] == 0) i++;
            if(colSum[j] == 0) j++;
        }

        return ans;
    }
}

/*
[3,8]
[4,7]
[5,7,10]
[8,6,8]

[[3,0],[1,7]]
[[5,0,0],[3,4,0],[0,2,8]]
*/