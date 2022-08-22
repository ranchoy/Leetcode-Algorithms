// https://leetcode-cn.com/problems/subarray-product-less-than-k/
// dp动态规划，尾缀乘积，当dp_multip>=k时更新left指针。
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if(k == 0) return 0;
        int n = nums.size();
        int ans = 0, left = 0;
        long long int dp_multip = 1;

        for(int i = 0; i < n; i++) {
            dp_multip = dp_multip * nums[i];
            if(dp_multip >= k) {
                while(left <= i && dp_multip >= k) {
                    dp_multip /= nums[left];
                    left++;
                }
            }
            ans += i - left + 1;
        }

        return ans;
    }
};

/*
[1,1,1]
1
[1,2,3]
0
[10,5,2,6]
100

0
0
8
*/
