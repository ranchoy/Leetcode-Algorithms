// https://leetcode.cn/problems/powx-n/
// 题解：快速幂，递归求解x^n的解，x -> x^2 -> x^4 -> x^8 -> x^16 * x = x^17。
class Solution {
    public double myPow(double x, int n) {
        return (n > 0) ? quickMul(x, n) : (1 / quickMul(x, -n));
    }

    public double quickMul(double x, int n) {
        if(n == 0) return 1.0;
        double y = quickMul(x, n/2);
        return (n % 2 == 0) ? y * y : y * y * x;
    }
}

/*
2.00000
10

1024.00000
*/