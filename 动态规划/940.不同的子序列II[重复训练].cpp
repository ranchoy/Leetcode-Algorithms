// https://leetcode.cn/problems/distinct-subsequences-ii/
// 题解：DP动态规划，保留以s[i]结尾的不重复子序列个数以实现去重，注意输出不溢出。
// 递推公式：dp[s[i]-'a'] = 1 + \sum\limits{'z'}{j='a'}dp[s[j-'a']];
class Solution {
public:
    const int N = 1e9 + 7;
    int distinctSubseqII(string s) {
        long sum = 0;
        int len = s.size();
        vector<int> dp(26,0);

        for(int i = 0, k, pre; i < len; i++) {
            k = s[i] - 'a';
            pre = dp[k];
            dp[k] = (sum % N + 1) % N;
            sum = (sum - pre + dp[k]) % N;
        }

        return (sum + N) % N; // important
    }
};

/*
"aba"
"abc"

6
7
*/
