// https://leetcode.cn/problems/longest-well-performing-interval/
// 题解：前缀和+单调栈，寻找最长区间[i,j]使得dp[j] - dp[i] > 0，即dp[j] > dp[i]，寻找“最长的上坡区间”。为了加快速度每次需要记录波谷（相同大小的波谷dp[i]不需要记录）。
class Solution {
    public int longestWPI(int[] hours) {
        int ans = 0;
        int n = hours.length;
        int[] dp = new int[n + 1];
        Deque<Integer> stk = new ArrayDeque<>(); // 双端队列
        stk.push(0);

        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i-1] + (hours[i-1] > 8 ? 1 : -1);
            if(dp[stk.peek()] > dp[i]) {
                stk.push(i); // 单调栈，记录下坡顶点。
            }
        }

        // j < stk.pop()时，负值不更新。并且此时dp[stk.pop()]小于0，表明区间[j,stk.pop()]不满足题目要求。
        for(int j = n; j >= 1; j--) {
            while(!stk.isEmpty() && dp[j] > dp[stk.peek()]) {
                ans = Math.max(ans, j - stk.pop());
            }
        }

        return ans;
    }
}

/*
[6,6,6]
[9,9,6,0,6,6,9]
[9,9,6,0,6,6,9,6,6,6]

0
3
3
*/