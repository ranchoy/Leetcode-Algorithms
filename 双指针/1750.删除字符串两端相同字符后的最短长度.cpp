// https://leetcode.cn/problems/minimum-length-of-string-after-deleting-similar-ends/
// 题解：双指针，注意移动left和right索引向中间移动时，最后剩下的子串为1个或2个长度的情况，前者结果为1，后者结果为0或2。
class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n - 1;

        while(left < right && s[left] == s[right]) {
            while(left < right - 1 && s[left] == s[left + 1]) {
                left++;
            }
            while(left < right - 1 && s[right] == s[right - 1]) {
                right--;
            }
            left++; right--;
        }

        return right - left + 1;
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
