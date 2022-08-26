// https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/
// 题解：模拟，关键是保留仅比max_val小的最大元素。
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int max_val = INT_MIN, pre_val;

        for(int i = 0; i < nums.size(); i++) {
            if(max_val <= nums[i]) {
                pre_val = max_val; max_val = nums[i];
            } else {
                pre_val = max(pre_val, nums[i]);
            }
        }

        return (pre_val - 1) * (max_val - 1);
    }
};

/*
[3,4,5,2]
[1,5,4,5]

12
16
*/
