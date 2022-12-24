// https://leetcode.cn/problems/wiggle-subsequence/
// 题解：动态规划DP，up[i]表示nums[0,i]最后两个数递增的摆动序列，down[i]则表示nums[0,i]最后两个数递减的摆动序列。
// 递推公式：nums[i] > nums[i-1], up[i] = down[i-1] + 1; nums[i] < nums[i-1], down[i] = up[i-1] + 1;
class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int n = nums.size();
        int up = 1, down = 1;

        if(n < 2) return n;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) up = down + 1;
            if(nums[i] < nums[i-1]) down = up + 1;
        }

        return max(up, down);
    }
};

/*
[1,7,4,9,2,5]
[1,17,5,10,13,15,10,5,16,8]

6
7
*/
