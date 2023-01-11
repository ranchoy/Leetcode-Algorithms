// https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
// 题解：归并排序，注意逆序对数计算方法，应该累加(mid - i + 1)，以避免重复计算。
class Solution {
public:
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        int ans = reversed_pair_num(nums, 0, n - 1);
        return ans;
    }

    int reversed_pair_num(vector<int> &nums, int left, int right) {
        if(left >= right) return 0;

        int mid = (left + right) / 2;
        int left_num = reversed_pair_num(nums, left, mid);
        int right_num = reversed_pair_num(nums, mid + 1, right);

        int ans = 0;
        int i = left, j = mid + 1;
        vector<int> temp_arr;
        while(i <= mid && j <= right) {
            if(nums[i] > nums[j]) {
                ans += mid - i + 1; // important!
                temp_arr.push_back(nums[j++]);
            } else {
                temp_arr.push_back(nums[i++]);
            }
        }
        while(i <= mid) temp_arr.push_back(nums[i++]);
        while(j <= right) temp_arr.push_back(nums[j++]);
        for(i = 0; i < temp_arr.size(); i++) nums[i + left] = temp_arr[i];

        return ans + left_num + right_num;
    }
};

/*
[7,5,6,4]
[1,3,2,3,1]

5
4
*/
