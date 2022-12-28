// https://leetcode.cn/problems/minimum-length-of-string-after-deleting-similar-ends/
// 题解：双指针，注意移动left和right索引向中间移动时，最后剩下的子串为1个或2个长度的情况，前者结果为1，后者结果可能为0或2。
class Solution {
public:
    int minimumLength(string s) {
        if(s.size() == 1) return 1;
        int ans = 0, n = s.size();
        int left = 0, right = n - 1;
        int i = left, j = right;

        while(i < j) {
            while(i < j && s[i] == s[left]) {
                i++;
            }
            while(i < j && s[j] == s[right]) {
                j--;
            }

            if(right == left + 2) return 1; // remain substr len = 1.
            if(s[left] != s[right]) {
                return right - left + 1;
            }

            left = i; right = j; // update
        }

        return (left == right) ? 0 : n;
    }
};

/*
"ca"
"aabccabba"
"cabaabac"
"bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb"

2
3
0
1
*/
