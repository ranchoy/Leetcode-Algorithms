// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
// 同题：https://leetcode-cn.com/problems/permutations-ii/
// 同题：https://leetcode-cn.com/problems/permutation-ii-lcci/
// 同题：https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=117
// 全排列，从当前已排序下标idx开始进行下一轮排序，注意避免重复元素（i!=idx && s[i]==s[idx]）。
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        sort(s.begin(), s.end()); // 字串排序
        dfs(res, s, 0);
        return res;
    }

    void dfs(vector<string> &res, string s, int idx) {
        if(idx == s.length()-1) {
            res.push_back(s);
        } else {
            for(int i = idx; i < s.length(); i++) {
                if(i != idx && s[i] == s[idx]) {
                    continue;
                }
                swap(s[idx], s[i]);
                dfs(res, s, idx+1); // 从idx开始
            }
        }
    }
};

/*
"abc"
"suvyls"

["abc","acb","bac","bca","cab","cba"]
*/
