// https://leetcode-cn.com/problems/valid-parentheses/
// 模拟堆栈，注意入栈和出栈
class Solution {
public:
    bool isValid(string s) {
        // 入栈出栈，最后栈不为空则不满足要求，否则满足要求
        stack<char> stk;

        if(s.size() == 0 || s.size()%2==1)
            return false;
        if(s[0] == ')' || s[0] == ']' || s[0] == '}')
            return false;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
                continue;
            } else if(s[i] == ')') {
                if(stk.size()==0 || stk.top() != '(') {
                    return false;
                }
            } else if(s[i] == ']') {
                if(stk.size()==0 || stk.top() != '[') {
                    return false;
                }
            } else {
                if(stk.size()==0 || stk.top() != '{') {
                    return false;
                }
            }
            stk.pop();
        }

        return (stk.size() == 0) ? true : false;
    }
};
