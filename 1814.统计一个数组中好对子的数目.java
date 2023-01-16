// https://leetcode.cn/problems/count-nice-pairs-in-an-array/
// 题解：数学模拟，只要x - rev(x)相等，就可以组成满足题意的元素对。
class Solution {
    int MOD = (int) (1e9 + 7);
    public int countNicePairs(int[] nums) {
        int ans = 0;
        Map<Integer, Integer> map_list = new HashMap<Integer, Integer>();

        for(int i : nums) {
            int j = reverse_num(i);
            ans = (ans + map_list.getOrDefault(i - j, 0)) % MOD;
            map_list.put(i - j, map_list.getOrDefault(i - j, 0) + 1);
        }

        return ans;
    }

    int reverse_num(int num) {
        int ans = 0;
        while(num != 0) {
            ans = ans * 10 + num % 10;
            num = num / 10;
        }
        return ans;
    }
}

/*
[42,11,1,97]
[13,10,35,24,76]

2
4
*/
