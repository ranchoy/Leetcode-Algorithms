// https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/
// 题解：单调栈，逆序记录小于当前prices[i]的元素，栈顶的元素距离prices[i]更近。
class Solution {
public:
    vector<int> finalPrices(vector<int> &prices) {
        int n = prices.size();
        stack<int> stk;
        vector<int> res(n, 0);

        for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && stk.top() > prices[i]) {
                stk.pop();
            }

            res[i] = stk.empty() ? prices[i] : (prices[i] - stk.top());
            stk.push(prices[i]);
        }

        return res;
    }
};

/*
[8,4,6,2,3]
[1,2,3,4,5]

[4,2,4,2,3]
[1,2,3,4,5]
*/
