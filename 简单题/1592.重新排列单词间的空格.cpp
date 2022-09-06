// https://leetcode.cn/problems/rearrange-spaces-between-words/
// 题解：stringstream使用，注意text以空格开始情况。
class Solution {
public:
    string reorderSpaces(string text) {
        string word, res;
        vector<string> words;
        int word_cnt = 0, len = text.size();
        int blank = count(text.begin(), text.end(), ' ');

        stringstream ss(text);
        while(ss >> word) {
            word_cnt++; words.emplace_back(word);
        }
        if(word_cnt == 1) return words[0] + string(blank, ' ');

        blank = blank / (word_cnt - 1);
        for(int i = 0; i < word_cnt; i++) {
            res += words[i];
            if(i != word_cnt - 1) res += string(blank, ' ');
        }
        if(res.size() < len) res += string(len - res.size(), ' ');
        return res;
    }
};

/*
"  this   is  a sentence "
" practice   makes   perfect"

"this   is   a   sentence"
"practice   makes   perfect "
*/
