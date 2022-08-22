// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
// 快排算法，选择基准，区间[left,right]排序，从右区间找到比base小的，从左区间找到比base大的，再互换。
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        quick_sort(nums, 0, n-1);
        return nums[n-k];
    }
    
    void quick_sort(vector<int> &nums, int left, int right) {
        if(left >= right) return;
        int base = nums[left];
        int start = left, end = right;
        while(left < right) {
            while(left < right && nums[right] >= base) {
                right--;
            }
            nums[left] = nums[right];
            while(left < right && nums[left] <= base) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = base;
        quick_sort(nums, start, left-1);
        quick_sort(nums, left+1, end);
    }
};

/*
[3,2,1,5,6,4]
2
[3,2,3,1,2,4,5,5,6]
4

5
4
*/
