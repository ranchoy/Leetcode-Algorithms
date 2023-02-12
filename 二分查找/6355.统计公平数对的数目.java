import java.util.*;
// https://leetcode.cn/contest/weekly-contest-332/problems/count-the-number-of-fair-pairs/
// 题解：二分查找，以索引i为锚点，寻找满足lower<=nums[i]+nums[j]<=upper的j的区间[left,right]。
class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        long ans = 0;
        int n = nums.length;

        Arrays.sort(nums);
        for(int i = 0; i < n - 1; i++) {
            int left = i + 1, right = n - 1;
            if(nums[i] + nums[left] > upper || nums[i] + nums[right] < lower) continue;

            while(left <= right) { // important!
                int mid = (left + right) >> 1;
                if(nums[i] + nums[mid] < lower) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            int x = left;

            left = i + 1; right = n - 1;
            while(left <= right) { // important!
                int mid = (left + right) >> 1;
                if(nums[i] + nums[mid] > upper) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ans += right - x + 1;
        }

        return ans;
    }
}

/*
[0,1,7,4,4,5]
3
6
[1,7,9,2,5]
11
11

6
1
*/