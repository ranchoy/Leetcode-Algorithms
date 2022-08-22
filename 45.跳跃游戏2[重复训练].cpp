// https://leetcode-cn.com/problems/jump-game-ii/
// 每次跳跃，选择区间内最大的跳跃点，max(max_idx, i+nums[i])。
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int n = nums.size() - 1;
        int step = 0, end = 0, mx_idx = 0;
  
        for(int i = 0; i < n; i++) {
            mx_idx = max(mx_idx, i + nums[i]);
            if(i == end){
                end = mx_idx;
                step++;
            }
        }
        
        return step;
    }
};

/*
[2,3,0,1,4]
2
*/
