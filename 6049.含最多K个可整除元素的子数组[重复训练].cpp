// https://leetcode.cn/problems/k-divisible-elements-subarrays/
// 以当前元素i为起点，一直到k个被p整除的数结束，得到子数组存入集合，进行去重。最后，输出集合的大小。
class Solution {
public:
    int countDistinct(vector<int> &nums, int k, int p) {
        vector<int> temp;
        set<vector<int>> hlist;
        int cnt, n = nums.size();

        for(int i = 0; i < n; i++) {
            cnt = 0;
            for(int j = i; j < n; j++) {
                temp.push_back(nums[j]);
                if(nums[j] % p == 0) {
                    cnt++;
                    if(cnt > k) break;
                }
                hlist.insert(temp);
            }
            temp.clear();
        }
        return hlist.size();
    }
};

/*
[2,3,3,2,2]
2
2

11
*/
