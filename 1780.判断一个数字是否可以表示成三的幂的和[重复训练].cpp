// https://leetcode.cn/problems/check-if-number-is-a-sum-of-powers-of-three/
// 题解：DFS搜索，从大至小选择若干个不同的三的幂之和，首先选择[i]，再从[0,i-1]选择一个，逐渐缩小范围。
// 最优题解：数学进制，如果n转换为3进制，存在某一位为2，则不能由不同的三的幂之和组成。
class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n < 0) return false;
        while(n > 0) {
            if(n % 3 == 2) return false;
            n = n / 3;
        }
        return true;
    }

    bool checkPowersOfThree2(int n) {
        int N = 15;
        bool flag = false;
        vector<int> dp(N+1, 1);
        for(int i = 1; i < N; i++) dp[i] = dp[i-1] * 3;

        for(int i = N-1; i >= 0; i--) {
            if(flag == true || dp[i] > n) continue;
            dfs(dp, flag, n - dp[i], i-1); // start with dp[i].
        }

        return flag;
    }


    void dfs(vector<int> &dp, bool &flag, int n, int k) {
        if(n == 0) flag = true;
        if(flag == true || n < 0 || k < 0) return; // cut tree.

        for(int i = k; i >= 0; i--) {
            dfs(dp, flag, n - dp[i], i-1); // dp[i-1] is considered in the next.
        }
    }
};
/*
12
21
91
7814780

true
false
true
false
*/
