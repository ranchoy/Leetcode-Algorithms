// https://leetcode.cn/problems/maximum-number-of-consecutive-values-you-can-make/
// 题解：贪心+思维，假设目前可表示区间为[0,x]。若新加入一个数y且y<=x+1，则新区间为[0,y] = [0,x] + [y,x+y]。
class Solution {
    public int getMaximumConsecutive(int[] coins) {
        int ans = 0;
        int n = coins.length;
        Arrays.sort(coins);

        for(int y : coins) {
            if(y > ans + 1) break;
            ans += y; // 区间扩张至[0,ans+y]
        }

        return ans + 1;
    }
}

/* 
[1,1,1,4]
[1,4,10,3,1]

8
20
*/