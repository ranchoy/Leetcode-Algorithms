// https://leetcode.cn/problems/score-of-parentheses/
// 题解：堆栈+标记，当连续出栈时不进行分数累加。
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> stk;
        bool flag = false;
        int res= 0, len = s.size();

        for(int i = 0; i < len; i++) {
            if(s[i] == '(') {
                stk.push('(');
                flag = true;
            } else if(!stk.empty() && s[i] == ')') {
                stk.pop();
                if(flag == true) {
                    res += pow(2,stk.size());
                    flag = false;
                }
            }
        }

        return res;
    }
};

/*
"()"
"((()))"
"(()()())"
"((())()())"

1
4
6
8
*/
