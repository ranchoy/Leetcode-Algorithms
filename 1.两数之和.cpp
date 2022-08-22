// https://leetcode-cn.com/problems/two-sum/
// 字典键值对，利用unordered_map存储数组元素，并匹配。
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> mp; // <val, idx>
        for(int i = 0; i < nums.size(); i++) {
            int val = target - nums[i];
            if(mp.find(val) != mp.end()) {
                return {mp[val], i};
            }
            mp.insert(make_pair(nums[i], i));
        }
        return {};
    }
};

/*
[2,7,11,15]
9

[0,1]
*/
