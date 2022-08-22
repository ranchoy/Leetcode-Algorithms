// https://leetcode.cn/problems/minimum-consecutive-cards-to-pick-up/
// map函数映射，每次更新元素出现的下标。
class Solution {
public:
    int minimumCardPickup(vector<int> &cards) {
        map<int,int> mp; // <card[i], i>
        int k, n = cards.size();
        int len, min_len = INT_MAX;

        for(int i = 0; i < n; i++) {
            k = cards[i];
            if(mp.count(k) > 0) {
                len = i - mp[k] + 1;
                min_len = min(min_len, len);
            }
            mp[k] = i;
        }

        return (min_len == INT_MAX) ? -1 : min_len;
    }
};

/*
[1,0,5,3]
[3,4,2,3,4,7]

-1
4
*/
