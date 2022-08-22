// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// 二分查找，分别找刚好大于target-1与target的位置，如果nums[left]==target则存在区间，否则不存在。
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int len = nums.size();
        int left = find_index(nums, target-1, 0, len-1); // 大于target-1下标
        int right = find_index(nums, target, 0, len-1) - 1; // 大于target下标

        if(left < len && nums[left] == target) {
            return {left, right};
        }

        return {-1,-1};
    }

    int find_index(vector<int> &nums, int target, int left, int right) {
        if(left > right) return left; // 重要
        int mid = left + ((right - left)>>1);
        if(nums[mid] > target) { // 重要
            return find_index(nums, target, left, mid-1);
        }
        return find_index(nums, target, mid+1, right);
    }
};

/*
[1]
1
[5,7,7,8,8,10]
8

[0,0]
[3,4]
*/
