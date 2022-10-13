
// https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/
// 题解：单调栈，如果stk.top()小于nums[i]则后者自己可以单独作为一组，否则与前面元素一组（直至stk.top()<nums[i]）。
class Solution {
public:
    int maxChunksToSorted(vector<int> &nums) {
        int elem;
        stack<int> stk; // asc

        for(int i = 0; i < nums.size(); i++) {
            if(stk.empty() || nums[i] >= stk.top()) {
                stk.push(nums[i]);
            } else {
                elem = stk.top(); stk.pop(); // 124
                while(!stk.empty() && stk.top() > nums[i]) {
                    stk.pop();
                }
                stk.push(elem); // 12|43
            }
        }

        return stk.size();
    }
};

/*
[5,4,3,2,1]
[2,1,3,4,4]

1
4
*/
