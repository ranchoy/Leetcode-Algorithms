// https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/
// 题解：贪心+思维，每次倒2杯水最划算，但是如果x+y<z，则只要z次。因此，ans为amount[]中最大的或者(sum+1)/2。
class Solution {
    public int fillCups(int[] amount) {
        int ans = 0, sum = 0;
        for(int item : amount) {
            sum += item;
            ans = Math.max(ans, item);
        }
        return Math.max(ans, (sum + 1)/2);
    }
}

/*
[0,0,0]
[1,4,2]
[5,4,4]

0
4
7
*/