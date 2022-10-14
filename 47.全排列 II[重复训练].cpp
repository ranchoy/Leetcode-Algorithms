// https://leetcode.cn/problems/permutations-ii/
// 同题：https://leetcode.cn/problems/permutation-ii-lcci/
// 同题：https://leetcode.cn/problems/zi-fu-chuan-de-pai-lie-lcof/
// 同题：https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=117
// 较难想到，模拟题，每次固定一个不重复的nums[left]，再向left+1递归，注意nums数组不是引用。
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end(), less<int>());
        dfs(nums, 0);
        return res;
    }
    
    void dfs(vector<int> nums, int left) {
        int n = nums.size();
        if(left == n-1) {
            res.push_back(nums);
        } else {
            for(int i = left; i <= n-1; i++) {
                if(i != left && nums[left] == nums[i]) continue; // 保证nums[left]不重复, 不能用while替代
                swap(nums[left], nums[i]);
                dfs(nums, left+1); // important
            }
        }
    }
};

/*
[1,1,2]
[1,2,3]

[[1,1,2],[1,2,1],[2,1,1]]
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
