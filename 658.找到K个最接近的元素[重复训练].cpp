// https://leetcode.cn/problems/find-k-closest-elements/
// 题解：二分法+双指针，二分法寻找min_idx，双指针扩大范围，注意left和right的边界问题。
class Solution {
public:
    vector<int> findClosestElements(vector<int> &nums, int k, int x) {
        if(nums.size() <= k) return nums;
        int len = nums.size(), a, b;
        int min_idx = find_minimun_idx(nums, x, 0, len-1);
        int left = min_idx, right = min_idx;

        while(right - left + 1 < k) {
            if(left == 0 || right == len-1) { // important
                if(left == 0) right++;
                else if(right == len-1) left--;
            } else {
                a = abs(nums[left-1] - x), b = abs(nums[right+1] - x);
                if(a <= b) left--;
                else right++;
            }
        }

        return vector<int>(nums.begin() + left, nums.begin() + right + 1);
    }

    int find_minimun_idx(vector<int> &nums, int x, int left, int right) {
        if(left == right) return left;
        int a = abs(nums[left] - x), b = abs(nums[right] - x);
        if(left + 1 == right) return (a <= b) ? left : right;

        int mid = left + (right - left) / 2;
        if(nums[mid] < x) return find_minimun_idx(nums, x, mid, right);
        else return find_minimun_idx(nums, x, left, mid);
    }
};

/*
[1]
1
1
[1,2,3,4,5]
4
-1
[0,0,1,2,3,3,4,7,7,8]
3
5
[0,1,1,1,2,3,6,7,8,9]
9
4

[1]
[1,2,3,4]
[3,3,4]
[0,1,1,1,2,3,6,7,8]
*/
