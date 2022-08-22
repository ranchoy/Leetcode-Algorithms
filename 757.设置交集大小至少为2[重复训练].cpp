// https://leetcode.cn/problems/set-intersection-size-at-least-two/
// 题意：贪心策略，每次维护两个元素，从后往前遍历区间，记录节点更新次数。
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals) {
        int a, b, res = 2;
        int cur, next, len, left, right;
        sort(intervals.begin(), intervals.end(), comp);

        len = intervals.size();
        cur = intervals[len-1][0]; next = cur + 1;
        for(int i = len-2; i >= 0; i--) {
            left = intervals[i][0]; right = intervals[i][1];
            if(right >= next) {
               continue;
            } else if(right < cur) {
               res += 2;
               cur = intervals[i][0];
               next = cur + 1;
            } else {
               res += 1;
               next = cur;
               cur = intervals[i][0];
            }
        }

        return res;
    }

    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] != b[0]) {
            return a[0] < b[0]; // asc
        }
        return a[1] > b[1]; // desc
    }
};

/*
[[1, 3], [1, 4], [2, 5], [3, 5]]
[[2,10],[3,7],[3,15],[4,11],[6,12],[6,16],[7,8],[7,11],[7,15],[11,12]]

3
5
*/
