// https://leetcode.cn/problems/total-appeal-of-a-string/
// 题解：https://leetcode.cn/circle/discuss/nf6j8j/view/uNb9VC/
class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        long long res = 0;
        vector<int> dp(26,n); // dp[i]表示字母('a'+i)首次出现的位置
        for(int i = n-1; i >= 0; i--) { // 重要，从右边界开始
            dp[s[i] - 'a'] = i;
            for(int j = 0; j < 26; j++) {
                if(dp[j] < n) {
                    res += n - dp[j]; // 字符(j+'a')在字符(i+'a')右边，则包括前者的子串个数为(n-dp[j])
                }
            }
        }
        return res;
    }
};

/*
"abbca"

28
*/
