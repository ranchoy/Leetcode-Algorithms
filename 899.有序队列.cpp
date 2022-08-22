// https://leetcode.cn/problems/orderly-queue/
// 题解：当k=1时模拟比较，当k>1时按字典序排序
class Solution {
public:
    string orderlyQueue(string s, int k) {
        string r_str = s;

        if(k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        
        for(int i = 0; i < s.length(); i++) {
            s += s[0];
            s.erase(s.begin(), s.begin()+1);
            if(r_str > s) r_str = s;
        }

        return r_str;
    }
};

/*
"cba"
1
"baaca"
3

"acb"
"aaabc"
*/
