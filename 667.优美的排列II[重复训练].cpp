// https://leetcode.cn/problems/beautiful-arrangement-ii/
// 题解：模拟题，规律如下：
// 当k = 1时，res = [1,2,3,...,n];
// 当k = n-1时，res = [1,n,2,n-1,3,...];
// 当1< k <n-1时，res = [1,k+1,2,k,3,k-1,4,...,k+2,k+3,...,n];
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        
        for(int i = 1, j = k+1; i <= j; i++, j--) {
            res.push_back(i);
            if(i != j) res.push_back(j);
        }
        for(int i = k+2; i <= n; i++) res.push_back(i);
        
        return res;
    }
};
/*
3
1
5
3

[1,2,3]
[1,4,2,3,5]
*/
