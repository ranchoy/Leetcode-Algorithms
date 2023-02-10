import java.util.*;
// https://leetcode.cn/problems/n-queens/
// 题解：深度优先遍历DFS，按照行数i依次放置皇后在j=col_arr[i]处，列vis[j]、斜角diag1[i+j+n-1]和反斜角diag2[i+j]不重复。
class Solution {

    private int[] col_arr;
    private List<List<String>> ans;
    private boolean[] vis, diag1, diag2;
    public List<List<String>> solveNQueens(int n) {
        this.col_arr = new int[n]; // col_arr[i]=j，第i行j列放置皇后。
        this.vis = new boolean[n]; // 第j列是否被放置皇后。
        this.diag1 = new boolean[2*n - 1]; // 正斜对角i-j是否被放置皇后。
        this.diag2 = new boolean[2*n - 1]; // 正斜对角i+j是否被放置皇后。
        this.ans = new ArrayList<>();

        dfs(n, 0);
        return ans;
    }

    void dfs(int n, int i) {
        if(i == n) {
            List<String> board = new ArrayList<>();
            char[] row = new char[n];
            for(int item : col_arr) {
                Arrays.fill(row, '.');
                row[item] = 'Q';
                board.add(new String(row));
            }
            ans.add(board);
        } else {
            for(int j = 0; j < n; j++) {
                int k = i - j + (n - 1); // 避免负数
                if(!vis[j] && !diag1[i + j] && !diag2[k]) {
                    col_arr[i] = j;
                    vis[j] = diag1[i+j] = diag2[k] = true;
                    dfs(n, i+1);
                    vis[j] = diag1[i+j] = diag2[k] = false; // 恢复现场
                }
            }
        }
    }
}


/*
1
4

[["Q"]]
[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
*/