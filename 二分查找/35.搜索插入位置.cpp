// https://leetcode-cn.com/problems/search-insert-position/
// 二分查找
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        return find_index(nums, target, 0, nums.size()-1);
    }

    int find_index(vector<int> &nums, int target, int left, int right) {
        if(left > right) return left;
        int mid = left + ((right - left) >> 1);
        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] > target) {
            return find_index(nums, target, left, mid-1);
        }
        return find_index(nums, target, mid+1, right);
    }
};

/*
[1,3,5,6]
2
[1,3,5,6]
5
[1,3,5,6]
7

1
2
4
*/
