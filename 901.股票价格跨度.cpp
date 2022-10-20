// https://leetcode.cn/problems/online-stock-span/
// 题解：类单调栈，记录连续天数day_arr，后续比较可以直接通过day_arr跳跃。
class StockSpanner {
private:
    vector<int> day_arr;
    vector<int> price_arr;
public:
    StockSpanner() {

    }

    int next(int price) {
        int cnt = 1;
        int i = price_arr.size() - 1;

        while(i >= 0) {
            if(price_arr[i] <= price) {
                cnt += day_arr[i];
                i -= day_arr[i];
            } else {
                break;
            }
        }

        day_arr.push_back(cnt);
        price_arr.push_back(price);
        return cnt;
    }
};

/*
["StockSpanner","next","next","next","next","next","next","next"]
[[],[100],[80],[60],[70],[60],[75],[85]]
["StockSpanner","next","next","next","next","next","next","next","next","next","next"]
[[],[28],[14],[28],[35],[46],[53],[66],[80],[87],[88]]

[null,1,1,1,2,1,4,6]
[null,1,1,3,4,5,6,7,8,9,10]
*/

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
