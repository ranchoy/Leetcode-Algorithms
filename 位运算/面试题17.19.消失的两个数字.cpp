// https://leetcode.cn/problems/missing-two-lcci/
// 题解：位运算，通过异或运算得到缺失两个数异或和，再根据最低位进行分类得到两个数。
class Solution {
public:
    vector<int> missingTwo(vector<int> &nums) {
        int n = nums.size();
        int xorsum = 0, res1 = 0, res2 = 0;
        for(int i = 0; i < n; i++) xorsum ^= nums[i];
        for(int i = 1; i <= n+2; i++) xorsum ^=i;

        int l = xorsum & (-xorsum);
        for(int i = 0; i < n; i++) {
            if(nums[i] & l) res1 ^= nums[i];
            else res2 ^= nums[i];
        }
        for(int i = 1; i <= n+2; i++) {
            if(i & l) res1 ^= i;
            else res2 ^= i;
        }

        return {res1,res2};
    }
};

/*
[1]
[2,3]

[2,3]
[1,4]
*/
