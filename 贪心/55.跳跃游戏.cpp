// https://leetcode-cn.com/problems/jump-game/
// 贪心算法，统计[i,end]内的mx=max(mx, i+nums[i])值，等到了end位置再更新end=mx。
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0, end = 0;
        for(int i = 0; i < nums.size(); i++) {
            mx = max(mx, i+nums[i]);
            if(i == end) {
                end = mx;
            }
        }
        return (end >= nums.size()-1);
    }
};

/*
[2,3,1,1,4]
[3,2,1,0,4]
true
false
*/
