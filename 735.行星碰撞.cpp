// https://leetcode.cn/problems/asteroid-collision/
// 题型：数组，堆栈
class Solution {
public:
    vector<int> asteroidCollision(vector<int> &nums) {
        stack<int> stk;
        vector<int> res;
        int len = nums.size();

        for(int i = 0; i < len; i++) {
            if(stk.empty() || is_same_symbol(nums[i], stk.top()) || (nums[i] > 0 && stk.top() < 0)) {
                stk.push(nums[i]); // empty | same symbol | disjoint direction
            } else {
                while(!stk.empty() && !is_same_symbol(nums[i], stk.top()) && (nums[i] + stk.top() < 0)) {
                    stk.pop();
                }

                if(stk.empty() || is_same_symbol(nums[i], stk.top())) {
                    stk.push(nums[i]);
                } else if(nums[i] + stk.top() == 0) {
                    stk.pop(); // [1] -1
                }
            }
        }

        while(!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool is_same_symbol(int a, int b) {
        return (a ^ b) >= 0;
    }
};

/*
[-2,-1,1,2]
[-2,-2,-2,-2]
[-2,-2,1,-2]

[-2,-1,1,2]
[-2,-2,-2,-2]
[-2,-2,-2]
*/
