// https://leetcode.cn/problems/minimum-value-to-get-positive-step-by-step-sum/
// 题解：前缀和最小的元素，取反加一
class Solution {
public:
    int minStartValue(vector<int> &nums) {
        if(nums.size() == 0) return 1;
        int dp_sum = 0, min_val = 0;

        for(int i = 0; i < nums.size(); i++) {
            dp_sum += nums[i];
            min_val = min(min_val, dp_sum);
        }

        return (1 - min_val);
    }
};

/*
[1,2]
[-3,2,-3,4,2]

1
5
*/
