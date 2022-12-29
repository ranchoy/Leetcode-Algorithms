// https://leetcode.cn/problems/form-array-by-concatenating-subarrays-of-another-array/
class Solution {
public:
    int KMP(vector<int> &nums, int idx, vector<int> &group) {
        if(group.size() + idx > nums.size()) return -1;
        int m = group.size(), k;
        vector<int> next(m,0); // next[i]，group[0,i]的公共前后缀最长长度为next[i]+1。

        // init next array.
        k = next[0] = -1;
        for(int i = 1; i < m; i++) {
            while(i > -1 && group[i] != group[k+1]) {
                k = next[k]; // 不匹配，跳过公共部分，至next[k]。
            }
            if(group[i] == group[k+1]) {
                k++;
            }
            next[i] = k;
        }
        
        for(int i = idx, j = -1; i < nums.size(); i++) {
            while(j > -1 && nums[i] != group[j+1]) {
                j = group[j];
            }
            if(nums[i] == group[j+1]) {
                j++;
            }
            if(j + 1 == m) {
                return i - m + 1; // idx下次匹配的nums下标
            }
        }
        
        return -1;
    }
    
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums) {
        int idx = 0, k = 0;
        int n = nums.size(), m = groups.size();

        for(int i = 0; i < m; i++) {
            k = KMP(nums, k, groups[i]);
            if(k == -1) return false;
            k += groups[i].size();
        }
        
        return true;
    }
    
    bool canChoose2(vector<vector<int>> &groups, vector<int> &nums) {
        int idx = 0;
        int n = nums.size(), m = groups.size();

        for(int i = 0; i < n && idx < m; i++) {
            if(nums[i] != groups[idx][0]) {
                continue;
            }

            int j = i, k = 0;
            while(j < n && k < groups[idx].size()) {
                if(nums[j] == groups[idx][k]) {
                    j++; k++;
                } else {
                    break;
                }
            }
            if(k == groups[idx].size()) {
                i = j - 1; idx++;
            }
        }

        return (idx == m) ? true : false;
    }
};

/*
[[10,-2],[1,2,3,4]]
[1,2,3,4,10,-2]
[[1,-1,-1],[3,-2,0]]
[1,-1,0,1,-1,-1,3,-2,0]

false
true
*/
