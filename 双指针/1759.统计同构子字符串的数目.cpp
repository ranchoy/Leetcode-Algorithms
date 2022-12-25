// https://leetcode.cn/problems/count-number-of-homogenous-substrings/
// 题解：双指针，通过索引left和right，不断计算同构子串，注意结果res会越界，使用long类型。
class Solution {
public:
    const int MOD = 1e9 + 7;
    int countHomogenous(string s) {
        int n = s.size();
        int left = 0, right = 0;
        long res = 0, len;

        while(left < n) {
            while(right + 1 < n && s[left] == s[right + 1]) {
                right++;
            }

            if(right == left) {
                res = (res + 1) % MOD;
                left++; right++;
            } else {
                len = (long)(right - left + 1);
                res = (res + len * (len + 1) / 2) % MOD;
                left = right + 1; right = right + 1;
            }
        }

        return (int)res;
    }
};

/*
"xy"
"abbcccaa"
"zzzzz"

2
13
15
*/
