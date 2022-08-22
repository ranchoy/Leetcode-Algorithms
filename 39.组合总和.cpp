// https://leetcode-cn.com/problems/combination-sum/
// DFS回溯搜索，注意使用idx限制当前开始下标，在DFS中的下一次下标是从索引i开始的。
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int> &nums, int target) {
        vector<int> temp;
        dfs(nums, temp, 0, target);
        return res;
    }

    void dfs(vector<int> &nums, vector<int> &temp, int idx, int target) {
        if(target < 0) return;
        if(target == 0) {res.push_back(temp); return;}

        for(int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            dfs(nums, temp, i, target - nums[i]);
            temp.pop_back();
        }
    }
};

/*
[2,3,6,7]
7
[2,3,5]
8

[[2,2,3],[7]]
[[2,2,2,2],[2,3,3],[3,5]]
*/
