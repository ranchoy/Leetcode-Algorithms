// https://leetcode.cn/problems/median-of-two-sorted-arrays/
// 非最优解：双指针，记录中位数附近两个数的指针。
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int *p_pre = nullptr, *p_cur = nullptr;
        int m = nums1.size(), n = nums2.size();
        int mid_len = (m + n)/2 + 1, i = 0, j = 0;

        for(int k = 0; k < mid_len; k++) {
            p_pre = p_cur;
            if(i == m || j == n) {
                p_cur = (j == n) ? &nums1[i++] : &nums2[j++];
            } else {
                p_cur = (nums1[i] <= nums2[j]) ? &nums1[i++] : &nums2[j++];
            }
        }

        return ((m+n)&1) ? *p_cur : (double)(*p_cur + *p_pre)/2;
    }
};

/*
[1,3]
[2]
[1,3]
[2,4]

2.00000
2.50000
*/
