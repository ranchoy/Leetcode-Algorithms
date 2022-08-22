// https://leetcode.cn/problems/group-the-people-given-the-group-size-they-belong-to/
// 题解：模拟题，用户先按组聚合再按序列分组。
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        vector<vector<int>> ans;
        map<int,vector<int>> mps; // <size,idx>

        for(int i = 0; i < groupSizes.size(); i++) {
            mps[groupSizes[i]].push_back(i);
        }

        map<int,vector<int>>::iterator iter;
        for(iter = mps.begin(); iter != mps.end(); iter++) {
            vector<int> &nums = iter->second;
            for(int i = 0; i < nums.size(); i += iter->first) {
                vector<int>::iterator tmp = nums.begin();
                ans.push_back(vector<int>(tmp+i, tmp+i+iter->first));
            }
        }

        return ans;
    }
};

/*
[2,1,3,3,3,2]
[3,3,3,3,3,1,3]

[[1],[0,5],[2,3,4]]
[[5],[0,1,2],[3,4,6]]
*/
