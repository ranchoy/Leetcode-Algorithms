// https://leetcode.cn/problems/ways-to-make-a-fair-array/
// 题解：动态规划DP，提前算好奇偶数和，然后再逐位筛选，注意删除nums[i]后的奇偶顺序改变。
class Solution {
    public int waysToMakeFair(int[] nums) {
        int n = nums.length;
        int ans = 0, s1 = 0, s2 = 0;

        for(int i = 0; i < n; i++) {
            s1 += (i % 2 == 1) ? nums[i] : 0;
            s2 += (i % 2 == 0) ? nums[i] : 0; 
        }

        int t1 = 0, t2 = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 1) {
                if(t1 + (s2 - t2) == t2 + (s1 - t1 - nums[i])) {
                    ans++;
                }
            } else {
                if(t1 + (s2 - t2 - nums[i]) == t2 + (s1 - t1)) {
                    ans++;
                }
            }
            t1 += (i % 2 == 1) ? nums[i] : 0;
            t2 += (i % 2 == 0) ? nums[i] : 0;
        }

        return ans;
    }
}

/*
[1,2,3]
[1,1,1]
[2,1,6,4]

0
3
1
*/