// https://leetcode.cn/problems/max-chunks-to-make-sorted/
// https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/
// 题解：单调栈，每次保留块最大值（块融合），块数等于栈大小。
class Solution {
public:
    int maxChunksToSorted(vector<int> &nums) {
        stack<int> stk;

        for(int i = 0, mx; i < nums.size(); i++) {
            if(stk.empty() || nums[i] >= stk.top()) {
                stk.push(nums[i]);
            } else {
                mx = stk.top(); stk.pop();
                while(!stk.empty() && nums[i] < stk.top()) {
                    stk.pop();
                }
                stk.push(mx);
            }
        }

        return stk.size();
    }
};

/*
[5,1,0,4,3,2]
[1,0,4,3,5,2]
[1,0,3,2,4,5]

1
2
4
*/
