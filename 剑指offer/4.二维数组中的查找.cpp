// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
// 数组题， 核心是从右上角开始走，target等于当前元素则返回true；target比当前元素大则row+1，否则col-1。
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &nums, int target) {
        if(nums.size() == 0 || nums[0].size() == 0) return false;
        if(nums[0][0] == target) return true;
        int n = nums.size(), m = nums[0].size();
        int row = 0, col = m-1;
        while(row < n && col >= 0) {
            if(nums[row][col] == target) {
                return true;
            } else if(nums[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};

/*
[[-1,3]]
3
[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
5

true
true
*/
