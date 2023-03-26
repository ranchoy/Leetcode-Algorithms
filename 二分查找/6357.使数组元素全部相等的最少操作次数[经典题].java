import java.util.*;
// https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal/
// 题解：二分查找 + 前缀和，通过二分查找nums中比queries[i]小的最大下标idx，分别计算左右半区的面积和，注意二分查找的写法。
class Solution {
    public List<Long> minOperations(int[] nums, int[] queries) {
        int n = nums.length, m = queries.length;
        long[] dp = new long[n + 1];
        Long[] ans = new Long[m];

        Arrays.sort(nums);
        for(int i = 0; i < n; i++) {
            dp[i + 1] = nums[i] + dp[i];
        }

        for(int i = 0; i < m; i++) {
            int idx = binary_search_lower_bound(nums, queries[i]);

            long part_left = (long) queries[i] * idx - dp[idx];
            long part_right = (dp[n] - dp[idx]) - (long) queries[i] * (n - idx);
            ans[i] = part_left + part_right;
        }

        return Arrays.asList(ans);
    }

    // 见 https://www.bilibili.com/video/BV1AP41137w7/
    public int binary_search_lower_bound(int[] nums, int target) {
        int left = 0, right = nums.length - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left; // nums[0,left-1]都是比target小的元素。
    }
}

/*
[47,50,97,58,87,72,41,63,41,51,17,21,7,100,69,66,79,92,84,9,57,26,26,28,83,38]
[3]
[47,50,97,58,87,72,41,63,41,51,17,21,7,100,69,66,79,92,84,9,57,26,26,28,83,38]
[9]
[39,21,5,58,11,73,93,87,4,63,66,64,77,60,24,2,6,82,97,94,100,92,67,52,82,97,9,99,29,31,100,67,56,28,8,81,41,18,63,43,22,60,96,91,33,22,92,16,89]
[100]
[67,53,67,35,88,76,92,99,12,80,78,11,59,49,52,50,10,89,46,100,74,90,7,76,34,78,85,74,38,12,75,46,60,43,88,32,5,61,53,99,13,82,11,75,83,80,53,98,46,95,67,70,90,21,10,23,43,80,22,23,62,74,78,4,50,47,39,82,90,73,34,47,78,89,99,76,45,64,58,14,3,57,30,21,73,32,11,76,46]
[99]

[1331]
[1179]
[2190]
[3833]
*/