// https://leetcode-cn.com/problems/sort-array-by-parity/
// 模拟题目，空间复杂度最低。
class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int i = 0, j = 1;
        int n = nums.size();

        while(i < n) {
            if(nums[i]&1 == 1) {
                j = i + 1;
                while(j < n && (nums[j]&1 != 0)) {
                    j++;
                }
                if(j < n) {
                    swap(nums[i], nums[j]);
                }
            }
            i++;
        }
        return nums;
    }
};

/*
[0,1]
[3,1,2,4]

[0,1]
[2,4,3,1]
*/
