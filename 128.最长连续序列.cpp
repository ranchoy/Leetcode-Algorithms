// https://leetcode-cn.com/problems/longest-consecutive-sequence/
// set容器去重，注意插入元素方法。
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if(nums.size() == 0) return 0; // 重要
        int mx = 0;
        set<int> st;

        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++) {
            int cnt = 1;
            int k = nums[i];
            while(st.count(--k) != 0) {
                st.erase(k);
                cnt++;
            }
            k = nums[i];
            while(st.count(++k) != 0) {
                st.erase(k);
                cnt++;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};

/*
[100,4,200,1,3,2]
4
*/
