// https://leetcode-cn.com/problems/maximum-subarray/
// dp，连续子数组最大和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i] = max(nums[i], dp[i]+nums[i])
        int mx = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] < nums[i-1] + nums[i]) {
                nums[i] += nums[i-1]; 
            }
            mx = max(mx, nums[i]);
        }
        return mx; 
    }
};
