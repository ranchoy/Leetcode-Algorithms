// https://leetcode.cn/problems/trapping-rain-water/
// 题解：单调栈，栈空间递减，遇到比栈顶大的height[i]计算雨水，注意会遇到21112平顶和1112接不住雨水的情况。
class Solution {
    public int trap(int[] height) {
        int n = height.length, ans = 0;
        Deque<Integer> stk = new ArrayDeque<>();

        for(int i = 0; i < n; i++) {
            while(!stk.isEmpty() && height[stk.peek()] < height[i]) {
                int idx = stk.pop(); // 当前最低点
                while(!stk.isEmpty() && height[stk.peek()] == height[idx]) {
                    stk.pop(); // 21112
                }

                if(!stk.isEmpty()) {
                    int l = i - stk.peek() - 1; // 避免1112
                    int h = Math.min(height[i], height[stk.peek()]) - height[idx];
                    ans += h * l;
                }
            }
            stk.push(i);
        }

        return ans;
    }
}

/*
[2,1,1,1,2]
[0,1,0,2,1,0,1,3,2,1,2,1]
[4,2,0,3,2,5]

3
6
9
*/