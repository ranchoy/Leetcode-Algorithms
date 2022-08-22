// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
// ����ָ�룬ע�������ظ�Ԫ��ʱ����left=mp[temp_c]+1���Ա����ظ���
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 1) return 1;
        int left = 0, mx_len = 0;
        unordered_map<char,int> mp; // <�ַ�,�±�>
        for(int i = 0; i < s.size(); i++) {
            char temp_c = s[i];
            if(mp.count(temp_c) == 0) {
                mx_len = max(mx_len, i-left+1);
            } else {
                if(mp[temp_c] < left) {
                    mx_len = max(mx_len, i-left+1); // abbca
                } else {
                    mx_len = max(mx_len, i-mp[temp_c]); // pwwkew
                    left = mp[temp_c] + 1; // �ǳ���Ҫ
                }
            }
            mp[temp_c] = i; // ����
        }
        return mx_len;
    }
};

/*
"bbbb"
"dvdf"
"pwwkew"
"abcabcbb"

1
3
3
3
*/
