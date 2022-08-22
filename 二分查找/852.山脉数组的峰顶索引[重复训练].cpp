// https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
// 二分查找，注意left与right更新的值是mid。
class Solution {
public:
    int peakIndexInMountainArray(vector<int> &nums) {
        int n = nums.size();
        int mid, left = 0, right = n-1;

        while(left < right) {
            mid = left + ((right - left)>>1);
            // 测试数据不会出现此情况
            if((mid == 0 && nums[mid] > nums[mid+1]) ||
               (mid == n-1 && nums[mid] > nums[mid-1])) {
                return mid;
            }

            if(nums[mid] >= nums[mid-1] && nums[mid] <= nums[mid+1]) {
                left = mid;
            } else if(nums[mid] <= nums[mid-1] && nums[mid] >= nums[mid+1]) {
                right = mid;
            } else {
                return mid;
            }
        }

        return left;
    }
};

/*
[3,5,3,2,0]

1
*/
