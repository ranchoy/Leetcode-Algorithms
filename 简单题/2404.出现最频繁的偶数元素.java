// https://leetcode.cn/problems/most-frequent-even-element/
// 题解：模拟，注意尽关心数组中偶数元素即可。
class Solution {
    public int mostFrequentEven(int[] nums) {
        int n = nums.length, ans_cnt = 0, ans_num = Integer.MAX_VALUE;
        Map<Integer,Integer> map_list = new HashMap<>();

        for(int item : nums) {
            if(item % 2 == 1) continue;
            int v = map_list.getOrDefault(item, 0) + 1;
            map_list.put(item, v);

            if(v > ans_cnt || (v == ans_cnt && item < ans_num)) {
                ans_cnt = v; ans_num = item;
            }
        }

        return map_list.isEmpty() ? -1 : ans_num;
    }
}

/*
[0,1,2,2,4,4,1]
[4,4,4,9,2,4]
[29,47,21,41,13,37,25,7]

2
4
-1
*/