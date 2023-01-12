// https://leetcode.cn/problems/rearrange-characters-to-make-target-string/
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int ans = s.size();
        int n = s.size(), m = target.size();
        map<char,int> map_list1, map_list2;
        for(int i = 0; i < n; i++) map_list1[ s[i] ]++;
        for(int i = 0; i < m; i++) map_list2[ target[i] ]++;

        for(auto &[k, v] : map_list2) {
            ans = min(ans, map_list1[k] / v);
        }

        return ans;
    }
};

/*
"abcba"
"abc"
"ilovecodingonleetcode"
"code"
"aaaaaaaaaaaaaaaaaaaaaaaaaa"
"aaaaaaaaa"

1
2
2
*/
