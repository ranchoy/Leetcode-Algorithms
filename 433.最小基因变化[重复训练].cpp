// https://leetcode.cn/problems/minimum-genetic-mutation/
// DFS深度优先遍历，注意字符串start变换至end时，每步只能变一次且每次变换cur_str必须在bank中。
// 为什么vis不要重新置0呢？因为path1=1->2->4->5要4步，而path2=1->3->5只要3步，5一定是被更短的path2先标记。
class Solution {
public:
    int min_step, diff_size;
    vector<char> gen_key = {'A','C','G','T'};
    unordered_set<string> hash_st, vis;

    int minMutation(string start, string end, vector<string> &bank) {
        min_step = INT_MAX;
        for(int i = 0; i < bank.size(); i++) {
            hash_st.emplace(bank[i]);
        }
        vis.emplace(start);
        dfs(bank, start, end, start, 0);
        return (min_step == INT_MAX) ? -1 : min_step;
    }

    void dfs(vector<string> &bank, string start, string end, string cur_str, int step) {
        if(cur_str == end) {
            min_step = min(min_step, step);
            return;
        }

        for(int i = 0; i < end.size(); i++) { // 注意，从0开始
            for(int j = 0; j < gen_key.size(); j++) {
                if(cur_str[i] == gen_key[j]) continue;
                string new_str = cur_str; new_str[i] = gen_key[j];
                
                if(vis.count(new_str) == 0 && hash_st.count(new_str) == 1) {
                    vis.emplace(new_str);
                    dfs(bank, start, end, new_str, step+1);
                }
            }
        }
    }
};

/*
"AACCGGTT"
"AAACGGTA"
["AACCGGTA","AACCGCTA","AAACGGTA"]
"AACCGGTT"
"AAACGGTA"
["AACCGATT","AACCGATA","AAACGATA","AAACGGTA"]

2
4
*/
