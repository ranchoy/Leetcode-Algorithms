// https://leetcode.cn/problems/k-th-symbol-in-grammar/
// 题解：DFS+规律，当k大于half时，左右对称，异或即可，否则正常遍历。
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k == 1) return 0;
        int half = (int)(1 << (n - 2));
        if(k > half) return 1 ^ kthGrammar(n-1, k - half);
        return kthGrammar(n-1, k);
    }
};

/*
2
1
30
400000000

0
1
*/
