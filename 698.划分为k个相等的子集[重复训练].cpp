// https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/
// 题解：降序+DFS+剪枝，注意降序排列，以及剪枝技巧。
class Solution {
public:
    int target;
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int dp_sum = 0;
        for(auto num : nums) dp_sum += num;
        if(dp_sum % k != 0) return false;

        target = dp_sum / k;
        vector<int> bucket(k, 0);
        sort(nums.begin(), nums.end(), greater<int>()); // important
        return dfs(nums, bucket, 0, k);
    }

    bool dfs(vector<int> &nums, vector<int> &bucket, int idx, int k) {
        if(idx == nums.size()) return true;
        for(int i = 0; i < k; i++) {
            if(i > 0 && bucket[i] == bucket[i-1]) continue; // important two
            if(bucket[i] + nums[idx] > target) continue;
            bucket[i] += nums[idx];
            if(dfs(nums, bucket, idx+1, k)) return true;
            bucket[i] -= nums[idx];
        }
        return false;
    }
};

/*
[2,2,2,2,3,4,5]
4

false
*/
