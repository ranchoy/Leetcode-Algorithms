import java.util.*;
// https://leetcode.cn/problems/arithmetic-subarrays/
// 题解：模拟 + 数学，注意等差数列的性质，分类讨论不满足情况即可。
class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        int n = nums.length, m = l.length;
        Boolean[] ans = new Boolean[m];

        for(int i = 0; i < m; i++) {
            ans[i] = true;
            int l_idx = l[i], r_idx = r[i], k = r[i] - l[i] + 1;
            int max_v = Integer.MIN_VALUE, min_v = Integer.MAX_VALUE;

            for(int j = l_idx; j <= r_idx; j++) {
                max_v = Math.max(max_v, nums[j]);
                min_v = Math.min(min_v, nums[j]);
            }

            if(max_v == min_v) {
                // d=0的等差数列
                for(int j = l_idx; j <= r_idx; j++) {
                    if(nums[j] - min_v != 0) {
                        ans[i] = false; break;
                    }
                }
            } else {
                // d!=0的等差数列
                if((max_v - min_v) % (k - 1) != 0) {
                    ans[i] = false; continue;
                }

                int[] t_arr = new int[k];
                int d = (max_v - min_v) / (k - 1);
                for(int j = l_idx; j <= r_idx; j++) {
                    if((nums[j] - min_v) % d != 0) {
                        ans[i] = false; break;
                    } else {
                        t_arr[(nums[j] - min_v) / d] += 1; // 区间[l_idx,r_idx]内等差成立，无重复或缺失。
                    }
                }

                for(int j = 0; j < k; j++) {
                    if(t_arr[j] != 1) {
                        ans[i] = false; break; // 存在重复或缺失
                    }
                }
            }
        }

        return Arrays.asList(ans);
    }
}