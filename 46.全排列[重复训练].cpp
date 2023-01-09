// https://leetcode.cn/problems/permutations/
// 题解：DFS，理解当前for循环步骤执行完，才能执行下一for循环，故数组[1,x,x]先遍历完全。
class Solution {
public:
    ;
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        dfs(nums, res, 0);
        return res;
    }

    void dfs(vector<int> nums, vector<vector<int>> &res, int left) {
        int n = nums.size();

        if(left == n-1) {
            res.emplace_back(nums);
        } else {
            for(int i = left; i < n; i++) {
                swap(nums[i], nums[left]);
                dfs(nums, res, left+1);
            }
        }
    }
};

/*
[1,2,3]

[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
