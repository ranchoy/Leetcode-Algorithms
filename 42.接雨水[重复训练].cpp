// https://leetcode-cn.com/problems/trapping-rain-water/
// 单调栈，遇到当前元素height[i]大于栈顶情况，则弹出栈顶元素，并统计水坑容积，直至当前元素大于栈顶；
// 双指针，left[i]与right[i]分别表示元素height[i]的左区间[0~i-1]最大高度与右区间[i+1~n-1]最大高度。
class Solution {
public:
    int trap(vector<int> &height) {
        int res = 0;
        stack<int> stk;
        int n = height.size();

        for(int i = 0; i < n; i++) {
            while(!stk.empty() && height[i] > height[stk.top()]) {
                int idx = stk.top(); stk.pop(); // 底部索引
                while(!stk.empty() && height[idx] == height[stk.top()]) {
                    stk.pop(); // 样例，41114
                }
                if(!stk.empty()) {
                    int h = min(height[i], height[stk.top()]) - height[idx];
                    int l = i - stk.top() - 1;
                    res += h * l;
                }
            }
            stk.push(i);
        }
        return res;
    }

    // int trap2(vector<int> &height) {
    //     int res = 0;
    //     int n = height.size();
    //     vector<int> left(n,0), right(n,0);
    //     for(int i = 1; i < n; i++) {
    //         left[i] = max(left[i-1], height[i]);
    //     }
    //     for(int i = n-2; i >= 0; i--) {
    //         right[i] = max(right[i+1], height[i]);
    //     }
    //     for(int i = 0; i < n; i++) {
    //         int min_height = min(left[i], right[i]);
    //         res += max(0, min_height - height[i]);
    //     }
    //     return res;
    // }
};

/*
[4,2,0,3,2,5]
[0,1,0,2,1,0,1,3,2,1,2,1]

9
6
*/
