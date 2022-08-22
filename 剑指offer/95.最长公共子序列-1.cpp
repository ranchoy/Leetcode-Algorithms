// https://leetcode-cn.com/problems/qJnOS7/
// 动态规划，使用递归或者DP数组，注意剪枝
class Solution {
public:
    set<string> st;
    int dp[1010][1010] = {0};
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        int mx_len = max_lcs(text1, text2, len1, len2);
        
        // string lcs_str;
        // lcs_print(text1, text2, lcs_str, dp, len1, len2);
        // for(auto it=st.begin(); it!=st.end(); it++) {
        //     cout << *it << endl;
        // }

        return mx_len;
    }

    int max_lcs(string &s1, string &s2, int len1, int len2) {
        int mx_len = 0;
        if(len1 == 0 || len2 == 0) return 0;
        
        if(s1[len1 - 1] == s2[len2 - 1]) {
            mx_len = 1 + max_lcs(s1, s2, len1-1, len2-1);
        } else if (s1[len1 - 1] != s2[len2 - 1]) {
            // 这里两个子区间有重复比较情况，需要剪枝
            int l1 = (dp[len1][len2-1] != 0) ? dp[len1][len2-1] : max_lcs(s1, s2, len1, len2-1);
            int l2 = (dp[len1-1][len2] != 0) ? dp[len1-1][len2] : max_lcs(s1, s2, len1-1, len2);
            mx_len = max(l1, l2);
        }
        dp[len1][len2] = mx_len;
        return mx_len;
    }

    void lcs_print(string &s1, string &s2, string lcs_str, int dp[][1010], int i, int j) {
        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                lcs_str += s1[i-1];
                i--;
                j--;
            }
            else {
                if(dp[i][j-1] < dp[i-1][j]){
                    i--;
                } else if(dp[i][j-1] > dp[i-1][j]) {
                    j--;
                } else {
                    lcs_print(s1, s2, lcs_str, dp, i-1, j);
                    lcs_print(s1, s2, lcs_str, dp, i, j-1);
                    return;
                }
            }
        }

        reverse(lcs_str.begin(), lcs_str.end());
        st.insert(lcs_str);
    }
};

/*
"abcde"
"ace"
3
"ylqpejqbalahwr"
"yrkzavgdmdgtqpg"
3
*/
