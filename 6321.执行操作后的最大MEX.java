// https://leetcode.cn/problems/smallest-missing-non-negative-integer-after-operations/
// 题解：哈希表HashMap + 同余分组，nums数组中的元素按照非负余数分组，ans从零开始遍历，一旦剩余余数无法使用返回结果。
class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        int ans = 0;
        int n = nums.length;
        Map<Integer,Integer>map_list = new HashMap<>();

        for(int item : nums) {
            int key = (item % value + value) % value;
            int val = map_list.getOrDefault(key, 0);
            map_list.put(key, val + 1);
        }

        while(map_list.getOrDefault(ans % value, 0) > 0) {
            map_list.compute(ans % value, (k, v) -> v - 1);
            ans++; // 遍历下一个数字
        }

        return ans;
    }
}

/*
[1,-10,7,13,6,8]
5
[3,0,3,2,4,2,1,1,0,4]
5

4
10
*/