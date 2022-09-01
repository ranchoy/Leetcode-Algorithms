// https://leetcode.cn/problems/longest-subsequence-with-limited-sum/
// 题解：sort排序+模拟。
class Solution {
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        vector<int> res;
        sort(nums.begin(), nums.end(), less<int>());

        for(int i = 0; i < queries.size(); i++) {
            int k = 0, s = 0;
            while(k < nums.size() && s + nums[k] <= queries[i]) {
                s += nums[k++];
            }
            res.push_back(k);
        }

        return res;
    }
};

/*
[4,5,2,1]
[3,10,21]

[2,3,4]
*/
