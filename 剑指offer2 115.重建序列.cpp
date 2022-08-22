// https://leetcode.cn/problems/ur2n8P/ 
// 题解：子数组seq[i]的元素顺序和数组nums一致。
class Solution {
public:
    bool sequenceReconstruction(vector<int> &nums, vector<vector<int>> &seq) {
        int n = nums.size();
        vector<int> pre(n+1, 0); // i->j, pre[j] = i;
        vector<bool> is_order(n+1, false); // order is correct

        for(int i = 1; i < n; i++) {
            pre[nums[i]] = nums[i-1];
        }

        for(auto &s : seq) {
            for(int i = 1; i < s.size(); i++) {
                if(is_order[s[i]] == false && pre[s[i]] == s[i-1]) {
                    is_order[s[i]] = true;
                }
            }
        }

        for(int i = 1; i < n; i++) {
            if(is_order[nums[i]] == false) return false;
        }

        return true;
    }
};

/*
[1,2,3]
[[1,2],[1,3]]
[1,2,3]
[[1,2],[1,3],[2,3]]

false
true
*/
