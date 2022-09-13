// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
// 题解：贪心算法，昨天买今天卖，只要为正则记录收益。
// res = \sum_{i=1}^{x}([ri]-[li]) = ([ri]-[ri-1]) + ([ri-1]-[ri-2]) + ... + ([li+1]-[li])
//     = \sum_{i=1}^{n-1}max([i]-[i-1], 0).
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0, len = prices.size();
        if(len < 2) return 0;

        for(int i = 1; i < len; i++) {
            res += max(prices[i] - prices[i-1], 0);
        }

        return res;
    }
};

/*
[1,2,3,4]
[7,1,5,3,6,4]

3
7
*/
