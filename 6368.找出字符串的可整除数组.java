// https://leetcode.cn/problems/find-the-divisibility-array-of-a-string/
// 题解：模拟，(x * 10 + (word[i] - '0')) % m == 0表示word[0,...,i]可以被m整除。
class Solution {
    public int[] divisibilityArray(String word, int m) {
        long x = 0;
        int n = word.length();
        int[] ans = new int[n];

        for(int i = 0; i < n; i++) {
            x = (x * 10 + (word.charAt(i) - '0')) % m;
            ans[i] = (x == 0) ? 1 : 0;
        }

        return ans;
    }
}

/*
"1010"
10
"998244353"
3

[0,1,0,1]
[1,1,0,0,0,1,1,0,0]
*/