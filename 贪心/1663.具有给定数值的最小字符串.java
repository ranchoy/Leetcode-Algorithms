// https://leetcode.cn/problems/smallest-string-with-a-given-numeric-value/
// 题解：贪心，若字符串字典序最小，每次应尽量选择最小的字母'a'，每位字母的合法取值范围为[max(1,k-(n-i)*26), k-(n-i)]。
class Solution {
    public String getSmallestString(int n, int k) {
        StringBuffer ans = new StringBuffer();

        for(int i = 1; i <= n; i++) {
            int seq = Math.max(1, k - (n - i) * 26);
            k -= seq;
            ans.append((char)('a' + seq - 1));
        }

        return ans.toString();
    }
}

/*
3
27
5
73

"aay"
"aaszz"
*/