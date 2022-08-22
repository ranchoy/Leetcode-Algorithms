// https://leetcode.cn/problems/special-binary-string/
// 题解：子序列按照降序调整顺序，注意特殊序列总以1开始0结束。
class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s.size() <= 2) return s;
        string ans, t1, t2;
        int left = 0, cnt = 0;
        vector<string> s_arr;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                ++cnt;
            } else {
                --cnt;
                if(cnt == 0) {
                    t1 = s.substr(left+1, i-left-1); // 1+101100+0
                    t2 = makeLargestSpecial(t1); // 110010
                    s_arr.emplace_back("1" + t2 + "0"); // 1+110010+0
                    left = i + 1;
                }
            }
        }

        sort(s_arr.begin(), s_arr.end(), greater<string>{}); // desc sort
        for(int i = 0; i < s_arr.size(); i++) ans += s_arr[i];
        return ans;
    }
};

/*
"11011000"

"11100100"
*/
