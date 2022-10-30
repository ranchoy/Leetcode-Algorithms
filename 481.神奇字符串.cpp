// https://leetcode.cn/problems/magical-string/
// 题解：双指针，指针i为待构造子串长度，指针j为待构造索引。
class Solution {
public:
    int magicalString(int n) {
        if(n < 4) return 1;

        string s(n, '0'); // important!
        s[1] = '1', s[2] = '2', s[3] = '2';
        int num, size;
        int res = 1, i = 2, j = 3;

        while(j < n) {
            size = s[i] - '0';
            num = 3 - (s[j-1] - '0');
            while(size > 0 && j < n) {
                if(num == 1) res++;
                s[j++] = num + '0';
                size--;
            }
            i++; // important!
        }
        return res;
    }
};

/*
6
9758

3
4874
*/
