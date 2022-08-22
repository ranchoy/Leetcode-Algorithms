// https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
// 位运算，按位取模得到只出现一次的元素。
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        vector<int> bit_arr(32,0);

        for(int i = 0; i < nums.size(); i++) {
            for(int k = 0; k < 32; k++) {
                bit_arr[k] += (nums[i] >> k)&1;
                bit_arr[k] = bit_arr[k]%3;
            }
        }

        for(int k = 0; k < 32; k++) {
            if(bit_arr[k] != 0) res += 1<<k;
        }

        return res;
    }
};

/*
[3,4,3,3]
[9,1,7,9,7,9,7]

4
1
*/
