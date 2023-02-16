// https://leetcode.cn/problems/next-greater-element-ii/
// 题解：单调栈 + 循环数组，寻找循环数组nums[stk.peek()]右边开始第一个更大的元素nums[i]。
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Deque<Integer> stk = new ArrayDeque<>(); // 单调递减栈

        Arrays.fill(ans, -1);
        for(int i = 0; i < 2*n -1; i++) {
            while(!stk.isEmpty() && nums[stk.peek()] < nums[i % n]) {
                ans[stk.pop()] = nums[i % n]; // 比nums[stk.peek()]大的数是nums[i % n]。
            }
            stk.push(i % n);
        }

        return ans;
    }
}

/*
[1,2,1]
[2,3,1]
[1,2,3,4,1]

[2,-1,2]
[3,-1,2]
[2,3,4,-1,2]
*/