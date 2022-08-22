// https://leetcode-cn.com/problems/pacific-atlantic-water-flow/
// DFS深度递归，注意题意是元素(i,j)能够同时进入太平洋和大西洋。
class Solution {
public:
    int n, m;
    vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        n = heights.size(); m = heights[0].size();
        vector<vector<int>> res;
        vector<vector<int>> vis_p(n, vector<int>(m,0));
        vector<vector<int>> vis_a(n, vector<int>(m,0));
        vector<vector<int>> map_p(n, vector<int>(m,0));
        vector<vector<int>> map_a(n, vector<int>(m,0));

        // 竖直方向
        for(int i = 0; i < n; i++) {
            dfs(heights, vis_p, map_p, i, 0); // 太平洋
            dfs(heights, vis_a, map_a, i, m-1); // 大西洋
        }
        // 水平方向
        for(int j = 0; j < m; j++) {
            dfs(heights, vis_p, map_p, 0, j); // 太平洋
            dfs(heights, vis_a, map_a, n-1, j); // 大西洋
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map_p[i][j] == 1 &&map_a[i][j] == 1) {
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
    
    void dfs(vector<vector<int>> &heights, vector<vector<int>> &vis, vector<vector<int>> &mp, int sx, int sy) {
        if(is_cross_border(sx, sy) == true) return; // 越界，结束
        if(mp[sx][sy] == 1) return; // 已标记，结束，（重要剪枝）

        mp[sx][sy] = 1; // [sx][sy]标记为1
        for(int i = 0; i < 4; i++) {
            int nx = sx + dir[i][0];
            int ny = sy + dir[i][1];
            if(is_cross_border(nx, ny) == true || vis[nx][ny] == 1) {
                continue;
            }
            if(heights[nx][ny] >= heights[sx][sy]) {
                vis[nx][ny] = 1;
                dfs(heights, vis, mp, nx, ny);
                vis[nx][ny] = 0;
            }
        }
    }
    
    bool is_cross_border(int x, int y) {
        if(x < 0 || y < 0 || x >= n || y >= m) {
            return true;
        }
        return false;
    }
    
    void dfs2(vector<vector<int>> &heights, vector<vector<int>> &vis, vector<vector<int>> &mp, int sx, int sy) {
        if(is_cross_border(sx, sy) == true) return; // 越界，结束
        if(mp[sx][sy] == 1) return; // 已标记，结束，（重要剪枝）
        int nx, ny;
        bool flag1 = false, flag2 = false;

        // 判断[sx][sy]是否大于等于周围元素
        for(int i = 0; i < 4; i++) {
            nx = sx + dir[i][0];
            ny = sy + dir[i][1];
            if(sx == 0 || sy == 0) {
                flag1 = true; // [sx][sy]为边界
            }
            if(is_cross_border(nx, ny) == false && heights[sx][sy] >= heights[nx][ny]) {
                flag2 = true; // [sx][sy]比周围元素小
            }
        }

        // 边界元素或者大于等于周围元素，则mp[sx][sy]=1，表示其能够进入大洋
        if(flag1 == true || flag2 == true) {
            mp[sx][sy] = 1; // [sx][sy]满足条件
        }

        for(int i = 0; i < 4; i++) {
            nx = sx + dir[i][0];
            ny = sy + dir[i][1];
            if(is_cross_border(nx, ny) == true || vis[nx][ny] == 1) {
                continue;
            }
            if(heights[nx][ny] >= heights[sx][sy]) {
                vis[nx][ny] = 1;
                dfs(heights, vis, mp, nx, ny);
                vis[nx][ny] = 0;
            }
        }
    }
};

/*
[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]

[[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
*/
