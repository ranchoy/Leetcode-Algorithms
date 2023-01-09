// https://leetcode.cn/problems/two-out-of-three/
class Solution {
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3) {
        vector<int> ans;
        set<int> h1, h2, h3;

        for(auto item : nums1) h1.insert(item);
        for(auto item : nums2) h2.insert(item);
        for(auto item : nums3) h3.insert(item);

        for(int i = 0; i <= 100; i++) {
            if(h1.count(i) + h2.count(i) + h3.count(i) >= 2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

/*
[1,1,3,2]
[2,3]
[3]
[3,1]
[2,3]
[1,2]

[2,3]
[2,3,1]
*/
