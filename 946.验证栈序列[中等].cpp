// https://leetcode.cn/problems/validate-stack-sequences/
// 题解：堆栈模拟，注意不要数组越界。
class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> stk;
        int j = 0;
        int n = pushed.size(), m = popped.size();

        for(int i = 0; i < n; i++) {
            while(!stk.empty() && j < m && stk.top() == popped[j]) {
                stk.pop(); j++;
            }
            stk.push(pushed[i]);
        }

        while(!stk.empty() && j < m && stk.top() == popped[j]) {
            stk.pop(); j++;
        }

        return stk.empty() ? true : false;
    }
};

/*
[1,2,3,4,5]
[4,5,3,2,1]
[1,2,3,4,5]
[4,3,5,1,2]

true
false
*/
