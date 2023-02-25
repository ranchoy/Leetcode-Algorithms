import java.util.*;
// https://leetcode.cn/problems/remove-k-digits/
// 题解：贪心 + 单调栈，当栈顶元素stk.peek() > c时，弹出栈顶元素；当仍然k > 0时，弹出栈顶元素。注意需要删除高位前置"0"元素，即stk.pollLast()。
// 双端队列ArrayDeque<>可以作为栈，stk.peek() == stk.peekFirst() == stk.getFirst()，stk.pop() == stk.pollFirst()，stk.push() == stk.addFirst()。
class Solution {
    public String removeKdigits(String num, int k) {
        StringBuffer ans = new StringBuffer();
        int n = num.length();
        Deque<Character> stk = new ArrayDeque<>();

        for(char c : num.toCharArray()) {
            while(!stk.isEmpty() && k > 0 && stk.peek() > c) {
                stk.pop(); k--;
            }
            stk.push(c);
        }
        while(!stk.isEmpty() && k > 0) {
            stk.pollFirst(); k--; // 12345
        }

        boolean flag = true;
        while(!stk.isEmpty()) {
            if(flag && stk.getLast() == '0') {
                stk.pollLast(); continue;
            }
            flag = false;
            ans.append(stk.pollLast());
        }

        return (ans.length() == 0) ? "0" : ans.toString();
    }
}

/*
"10"
1
"10200"
1
"1432219"
3

"0"
"1"
"200"
"1219"
*/