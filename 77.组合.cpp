// https://leetcode-cn.com/problems/combinations/
// DFS回溯遍历，利用idx保证向后添加元素，不会添加重复元素。
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        dfs(temp, n, k, 1);
        return res;
    }

    void dfs(vector<int> &temp, int n, int k, int idx) {
        if(k == temp.size()) {res.push_back(temp); return;}

        for(int i = idx; i <= n; i++) {
            temp.push_back(i);
            dfs(temp, n, k, i+1);
            temp.pop_back();
        }
    }
};

/*
1 1
4 2

[[1]]
[[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
*/
