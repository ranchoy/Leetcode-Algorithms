// https://leetcode.cn/problems/min-max-game/
// 题解：模拟，注意递推的下标选择。
class Solution {
public:
    int minMaxGame(vector<int> &nums) {
        int n = nums.size();

        while(n > 1) {
            int k = 0;
            for(int i = 0; i < n/2; i++) {
                if(i & 1) {
                    nums[k++] = max(nums[2*i], nums[2*i + 1]);
                } else {
                    nums[k++] = min(nums[2*i], nums[2*i + 1]);
                }
            }
            n = n / 2;
        }

        return nums[0];
    }
};

/*
[3]
[1,3,5,2,4,8,2,2]

3
1
*/
