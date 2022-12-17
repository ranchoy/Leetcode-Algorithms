// https://leetcode.cn/problems/form-array-by-concatenating-subarrays-of-another-array/
// 题解：KMP字符串匹配 or 模拟。KMP匹配时，next[i]表示模式串s[0,i]的最长公共前后缀的结尾索引，最长公共串的长度为next[i]+1。
// 注意：1. KMP的核心是next[i]的构建。当遇到不匹配情况时，跳过公共部分，至next[i]。
//       2. 字符串"abab"，前缀"aba"，后缀"bab"，长公共前后缀"ba"。
class Solution {
public:
    int KMP(vector<int> &nums, int idx, vector<int> &group) {
        if(group.size() + idx > nums.size()) return -1;
        int m = group.size(), k;
        vector<int> next(m+1,0); // next[i]，group[0,i]的公共前后缀最长长度为next[i]+1。

        // init next[i] array.
        k = next[0] = -1;
        for(int i = 1; i < m; i++) {
            while(k > -1 && group[i] != group[k+1]) {
                k = next[k]; // 不匹配，跳过公共部分，至next[k]。
            }

            if(group[i] == group[k+1]) k++;
            next[i] = k;
        }

        for(int i = idx, j = -1; i < nums.size(); i++) {
            while(j > -1 && nums[i] != group[j+1]) {
                j = next[j];
            }

            if(nums[i] == group[j+1]) j++;
            if(j + 1 == m) return i + 1; // nums下次开始匹配的初始下标
        }

        return -1;
    }

    bool canChoose(vector<vector<int>> &groups, vector<int> &nums) {
        int idx = 0, k = 0;
        int n = nums.size(), m = groups.size();

        for(int i = 0; i < m; i++) {
            k = KMP(nums, k, groups[i]);
            if(k == -1) return false;
        }

        return true;
    }
};

/*
[[10,-2],[1,2,3,4]]
[1,2,3,4,10,-2]
[[1,-1,-1],[3,-2,0]]
[1,-1,0,1,-1,-1,3,-2,0]
[[21,22,21,22,21,30]]
[21,22,21,22,21,22,21,30]

false
true
true
*/
