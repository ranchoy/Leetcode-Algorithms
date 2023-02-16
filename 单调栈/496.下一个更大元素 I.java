// https://leetcode.cn/problems/next-greater-element-i/
// 题解：单调栈 + 哈希表，寻找nums2[stk.peek()]右边第一个更大的元素nums2[i]，哈希表记录nums1[]元素在nums2[]中的索引。
class Solution {
    final static int N = 10010;
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        int[] ans = new int[m];
        int[] idx_arr = new int[N];
        Deque<Integer> stk = new ArrayDeque<>(); // 单调递减栈

        Arrays.fill(ans, -1);
        for(int i = 0; i < m; i++) idx_arr[nums2[i]] = i; // <val, idx>
        for(int i = 0; i < m; i++) {
            while(!stk.isEmpty() && nums2[stk.peek()] < nums2[i]) {
                ans[stk.pop()] = nums2[i];
            }
            stk.push(i);
        }

        for(int i = 0; i < n; i++) {
            int k = idx_arr[ nums1[i] ];
            nums1[i] = ans[k];
        }

        return nums1;
    }
}

/*
[2,4]
[1,2,3,4]
[4,1,2]
[1,3,4,2]

[3,-1]
[-1,3,-1]
*/