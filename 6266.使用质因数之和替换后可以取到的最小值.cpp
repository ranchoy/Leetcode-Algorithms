// https://leetcode.cn/problems/smallest-value-after-replacing-with-sum-of-prime-factors/
// 题解：递归+质因数分解，注意sum=n的情况。
class Solution {
public:
    int smallestValue(int n) {
        int sum = 0, temp = n;

        for(int i = 2; i <= n && temp > 1; i++) {
            while(temp % i == 0) {
                sum += i;
                temp /= i;
            }
        }

        return sum == n ? n : smallestValue(sum);
    }
};


/*
3
4
15

3
4
5
*/
