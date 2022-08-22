// https://leetcode-cn.com/problems/most-common-word/
// 模拟题目，注意单词划分规则，只要不是字母就开始划分，注意多个字符连续情况。
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        string res;
        map<string,int> mp; // (单词，次数)
        set<string> banned_st;
        for(int i = 0; i < banned.size(); i++) {
            banned_st.insert(banned[i]);
        }

        int left = 0, right = 0;
        int n = paragraph.size();
        for(int i = 0; i < n; i++) {
            if(isalpha(paragraph[i])) {
                right = i;
                paragraph[i] = tolower(paragraph[i]);
            } else {
                if(i > 0 && isalpha(paragraph[i-1])) { // 找到[字母+字符]位置
                    int len = i - left;
                    string temp_s = paragraph.substr(left, len);
                    mp[temp_s] = (mp.count(temp_s) == 0) ? 1 : mp[temp_s]+1;
                }
                if(i < n-1 && paragraph[i] == ' ') {
                    left = i + 1;
                }
            }
        }

        if(left <= n - 1) { // "Bob."
            int len = right - left + 1;
            string temp_s = paragraph.substr(left, len);
            mp[temp_s] = (mp.count(temp_s) == 0) ? 1 : mp[temp_s]+1;
        }

        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(banned_st.count(it->first) > 0) {
                mp.erase(it);
            }
        }

        int mx = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second > mx) {
                mx = it->second;
                res = it->first;
            }
        }

        return res;
    }
};

/*
"Bob, tom.."
["bob"]
"Bob. hIt, baLl."
["bob", "hit"]

"tom"
"ball"
*/
