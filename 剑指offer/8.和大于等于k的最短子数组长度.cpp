// https://leetcode-cn.com/problems/2VG8Kg/
// 前缀和 + 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int min_len = INT_MAX;
        for(int j=0; j<nums.size(); j++) {
            sum += nums[j];
            while(sum >= target) {
                min_len = min(min_len, j - left + 1);
                sum -= nums[left];
                left += 1; // 右移
            }
        }
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};
