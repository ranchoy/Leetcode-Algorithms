// https://leetcode.cn/problems/decode-the-message/
class Solution {
    public String decodeMessage(String key, String message) {
        int n = key.length(), m = message.length();
        char[] ans = new char[m];
        char[] decode_tab = new char[26];

        for(int i = 0, k = 0; i < n; i++) {
            char c = key.charAt(i);
            if(c != ' ' && decode_tab[c - 'a'] == '\0') {
                decode_tab[c - 'a'] = (char) (k + 'a'); k++;
            }
        }
        for(int i = 0; i < m; i++) {
            char c = message.charAt(i);
            ans[i] = (c != ' ') ? decode_tab[c - 'a'] : ' ';
        }

        return new String(ans);
    }
}

/*
"the quick brown fox jumps over the lazy dog"
"vkbs bs t suepuv"

"this is a secret"
*/