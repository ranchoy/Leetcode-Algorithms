// https://leetcode.cn/problems/minimum-size-subarray-sum/
// 题解：滑动窗口，输出长度最小连续子数组，长度或者子数组
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int len, min_len = INT_MAX;

        // map<int, vector<int>> mp; // 差值-左右区间

        int sum = nums[0];
        while(left <= right && right < n) {
            if(sum >= target) {
                min_len = min(min_len, right-left+1);
                sum -= nums[left];
                left += 1;
            } else {
                right += 1;
                if(right >= n) break;
                sum += nums[right];
            }
    
            // // 记录左索引
            // if(sum >= target) mp[right - left + 1].push_back(left);
        }

        // // 输出最小区间
        // vector<int> vt = mp[min_len];
        // for(int i=0; i<vt.size(); i++)
        //     cout << vt[i] << endl;

        return (min_len == INT_MAX) ? 0 : min_len;
    }
};

/*
7
[2,3,1,2,4,3]
2
*/
