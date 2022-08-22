// https://leetcode-cn.com/problems/maximum-product-subarray/
// dp动态规划，维护dp_max和dp_min两个数组
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res;
        int n = nums.size();
        vector<int> dp_max(n, 0);
        vector<int> dp_min(n, 0);

        res = dp_max[0] = dp_min[0] = nums[0];
        for(int i = 1; i < n; i++) {
            dp_max[i] = elem_max(nums[i], dp_max[i-1]*nums[i], dp_min[i-1]*nums[i]);
            dp_min[i] = elem_min(nums[i], dp_min[i-1]*nums[i], dp_max[i-1]*nums[i]);
            res = elem_max(res, dp_max[i], dp_min[i]);
        }

        return res;
    }

    int elem_max(int a, int b, int c) {
        return max(max(a, b), c);
    }

    int elem_min(int a, int b, int c) {
        return min(min(a,b), c);
    }
};

/*
[2,3,-2,4]
6
[-2,0,-1]
0
*/
