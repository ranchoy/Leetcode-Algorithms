// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
// DP规划+hash表，dp[i]表示以i结尾的最长子串从长度dp[i]，hash表存<字符，下标>，left表示无重复子串左边界
// 当mp[s[i]]不存在时，dp[i] = dp[i-1] + 1;
// 当mp[s[i]]存在时，如果left>mp[s[i]]，则dp[i] = dp[i-1] + 1;
//                  否则，dp[i] = i - mp[s[i]]; 更新left = mp[s[i]] + 1;外层更新mp[s[i]] = i;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int mx_len = 0, left = 0;
        if(n == 0 || n == 1) return n;
        vector<int> dp(n, 0); // 以i结尾的最长子串长度dp[i]
        unordered_map<char,int> mp; // <字符，下标>

        dp[0] = 1; mp[s[0]] = 0; // 初始化
        for(int i = 1; i < n; i++) {
            if(mp.count(s[i]) == 0) {
                dp[i] = dp[i-1] + 1;
            } else {
                if(left > mp[s[i]]) {
                    dp[i] = dp[i-1] + 1;
                } else {
                    dp[i] = i - mp[s[i]];
                    left = mp[s[i]] + 1; // 必须放这
                }
            }
            mp[s[i]] = i; // 更新
            mx_len = max(mx_len, dp[i]);
        }

        return mx_len;
    }
};

/*
"pwwkew"
"tmmzuxt"
"abcabcbb"
"blqsearxxxbiwqa"

3
5
3
8
*/
