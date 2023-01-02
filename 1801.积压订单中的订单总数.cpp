// https://leetcode.cn/problems/number-of-orders-in-the-backlog/
// 题解：优先队列priority_queue<Type, Container, Functional>，其中Type为数据类型，Container为保存数据的容器，Functional为元素比较方式。
// greater<int>与greater<int>()的区别，greater<int>对应于结构体类型，greater<int>()对应于没有参数且返回类型为greater<int>的函数类型。比如priority_queue中使用不带括号的，sort()使用带括号的。
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>> &orders) {
        int ans = 0;
        const int MOD = 1e9 + 7;
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int, int>>> buy_orders; // <price,amount>, low to high
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sell_orders; // <price,amount>, high to low

        for(auto &order : orders) {
            int price = order[0], amount = order[1], order_type = order[2];

            if(order_type == 0) {
                while(amount > 0 && !sell_orders.empty() && sell_orders.top().first <= price) {
                    auto sell_item = sell_orders.top();
                    sell_orders.pop();

                    int sell_amount = min(sell_item.second, amount);
                    amount -= sell_amount; sell_item.second -= sell_amount;

                    if(sell_item.second > 0) {
                        sell_orders.push(sell_item);
                    }
                }

                if(amount > 0) {
                    buy_orders.emplace(price, amount);
                }
            } else {
                while(amount > 0 && !buy_orders.empty() && buy_orders.top().first >= price) {
                    auto buy_item = buy_orders.top();
                    buy_orders.pop();

                    int buy_amount = min(buy_item.second, amount);
                    amount -= buy_amount;
                    buy_item.second -= buy_amount;

                    if(buy_item.second > 0) {
                        buy_orders.push(buy_item);
                    }
                }

                if(amount > 0) {
                    sell_orders.emplace(price, amount);
                }
            }
        }

        while(!buy_orders.empty()) {
            ans = (ans + buy_orders.top().second) % MOD;
            buy_orders.pop();
        }
        while(!sell_orders.empty()) {
            ans = (ans + sell_orders.top().second) % MOD;
            sell_orders.pop();
        }

        return ans;
    }
};

/*
[[10,5,0],[15,2,1],[25,1,1],[30,4,0]]

6
*/
