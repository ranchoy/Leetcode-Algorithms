// https://leetcode.cn/problems/generate-parentheses/
// 题解：深度搜索DFS，注意有效括号组合是：左右括号数量相等，且左括号有匹配的右括号。即，当right < left时，补充右括号。
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> ans;
        DFS(ans, s, 0, 0, n);
        return ans;
    }

    void DFS(vector<string> &ans, string &cur, int left, int right, int n) {
        if(cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if(left < n) {
            cur.push_back('(');
            DFS(ans, cur, left + 1, right, n);
            cur.pop_back();
        }
        if(right < left) { // important!!!
            cur.push_back(')');
            DFS(ans, cur, left, right + 1, n);
            cur.pop_back();
        }
    }
};

/*
1
2
3
4

["()"]
["(())","()()"]
["((()))","(()())","(())()","()(())","()()()"]
["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
*/
