// https://leetcode.cn/problems/sort-an-array/
// 题解：归并排序，先将左半区[left,mid]和右半区[mid+1,right]排序完毕，再排序[left,right]区间。
class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        int len = nums.size();
        merge_sort(nums, 0, len-1);
        return nums;
    }

    void merge_sort(vector<int> &nums, int left, int right) {
        if(left >= right) return;

        int mid = (left + right) >> 1;
        int i = left, j = mid + 1;

        // merge sorting of left and right regions.
        merge_sort(nums, left, mid);
        merge_sort(nums, mid + 1, right);

        vector<int> temp;
        while(i <= mid && j <= right) {
            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        // elements remaining
        while(i <= mid) temp.push_back(nums[i++]);
        while(j <= right) temp.push_back(nums[j++]);
        for(i = left; i <= right; i++) nums[i] = temp[i - left]; // copy
    }
};
