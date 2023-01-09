// https://leetcode.cn/problems/fruit-into-baskets/
// 题解：滑动窗口+记录，需要记录起始索引s_idx，第一类水果索引idx1，第二类水果idx2。
class Solution {
public:
    int totalFruit(vector<int> &fruits) {
        set<int> st;
        int n = fruits.size();
        int mx = 0, s_idx = 0, idx1 = 0, idx2 = 0;

        for(int i = 0; i < n; i++) {
            if(st.size() == 2 && st.count(fruits[i]) == 0) {
                st.erase(fruits[idx1]);
                s_idx = idx2;
            }
            if(i != 0 && fruits[i] != fruits[i-1]) {
                idx1 = i - 1; idx2 = i;
            }
            if(st.count(fruits[i]) == 0) {
                st.insert(fruits[i]);
            }
            mx= max(mx, i - s_idx + 1);;
        }

        return mx;
    }
};

/*
[0,1,2]
[0,1,6,6,4,4,6]
[1,0,1,4,1,4,1,2,3]

2
5
5
*/
