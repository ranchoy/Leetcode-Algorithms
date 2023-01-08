// https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/
// 题解：双指针，left不断向右移动，若lsum+rsum>x则窗口right右移以不断减小rsum，寻找满足lsum+rsum=x的结果。
class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ans = n + 1;
        int left = 0, right = 0, lsum = 0, rsum = sum; // important!
        if(sum < x) return -1;

        for(left = -1; left < n; left++) {
            if(left != -1) lsum += nums[left];

            while(right < n && lsum + rsum > x) {
                rsum -= nums[right];
                right++;
            }
            if(lsum + rsum == x) {
                ans = min(ans, (left + 1) + (n - right));
            }
        }

        return ans > n ? -1 : ans;
    }
};

/*
[5,6,7,8,9]
4
[3,2,20,1,1,3]
10

-1
5
*/
