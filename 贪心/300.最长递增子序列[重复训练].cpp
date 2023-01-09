// https://leetcode.cn/problems/longest-increasing-subsequence/
// 题解：贪心+二分查找，dp[i]表示长度为i的上升子序列末尾元素最小值，记录上升子序列的最大长度即可。
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size(), len = 1;
        vector<int> dp(n+1,0); // dp[i]表示长度为i的上升子序列末尾元素最小值

        dp[1] = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] > dp[len]) {
                dp[++len] = nums[i];
            } else {
                int left = 1, right = len;

                while(left <= right) {
                    int mid = (left + right) >> 1;
                    if(dp[mid] < nums[i]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                dp[left] = nums[i];
            }
        }

        return len;
    }
};

/*
[7,7,7,7,7,7]
[5,4,3,2,1,6]
[1,2,3,4,5,6]

1
2
6
*/
