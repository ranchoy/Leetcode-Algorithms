// https://leetcode.cn/problems/transform-to-chessboard/
// 题解：棋盘满足，四角4个0|4个1|2个0+2个1，棋盘的数字1个数为n/2|(n+1)/2；当棋盘n为偶数时，行列移动次数为min(row|col, n-row|col)；当棋盘n为奇数且行列位差奇数时，行列移动次数为n-row|col。
class Solution {
public:
    int movesToChessboard(vector<vector<int>> &board) {
        int n = board.size();
        int row_cnt = 0, col_cnt = 0, row_swap = 0, col_swap = 0;

        // judge whether the board is legal
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[0][0] ^ board[0][j] ^ board[i][0] ^ board[i][j] == 1)
                    return -1;
            }
        }

        for(int i = 0; i < n; i++) {
            row_cnt += board[0][i];
            col_cnt += board[i][0];
            if(board[0][i] == i % 2) row_swap++;
            if(board[i][0] == i % 2) col_swap++;
        }

        // judge whether the board is legal
        if(row_cnt != n/2 && row_cnt != (n+1)/2) return -1;
        if(col_cnt != n/2 && col_cnt != (n+1)/2) return -1;

        if(n & 1) {
            if(row_swap & 1) row_swap = n - row_swap;
            if(col_swap & 1) col_swap = n - col_swap;
        } else {
            row_swap = min(row_swap, n - row_swap);
            col_swap = min(col_swap, n - col_swap);
        }

        return (row_swap + col_swap) / 2;
    }
};

/*
[[0,1],[1,0]]
[[1,1,0],[0,0,1],[0,0,1]]
[[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]

0
2
2
*/
