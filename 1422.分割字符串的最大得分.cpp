// https://leetcode.cn/problems/maximum-score-after-splitting-a-string/
// 题解：模拟题，先记录“1”总次数，再遍历寻找最大解。
class Solution {
public:
    int maxScore(string s) {
        int all_ones = 0, ans = 0;
        int tmp_ones = 0, tmp_zeros = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') ++all_ones;
        }
        for(int i = 0; i < s.length()-1; i++) {
            if(s[i] == '0') ++tmp_zeros;
            else if(s[i] == '1') ++tmp_ones;
            ans = max(ans, tmp_zeros + all_ones - tmp_ones);
        }
        return ans;
    }
};

/*
"00"
"011101"

1
5
*/
