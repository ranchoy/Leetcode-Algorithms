// https://leetcode.cn/contest/season/2022-fall/problems/EXvqDp/
// 题解：DFS搜索，注意方向设置问题，以及边界非拐角的'.'作为起始点。
class Solution {
public:
    int n, m;
    vector<vector<int>> res;
    vector<vector<int>> dir_list = {{0,1}, {0,-1}, {-1,0}, {1,0}};

    vector<vector<int>> ballGame(int num, vector<string> &plate) {
        n = plate.size(); m = plate[0].size();
        
        for(int j = 1; j < m-1; j++) {
            if(plate[0][j] == '.')   dfs(num, plate, {0,j}, {1,0}, {0,j});
            if(plate[n-1][j] == '.') dfs(num, plate, {n-1,j}, {-1,0}, {n-1,j});
        }
        for(int i = 1; i < n-1; i++) {
            if(plate[i][0] == '.')   dfs(num, plate, {i,0}, {0,1}, {i,0});
            if(plate[i][m-1] == '.') dfs(num, plate, {i,m-1}, {0,-1}, {i,m-1});
        }
        
        return res;
    }
    
    void dfs(int num, vector<string> &plate, vector<int> src_pos, vector<int> dir, vector<int> cur_pos) {
        if(num < 0) return;
        if(num >= 0 && plate[cur_pos[0]][cur_pos[1]] == 'O') {
            res.emplace_back(src_pos); return;
        }
        
        char ch = plate[cur_pos[0]][cur_pos[1]];
        vector<int> ndir = get_new_dir(dir, ch);
        int nx = cur_pos[0] + ndir[0], ny = cur_pos[1] + ndir[1];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) return;
        dfs(num-1, plate, src_pos, ndir, {nx, ny});
    }
    
    
    vector<int> get_new_dir(vector<int> &dir, char ch) {
        vector<int> ndir;
        if(ch == '.' || ch == 'O') return dir;
        if(dir[0] == 1 && dir[1] == 0) ndir = (ch == 'E') ? dir_list[1] : dir_list[0];
        else if(dir[0] == -1 && dir[1] == 0) ndir = (ch == 'E') ? dir_list[0] : dir_list[1];
        else if(dir[0] == 0  && dir[1] == 1) ndir = (ch == 'E') ? dir_list[3] : dir_list[2];
        else if(dir[0] == 0  && dir[1] == -1) ndir = (ch == 'E') ? dir_list[2] : dir_list[3];
        return ndir;
    }
};

/*
6
["....",".EE.","O.E.","...."]
41
["E...W..WW",".E...O...","...WO...W","..OWW.O..",".W.WO.W.E","O..O.W...",".OO...W..","..EW.WEE."]

[[3,1]]
[[0,2],[0,3],[0,5],[0,6],[1,0],[1,8],[3,0],[3,8],[4,0],[6,0],[7,1],[7,4]]
*/
