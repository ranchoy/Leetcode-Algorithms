// https://leetcode.cn/contest/weekly-contest-328/problems/count-the-number-of-good-subarrays/
// 题解：滑动窗口，pairs表示窗口[left,right=i]区间内元素相等对数，right指针不断向右移动，left指针向右移动保持满足最小k对要求即可。
class Solution {
public:
    long long countGood(vector<int> &nums, int k) {
        long long ans = 0;
        int n = nums.size();
        int left = 0, pairs = 0;
        map<int,int> elem_map; // <element, count>

        for(int item : nums) {
            pairs += elem_map[item]; // 增加item对数
            elem_map[item] += 1;

            while(pairs - (elem_map[ nums[left] ] - 1) >= k) {
                elem_map[ nums[left] ] -= 1;
                pairs -= elem_map[ nums[left] ]; // 减少item对数
                left += 1;
            }

            if(pairs >= k) ans += left + 1;
        }

        return ans;
    }
};

/*
[1,1,1,1,1]
10
[3,1,4,3,2,2,4]
2

1
4
*/
