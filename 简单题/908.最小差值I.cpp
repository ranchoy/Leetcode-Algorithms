// https://leetcode-cn.com/problems/smallest-range-i/
// 模拟题目，找到数组最大值与最小值。
class Solution {
public:
    int smallestRangeI(vector<int> &nums, int k) {
        int min_right, max_left;
        int min_val = INT_MAX, max_val = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            min_val = min(min_val, nums[i]);
            max_val = max(max_val, nums[i]);
        }
        max_left = max_val - k;
        min_right = min_val + k;
        return (min_right < max_left) ? (max_left - min_right) : 0;
    }
};

/*
[0,10]
2
[1,3,6]
3

6
0
*/
