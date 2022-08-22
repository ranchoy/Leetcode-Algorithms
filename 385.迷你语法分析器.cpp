// https://leetcode-cn.com/problems/mini-parser/
// 堆栈+模拟，注意“i=j-1”的更新条件，以及“stk.size()>1”的条件。
class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger> stk;
        if(s[0] != '[') return NestedInteger(stoi(s));

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ',') continue;
            if(s[i] == '-' || isdigit(s[i])) { // 转换数字
                int elem_val = 0;
                int j = (s[i] == '-') ? i+1 : i;
                int symbol = (s[i] == '-') ? -1 : 1;
                for(; j < s.size() && isdigit(s[j]); j++) {
                    elem_val = elem_val*10 + (s[j] - '0');
                }
                stk.top().add(NestedInteger(elem_val * symbol)); // 添加元素
                i = j - 1; // 非常重要
            } else if(s[i] == '[') {
                stk.push(NestedInteger()); // 空容器边界
            } else if(s[i] == ']' && stk.size() > 1) { // 非常重要
                NestedInteger temp = stk.top(); stk.pop();
                stk.top().add(temp);
            }
        }
        return stk.top();
    }
};

/*
"[123,456,[788,799,833],[[]]]"

[123,456,[788,799,833],[[]]]
*/
