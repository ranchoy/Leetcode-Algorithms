// https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
// 位运算+数字分组，a与b中第一个不同的位作为分组依据。
class Solution {
public:
    vector<int> singleNumbers(vector<int> &nums) {
        int bit_idx = 1;
        int a = 0, b = 0, res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        while((bit_idx & res) == 0) {
            bit_idx = bit_idx<<1; // a与b第一次不同位
        }
        for(int i = 0; i < nums.size(); i++) {
            if((bit_idx & nums[i]) == 0) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }
        if(a > b) swap(a, b);
        return vector<int>{a,b};
    }
};

/*
[1,2,5,2]
[4,1,4,6]

[1,5]
[1,6]
*/
