// https://leetcode.cn/problems/minimum-swaps-to-make-sequences-increasing/
// 题解：dp动态规划，dp[i][0]和dp[i][1]分别表示[i]位是否交换。
class Solution {
public:
    int minSwap(vector<int> &nums1, vector<int> &nums2) {
        bool flag1, flag2;
        int n = nums1.size();
        int dp[2] = {0,1}, dp_t[2] = {0,1};

        for(int i = 1; i < n; i++) {
            flag1 = nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1];
            flag2 = nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1];
            if(flag1 && !flag2) {
                dp[0] = dp_t[0]; dp[1] = dp_t[1] + 1; // [i]与[i-1]交换一致
            }
            if(flag2 && !flag1) {
                dp[0] = dp_t[1]; dp[1] = dp_t[0] + 1; // [i]与[i-1]交换相反
            }
            if(flag1 && flag2) {
                dp[0] = min(dp_t[0], dp_t[1]);
                dp[1] = min(dp_t[0], dp_t[1]) + 1; // 取[i-1]和[i]变化最小值
            }
            dp_t[0] = dp[0]; dp_t[1] = dp[1]; // recover
        }

        return min(dp[0], dp[1]);
    }
};

/*
[1,3,5,4]
[1,2,3,7]
[0,3,5,8,9]
[2,1,4,6,9]

1
1
*/
