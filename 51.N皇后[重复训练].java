// https://leetcode.cn/problems/n-queens/
// 题解：深度优先遍历DFS，按照行数i依次放置皇后在j=col_arr[i]处，列vis[j]、斜角diag1[i+j+n-1]和反斜角diag2[i+j]不重复。
class Solution {
    private int[] col_arr;
    private boolean[] vis, diag1, diag2;
    private List<List<String>> ans = new ArrayList<>();

    public List<List<String>> solveNQueens(int n) {
        this.col_arr = new int[n]; // 第i行第j=col_arr[i]列放置皇后;
        this.vis = new boolean[n]; // 第j列是否被放置皇后;
        this.diag1 = new boolean[2 * n - 1]; // 正斜对角i-j是否被放置皇后;
        this.diag2 = new boolean[2 * n - 1]; // 正斜对角i+j是否被放置皇后;

        dfs(n,0);
        return ans;
    }

    void dfs(int n, int i) {
        if(i == n) {
            List<String> board = new ArrayList<>();
            for(int j : col_arr) {
                char[] row = new char[n];
                Arrays.fill(row, '.');
                row[j] = 'Q';
                board.add(new String(row));
            }
            ans.add(board);
            return;
        }

        for(int j = 0; j < n; j++) {
            int k = i - j + (n - 1); // avoid negative numbers.
            if(!vis[j] && !diag1[k] && !diag2[i + j]) {
                col_arr[i] = j;
                vis[j] = diag1[k] = diag2[i + j] = true;
                dfs(n,i + 1);
                vis[j] = diag1[k] = diag2[i + j] = false; // 恢复现场
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