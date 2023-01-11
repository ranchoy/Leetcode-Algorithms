// https://leetcode.cn/problems/evaluate-the-bracket-pairs-of-a-string/solution/
// 题解：模拟+Hash，注意替换字符串temp_s的截取。
class Solution {
public:
    string evaluate(string s, vector<vector<string>> &knowledge) {
        int n = s.size();
        string ans, temp_s;
        map<string, string> map_list;
        for(auto item : knowledge) {
            map_list.insert(make_pair(item[0], item[1]));
        }

        bool flag = true;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                temp_s.clear();
                flag = false; continue;
            }
            if(s[i] == ')') {
                if(map_list.find(temp_s) != map_list.end()) {
                    ans += map_list[temp_s];
                } else {
                    ans += '?';
                }
                flag = true; continue;
            }
            temp_s += s[i];
            if(flag == true) ans += s[i];
        }

        return ans;
    }
};

/*
"hi(name)"
[["a","b"]]
"(a)(a)(a)aaa"
[["a","yes"]]
"(name)is(age)yearsold"
[["name","bob"],["age","two"]]

"hi?"
"yesyesyesaaa"
"bobistwoyearsold"
*/
