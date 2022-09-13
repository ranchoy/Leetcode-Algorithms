// https://leetcode.cn/problems/gas-station/
// 题解：贪心策略，油量剩余最少时放到最后跑，故起始点为(idx+1)%len。
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int len = gas.size();
        int remain = 0, t = INT_MAX, t_idx = 0;

        for(int i = 0; i < len; i++) {
            remain += gas[i] - cost[i];
            if(remain < t) {
                t = remain; t_idx = i;
            }
        }

        return (remain < 0) ? -1 : (t_idx+1)%len; // important
    }
};

/*
[3,1,1]
[1,2,2]
[1,2,3,4,5]
[3,4,5,1,2]

0
3
*/
