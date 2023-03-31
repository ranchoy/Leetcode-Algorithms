// https://leetcode.cn/problems/minimum-size-subarray-sum/
// 题解：动态规划DP + 二分，dp[i]表示长度为i从0开始连续子数组的和。右下标j需刚好满足(dp[j] - dp[i])>=target，i+1<=j<=n，得到最小结果。注意，下标i表示从nums[0]开始子数组的长度，0<=i<=n。计算的是长度为(j-i)的连续子数组nums[i,j-1]的和。
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length, ans = Integer.MAX_VALUE;
        int[] dp = new int[n + 1];

        for(int i = 1; i <= n; i++) dp[i] = dp[i - 1] + nums[i - 1];
        if(dp[n] <= target) return (dp[n] == target) ? n : 0;

        for(int i = 0; i <= n; i++) {
            int j = lower_bound(dp, target, i);
            System.out.println(i + " " + j);

            if(j <= n) ans = Math.min(ans, j - i); // i+1<=j<=n, important!!!
        }


        return ans;
    }

    int lower_bound(int[] dp, int target, int start_idx) {
        int m = dp.length;
        int left = start_idx + 1, right = m - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if((dp[mid] - dp[start_idx]) < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
}

/*
4
[1,4,4]
11
[1,2,3,4,5]
15
[1,2,3,4,5]
11
[1,1,1,1,1,1,1,1]

1
3
5
0
*/