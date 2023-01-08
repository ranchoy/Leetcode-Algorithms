// https://leetcode.cn/problems/wtcaE1/
// 题解：字典 + 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int char_cnt[210]; // 统计在下标i之前，字符出现的次数
        memset(char_cnt, 0, sizeof(char_cnt));
        int left = 0;
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            char_cnt[ch] += 1;

            while(char_cnt[ch] > 1) {
                char_cnt[s[left]] -= 1; // 重要，删除不在[left,i]区间的字符统计
                left += 1;
            }

            res = max(res, i-left+1);
        }
        return res;
    }
};
