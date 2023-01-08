// https://leetcode.cn/problems/jump-game-ii/
// 题解：贪心，不需要访问最后一个元素，因为有可能会增加一次跳跃次数。
// 每次跳跃，选择区间内最大的跳跃点，max(max_idx, i+nums[i])。
class Solution {
public:
    int jump(vector<int> &nums) {
        int n = nums.size();
        int step = 0, mx_idx = 0, next_idx = 0;

        for(int i = 0; i < n-1; i++) {
            mx_idx = max(mx_idx, i + nums[i]);
            if(i == next_idx) {
                next_idx = mx_idx; step++;
            }
        }

        return step;
    }
};

/*
[2,1]
[2,3,0,1,4]

1
2
*/
