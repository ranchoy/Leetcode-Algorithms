// https://leetcode-cn.com/problems/3sum/
// 滑动窗口，注意过滤重复元素，包括：[i]与[i-1]重复; [left]与[left+1]重复；[right-1]与[right]重复。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int left, right;
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end(), less<int>());

        for(int i = 0; i <= n-3; i++) {
            if(nums[i]+nums[i+1]+nums[i+2] > 0) continue;
            if(nums[i]+nums[n-2]+nums[n-1] < 0) continue;
            if(i != 0 && nums[i] == nums[i-1]) continue; // 非常重要，[-4,-2,-2,0,2,2]

            left = i + 1; right = n - 1;
            while(left < right) {
                int temp = nums[i]+nums[left]+nums[right];
                if(temp == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++; right--;
                    while(left < right && nums[left] == nums[left-1]) {
                        left++; // 重要，[-2,0,0,2,2]
                    }
                    while(left < right && nums[right] == nums[right+1]) {
                        right--;
                    }
                } else if(temp < 0){
                    left++;
                } else {
                    right--;
                }
            }
        }

        return res;
    }
};
/*
[1,2,-2,-1]
[-2,1,0,1,2]
[-1,0,1,2,-1,-4]
[-4,-2,-2,0,2,2]
[-2,0,0,2,2]

[]
[[-2,0,2],[-2,1,1]]
[[-1,-1,2],[-1,0,1]]
[[-2,0,2]]
*/
