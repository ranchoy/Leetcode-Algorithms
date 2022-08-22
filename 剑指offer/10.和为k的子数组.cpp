// https://leetcode-cn.com/problems/QTMn0o/
// 前缀和 + 等差法 + HashMap
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // k = sum(i,...,j) = sum(0,..j) - sum(0,...,i)
        // 映射<sum, cnt>， 如果mp[sum(0,..,i)]存在，则统计次数加上mp[sum-k]
        // 注意mp[0] = 1，因为当nums只有一个元素k时，次数为1
        unordered_map<int, int> mp; // <sum, k>
        mp[0] = 1;
        int sum = 0;
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if(mp.count(sum-k) == 1)
                res += mp[sum-k];
            if(mp.count(sum) == 0)
                mp[sum] = 1;
            else
                mp[sum] += 1;
        }
        return res;
    }
};
