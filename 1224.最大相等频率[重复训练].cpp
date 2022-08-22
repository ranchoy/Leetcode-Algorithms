// https://leetcode.cn/problems/maximum-equal-frequency/
// 题解：模拟题，存在三种情况：1.所有元素均出现一次；2.某一元素仅出现一次，其它元素出现次数相同；3.某一元素仅比其它元素仅多出现一次。
class Solution {
public:
    int N = 1e5 + 1;
    int maxEqualFreq(vector<int> &nums) {
        int ans = 0;
        int t, cur, len, max_cnt = 0;
        vector<int> cnt(N, 0);  // 元素x出现次数为cnt[x]
        vector<int> elem(N, 0); // 出现cnt[x]次的元素个数为elem[cnt[x]]

        for(int i = 0; i < nums.size(); i++) {
            len = i + 1; t = nums[i];
            cnt[t]++; cur = cnt[t];
            elem[cur]++; elem[cur-1]--; // update number of elements
            max_cnt = max(max_cnt, cur);

            if(max_cnt == 1) ans = len; // 1 2 3
            if(max_cnt * elem[max_cnt] + 1 == len) ans = len; // 11 22 3
            if((max_cnt-1) * (elem[max_cnt-1] + 1) + 1 == len) ans = len; // 11 22 333
        }

        return ans;
    }
};

/*
[1,1,1,2,2,2]
[2,2,1,1,5,3,3,5]

5
7
*/
