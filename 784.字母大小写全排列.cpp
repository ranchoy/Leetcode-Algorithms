// https://leetcode.cn/problems/letter-case-permutation/
// 题解：DFS+二叉树思路，字母有变和不变两种选择，遍历至叶子节点才返回字符串。
class Solution {
public:
    vector<string> res;
    vector<int> alpha_arr;

    vector<string> letterCasePermutation(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(isalpha(s[i])) alpha_arr.push_back(i);
        }
        dfs(s, 0);
        return res;
    }

    void dfs(string s, int idx) {
        if(idx == alpha_arr.size()) {
            res.emplace_back(s); return;
        }

        int i = alpha_arr[idx];
        dfs(s, idx+1); // no change
        s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i]+32 : s[i]-32;
        dfs(s, idx+1); // change
    }
};

/*
"3z4"
"a1b2"

["3z4","3Z4"]
["a1b2", "a1B2", "A1b2", "A1B2"]
*/
