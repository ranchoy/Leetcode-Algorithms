// https://leetcode.cn/problems/maximum-units-on-a-truck/
// 题解：Sort排序，考虑使用更简洁的lambda表达式。
class Solution {
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
        int res = 0, n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), [&](vector<int> &a, vector<int> &b) {
            return a[1] >= b[1];
        });

        for(int i = 0; i < n; i++) {
            if(truckSize == 0) break;
            if(truckSize >= boxTypes[i][0]) {
                res += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else {
                res += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
        }

        return res;
    }
};

/*
[[1,3],[2,2],[3,1]]
4
[[5,10],[2,5],[4,7],[3,9]]
10

8
91
*/
