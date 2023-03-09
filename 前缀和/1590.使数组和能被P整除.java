// https://leetcode.cn/problems/make-sum-divisible-by-p/
// 题解：数学 + 前缀和 + 哈希表HashMap，记录前缀和模p余数，如果区间[j,i]满足(sum_i-sum_j)%p==r，则该区间可以删除，记录最小区间。
// 参考1: (y - x) % p = 0, 等价于, x % p = 0;
// 参考2: (sum_i - sum_j) % p = r, 等价于, (sum_i - r + p) % p = sum_j % p;
class Solution {
    public int minSubarray(int[] nums, int p) {
        int ans = Integer.MAX_VALUE;
        int n = nums.length, r = 0, sum_i = 0; // sum_i表示[0,i]前缀和模p的余数
        Map<Integer,Integer> map_list = new HashMap<>(); // <余数,索引>

        for(int i = 0; i < n; i++) {
            r = (r + nums[i]) % p;
        }
        if(r == 0) return 0;

        for(int i = 0; i < n; i++) {
            map_list.put(sum_i, i); // 先存sum_i, 再更新sum_i。
            sum_i = (sum_i + nums[i]) % p;
            
            if(map_list.containsKey((sum_i - r + p) % p)) {
                int j = map_list.get((sum_i - r + p) % p);
                ans = Math.min(ans, i - j + 1);
            }
        }

        return (ans != n) ? ans : -1; // 当ans = n时，表示没有任何方案。
    }
}

/*
[1,2,3]
7
[3,1,4,2]
6
[6,3,5,2]
9

-1
1
2
*/