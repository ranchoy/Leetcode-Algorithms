// https://leetcode-cn.com/problems/permutation-ii-lcci/
// https://leetcode-cn.com/problems/permutations/
// 模拟题，从S[left]之后开始找S[i]与之互换，换完后left+1，当left到结尾结束。
class Solution {
public:
    vector<string> res;
    vector<string> permutation(string S) {
        sort(S.begin(), S.end(), less<int>());
        dfs(S, 0);
        return res;
    }

    void dfs(string S, int left) {
        if(left + 1 == S.length()) {
            res.push_back(S);2
        } else {
            for(int i = left; i < S.length(); i++) {
                if(i != left && S[i] == S[left]) continue;
                swap(S[i], S[left]);
                dfs(S, left+1); // 重要
            }
        }
    }
};

/*
"qqe"
["eqq","qeq","qqe"]
*/
