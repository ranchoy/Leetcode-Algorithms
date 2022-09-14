// https://leetcode.cn/problems/sort-an-array/
// 题解：快速排序，在[left,right]区间选择基线base，先后从右左半区找比base大和小的元素互换，最后将base与[i]互换。
// 注意，快排是非稳定算法，当原数组递减时，计算复杂度为O(n^2)。
class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        int n = nums.size();
        quick_sort(nums, 0, n-1);
        return nums;
    }
    
    void quick_sort(vector<int> &nums, int left, int right) {
        if(left >= right) return;
        int base = nums[left];
        int i = left, j = right;

        while(i < j) {
            while(i < j && nums[j] >= base) {
                --j;
            }
            nums[i] = nums[j];
            while(i < j && nums[i] <= base) {
                ++i;
            }
            nums[j] = nums[i];
        }
        
        nums[i] = base;
        quick_sort(nums, left, i-1);
        quick_sort(nums, i+1, right);
    }
};
