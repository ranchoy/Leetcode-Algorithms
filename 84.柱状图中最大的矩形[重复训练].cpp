// https://leetcode.cn/problems/largest-rectangle-in-histogram/
// 题解：单调栈，寻找比heights[i]矮的最近左右边界left[i]和right[i]，极端值分别为0和n。
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int res = 0, n = heights.size();
        stack<int> stk;
        vector<int> left(n, 0), right(n, n);

        for(int i = 0; i < n; i++) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        for(int i = 0; i < n; i++) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }

        return res;
    }
    
    int largestRectangleArea2(vector<int> &heights) {
        int res = 0, n = heights.size();
        stack<int> stk;
        vector<int> left(n), right(n);

        for(int i = 0; i < n; i++) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        stk = stack<int>();
        for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        for(int i = 0; i < n; i++) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }

        return res;
    }
};

/*
[2,4]
[2,1,5,6,2,3]

4
10
*/
