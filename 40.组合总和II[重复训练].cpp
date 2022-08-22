// https://leetcode-cn.com/problems/combination-sum-ii/submissions/
// DFS回溯，注意避免重复元素，解决方案是跳过相同元素。
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int> &nums, int target) {
        vector<int> temp;
        sort(nums.begin(), nums.end(), less<int>{});
        dfs(nums, temp, 0, target);
        return res;
    }

    void dfs(vector<int> &nums, vector<int> &temp, int idx, int target) {
        int n = nums.size();
        if(target < 0) return;
        if(target == 0) {res.push_back(temp); return;}

        for(int i = idx; i < n; i++) {
            temp.push_back(nums[i]);
            dfs(nums, temp, i + 1, target - nums[i]);
            temp.pop_back();
            while(i+1 < n && nums[i] == nums[i+1]) { // 重要
                i++;
            }
        }
    }
};

/*
[2]
1
[10,1,2,7,6,1,5]
8

[]
[[1,1,6],[1,2,5],[1,7],[2,6]]
*/
