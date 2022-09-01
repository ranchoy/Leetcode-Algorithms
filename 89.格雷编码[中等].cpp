// https://leetcode.cn/problems/gray-code/
// 题解：格雷码模拟，第i个格雷码的公式为：g[i] = (i >> 1) ^ i。
class Solution {
public:
    vector<int> grayCode(int n) {
        int len = 1 << n;
        vector<int> res(len, 0);

        for (int i = 0; i < len; i++) {
            res[i] = (i >> 1) ^ i;
        }
        return res;
    }
};

/*
2
4

[0,1,3,2]
[0,1,3,2,6,7,5,4]
*/
