// https://leetcode.cn/problems/possible-bipartition/
// 题解：DFS+染色法，cur_color=0表示未分组，1表示A组，2表示B组。
class Solution {
public:
    vector<int> color_arr; // status 0/1/2
    vector<vector<int>> dk_arr;

    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        color_arr = vector<int>(n+1, 0);
        dk_arr = vector<vector<int>>(n+1);

        for(int i = 0, a, b; i < dislikes.size(); i++) {
            a = dislikes[i][0]; b = dislikes[i][1];
            dk_arr[a].push_back(b);
            dk_arr[b].push_back(a);
        }

        for(int i = 1; i <= n; i++) {
            if(color_arr[i] == 0 && !dfs(dislikes, i, 1)) {
                return false; // i未被标记且颜色存在冲突
            }
        }

        return true;
    }

    bool dfs(vector<vector<int>> &dislikes, int idx, int cur_color) {
        color_arr[idx] = cur_color; // record

        for(auto item : dk_arr[idx]) {
            if(color_arr[item] && color_arr[item] == cur_color) {
                return false; // item被标记且颜色与idx相同
            }
            if(!color_arr[item] && !dfs(dislikes, item, 3 - cur_color)) {
                return false; // item未被标记且颜色存在冲突
            }
        }

        return true;
    }
};

/*
3
[[1,2],[1,3],[2,3]]
4
[[1,2],[1,3],[2,4]]

false
true
*/
