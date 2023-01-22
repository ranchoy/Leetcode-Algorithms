// https://leetcode.cn/problems/minimum-cost-to-split-an-array/
// 题解：动态规划DP，统计区间[j,i]的代价为i-j+1-unique_j,unique_j表示区间内仅出现一次的数字个数。
// 递推公式：dp[i] = k + i + 1 + min({dp[j-1] - j - unique_j, 0<=j<=i});
// 避免j下标-1：dp[i+1] = k + i + 1 + min({dp[j] - j - unique_j, 0<=j<=i});
// 优化：g[i+1] = dp[i+1] - (i+1) = k + min({g[j] - unique_j, 0<=j<=i}); ans = g[n] + n;
class Solution {
    public int minCost(int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[n+1];
        Map<Integer,Integer> mp = new HashMap<Integer,Integer>(); // <num,count>

        for(int i = 0; i < n; i++) {
            int unique = 0, mn = Integer.MAX_VALUE;
            for(int j = i; j >= 0; j--) {
                int x = nums[j];
                if(mp.get(x) == null) {
                    unique += 1; mp.put(x, 1);
                } else if (mp.get(x) == 1) {
                    unique -= 1; mp.put(x, 2); // 超过2次不必再统计
                }
                mn = Math.min(mn, dp[j] - unique);
            }
            dp[i+1] = k + mn;
            mp.clear(); // update
        }

        return dp[n] + n;
    }
}

/*
[1,2,1,2,1]
5
[1,2,1,2,1,3,3]
2

10
8
*/