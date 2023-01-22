// https://leetcode.cn/problems/calculate-amount-paid-in-taxes/
class Solution {
    public double calculateTax(int[][] brackets, int income) {
        double ans = 0;
        int n = brackets.length;

        for(int i = 0, pre = 0; i < n; i++) {
            int upper = brackets[i][0], percent = brackets[i][1];
            ans += (double) Math.min(income - pre, upper - pre) * percent / 100;
            if(income <= upper) break;
            pre = upper;
        }

        return ans;
    }
}

/*
[[1,0],[4,25],[5,50]]
2
[[3,50],[7,10],[12,25]]
10

0.25000
2.65000
*/