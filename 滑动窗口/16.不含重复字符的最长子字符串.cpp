// https://leetcode.cn/problems/wtcaE1/
// ��⣺�ֵ� + ��������
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int char_cnt[210]; // ͳ�����±�i֮ǰ���ַ����ֵĴ���
        memset(char_cnt, 0, sizeof(char_cnt));
        int left = 0;
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            char_cnt[ch] += 1;

            while(char_cnt[ch] > 1) {
                char_cnt[s[left]] -= 1; // ��Ҫ��ɾ������[left,i]������ַ�ͳ��
                left += 1;
            }

            res = max(res, i-left+1);
        }
        return res;
    }
};
