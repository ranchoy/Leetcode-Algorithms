// https://leetcode-cn.com/problems/permutations/
// DFS回溯，注意去重与left索引位置。
class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        dfs(nums, res, nums, 0);
        return res;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> temp, int left) {
        if(left == nums.size()) {
            res.push_back(temp);
        } else {
            for(int i = left; i < nums.size(); i++) {
                if(i != left && nums[i] == nums[i-1]) {
                    continue; // [1,2,2,3]去重
                }
                swap(temp[left], temp[i]);
                dfs(nums, res, temp, left+1);
            }
        }
    }
};

/*
[1,2,3]
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
