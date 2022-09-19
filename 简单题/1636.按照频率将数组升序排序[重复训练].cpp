// https://leetcode.cn/problems/sort-array-by-increasing-frequency/
// 题解：排序+Lambda表达式，即：auto f = [捕获变量](参数列表){操作&返回值};
class Solution {
public:
    map<int,int> mps;
    vector<int> frequencySort(vector<int> &nums) {
        for(auto x : nums) mps[x]++;
        auto comp = [&](int a, int b) {
            if(mps[a] == mps[b]) return a > b;
            return mps[a] < mps[b];
        };
        sort(nums.begin(), nums.end(), comp);
        return nums;
    }
};
/*
[2,3,1,3,2]
[-1,1,-6,4,5,-6,1,4,1]

[1,3,3,2,2]
[5,-1,4,4,-6,-6,1,1,1]
*/
